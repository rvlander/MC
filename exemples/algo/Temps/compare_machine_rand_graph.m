close all;
clear all;



[inds,oT,oX,oY] = readTR_sep('trace_');




for i=1:1000
    
errX=[];
errY=[];

for i=3:40

[cX,cY] = resampleXYrand(oX,oY,3,i);

X =cX;
Y=cY;
T=1:numel(X);
T=T*(oT(end)-oT(1))/numel(X);

[nT,dXsdT,dYsdT,ind0xs,t0xs,x0s,ind0ys,t0ys,y0s,c,fdY] = init(T',X,Y);


[a,b,wx,wy,phix,phiy] = direct_method(dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys);
sampling = t0ys(1):20:t0ys(end);

[nX,nY,signalx,signaly,slant,psi] = resample_hw_sin(sampling,t0xs,t0ys,a,b,wx,wy,phix,phiy,c,X(1),Y(1));

dX = interp1(nT,dXsdT,sampling);
dY = interp1(nT,dYsdT,sampling);

eX = norm(dX'-signalx)/norm(dX);
eY = norm(dY'-signaly)/norm(dY);

errX = [errX; eX];
errY = [errY; eY];

end

hold on
plot(errX);
hold on
plot(errY,'r');

end



