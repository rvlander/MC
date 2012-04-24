%clear all;
close all;

%loading trace
[inds,lT,lX,lY] = readTR_sep('../BaseDeDonnee/gaetan_phrase_2');

N = numel(inds);


ang = pi/4;


for i=1:N

j = i+1;
if(j>N)
    f = numel(lT);
else 
    f = inds(j)-1;
end

    
cX = lX(inds(i):f);
cY = lY(inds(i):f);
T = lT(inds(i):f);


hold on;
plot(cX,cY,'b');

X = cX*cos(ang) + cY*sin(ang);
Y = -cX*sin(ang) + cY*cos(ang);

X = cX;
Y = cY;

if	numel(T) > 5


[nT,dXsdT,dYsdT,ind0xs,t0xs,x0s,ind0ys,t0ys,y0s,c,fdY] = init(T,X,Y);


[a,b,wx,wy,phix,phiy] = direct_method(dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys);
sampling = t0ys(1):20:t0ys(end);

[nX,nY,signalx,signaly] = resample_hw_sin(sampling,t0xs,t0ys,a,b,wx,wy,phix,phiy,c,X(1),Y(1));



% figure
% plot(nT,dYsdT,'b');
% hold on;
% plot(sampling,signaly,'c');
% hold on;
% plot(nT,fdY,'r');
% hold on;
% plot(t0ys,y0s,'g*');


cnX = nX*cos(ang) - nY*sin(ang);
cnY = nX*sin(ang) + nY*cos(ang);

cnX = nX;
cnY = nY;


hold on;
plot(cnX,cnY,'r');

end


end





