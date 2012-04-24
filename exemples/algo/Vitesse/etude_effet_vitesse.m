%clear all;
close all;

%figure(1)

%loading trace
[inds,T,X,Y] = readTR_sep('../BaseDeDonnee/gaetan_mot_drogue');

T = T(inds(2):inds(3)-1);
X = X(inds(2):inds(3)-1);
Y = -Y(inds(2):inds(3)-1);

[nT,dXsdT,dYsdT,ind0xs,t0xs,x0s,ind0ys,t0ys,y0s,c,fdY] = init(T,X,Y);


[a,b,wx,wy,phix,phiy] = direct_method(dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys);
sampling = t0ys(1):5:t0ys(end);

[nXo,nYo,signalxo,signalyo] = resample_hw_sin(sampling,t0xs,t0ys,a,b,wx,wy,phix,phiy,c,X(1),Y(1));
[nX,nY,signalx,signaly] = resample_hw_sin(sampling,t0xs/5,t0ys/5,a*3,b*3,wx*5,wy*5,phix,phiy,c*5,X(1),Y(1));

figure
plot(X,-Y,'b');
hold on;
plot(nX,-nY,'r');


figure
plot(sampling,signalyo,'b*');
hold on;
plot(sampling,signaly,'r');