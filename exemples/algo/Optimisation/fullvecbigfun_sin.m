function [d,J] = fullvecbigfun_sin( theta, tdata , xdata, stdx, ydata, stdy, ...
                     a0,stda0 ,b0,stdb0 ,wx0 ,stdwx0,wy0,stdwy0,phi,stdphi,...
                     indx, indy)

N = max(size(tdata));
tailleX = max(size(indx));
tailleY = max(size(indy));
                 
%   theta = a, b, wx ,wy ,phix,phiy
a = theta(1:tailleX);
b = theta(tailleX+1:tailleX+tailleY);
wx = theta(tailleX+tailleY+1:2*tailleX+tailleY);
wy = theta(2*tailleX+tailleY+1:2*tailleX+2*tailleY);
phix = theta(2*tailleX+2*tailleY+1:3*tailleX+2*tailleY);
phiy = theta(3*tailleX+2*tailleY+1:3*tailleX+3*tailleY);

%activation/desacitivation des valeur a priori
is_a =0;
is_b = 0;
is_wx = 0;
is_wy = 0;
is_phi = 0;
is_weq = 0;


resx = zeros(N,1);
dresx = zeros(N,3*tailleX+3*tailleY);
resy = zeros(N,1);
dresy = zeros(N,3*tailleX+3*tailleY);

restx = zeros(3*(tailleX-1),1);
drestx = zeros(3*(tailleX-1),3*tailleX+3*tailleY);



for i=1:tailleX-1
    indsx = indx(i):indx(i+1);
    resx(indsx) = (xdata(indsx)-a(i)*sin(wx(i)*tdata(indsx)+phix(i)))/sqrt(stdx);
    restx((i-1)*(tailleX-1)+2) = is_wx*(wx(i)-wx0)/stdwx0;
    I = [i,tailleX+tailleY+i,2*tailleX+2*tailleY+i];
    dresx(indsx,I) = [-sin(wx(i)*tdata(indsx)+phix(i))/sqrt(stdx)   -(tdata(indsx)*a(i)).*cos(wx(i)*tdata(indsx)+phix(i))/sqrt(stdx)  -a(i)*cos(wx(i)*tdata(indsx)+phix(i))/sqrt(stdx)];
    drestx((i-1)*(tailleX-1)+2,I) = [ 0 is_wx 0];
end

for i=1:tailleY-1
    indsy = indy(i):indy(i+1);
    resy(indsy) = (ydata(indsy)-b(i)*sin(wy(i)*tdata(indsy)+phiy(i)))/sqrt(stdy);
    I = [tailleX+i,2*tailleX+tailleY+i,3*tailleX+2*tailleY+i];
    dresy(indsy,I) = [-sin(wy(i)*tdata(indsy)+phiy(i))/sqrt(stdy)   -(tdata(indsy)*b(i)).*cos(wy(i)*tdata(indsy)+phiy(i))/sqrt(stdy)   -b(i)*cos(wy(i)*tdata(indsy)+phiy(i))/sqrt(stdy)];
end


%calcul de la valeur de lafonction

 d = [ resx ; resy ; restx ];

%calcul du Jacobien







rest = [is_a/sqrt(stda0) 0 0 0 0 0;
        0 is_b/sqrt(stdb0) 0 0 0 0;
        0 0 is_wx/sqrt(stdwx0) 0 0 0;
        0 0 0 is_wy/sqrt(stdwy0) 0 0;
        0 0 0 0 -is_phi/sqrt(stdphi) is_phi/sqrt(stdphi);
        0 0 is_weq -is_weq 0 0];
       

    
    
J = [dresx;dresy;drestx];









end

