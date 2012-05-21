%B = filtfilt([4 5 6 85 21 6 97 4]);
%B = eye([15 10]);

data = [1:0.2:4]';
windowSize = 5;
C=filter(ones(1,windowSize)./windowSize,1,data)

