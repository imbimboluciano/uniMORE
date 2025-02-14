function [ris,info] = newton(fun,grad,hes,x,tol,maxit)

x = x(:);
ris = x;

%evaluate gradient on first iterate
g = feval(grad,x);
for i = 1 : maxit
    direction = -feval(hes,x) \g; % resolve linear system with / command
    [alpha,inf] = armijo(fun,g,x,direction,1,0.5,1e-4);
    if inf > 0
        fprintf('\n Problems with Armijo: alpha<=eps*s \n');
    end
    x = x + alpha * direction;
    ris = [ris x];
    g = feval(grad,x);
    if norm(g) < tol
        disp(['iter = ', num2str(i)])
        info = 0;
        return
    end

end
info = 1;