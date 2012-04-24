
%clear all;
close all;

%figure(1)

%loading trace
res = mfcsvread('../traces/test.csv');

%renaming
X = res.X;
Y = res.Y;
T = res.T;

figure(1)
plot(X,-Y);

% %pen down indices
% Z = res.Z;
% pdi = find(Z);
% 
% %filtering
% deb = pdi(2);
% fin = pdi(size(pdi,1)-1);
% 
% %shortening
% 
% X = X(deb:fin);
% Y = Y(deb:fin);
% T = T(deb:fin);

%plot(X,-Y);

%calcul if c
n = size(T,1);
%c = (X(n)-X(1))/(T(n)-T(1))
c=0;

figure(5);
plot(T,X,'r');
hold on;
plot(T,-Y,'b');


%derives

dT = diff(T);
dX = diff(X);
dY = diff(Y);



dXsdT = dX./dT -c;
dYsdT = dY./dT

%filtering
% fdX = dct(dXsdT);
% truc = round(size(fdX,1)/3);
% filtered = [fdX(1:truc);zeros(size(fdX,1)-truc,1)];
% dXsdT = idct(filtered);
% 
% fdY = dct(dYsdT);
% filtered = [fdY(1:truc);zeros(size(fdY,1)-truc,1)];
% dYsdT = idct(filtered);

%new T
aT = T(1:n-1)+T(2:n);
nT = aT/2;

% rajout de zeros à dXsdT,dYsDT et valeur à aT
dXsdT=[0;dXsdT;0];
dYsdT=[0;dYsdT;0];
nT = [T(1);nT;T(end)];
size(nT);
size(dXsdT);

%figure(2)
%plot(nT,dXsdT);
figure(3);
plot(nT,dYsdT,'r');


% points where dY/dT crosses zero
[ind0s,t0ys,y0s] = crossing(dYsdT,nT);
figure(3)
hold on;
plot(t0ys,y0s,'g*');

% calculs des parametres

nb_arcs = size(t0ys,2)-1

%pour y
wy = pi./diff(t0ys)
phiy = mod(-wy.*t0ys(1:nb_arcs),2*pi);
%t1s = zeros(nb_arcs,1);
b = zeros(nb_arcs,1);


for i=1:nb_arcs
    %f = cos(nT(ind0s(i):ind0s(i+1))*wy(i) + phiy(i));
    %hold on;
    %plot(nT(ind0s(i):ind0s(i+1)),0,'y');
    %[ind1,t1s,y1s] = crossing(diff(dYsdT(ind0s(i):ind0s(i+1))),nT(ind0s(i):ind0s(i+1)-1)) 
    %plot(t1s,y1s,'c*');
    %plot(nT(ind0s(i):ind0s(i+1)-1),diff(dYsdT(ind0s(i):ind0s(i+1))),'c');
    [val1,mid] = max(abs(dYsdT(ind0s(i):ind0s(i+1))));
    val = mean(abs(dYsdT(ind0s(i):ind0s(i+1))));
    sval = std(abs(dYsdT(ind0s(i):ind0s(i+1))));
    b(i) = sign( dYsdT(ind0s(i)+mid-1))*(val+sval);
end



%sampling
sampling = t0ys(1):20:t0ys(nb_arcs+1);
sphiy = zeros(nb_points,1);
nb_points = size(sampling,2);

%signal interpolé
signaly = zeros(nb_points,1);
k=1;
i=1;
for t=sampling
    if (t>t0ys(k+1))
        k = k+1;
    end
    signaly(i) = b(k)*sin(wy(k)*t+phiy(k));
    sphiy(i) = sphiy(k); 
    i=i+1;
end

%hold on;
%plot(sampling,signaly,'c*');



%%%memechose pour x !!
% points where dX/dT crosses zero
[ind0s,t0xs,x0s] = crossing(dXsdT,nT); 
%figure(2)
%hold on;
%plot(t0xs,x0s,'g*');

% calculs des parametres

nb_arcs = size(t0xs,2)-1
%pour x
wx = pi./diff(t0xs)
phix = mod(-wx.*t0xs(1:nb_arcs),2*pi);
%t1s = zeros(nb_arcs,1);
a = zeros(nb_arcs,1);


for i=1:nb_arcs
    %f = cos(nT(ind0s(i):ind0s(i+1))*wy(i) + phiy(i));
    %hold on;
    %plot(nT(ind0s(i):ind0s(i+1)),0,'y');
    %[ind1,t1s,y1s] = crossing(diff(dYsdT(ind0s(i):ind0s(i+1))),nT(ind0s(i):ind0s(i+1)-1)) 
    %plot(t1s,y1s,'c*');
    %plot(nT(ind0s(i):ind0s(i+1)-1),diff(dYsdT(ind0s(i):ind0s(i+1))),'c');
    [val1,mid] = max(abs(dXsdT(ind0s(i):ind0s(i+1))));
    val = mean(abs(dXsdT(ind0s(i):ind0s(i+1))));
    sval = std(abs(dXsdT(ind0s(i):ind0s(i+1))));
    a(i) = sign( dXsdT(ind0s(i)+mid-1))*(val+sval);
end


%sampling
% sampling = t0xs(1):20:t0xs(nb_arcs+1);
% nb_points = size(sampling,2);

%signal interpolé
signalx = zeros(nb_points,1);
sphix = zeros(nb_points,1);
k=1;
i=1;
for t=sampling
    if (t>t0xs(k+1)&& k< numel(a))
        k = k+1;
    end
    signalx(i) = a(k)*sin(wx(k)*t+phix(k));
    sphix(i) = phix(k);
    i=i+1;
end

%hold on;
%plot(sampling,signalx,'c');


nX = zeros(nb_points,1);
nY = zeros(nb_points,1);


nX(1) = X(ind0s(1));
nY(1) = Y(ind0s(1));


%constructions
for i=2:size(sampling,2)
%     nX(i) = (signalx(i-1)+c)*20 + nX(i-1);
%     nY(i) = signaly(i-1)*20 + nY(i-1);
    samp = sampling(1:i);
    sigx = signalx(1:i);
    sigy = signaly(1:i);
    nx = trapz(sigx+c)*20 + X(ind0s(1));
    ny = trapz(sigy)*20 + Y(ind0s(1));
    nX(i) = nx;
    nY(i) = ny;
end



figure(1)
hold on;
plot(nX,-nY,'r');

figure(5);
plot(sampling,nX,'b');
hold on;
plot(sampling,-nY,'g');

figure(6);
plot(sampling,mod((sphix - sphiy),pi/2)/pi*180,'m');






