
clear all;
close all;


[inds,T,X,Y] = readTR_sep('trace_');


[nT,dXsdT,dYsdT,ind0xs,t0xs,x0s,ind0ys,t0ys,y0s,c,fdY] = init(T,X,Y);


[px,py] = direct_method_parab(nT,dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys);
sampling = t0ys(1):20:t0ys(end);

[nX,nY,signalx,signaly] = resample_hw_parab(sampling,t0xs,t0ys,px,py,c,X(1),Y(1));


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











