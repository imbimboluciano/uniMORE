x = linspace(-pi,pi);
y = linspace(-pi/2,pi/2);
[X,Y] = meshgrid(x,y);
z = sin(X.*Y);
mesh(z);

x = linspace(-pi,pi);
y = linspace(-pi/2,pi/2);
[X,Y] = meshgrid(x,y);
z = sin(X.*Y);
surf(z);


x = linspace(-pi,pi);
y = linspace(-pi/2,pi/2);
[X,Y] = meshgrid(x,y);
Z = sin(X.*Y);
[c,h] = contour(X,Y,Z);
clabel(c,h);