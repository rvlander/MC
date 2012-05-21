function I = eye(M,N)

if(nargin == 1)
	if(numel(M) ==2)
		L = M(1);
		C = M(2);
	else
		L=M(1);
		C=M(1);	
	end
elseif (nargin >1)
L=M(1);
C=N(1);
end

Ndim = -max(-[L C]);
I = zeros(L,C);

for i=1:Ndim
I(i,i) =1;
end


end

