clear all;
close all;

[inds,X,Y] = readTR_sep('../traces/marseille/marseille.tr');

L = max(size(Y))-1; 

dY = diff(Y);
dX = diff(X);
dX = diff(X)-mean(dX);



X = filtfilt(ones(1,6)/6,1,dX);
Y = filtfilt(ones(1,6)/6,1,dY);


Fs = 100;                    % Sampling frequency
T = 1/Fs;                     % Sample time
L = max(size(Y))-1;                     % Length of signal
t = (0:L-1)*T;                % Time vector





NFFT = 2^nextpow2(L); % Next power of 2 from length of y
fY = fft(Y,NFFT)/L;
fX = fft(X,NFFT)/L;
f = Fs/2*linspace(0,1,NFFT/2+1);

% Plot single-sided amplitude spectrum.
plot(f,2*abs(fX(1:NFFT/2+1)),'b') 
hold on
plot(f,2*abs(fY(1:NFFT/2+1)),'r') 
title('Single-Sided Amplitude Spectrum of y(t)')
xlabel('Frequency (Hz)')
ylabel('|Y(f)|')