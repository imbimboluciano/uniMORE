function z = quadraticFunction(x1,x2)
%
% f:R^2 ---> R
% f(x) = 1/2 * x^T * A * x+ b^T*x + c
% A = [1 0; 0 3], b = [-1;0], c = 50
% A diagonal matrix so f is equal to 0.5 * (1*x1^2 + 3*x^2) + [-1,0] *[x1,x2] + 50

% function is stricly convex because A is defined positive
z = 0.5 * (x1.^2 + 3* x2.^2) - x1 + 50;

% A = [1 0; 0 0] b = [-1;0],  c = 50
% function is convex because A is semidefined positive
% we lose the uniqueness of minimum 
%z = 0.5 * (x1.^2) - x1 + 50; 

% A = [0 0; 0 3] b = [-1;0],  c = 50
% function is convex because A is semidefined positive
% we lose the uniqueness of minimum 
%z = 0.5 * (3* x2.^2) - x1 + 50; 

% A = [-1 0; 0 3] b = [-1;0],  c = 50
% function is not convex because A is not positive
%z = 0.5 * (-x1.^2 + 3*x2.^2) - x1 + 50; 