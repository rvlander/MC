function [B]=isvector(V)

        T = size(V);
        B = T(1)==1 ||  T(2)==1; 


end

