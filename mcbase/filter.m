function y=filter(b,a,x)
b=b./a(1);
a=a./a(1);

%pm('b',size(b));
%pm('a',size(a));


na = numel(a)-1;
nb = numel(b)-1;

%pm('nb',nb);
%pm('na',na);

y = zeros(numel(x),1);

for n=1:numel(x)
    
    if(n-nb<=0)
	%pm('b(1:n)',size(b(1:n)));
	%pm('x(n:-1:1)',size(x(n:-1:1)));
        p1 = sum(b(1:n).*x(n:-1:1)); %trouvé pourquoi il faut enlever le ctranspose
    else
	%pm('b',b);
	%pm('x(n:-1:n-nb)',size(x(n:-1:n-nb)));
        p1 = sum(b.*x(n:-1:n-nb));
    end
    
    
    if n-na<=0
	%pm('a(2:n-2)',a(2:n-2));
	%pm('y(n-1:-1:1)',size(y(n-1:-1:1)));
        p2 = sum(a(2:n).*y(n-1:-1:1));
    else
	%pm('a(2:end)',y(n-1:-1:n-na));
        p2 = sum(a(2:end).*y(n-1:-1:n-na));
    end
    
    
    y(n) = p1-p2;
end
end


