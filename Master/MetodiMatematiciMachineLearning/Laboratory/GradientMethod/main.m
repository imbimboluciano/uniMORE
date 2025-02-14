% comando to clean enviroment and memory
clear;close all;


t = [1 2 4 5 8]';
y = [3 4 6 11 20]';

tol = 1e-4;
maxit = 20000;

plot(t,y,'*r');
hold on

%we need a function that approximate the data given
%try manually but obviously this function not fit right
z = linspace(0,12,200);
vz = 2.5 * exp(0.21 .* z);
plot(z,vz,'k');

%so we start from the previous point (2.4,0.21)
% and we apply a gradient's method (steepest) with Armijo
% (objectiveFunction,gradient,initial iterate, tollerance, max number of
% iterate)
tic;
[ris, info] = steepest('objective_function','compute_gradient',[2.5,0.21],tol,maxit);
%[ris, info] = newton('objectiveFunction','gradient','hessian',[2.5,0.21],tol,maxit);
%[ris, info] = barzilai_borwein('objective_function','gradient',[2.5,0.21],tol,maxit);
toc;

if info==0
    sol = ris(1:2,end);
    fprintf('solution [%e,%e]\n',sol);
else
    fprintf('\n maxit reached \n');
    return
end

vz = sol(1) * exp(sol(2) .* z);
plot(z,vz,'r');

