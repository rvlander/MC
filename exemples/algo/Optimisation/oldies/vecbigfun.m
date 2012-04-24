function [d,J] = vecbigfun( theta, tdata , xdata, stdx, ydata, stdy, ...
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
is_weq = 0;


%calcul de la valeur de lafonction
resx = (xdata-a*cos(wx*tdata+phix))/sqrt(stdx);
resy = (ydata-b*cos(wy*tdata+phiy))/sqrt(stdy);

 d = [ resx ; resy ; is_a*(a-a0)/sqrt(stda0) ; is_b*(b-b0)/sqrt(stdb0) ; ...
     is_wx*(wx-wx0)/sqrt(stdwx0) ; is_wy*(wy-wy0)/sqrt(stdwy0) ...
     ; is_phi*(phiy-phix-phi)/sqrt(stdphi);is_weq*(wx-wy)];

%calcul du Jacobien

F = zeros(max(size(resx)),1);


dresx = [-cos(wx*tdata+phix)/sqrt(stdx) F  (tdata*a).*sin(wx*tdata+phix)/sqrt(stdx) F a*sin(wx*tdata+phix)/sqrt(stdx) F];
dresy = [F -cos(wy*tdata+phiy)/sqrt(stdy) F (tdata*b).*sin(wy*tdata+phiy)/sqrt(stdy) F b*sin(wy*tdata+phiy)/sqrt(stdy)];

rest = [is_a/sqrt(stda0) 0 0 0 0 0;
        0 is_b/sqrt(stdb0) 0 0 0 0;
        0 0 is_wx/sqrt(stdwx0) 0 0 0;
        0 0 0 is_wy/sqrt(stdwy0) 0 0;
        0 0 0 0 -is_phi/sqrt(stdphi) is_phi/sqrt(stdphi);
        0 0 is_weq -is_weq 0 0];
       

    
    
J = [dresx;dresy ; rest];









end

