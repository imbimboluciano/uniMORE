function g = compute_gradient(x)

t = [1 2 4 5 8];
y = [3 4 6 11 20];

g(1) = sum((x(1) * exp(x(2)*t) - y) .* exp(x(2)*t));

g(2) = sum((x(1) * exp(x(2)*t) - y) .* (x(1)*t) .* exp(x(2)*t));

g = g(:);
