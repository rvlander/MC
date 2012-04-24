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

thetamint = zeros(100,6);
val = zeros(100,1);


options = optimset('GradObj','on','DerivativeCheck','off');



f = @(theta)fastbigfun( theta, tdata' , xdata, stdx, ydata, stdy, ...
                      a0,stda0 ,b0,stdb0 ,wx0 ,stdwx0,wy0,stdwy0,phi,stdphi);



ra0 = a0 + randn(100,1)*stda0;
rb0 = b0 + randn(100,1)*stdb0;
rwx0 = wx0 + randn(100,1)*stdwx0;
rwy0 = wy0 + randn(100,1)*stdwy0;
rphix = rand(100,1)*2*pi;
rphiy = rand(100,1)*2*pi;
%                   
% ra0 = -10 + rand(100,1)*20;
% rb0 = -10 + rand(100,1)*20;
% rwx0 = rand(100,1)*0.1;
% rwy0 = rand(100,1)*0.1;
% rphix = rand(100,1)*2*pi-pi;
% rphiy = rand(100,1)*2*pi-pi;

minthetav = zeros(7,1);
minthetav(7) = 10000000000000000000000;
thetav = zeros(7,1);

i =0;
for a=-10:0.2:10
    j=0;
    for b=-10:0.2:10
        k=0;
        for wx=0:0.001:0.1
            for wy=0:0.001:0.1
                for phix=-pi:2*pi/100:pi
                    for phiy=-pi:2*pi/100:pi
                        thetav(1) = a;
                        thetav(2) = b;
                        thetav(3) = wx;
                        thetav(4) = wy;
                        thetav(5) = phix;
                        thetav(6) = phiy;

                        thetav(7) = f(thetav(1:6));
                        
                        if thetav(7)<minthetav(7)
                            minthetav = thetav;
                        end
                        
                    end
                end
            end
            k=k+1;
            k
        end
        j=j+1;
        j
    end
    i = i+1;
    i
end


thetamin = minthetav(1:6);

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

