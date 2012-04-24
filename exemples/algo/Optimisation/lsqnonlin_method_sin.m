function [a,b,wx,wy,phix,phiy] = lsqnonlin_method_sin(nT,dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys,tosave,numrun)




% calculs des parametres
nb_arcsx = size(t0xs,2)-1;
nb_arcsy = size(t0ys,2)-1;

stdx =1;
stdy =1;
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

f = @(theta)fullvecbigfun_sin( theta, nT , dXsdT, stdx, dYsdT, stdy, ...
                      a0,stda0 ,b0,stdb0 ,wx0 ,stdwx0,wy0,stdwy0,phi,stdphi,...
                  ind0xs,ind0ys);

tailleX = max(size(ind0xs));
tailleY = max(size(ind0ys));

tailleTheta = 3*tailleX + 3*tailleY;
             
thetamint = zeros(numrun,tailleTheta);
val = zeros(numrun,1);


options = optimset('MaxFunEvals',10000,'maxIter',10000,'Jacobian','on','DerivativeCheck','off','ScaleProblem','Jacobian');
%options = optimset('Jacobian','on','DerivativeCheck','off','ScaleProblem','Jacobian');

LB = [-10 -10 0 0 -pi -pi];
UB = [10 10 0.1 0.1 pi pi];


% ra0 = a0 + randn(numrun,1)*stda0;
% rb0 = b0 + randn(numrun,1)*stdb0;
% rwx0 = wx0 + randn(numrun,1)*stdwx0;
% rwy0 = wy0 + randn(numrun,1)*stdwy0;
% rphix = rand(100,1)*2*pi;
% rphiy = rand(100,1)*2*pi;


for i=1:numrun
    
ra0 = a0 + randn(tailleX,1)*stda0;
rb0 = b0 + randn(tailleY,1)*stdb0;
rwx0 = wx0 + randn(tailleX,1)*stdwx0;
rwy0 = wy0 + randn(tailleY,1)*stdwy0;
rphix = rand(tailleX,1)*2*pi;
rphiy = rand(tailleY,1)*2*pi;

% ra0 = -10 + rand(tailleX,1)*20;
% rb0 = -10 + rand(tailleY,1)*20;
% rwx0 = rand(tailleX,1)*0.1;
% rwy0 = rand(tailleY,1)*0.1;
% rphix = -pi+rand(tailleX,1)*2*pi;
% rphiy = -pi+rand(tailleY,1)*2*pi;


    [thetamint(i,:),val(i)] = lsqnonlin(f, [ra0; ... 
        rb0;rwx0;rwy0;rphix;rphiy],[],[],options);
end
[vmin , imin] = min(val);
theta = thetamint(imin,:);





tailleX = max(size(ind0xs));
tailleY = max(size(ind0ys));
                 
%   theta = a, b, wx ,wy ,phix,phiy
a = theta(1:tailleX);
b = theta(tailleX+1:tailleX+tailleY);
wx = theta(tailleX+tailleY+1:2*tailleX+tailleY);
wy = theta(2*tailleX+tailleY+1:2*tailleX+2*tailleY);
phix = theta(2*tailleX+2*tailleY+1:3*tailleX+2*tailleY);
phiy = theta(3*tailleX+2*tailleY+1:3*tailleX+3*tailleY);

end












