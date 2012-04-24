function [px,py] = direct_method_parab(nT,dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys)

% calculs des parametres
nb_arcs = size(t0xs,2)-1;
px = zeros(nb_arcs,3);
for i=1:nb_arcs
    px(i,:) = polyfit(nT(ind0xs(i):ind0xs(i+1)),dXsdT(ind0xs(i):ind0xs(i+1)),2);
end

% calculs des parametres
nb_arcs = size(t0ys,2)-1;
py = zeros(nb_arcs,3);
for i=1:nb_arcs
    py(i,:) = polyfit(nT(ind0ys(i):ind0ys(i+1)),dYsdT(ind0ys(i):ind0ys(i+1)),2);
end

end







