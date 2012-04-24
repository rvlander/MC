function [d,J] = simplefun( theta, tdata , xdata)
%   theta = a, b, wx ,wy ,phix,phiy
a = theta(1);
wx = theta(2);
phix = theta(3);


%calcul de la valeur de lafonction
resx = (xdata-a*cos(wx*tdata+phix));
d=[resx;zeros(3,1)];


%calcul du Jacobien
dresx = [-cos(wx*tdata+phix) (tdata*a).*sin(wx*tdata+phix) a*sin(wx*tdata+phix)];
   
    
J = [dresx;zeros(3,3)];
end

