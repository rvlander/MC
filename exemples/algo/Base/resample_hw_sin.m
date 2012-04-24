function [nX,nY,signalx,signaly,tanB,psi] = resample_hw_sin(sampling,t0xs,t0ys,a,b,wx,wy,phix,phiy,c,X0,Y0)


%sampling


nb_points = numel(sampling);

%signal interpolé
signaly = zeros(nb_points,1);
signalx = zeros(nb_points,1);

tanB = zeros(nb_points,1);
psi = zeros(nb_points,1);

ky=1;
kx=1;
i=1;
for t=sampling
    if (t>t0ys(ky+1)&& ky< numel(b))
        ky = ky+1;
    end
    if (t>t0xs(kx+1)&& kx< numel(a))
         kx = kx+1;
     end
    signaly(i) = b(ky)*sin(wy(ky)*t+phiy(ky));
    signalx(i) = a(kx)*sin(wx(kx)*t+phix(kx));
    phi = phix(kx)-phiy(ky);
    tanB(i) = b(ky)/(a(kx)*phi);
    psi(i) = -a(kx)*sin(phi);
%     sphiy(i) = sphiy(k); 
    i=i+1;
end

%signal interpolé


% k=1;
% i=1;
% for t=sampling
%     if (t>t0xs(kx+1)&& kx< numel(a))
%         kx = kx+1;
%     end
%  
%     signalx(i) = a(kx)*sin(wx(kx)*t+phix(kx));
%     sphix(i) = phix(k);
%     i=i+1;
% end

%hold on;
%plot(sampling,signalx,'c');

nX = zeros(nb_points,1);
nY = zeros(nb_points,1);

nX(1) = X0;
nY(1) = Y0;


%constructions
for i=2:nb_points
%     nX(i) = (signalx(i-1)+c)*20 + nX(i-1);
%     nY(i) = signaly(i-1)*20 + nY(i-1);
    samp = sampling(1:i);
    sigx = signalx(1:i);
    sigy = signaly(1:i);
    timestep = (sampling(i)-sampling(i-1));
    nx = trapz(sigx+c)*timestep+nX(1);
    ny = trapz(sigy)*timestep+nY(1);
    nX(i) = nx;
    nY(i) = ny;
end

