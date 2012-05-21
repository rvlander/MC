function y=filter(a,b,x)
 b=b./a(1);
 a=a./a(1);
 
 na = numel(a)-1;
 nb = numel(b)-1;

 y = zeros(numel(X));

 for n=1:numel(X)
   if n-nb>0 && n-na>0
       
	y(n) = sum(b,x(n:-1:n-nb))-sum(a(2:end),y(n-1:-1:n-na)));
   	%y(n) = b(1)*x(n) + b(2)*x(n-1) + ... + b(nb+1)*x(n-nb)
        %         - a(2)*y(n-1) - ... - a(na+1)*y(n-na)
   end 
 end

end
