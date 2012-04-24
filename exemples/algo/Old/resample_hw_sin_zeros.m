function [nX,nY,signalx,signaly] = resample_hw_sin_zeros(sampling,t0xs,t0ys,a,b,wx,wy,phix,phiy,c,X0,Y0)


%sampling


nb_points = numel(sampling);
sphiy = zeros(nb_points,1);

%signal interpolé
signaly = zeros(nb_points,1);
k=1;
i=1;
pass =0;
ipass =5;
tpass = 3;
for t=sampling
    if (pass&& k< numel(b))
        k = k+1;
    end
    signaly(i) = b(k)*sin(wy(k)*t+phiy(k));
    sphiy(i) = sphiy(k);
    if(i>1)
        if(signaly(i-1)*signaly(i)<=0 && ipass >= tpass)
            pass = 1;
            ipass=1;
        else
            pass =0;
            ipass = ipass+1;
        end
    end
    i=i+1;
end

%signal interpolé
signalx = zeros(nb_points,1);
sphix = zeros(nb_points,1);
k=1;
i=1;
pass =0;
ipass =5;
tpass = 3;
for t=sampling
    if (pass && k< numel(a))
        k = k+1;
    end
 
    signalx(i) = a(k)*sin(wx(k)*t+phix(k));
    sphix(i) = phix(k);
    
    if(i>1)
        if(signalx(i-1)*signalx(i)<=0 && ipass >= tpass)
            pass = 1;
            ipass=1;
        else
            pass =0;
            ipass = ipass+1;
        end
    end
    i=i+1;
end

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

