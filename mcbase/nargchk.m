function MSG=nargchk(low,high,n,unused)
%NARGCHK Summary of this function goes here
%   Detailed explanation goes here

MSG = '';
if(n<low || n>high) MSG ='arg check failed';


end

