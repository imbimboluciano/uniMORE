double sqrt(double a){
	double t, x = a;
	if (x <= 0.)
		return 0.;
	do {
		t = x;
		x = 0.5 * (t + a / t);
	} while (x != t);
	return x;
}double discriminante(double a, double b, double c) {
	double dis;
	dis = (b * b) - (4 * a * c);
	return dis;
}
int soluzioni(double a, double b, double c, double *x1, double *x2) {		double dis = discriminante(a, b, c);	if (dis < 0) {		return 0;	}	else if (dis > 0) {		*x1 = (-b + sqrt(dis)) / (2 * a);		*x2 = (-b - sqrt(dis)) / (2 * a);		return 2;	}	else {		*x1 = (-b + sqrt(dis)) / (2 * a);		*x2 = (-b - sqrt(dis)) / (2 * a);		return 1;	}	}int main(void){	double a = 2, b = 0, c = 4;	double sol1, sol2;	double *x1 = &sol1, *x2 = &sol2;	int ris = soluzioni(a, b, c, x1, x2);	return 0;}