t=[0:0.01:16.*pi];

phi=pi/4;

x=cos(1.5.*t);
y=cos(t+phi);

figure
plot(x,y)

data(:,1)=x;
data(:,2)=y;
[phi]=hilb2(data);
for i=1:size(phi,1)
    if phi(i,1)>180
        phi(i,1)=phi(i,1)-360;
    end
end

% plot(phi)

