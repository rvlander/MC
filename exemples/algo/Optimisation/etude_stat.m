function tosave = etude_stat(X,Y)

diffX = diff(X);
diffX = diffX-mean(diffX);

diffY = diff(Y);
diffY = diffY-mean(diffY);

diffX = filtfilt(ones(1,6)/6,1,diffX);
diffY = filtfilt(ones(1,6)/6,1,diffY);


iX = crossing(diff(diffX));
iY = crossing(diff(diffY));
    
deltatx = diff(crossing(diffX));
deltaty = diff(crossing(diffY));
    
tx = diffX(iX);
ty = diffY(iY);


%epuration
tx = tx(find(abs(tx)<10));
ntx = normpdf(-10:10,mean(tx),std(tx));
mux = mean(tx)
stdx = std(tx)

ty = ty(find(abs(ty)<10));
nty = normpdf(-10:10,mean(ty),std(ty));
muy = mean(ty)
stdy = std(ty)

phi = hilbert_prel(diffX,diffY);
freqX =abs(fft(diffX));
freqY =abs(fft(diffY));


wx = pi./(10*deltatx);
wy = pi./(10*deltaty);

%epuration
wx = wx(find(wx<0.1));
nwx = normpdf(0:0.0001:0.1,mean(wx),std(wx));
muwx = mean(wx)
stdwx = std(wx)

wy = wy(find(wy<0.1));
nwy = normpdf(0:0.0001:0.1,mean(wy),std(wy));
muwy = mean(wy)
stdwy = std(wy)


muphi = mean(phi)
stdphi = std(phi)





tosave = [mux stdx muy stdy muwx stdwx muwy stdwy muphi stdphi];

end
