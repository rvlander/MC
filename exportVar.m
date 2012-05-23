function [] = exportVar(filename,varargin)

nVarargs = length(varargin);

fid = fopen(filename,'w+');


for k=1:nVarargs
    V = varargin{k};
    [m n] = size(V);
    
    fprintf(fid,'double[][] ');
    fprintf(fid,'%c_matlab_result',inputname(k+1));
    fprintf(fid,' = {\n');
    
    if(numel(V)==0)
        fprintf(fid,'new double[%d][%d];\n',m,n);
    else
        
        for i=1:m
            fprintf(fid,'{');
            for j=1:n-1
                fprintf(fid,'%f,',V(i,j));
            end
            fprintf(fid,'%f}\n',V(i,n));
        end
        fprintf(fid,'};\n');
    end
end
fclose(fid);
end