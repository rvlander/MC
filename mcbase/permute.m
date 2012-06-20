function A=permute(B,vec)
if(vec(0) == 2)
	A = B.';
else A=B;
end
