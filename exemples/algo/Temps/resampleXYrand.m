function [cX,cY] = resampleXYrand(X,Y,deltamin,deltamax)

cX = [X(1)];
cY = [Y(1)];

i=2;

j=0;
%Maxit = 100;

delta = deltamin + (deltamax-deltamin)*rand;

while i<=numel(X)
    j=j+1;
    dir =  [X(i) Y(i)]-[cX(end) cY(end)] ;
    lanorme = norm(dir);
    [delta lanorme];
    if delta<lanorme
        newdir = dir./lanorme.*delta;
        cX = [cX; cX(end)+newdir(1)];
        cY = [cY; cY(end)+newdir(2)];
    else
        i = i+1;
        delta = deltamin + (deltamax-deltamin)*rand;
    end
end


end

