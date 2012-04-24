
%clear all;
close all;

%figure(1)

%loading trace
[X,Y] = readTR_ori('../traces/marseille/marseille.tr');


T = 0:(max(size(X))-1);
T = T'*10;



figure(1)
plot(T,X);

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
c = (X(n)-X(1))/(T(n)-T(1))
%c=0;


%derives

dT = diff(T);
dX = diff(X);
dY = diff(Y);



dXsdT = dX./dT -c;
dYsdT = dY./dT;

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
% 
% dXsdT = filtfilt(ones(1,6)/6,1,dXsdT);
% dYsdT = filtfilt(ones(1,6)/6,1,dYsdT);

nT = [T(1);nT;T(end)];
size(nT);
size(dXsdT);

figure(2)
plot(nT,dXsdT);
figure(3);
plot(nT,dYsdT,'r');


% points where dY/dT crosses zero
[ind0xs,t0xs,x0s] = crossing(filtfilt(ones(1,6)/6,1,dXsdT),nT); 
[ind0ys,t0ys,y0s] = crossing(filtfilt(ones(1,6)/6,1,dYsdT),nT);


figure(3)
hold on;
plot(t0ys,y0s,'g*');

figure(2)
hold on;
plot(t0xs,x0s,'g*');



% calculs des parametres
nb_arcsx = size(t0xs,2)-1;
nb_arcsy = size(t0ys,2)-1;

stdx =2;
stdy =2;
a0 = tosave(1);
stda0 = tosave(2);
b0 = tosave(3);
stdb0 = tosave(4); 
wx0  = tosave(5);
stdwx0 = tosave(6);
wy0 = tosave(7);
stdwy0 = tosave(8);
phi = tosave(9);
stdphi = tosave(10); 

f = @(theta)fullvecbigfun( theta, nT , dXsdT, stdx, dYsdT, stdy, ...
                      a0,stda0 ,b0,stdb0 ,wx0 ,stdwx0,wy0,stdwy0,phi,stdphi,...
                  ind0xs,ind0ys);

tailleX = max(size(ind0xs));
tailleY = max(size(ind0ys));

tailleTheta = 3*tailleX + 3*tailleY;
             
thetamint = zeros(100,tailleTheta);
val = zeros(100,1);


options = optimset('MaxFunEvals',10000,'maxIter',10000,'Jacobian','on','DerivativeCheck','off','ScaleProblem','Jacobian');
LB = [-10 -10 0 0 -pi -pi];
UB = [10 10 0.1 0.1 pi pi];




for i=1:100
    
    ra0 = a0 + randn(tailleX,1)*stda0;
rb0 = b0 + randn(tailleY,1)*stdb0;
rwx0 = wx0 + randn(tailleX,1)*stdwx0;
rwy0 = wy0 + randn(tailleY,1)*stdwy0;
rphix = rand(tailleX,1)*2*pi;
rphiy = rand(tailleY,1)*2*pi;

% ra0 = -10 + rand(tailleX,1)*20;
% rb0 = -10 + rand(tailleY,1)*20;
% rwx0 = rand(tailleX,1)*0.1;
% rwy0 = rand(tailleY,1)*0.1;
% rphix = -pi+rand(tailleX,1)*2*pi;
% rphiy = -pi+rand(tailleY,1)*2*pi;


    [thetamint(i,:),val(i)] = lsqnonlin(f, [ra0; ... 
        rb0;rwx0;rwy0;rphix;rphiy],LB,UB,options);
end
[vmin , imin] = min(val);
theta = thetamint(imin,:);





tailleX = max(size(ind0xs));
tailleY = max(size(ind0ys));
                 
%   theta = a, b, wx ,wy ,phix,phiy
a = theta(1:tailleX);
b = theta(tailleX+1:tailleX+tailleY);
wx = theta(tailleX+tailleY+1:2*tailleX+tailleY);
wy = theta(2*tailleX+tailleY+1:2*tailleX+2*tailleY);
phix = theta(2*tailleX+2*tailleY+1:3*tailleX+2*tailleY);
phiy = theta(3*tailleX+2*tailleY+1:3*tailleX+3*tailleY);



%sampling
sampling = t0ys(1):10:t0ys(nb_arcsy+1);
nb_points = size(sampling,2);
sphiy = zeros(nb_points,1);

%signal interpolé
signaly = zeros(nb_points,1);
k=1;
i=1;
for t=sampling
    if (t>t0ys(k+1))
        k = k+1;
    end
    signaly(i) = b(k)*cos(wy(k)*t+phiy(k));
    sphiy(i) = sphiy(k); 
    i=i+1;
end

%signal interpolé
signalx = zeros(nb_points,1);
sphix = zeros(nb_points,1);
k=1;
i=1;
for t=sampling
    if (t>t0xs(k+1))
        k = k+1;
    end
    signalx(i) = a(k)*cos(wx(k)*t+phix(k));
    sphix(i) = phix(k);
    i=i+1;
end

figure(2);
hold on;
plot(sampling,signalx,'c');

figure(3);
hold on;
plot(sampling,signaly,'y');


nX = zeros(nb_points,1);
nY = zeros(nb_points,1);


nX(1) = X(ind0xs(1));
nY(1) = Y(ind0ys(1));





%constructions
for i=2:size(sampling,2)
%     nX(i) = (signalx(i-1)+c)*20 + nX(i-1);
%     nY(i) = signaly(i-1)*20 + nY(i-1);
    samp = sampling(1:i);
    sigx = signalx(1:i);
    sigy = signaly(1:i);
    nx = trapz(sigx+c)*10 + X(ind0s(1));
    ny = trapz(sigy)*10 + Y(ind0s(1));
    nX(i) = nx;
    nY(i) = ny;
end



figure(10)
plot(X,-Y,'b');
hold on;
plot(nX,-nY,'r');












