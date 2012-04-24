
%clear all;
close all;

%figure(1)

%loading trace
[T,X,Y,R] = readTR('../traces/marseille/marseille.tr');





% %derives
% 
% dT = diff(T);
% dX = diff(X);
% dY = diff(Y);
% 
% 
% 
% dXsdT = dX./dT;
% dYsdT = dY./dT;
% 
% 
% %new T
% aT = T(1:end-1)+T(2:end);
% nT = aT/2;
% 
% % points where dY/dT crosses zero
% [ind0xs,t0xs,x0s] = crossing(filtfilt(ones(1,6)/6,1,dXsdT),nT);
% [ind0ys,t0ys,y0s] = crossing(filtfilt(ones(1,6)/6,1,dYsdT),nT);
% 
% 
% diffzx = diff(t0xs);
% diffzy = diff(t0ys);
% 
% px = mean(diffzx);
% py = mean(diffzy);
% 
% nzx = max(size(x0s));
% ndtzx = t0xs(1) + px* ((1:nzx)-1); 
% 
% nzy = max(size(y0s));
% ndtzy = t0ys(1) + py* ((1:nzy)-1); 




% figure(1)
% plot(nT,dXsdT,'b');
% hold on;
% plot(t0xs,x0s,'g*');
% hold on;
% plot(ndtzx,x0s,'black+');
% 
% 
% 
% figure(2)
% plot(nT,dYsdT,'r');
% hold on;
% plot(t0ys,y0s,'g*');
% hold on;
% plot(ndtzy,y0s,'black+');



[xmax,ixmax,xmin,ixmin] = extrema(X(logical(R)));
[ymax,iymax,ymin,iymin] = extrema(Y(logical(R)));

[nxmax,nixmax,nxmin,nixmin] = extrema(X(logical(~R)));
[nymax,niymax,nymin,niymin] = extrema(Y(logical(~R)));

[ixmax,nx] = sort(ixmax);
xmax = xmax(nx);

[iymax,ny] = sort(iymax);
ymax = ymax(ny);

[nixmax,nnx] = sort(nixmax);
nxmax = nxmax(nnx);

[niymax,nny] = sort(niymax);
nymax = nymax(nny);

%a modifier pour adapter a tous les machins
xmax = xmax(2:end-1);
ixmax = ixmax(2:end-1);
ymax = ymax(2:end-1);
iymax = iymax(2:end-1);


diffzx = diff(T(ixmax));
diffzy = diff(T(iymax));

px = mean(diffzx);
py = mean(diffzy);

nzx = floor((T(end)-T(1))/px);
ndtzx = T(ixmax(1)) + px* ((1:nzx)-3); 

nzy =   floor((T(end)-T(1))/py);
ndtzy = T(iymax(1)) + py* ((1:nzy)-3); 

% indx = interp1(ndtzx,T,'linear');
% indy = interp1(ndtzy,T,'linear');

 
indx = interp1(T,1:numel(T),ndtzx,'nearest');
indy = interp1(T,1:numel(T),ndtzy,'nearest');


fx = isfinite(indx);
fy = isfinite(indy);

indx = indx(fx);
indy = indy(fy);
ndtzx = ndtzx(fx);
ndtzy = ndtzy(fy);


figure(1)
plot(T,X,'b');
hold on;
plot(T(ixmax),xmax,'g*');
hold on;
plot(T(nnz(R)+nixmax(2:end-1)),nxmax(2:end-1),'c*');
hold on;
plot(ndtzx,X(indx),'black+');

figure(2)
plot(T,Y,'r');
hold on;
plot(T(iymax),ymax,'g*');
hold on;
plot(T(nnz(R)+niymax(2:end-1)),nymax(2:end-1),'c*');
hold on;
plot(ndtzy,Y(indy),'black+');







