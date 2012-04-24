function [nX,nY,signalx,signaly] = resample_hw_triangle(sampling,t0xs,t0ys,dxu,dxd,dyu,dyd,c,X0,Y0)


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
    if (t>t0ys(ky+1)&& ky< size(dyu,1))
        ky = ky+1;
    end
    if (t>t0xs(kx+1)&& kx< size((dxu),1))
         kx = kx+1;
    end
     
%     j = ind0ys(i)+floor((ind0ys(i+1)-ind0ys(i))/2);
%     
     if(abs(t-t0ys(ky))<abs(t-t0ys(ky+1)))
        signaly(i) = dyu(ky,1)*(t-t0ys(ky));
     else
         signaly(i) = dyd(ky,1)*(t-t0ys(ky+1));
     end
     
     if(abs(t-t0xs(kx))<abs(t-t0xs(kx+1)))
         signalx(i) = dxu(kx,1)*(t-t0xs(kx));
     else
         signalx(i) = dxd(kx,1)*(t-t0xs(kx+1));
     end


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

