function [res] = isinteger(X)

I = mod(X,1);


res = ~any(I);

end

