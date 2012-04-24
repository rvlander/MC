function [d,gradd] = bigfun( theta, tdata , xdata, stdx, ydata, stdy, ...
                     a0,stda0 ,b0,stdb0 ,wx0 ,stdwx0,wy0,stdwy0,phi,stdphi)
%   theta = a, b, wx ,wy ,phix,phiy
a = theta(1);
b = theta(2);
wx = theta(3);
wy = theta(4);
phix = theta(5);
phiy = theta(6);

%activation/desacitivation des valeur a priori
is_a =0;
is_b = 0;
is_wx = 0;
is_wy = 0;
is_phi = 0;


%calcul de la valeur de lafonction
resx = (xdata-a*cos(wx*tdata+phix)).^2/stdx;
resy = (ydata-b*cos(wy*tdata+phiy)).^2/stdy;

d = sum(resx) + sum(resy) + is_a*(a-a0)^2/stda0 + is_b*(b-b0)^2/stdb0 + ...
    is_wx*(wx-wx0)^2/stdwx0 + is_wy*(wy-wy0)^2/stdwy0 + is_phi*(phiy-phix-phi)^2/stdphi;

%calcul du gradient
gradd = zeros(6,1);

%dérivée en a
gradd(1) = 2/stdx*sum((xdata-a*cos(wx*tdata+phix)).*-cos(wx*tdata+phix))+ ...
   is_a*2/stda0*(a-a0);

%dérivée en b
gradd(2) = 2/stdy*sum((ydata-b*cos(wy*tdata+phiy)).*-cos(wy*tdata+phiy))+ ...
   is_b*2/stdb0*(b-b0);

%dérivée en wx
gradd(3) = 2/stdx*sum((xdata-a*cos(wx*tdata+phix)).* ...
    (a*tdata.*sin(wx*tdata + phix))) + is_wx*2/stdwx0*(wx-wx0);

%dérivée en wy
gradd(4) = 2/stdy*sum((ydata-b*cos(wy*tdata+phiy)).* ...
    (b*tdata.*sin(wy*tdata + phiy))) + is_wy*2/stdwy0*(wy-wy0);

%dérivée en phix
gradd(5) = 2/stdx*sum((xdata-a*cos(wx*tdata+phix)).* ...
    (a*sin(wx*tdata+phix)))-is_phi*2/stdphi*(phiy-phix-phi);

%dérivée en phiy
gradd(6) = 2/stdy*sum((ydata-b*cos(wy*tdata+phiy)).* ...
    (b*sin(wy*tdata+phiy)))+is_phi*2/stdphi*(phiy-phix-phi);







end

