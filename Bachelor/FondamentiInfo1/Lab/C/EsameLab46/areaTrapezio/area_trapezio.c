#include<math.h>


double area_trapezio(double a, double b, double c, double d) {
	if (b <= a)	return -1;

	double cquad = pow(c, 2);
	double dquad = pow(d, 2);
	double difquad = ((b - a) + ((cquad - dquad) / (b - a)));
	double trapezio = ((a + b) / 2) * sqrt(cquad - ( pow(difquad,2) / 4));
	return trapezio;

}