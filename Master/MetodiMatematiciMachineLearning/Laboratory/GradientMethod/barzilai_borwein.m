function [x, info] = barzilai_borwein(fun,grad,x,tol,maxit)
x = x(:);
g = feval(grad,x);
rho = 1;
gold = g;

for i = 1 : maxit
   d = - rho*g;
   FR = feval(fun,x);
   gf = g'*d;
   [alpha, inf] = armijo(fun,x,d,1,0.5,1e-4,FR,gf);
   if inf>0
       fprintf(' \n problemi in backtraking: alpha<=eps*s \n ');
   end    
   s = alpha * d;
   x = x + s;
   g = feval(grad,x);
   y = g - gold; gold = g;
   %rho = (s'*s) / (s'*y); % first rule of Barzilai-Borwein
   % rho = (s'*y) / (y'*y) second rule of Barzilai-Borwein
   if norm(g) < tol
       disp(['iter = ', num2str(i)])
       info = 0;
       return
   end
end
info = 1;