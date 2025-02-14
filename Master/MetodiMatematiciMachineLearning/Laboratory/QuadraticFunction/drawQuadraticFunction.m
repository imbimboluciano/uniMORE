x = linspace(-10,11,100);
y = linspace(-10,10,100);

[X,Y] = meshgrid(x,y);
Z = quadraticFunction(X,Y);
surf(X,Y,Z);

figure(2);
contour(X,Y,Z,60) %last parameter is number of curvs

figure(1);
hold on;
xs = input(' point to draw tangent plane: ');
Z = tangentPlane(X,Y,xs(1),xs(2));
surf(X,Y,Z);
hold off;