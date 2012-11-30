function [min,inds] = min(A)

	[min,inds] = max(-A);
	min = -min;
end
