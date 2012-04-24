%clear all;
close all;

%figure(1)

%loading trace
res = mfcsvread('traces/test.csv');

%renaming
X = res.X;
Xfilt = filtfilt(ones(1,6)/6,1,X)
Y = res.Y;
Yfilt = filtfilt(ones(1,6)/6,1,Y)
T = res.T;


[maxx,ix] = findpeaks(Xfilt);
[maxy,iy] = findpeaks(Yfilt);

nY = Y-mean(Y);
nY = nY/max(abs(nY));
fy = acos(nY)./T;


plot(T(1:end-1),diff(Xfilt),'r');
hold on;
%plot(T,Y,'b');
%plot(T,Xfilt);
hold on;
%plot(T(ix),X(ix),'og');
%plot(T(iy),Y(iy),'og');

figure(2);
plot(T,fy);

pX = diff(T(ix));
