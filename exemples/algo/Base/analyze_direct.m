
clear all;
close all;


[inds,T,X,Y] = readTR_sep('/home/rvlander/Desktop/trace_enregistree_');
%  [inds,T,X,Y] = readTR_sep('../traces/marseille/marseille.tr');
% 
% T = T(inds(2):inds(3)-1);
% X = X(inds(2):inds(3)-1);
% Y = -Y(inds(2):inds(3)-1);

%  X = filtfilt(ones(1,6)/6,1,X);
%  Y = filtfilt(ones(1,6)/6,1,Y);



[nT,dXsdT,dYsdT,ind0xs,t0xs,x0s,ind0ys,t0ys,y0s,c,fdY] = init(T,X,Y);


[a,b,wx,wy,phix,phiy] = direct_method(dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys);
sampling = t0ys(1):20:t0ys(end);

%export2strace(a,b,wx,wy,phix,phiy,t0xs(1:end-1),t0ys(1:end-1),T(end));

[nX,nY,signalx,signaly,slant,psi] = resample_hw_sin(sampling,t0xs,t0ys,a,b,wx,wy,phix,phiy,c,X(1),Y(1));


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










