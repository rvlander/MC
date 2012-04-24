%clear all;
close all;

%loading trace
[inds,lT,lX,lY] = readTR_sep('trace_');


N = numel(inds);

errd = zeros(N-1,1);
erro = zeros(N-1,1);

timerd = 0;
timero = 0;




ang = pi/4;


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

% X = cX;
% Y = cY;

if numel(T) > 18

[nT,dXsdT,dYsdT,ind0xs,t0xs,x0s,ind0ys,t0ys,y0s,c] = init(T,X,Y);


t=cputime;
[a,b,wx,wy,phix,phiy] = direct_method(dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys);
timerd = timerd + cputime-t;
t=cputime;
[ao,bo,wxo,wyo,phixo,phiyo] = lsqnonlin_method_sin(nT,dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys,tosave,5);
timero = timero + cputime-t;

sampling = t0ys(1):20:t0ys(end);

[nX,nY,signalx,signaly] = resample_hw_sin(sampling,t0xs,t0ys,a,b,wx,wy,phix,phiy,c,X(1),Y(1));
[nXo,nYo,signalxo,signalyo] = resample_hw_sin(sampling,t0xs,t0ys,ao,bo,wxo,wyo,phixo,phiyo,c,X(1),Y(1));

sdXsdT = interp1(nT,dXsdT,sampling)';
sdYsdT = interp1(nT,dYsdT,sampling)';


errd(i) = norm([signalx signaly]-[sdXsdT sdYsdT])/norm([sdXsdT sdYsdT]);
erro(i) = norm([signalxo signalyo]-[sdXsdT sdYsdT])/norm([sdXsdT sdYsdT]);


end 

end

% figure
% plot(nT,dXsdT);
% hold on;
% plot(sampling,signalx,'c');
% hold on;
% plot(sampling,signalxo,'g');
% 
% figure
% plot(nT,dYsdT,'r');
% hold on;
% plot(sampling,signaly,'m');
% hold on;
% plot(sampling,signalyo,'y');

