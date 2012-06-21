function A=reshape(X,M,N)

if(nargin<3 && numel(M)>1)
  N = M(2);
  M = M(1);
end


if(numel(X) ~= M*N) 
    error('reshape : source and target matrix have a different number of elements');
end

A = zeros(M,N);



n_elem = M*N;

A(1:n_elem) = X;

end

