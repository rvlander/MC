function [] = plot_trace( inds, X ,Y )

plot(X(1:inds(1)-1),-Y(1:inds(1)-1));
for i=2:max(size(inds))
    
    hold on;
    plot(X(inds(i-1):inds(i)-1),-Y(inds(i-1):inds(i)-1));

end

