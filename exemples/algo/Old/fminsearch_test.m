%close all;

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

thetamint = zeros(500,6);
val = zeros(500,1);


options = optimset('MaxFunEvals',1000000,'maxIter',1000000);



f = @(theta)bigfun( theta, tdata' , xdata, stdx, ydata, stdy, ...
                      a0,stda0 ,b0,stdb0 ,wx0 ,stdwx0,wy0,stdwy0,phi,stdphi);



                      ra0 = a0 + randn(500,1)*stda0;
rb0 = b0 + randn(500,1)*stdb0;
rwx0 = wx0 + randn(500,1)*stdwx0;
rwy0 = wy0 + randn(500,1)*stdwy0;
rphix = rand(500,1)*2*pi;
rphiy = rand(500,1)*2*pi;
                  
for i=1:500   

    [thetamint(i,:),val(i)] = fminsearch(f, [ra0(i), ... 
        rb0(i),rwx0(i),rwy0(i),rphix(i),rphiy(i)]);
end

[vmin , imin] = min(val);
thetamin = thetamint(imin,:)

synthx = thetamin(1)*cos(thetamin(3)*tdata+thetamin(5));

figure
plot(xdata,'b');
hold on;
plot(synthx, 'r');
