close all;
clear all;

[inds,oT,X,Y] = readTR_sep('trace_');


[cX,cY] = resampleXYrand(X,Y,3,20);

X =cX;
Y=cY;
T=1:numel(X);
T=T*(oT(end)-oT(1))/numel(X);

[nT,dXsdT,dYsdT,ind0xs,t0xs,x0s,ind0ys,t0ys,y0s,c,fdY] = init(T',X,Y);


[a,b,wx,wy,phix,phiy] = direct_method(dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys);
sampling = t0ys(1):20:t0ys(end);

[nX,nY,signalx,signaly,slant,psi] = resample_hw_sin(sampling,t0xs,t0ys,a,b,wx,wy,phix,phiy,c,X(1),Y(1));

plot(X,Y,'r*');
hold on;
plot(cX,cY,'g*');


figure(1)
plot(X,Y,'b');
hold on;
plot(nX,nY,'r');


figure(2)
plot(nT,dXsdT,'LineWidth',1, 'LineSmoothing','on');
hold on;
plot(t0xs,x0s,'g*');
hold on;
plot(sampling,signalx,'c','LineWidth',1, 'LineSmoothing','on');
hold on;
plot(nT,filtfilt(ones(1,2)/2,1,dXsdT),'r','LineWidth',1, 'LineSmoothing','on');


figure(3);
plot(nT,dYsdT,'r','LineWidth',1, 'LineSmoothing','on');
hold on;
plot(sampling,signaly,'m','LineWidth',1, 'LineSmoothing','on');


figure(4)
plot(T,X);

figure(5)
plot(T,Y);

