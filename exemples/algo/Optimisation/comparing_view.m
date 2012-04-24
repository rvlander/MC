%clear all;
close all;

%loading trace
%[inds,T,X,Y] = readTR_sep('../traces/marseille/marseille.tr');
[inds,T,X,Y] = readTR_sep('trace_');

% i=100;
% 
% X = lX(inds(i):inds(i+1)-1);
% Y = lY(inds(i):inds(i+1)-1);
% 
% T = 0:(numel(X)-1);
% T = T'*10;

%   X = filtfilt(ones(1,6)/6,1,X);
%   Y = filtfilt(ones(1,6)/6,1,Y);

[nT,dXsdT,dYsdT,ind0xs,t0xs,x0s,ind0ys,t0ys,y0s,c] = init(T,X,Y);

tosave = etude_stat(X,Y);

[a,b,wx,wy,phix,phiy] = direct_method(dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys);

%  tosave = zeros(10,1);
%   tosave(1) = mean(a);
%   tosave(2) = std(a);
%   tosave(3) = mean(b);
%   tosave(4) = std(b); 
% tosave(5) = mean(wx);
% tosave(6) = std(wx);
% tosave(7)= mean(wy);
% tosave(8) = std(wy);
% tosave(9) =0;
% tosave(10)=0; 


[ao,bo,wxo,wyo,phixo,phiyo] = lsqnonlin_method_sin(nT,dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys,tosave,5);


sampling = t0ys(1):10:t0ys(end);

[nX,nY,signalx,signaly] = resample_hw_sin(sampling,t0xs,t0ys,a,b,wx,wy,phix,phiy,c,X(1),Y(1));
[nXo,nYo,signalxo,signalyo] = resample_hw_sin(sampling,t0xs,t0ys,ao,bo,wxo,wyo,phixo,phiyo,c,X(1),Y(1));

sdXsdT = interp1(nT,dXsdT,sampling)';
sdYsdT = interp1(nT,dYsdT,sampling)';

errd = norm([signalx signaly]-[sdXsdT sdYsdT])/norm([sdXsdT sdYsdT])
erro = norm([signalxo signalyo]-[sdXsdT sdYsdT])/norm([sdXsdT sdYsdT])


figure
plot(nT,dXsdT,'b');
hold on;
plot(sampling,signalx,'c');
hold on;
plot(sampling,signalxo,'g');

figure
plot(nT,dYsdT,'r');
hold on;
plot(sampling,signaly,'m');
hold on;
plot(sampling,signalyo,'g');

figure
plot(X,Y)
hold on
plot(nXo,nYo,'g');
hold on
plot(nX,nY,'r');

