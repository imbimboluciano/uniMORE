function g = gradientQuadraticFunction(x1,x2)

%z = 0.5 * (x1.^2 + 3* x2.^2) - x1 + 50;
g = [x1 - 1,3* x2];

%z = 0.5 * (x1.^2) - x1 + 50;
%g = [x1 - 1, x2*0];

%z = 0.5 * (-x1.^2 + 3*x2.^2) - x1 + 50; 
%g = [-x1 -1,3*x2];