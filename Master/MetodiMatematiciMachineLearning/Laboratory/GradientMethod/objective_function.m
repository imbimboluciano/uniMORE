function f = objective_function(x) 

t = [1 2 4 5 8];
y = [3 4 6 11 20];

%non linear function
f = 0.5 * sum((x(1)*exp(x(2) * t) - y).^2);

