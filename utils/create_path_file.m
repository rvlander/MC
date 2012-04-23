parts = regexp(path,':','split');

fid = fopen('outpath','w+');

%for part=parts
fprintf(fid,'%s\n',parts{:});
%end

fclose(fid);