function [] = exportVar(filename,varargin)

nVarargs = length(varargin);

fid = fopen(filename,'w+');


for k=1:nVarargs
    V = varargin{k};
    [m n] = size(V);
    
    fprintf(fid,'double[][] ');
    fprintf(fid,'%c_matlab_result',inputname(k+1));
   
    
    if(numel(V)==0)
        fprintf(fid,'= new double[%d][%d];\n',m,n);
    else
         fprintf(fid,' = {\n');
        for i=1:m-1
            fprintf(fid,'{');
            for j=1:n-1
                fprintf(fid,'%f,',V(i,j));
            end
            fprintf(fid,'%f},\n',V(i,n));
        end
            fprintf(fid,'{');
            for j=1:n-1
                fprintf(fid,'%f,',V(m,j));
            end
            fprintf(fid,'%f}\n',V(m,n));
        fprintf(fid,'};\n');
    end
end
fclose(fid);
end