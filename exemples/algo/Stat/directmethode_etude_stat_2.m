%clear all;
close all;

%loading trace
[inds,lT,lX,lY] = readTR_sep('../BaseDeDonnee/jc_squigle');
%[inds,lT,lX,lY] = readTR_sep('../traces/marseille/marseille.tr');

N = numel(inds);


ang = pi/4;

Ap=[];
B=[];
WX = [];
WY = [];
PX = [];
PY = [];
Sslant = [];
Ppsi = [];

for i=1:N

j = i+1;
if(j>N)
    f = numel(lT);
else 
    f = inds(j)-1;
end

    
cX = lX(inds(i):f);
cY = lY(inds(i):f);
T = lT(inds(i):f);

X = cX*cos(ang) + cY*sin(ang);
Y = -cX*sin(ang) + cY*cos(ang);

X = cX;
Y = cY;

if	numel(T) > 18
hold on;
plot(cX,cY,'b');



[nT,dXsdT,dYsdT,ind0xs,t0xs,x0s,ind0ys,t0ys,y0s,c,fdY] = init(T,X,Y);


[a,b,wx,wy,phix,phiy] = direct_method(dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys);
sampling = t0ys(1):20:t0ys(end);

[nX,nY,signalx,signaly,slant,psi] = resample_hw_sin(sampling,t0xs,t0ys,a,b,wx,wy,phix,phiy,c,X(1),Y(1));

Ap = [Ap,a'];
B= [B,b'];
WX = [WX ,wx];
WY = [WY ,wy];
PX = [PX, phix];
PY = [PY, phiy];
Ppsi = [Ppsi, psi'];
Sslant = [Sslant, slant'];

% figure
% plot(nT,dYsdT,'b');
% hold on;
% plot(sampling,signaly,'c');
% hold on;
% plot(nT,fdY,'r');
% hold on;
% plot(t0ys,y0s,'g*');


cnX = nX*cos(ang) - nY*sin(ang);
cnY = nX*sin(ang) + nY*cos(ang);

cnX = nX;
cnY = nY;

figure(1)
hold on;
plot(cnX,cnY,'r');

end


end

FX = WX*1000/(2*pi);
FY = WY*1000/(2*pi);

nFX = find(0<FX & FX<40);
nFY = find(0<FY & FY<40);


figure;
[A,G] = hist(FX(nFX),100);
bar(G,A,'y');

figure;
[A,G] = hist(FY(nFY),100);
bar(G,A,'b');

% figure;
% [A,G] = hist(180*atan(Sslant)/pi,10);
% bar(G,A,'r');
% 
% figure;
% [A,G] = hist(Ppsi,10);
% bar(G,A,'g');

% figure;
% [A,G] = hist(abs(Ap),100);
% bar(G,A,'g');
% 
% figure;
% [A,G] = hist(abs(B),100);
% bar(G,A,'r');
% 
% figure;
% [A,G] = hist(mod(PX*180/pi,90),100);
% bar(G,A,'c');
% 
% figure;
% [A,G] = hist(mod(PY*180/pi,90),100);
% bar(G,A,'m');






