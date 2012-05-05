function [A]=diff( X )

n = size(X,1);
A = [X(2:n,:)-X(1:n-1,:)];

end