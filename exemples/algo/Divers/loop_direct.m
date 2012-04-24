
clear all;
close all;


[inds,T,X,Y] = readTR_sep('trace_');



[nT,dXsdT,dYsdT,ind0xs,t0xs,x0s,ind0ys,t0ys,y0s,c,fdY] = init(T,X,Y);
[a,b,wx,wy,phix,phiy] = direct_method(dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys);
sampling = T(1):9:T(end);
[nX,nY,signalx,signaly,slant,psi] = resample_hw_sin(sampling,t0xs,t0ys,a,b,wx,wy,phix,phiy,c,X(1),Y(1));


figure(1)
hold on;
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

% 
% figure(3);
% hold on;
% plot(nT,dYsdT,'r','LineWidth',1, 'LineSmoothing','on');
% hold on;
% plot(sampling,signaly,'m','LineWidth',1, 'LineSmoothing','on');

for i=1:100
    
pause;
 
T = sampling';
X =nX;
Y=nY;
    
[nT,dXsdT,dYsdT,ind0xs,t0xs,x0s,ind0ys,t0ys,y0s,c,fdY] = init(T,X,Y);
[a,b,wx,wy,phix,phiy] = direct_method(dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys);
sampling = T(1):9:T(end);
[nX,nY,signalx,signaly,slant,psi] = resample_hw_sin(sampling,t0xs,t0ys,a/0.95,b/0.95,wx,wy,phix,phiy,c,X(1),Y(1));


figure(1)
hold on;
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

% 
% figure(3);
% hold on;
% plot(nT,dYsdT,'r','LineWidth',1, 'LineSmoothing','on');
% hold on;
% plot(sampling,signaly,'m','LineWidth',1, 'LineSmoothing','on');

end












