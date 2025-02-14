function z = tangentPlane(x1,x2,xs1,xs2)
vg = gradientQuadraticFunction(xs1,xs2);
z = quadraticFunction(xs1,xs2) + vg(1)*(x1-xs1) + vg(2)*(x2-xs2);