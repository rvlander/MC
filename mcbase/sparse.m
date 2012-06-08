function I=sparse(A,B,C)
if(nargin==1)
	I=A;
elseif(nargin==3)
	I = zeros(max(A),max(B));
	n = numel(A);
	for i=1:n
		I(A(i),B(i))=C(i)	
	end
end

end
