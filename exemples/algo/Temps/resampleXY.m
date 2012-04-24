function [cX,cY] = resampleXY(X,Y,delta)

cX = [X(1)];
cY = [Y(1)];

i=2;

j=0;
%Maxit = 100;

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
    end
end


end

