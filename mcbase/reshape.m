function A=reshape(X,M,N)

if(numel(X) ~= M*N) 
    error('reshape : source and target matrix have a different number of elements');
end

A = zeros(M,N);

n_elem = M*N;

A(1:n_elem) = X;

end

