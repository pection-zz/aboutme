fid = fopen('HOGFull1Font-imagesize-50-block-20-cell-20-bin-9-sined-True-nimage-30000.csv');
out = textscan(fid,'%s%f%f','delimiter',',');
fclose(fid);

date = datevec(out{1});
col1 = out{2};
col2 = out{3};