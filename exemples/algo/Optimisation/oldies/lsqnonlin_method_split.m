function [a,b,wx,wy,phix,phiy] = lsqnonlin_method_split(nT,dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys,tosave,numrun)




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



tailleX = max(size(ind0xs));
tailleY = max(size(ind0ys));

             
thetamint = zeros(numrun,3);
val = zeros(numrun,1);

options = optimset('Jacobian','on','DerivativeCheck','off','ScaleProblem','Jacobian');
%options = optimset('MaxFunEvals',1000,'maxIter',1000,'Jacobian','on','DerivativeCheck','off','ScaleProblem','Jacobian');
LB = [-10 -10 0 0 -pi -pi];
UB = [10 10 0.1 0.1 pi pi];


nb_arcsx = max(size(t0xs))-1;
a = zeros(nb_arcsx,1);
wx = zeros(nb_arcsx,1);
phix = zeros(nb_arcsx,1);

for i=1:nb_arcsx

for j=1:numrun
    
    ra0 = a0 + randn(1,1)*stda0;
rwx0 = wx0 + randn(1,1)*stdwx0;

rphix = rand(1,1)*2*pi;


% ra0 = -10 + rand(tailleX,1)*20;
% rb0 = -10 + rand(tailleY,1)*20;
% rwx0 = rand(tailleX,1)*0.1;
% rwy0 = rand(tailleY,1)*0.1;
% rphix = -pi+rand(tailleX,1)*2*pi;
% rphiy = -pi+rand(tailleY,1)*2*pi;
    inds = ind0xs(i):ind0xs(i+1);
    f = @(theta)simplefun( theta, nT(inds) , dXsdT(inds));
    [thetamint(j,:),val(j)] = lsqnonlin(f, [ra0; ... 
        rwx0;rphix],LB,UB,options);
end
[vmin , imin] = min(val);
theta = thetamint(imin,:);

a(i) = theta(1);
wx(i) = theta(2);
phix(i) = theta(3);

end



nb_arcsy = max(size(t0ys))-1;
b = zeros(nb_arcsx,1);
wy = zeros(nb_arcsx,1);
phiy = zeros(nb_arcsx,1);

for i=1:nb_arcsy

for j=1:numrun
    
   
rb0 = b0 + randn(1,1)*stdb0;
rwy0 = wy0 + randn(1,1)*stdwy0;
rphiy = rand(1,1)*2*pi;

% ra0 = -10 + rand(tailleX,1)*20;
% rb0 = -10 + rand(tailleY,1)*20;
% rwx0 = rand(tailleX,1)*0.1;
% rwy0 = rand(tailleY,1)*0.1;
% rphix = -pi+rand(tailleX,1)*2*pi;
% rphiy = -pi+rand(tailleY,1)*2*pi;
    inds = ind0ys(i):ind0ys(i+1);
    f = @(theta)simplefun( theta, nT(inds) , dYsdT(inds));
    [thetamint(j,:),val(j)] = lsqnonlin(f, [rb0; ... 
        rwy0;rphiy],LB,UB,options);
end
[vmin , imin] = min(val);
theta = thetamint(imin,:);

b(i) = theta(1);
wy(i) = theta(2);
phiy(i) = theta(3);

end


end












