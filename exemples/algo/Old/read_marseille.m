clear all; close all;

tx = [];
ty = [];

deltatx = [];
deltaty = [];

phi = [];
freqX = [0];
freqY = [0];
for i=0:45
    filename = strcat('../traces/marseille/',num2str(i),'marseille.csv')
    out = csvread(filename);
    X = out(:,2);
    diffX = diff(X);
    diffX = diffX-mean(diffX);
    Y = out(:,3);
    diffY = diff(Y);
    
    iX = crossing(diff(diffX));
    iY = crossing(diff(diffY));
    
%     figure
%     plot(diffX,'r');
%     hold on;
%     plot(diffY,'b');
    
    deltatx = [deltatx diff(crossing(diffX))];
    deltaty = [deltaty diff(crossing(diffY))];
    
    tx = [tx;diffX(iX)];
    ty = [ty;diffY(iY)];
    phi = [phi ; hilbert_prel(diffX,diffY)];
    freqX = add_vect(freqX,abs(fft(diffX)));
    freqY = add_vect(freqY,abs(fft(diffY)));
end


wx = 0.01*pi./deltatx;
wy = 0.01*pi./deltaty;

phideg = phi*180/pi;
[H,B] = hist(phideg);
bar(B,H);

figure;
plot(freqX,'b');
hold on;
plot(freqY,'r');

figure
[A,G] = hist(abs(tx));
bar(G,A);

figure
[A,G] = hist(abs(ty));
bar(G,A,'r');

figure
[A,G] = hist(wx,100);
bar(G,A,'y');

figure
[A,G] = hist(wy,100);
bar(G,A,'c');

