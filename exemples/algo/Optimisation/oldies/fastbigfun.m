function d = fastbigfun( theta, tdata , xdata, stdx, ydata, stdy, ...
                     a0,stda0 ,b0,stdb0 ,wx0 ,stdwx0,wy0,stdwy0,phi,stdphi)
%   theta = a, b, wx ,wy ,phix,phiy
a = theta(1);
b = theta(2);
wx = theta(3);
wy = theta(4);
phix = theta(5);
phiy = theta(6);

%activation/desacitivation des valeur a priori
is_a =1;
is_b = 1;
is_wx = 1;
is_wy = 1;
is_phi = 1;


%calcul de la valeur de lafonction
resx = (xdata-a*cos(wx*tdata+phix)).^2;
resy = (ydata-b*cos(wy*tdata+phiy)).^2;

d = sum(resx)/stdx + sum(resy)/stdy + is_a*(a-a0)^2/stda0 + is_b*(b-b0)^2/stdb0 + ...
    is_wx*(wx-wx0)^2/stdwx0 + is_wy*(wy-wy0)^2/stdwy0 + is_phi*(phiy-phix-phi)^2/stdphi;

end

