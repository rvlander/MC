%clear all;
close all;

%loading trace
%[inds,T,X,Y] = readTR_sep('../traces/marseille/marseille.tr');
[inds,T,X,Y] = readTR_sep('trace_');



[nT,dXsdT,dYsdT,ind0xs,t0xs,x0s,ind0ys,t0ys,y0s,c] = init(T,X,Y);
sampling = t0ys(1):10:t0ys(end);

sdXsdT = interp1(nT,dXsdT,sampling)';
sdYsdT = interp1(nT,dYsdT,sampling)';

tosave = etude_stat(X,Y);


nb_iter = 1000;

erru = zeros(nb_iter,1);
errs = zeros(nb_iter,1);


for i=1:nb_iter

[au,bu,wxu,wyu,phixu,phiyu] = lsqnonlin_method_1run(nT,dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys,tosave,0);
[as,bs,wxs,wys,phixs,phiys] = lsqnonlin_method_1run(nT,dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys,tosave,1);

[nXu,nYu,signalxu,signalyu] = resample_hw_sin(sampling,t0xs,t0ys,au,bu,wxu,wyu,phixu,phiyu,c,X(1),Y(1));
[nXs,nYs,signalxs,signalys] = resample_hw_sin(sampling,t0xs,t0ys,as,bs,wxs,wys,phixs,phiys,c,X(1),Y(1));

erru(i) = norm([signalxu signalyu]-[sdXsdT sdYsdT])/norm([sdXsdT sdYsdT]);
errs(i) = norm([signalxs signalys]-[sdXsdT sdYsdT])/norm([sdXsdT sdYsdT]);

end

Bins = 0.05:0.05:1.5

[Au] = hist(erru,Bins);
[As] = hist(errs,Bins);

bar(Bins,Au);
figure;
bar(Bins,As);


