function [dxu,dxd,dyu,dyd] = direct_method_triangle(nT,dXsdT,dYsdT,t0xs,t0ys,ind0xs,ind0ys)

% calculs des parametres
nb_arcs = size(t0xs,2)-1;
dxu = zeros(nb_arcs,2);
dxd = zeros(nb_arcs,2);
for i=1:nb_arcs
    j = ind0xs(i)+floor((ind0xs(i+1)-ind0xs(i))/2);
    dxu(i,:) = polyfit(nT(ind0xs(i):j),dXsdT(ind0xs(i):j),1);

    dxd(i,:) = polyfit(nT(j:ind0xs(i+1)),dXsdT(j:ind0xs(i+1)),1);
%     
%         figure(8)
%     plot(nT(j:ind0xs(i+1)),dXsdT(j:ind0xs(i+1)));
%     hold on;
%     plot(nT(j:ind0xs(i+1)),dxd(i,1)*nT(j:ind0xs(i+1))+dxd(i,2),'r');
end

% calculs des parametres
nb_arcs = size(t0ys,2)-1;
dyu = zeros(nb_arcs,2);
dyd = zeros(nb_arcs,2);
for i=1:nb_arcs
    j = ind0ys(i)+floor((ind0ys(i+1)-ind0ys(i))/2);
    dyu(i,:) = polyfit(nT(ind0ys(i):j),dYsdT(ind0ys(i):j),1);
    dyd(i,:) = polyfit(nT(j:ind0ys(i+1)),dYsdT(j:ind0ys(i+1)),1);
end

end







