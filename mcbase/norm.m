function [Y] = norm(X)
	T=X.^2;
	Y=sqrt(sum(sum(T)));
end
