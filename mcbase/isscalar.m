function [B]=isscalar(V)

        T = size(V);
        B = T(1)==1 &&  T(2)==1; 


end

