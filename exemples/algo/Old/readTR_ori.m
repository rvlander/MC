function [T,X,Y] = readTR_ori(filename)
    T = [];
    X = [];
    Y = [];
    tline = 0;
    fid = fopen(filename);
    ntline = 0;
    ntline=fgetl(fid);
    while tline~=-1
        tline = ntline;
        ntline = fgetl(fid);
        if(tline~=-1)
            if (tline(1) == '#')
                timestamp = sscanf(tline,'#%f');
                if(timestamp>0 )
                    val = sscanf(ntline,'%f,%f,%f');
                    stepx = (val(2)-X(end))/timestamp;
                    stepy = (val(3)-Y(end))/timestamp;
                    for i=1:timestamp
                        X = [X;X(end)+stepx];
                        Y = [Y;Y(end)+stepy];
                    end
                end
            else
                val = sscanf(tline,'%f,%f,%f');
                T = [T;val(1)];
                X = [X;val(2)];
                Y = [Y;val(3)];
            end
        end
    end
    fclose(fid);
end
