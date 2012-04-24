%clear all;
close all;

%loading trace
[X,Y] = readTR('../traces/marseille/marseille.tr');


T = 0:(max(size(X))-1);
T = T'*10;

[nT,dXsdT,dYsdT,ind0xs,t0xs,x0s,ind0ys,t0ys,y0s,c] = init(T,X,Y);

[a,b,wx,wy,phix,phiy] = direct_method(dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys);
% [ao,bo,wxo,wyo,phixo,phiyo] = lsqnonlin_method(nT,dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys,tosave,5);
[ao,bo,wxo,wyo,phixo,phiyo] = lsqnonlin_method_sin(nT,dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys,tosave,5);


[nX,nY,signalx,signaly] = resample_hw_sin(nT,t0xs,t0ys,a,b,wx,wy,phix,phiy,c);
% [nXo,nYo,signalxo,signalyo] = resample_hw_cos(nT,t0xs,t0ys,ao,bo,wxo,wyo,phixo,phiyo,c);
[nXo,nYo,signalxo,signalyo] = resample_hw_sin(nT,t0xs,t0ys,ao,bo,wxo,wyo,phixo,phiyo,c);

errd = norm([signalx signaly]-[dXsdT dYsdT])/norm([dXsdT dYsdT])
erro = norm([signalxo signalyo]-[dXsdT dYsdT])/norm([dXsdT dYsdT])

figure
plot(nT,dXsdT);
hold on;
plot(nT,signalx,'c');
hold on;
plot(nT,signalxo,'g');

figure
plot(nT,dYsdT,'r');
hold on;
plot(nT,signaly,'m');
hold on;
plot(nT,signalyo,'y');

