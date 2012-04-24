fps = 25;
delay = 1/25*1000;

Tend= min(T(end),sampling(end));

nb_img = floor(Tend/delay);

frames = moviein(nb_img);

for i = 1:nb_img
    time = i*delay;
    indsT = find(T<=time);
    indsS = find(sampling<=time);
    
    plot(X, Y,'Color',[1. 1. 1.]);
    hold on;
    plot(nX, nY,'Color',[1. 1. 1.]);
    
    
    plot(X(indsT), Y(indsT));
    hold on;
    plot(nX(indsS), nY(indsS),'r');
    
    frames(:, i) = getframe;
end

title('Movie being played back...')
movie(frames, 10, fps)