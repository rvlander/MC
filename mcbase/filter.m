function y=filter(b,a,x)
b=b./a(1);
a=a./a(1);

na = numel(a)-1;
nb = numel(b)-1;

y = zeros(numel(x),1);

for n=1:numel(x)
    
    if(n-nb<=0)
        p1 = sum(b(1:n).*x(n:-1:1)'); %trouvé pourquoi il faut enlever le ctranspose
    else
        p1 = sum(b.*x(n:-1:n-nb)');
    end
    
    
    if n-na<=0
        p2 = sum(a(2:n-2).*y(n-1:-1:1)');
    else
        p2 = sum(a(2:end).*y(n-1:-1:n-na)');
    end
    
    
    y(n) = p1-p2;
end
end


