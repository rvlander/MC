%clear all; 
close all;

[X,Y] = readTR('../traces/marseille/marseille.tr');



% X = filtfilt(ones(1,6)/6,1,X);
% Y = filtfilt(ones(1,6)/6,1,Y);


vX = diff(X)/10;
vX = diffX-mean(diffX);

vY = diff(Y)/10;
%diffY = diffY-mean(diffY);

vX = filtfilt(ones(1,6)/6,1,vX);
vY = filtfilt(ones(1,6)/6,1,vY);

aX = diff(vX)/10;
aY = diff(vY)/10;

plot((Y- mean(Y))/100);
hold on
plot(vY,'g');
hold on
plot(aY*100,'r');


