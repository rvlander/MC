function [ R ] = add_vect( X,Y )
%ADD_VECT Summary of this function goes here
%   Detailed explanation goes here

l = max([size(X,1) size(Y,1)]);

lX = [X;zeros(l - size(X,1),1)];
lY = [Y;zeros(l - size(Y,1),1)];


R = lX+lY;

end

