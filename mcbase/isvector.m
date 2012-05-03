function [B]=isvector(V)

        T = SIZE(V);
        B = T==[1 n] ||  T==[n 1]; 


end

