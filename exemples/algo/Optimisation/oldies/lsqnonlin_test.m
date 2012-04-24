close all;

% xdata = diffX/0.01;
% figure
% plot(xdata)
% //load tosave;
% xdata = diffX/0.01;
% figure
% plot(xdata)


stdx =2;
stdy =2;
a0 = tosave(1);
stda0 = tosave(2);
b0 = tosave(3);
stdb0 = tosave(4); 
wx0  = tosave(5);
stdwx0 = tosave(6);
wy0 = tosave(7);
stdwy0 = tosave(8);
phi = tosave(9);
stdphi = tosave(10); 

xdata = diffX/10;
figure
plot(xdata)
ydata = diffY/10;

tdata = 0:(max(size(xdata))-1);
tdata = tdata*10;

f = @(theta)vecbigfun( theta, tdata' , xdata, stdx, ydata, stdy, ...
                      a0,stda0 ,b0,stdb0 ,wx0 ,stdwx0,wy0,stdwy0,phi,stdphi);

thetamint = zeros(20,6);
val = zeros(20,1);
ra0 = a0 + randn(100,1)*stda0;
rb0 = b0 + randn(100,1)*stdb0;
rwx0 = wx0 + randn(100,1)*stdwx0;
rwy0 = wy0 + randn(100,1)*stdwy0;
rphix = rand(100,1)*2*pi;
rphiy = rand(100,1)*2*pi;

options = optimset('MaxFunEvals',10000,'maxIter',10000,'Jacobian','on','DerivativeCheck','off','ScaleProblem','Jacobian');
LB = [-10 -10 0 0 -pi -pi];
UB = [10 10 0.1 0.1 pi pi];


ra0 = a0 + randn(100,1)*stda0;
rb0 = b0 + randn(100,1)*stdb0;
rwx0 = wx0 + randn(100,1)*stdwx0;
rwy0 = wy0 + randn(100,1)*stdwy0;
rphix = rand(100,1)*2*pi;
rphiy = rand(100,1)*2*pi;


for i=1:20

    [thetamint(i,:),val(i)] = lsqnonlin(f, [ra0(i), ... 
        rb0(i),rwx0(i),rwy0(i),rphix(i),rphiy(i)],LB,UB,options);
end
[vmin , imin] = min(val);
thetamin = thetamint(imin,:)

synthx = thetamin(1)*cos(thetamin(3)*tdata+thetamin(5));
synthy = thetamin(2)*cos(thetamin(4)*tdata+thetamin(6));

figure
plot(xdata,'b');
hold on;
plot(synthx, 'g');

figure
plot(ydata,'r');
hold on;
plot(synthy, 'y');

sxoff = X(1) - thetamin(1)/thetamin(3)*sin(thetamin(5));
syoff = Y(1) - thetamin(2)/thetamin(4)*sin(thetamin(6));
sX= sxoff + c*tdata + thetamin(1)/thetamin(3)*sin(thetamin(3)*tdata+thetamin(5));
sY= syoff + thetamin(2)/thetamin(4)*sin(thetamin(4)*tdata+thetamin(6));

figure
plot(X,-Y,'r');
hold on;
plot(sX,-sY,'b');
