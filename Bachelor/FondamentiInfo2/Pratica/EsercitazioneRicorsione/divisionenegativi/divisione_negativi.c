#include<limits.h>

int DivisioneNegativiRec(int a, int b) {
	if (a >= 0 && b > 0) {
		if (a >= b) return 1 + DivisioneNegativiRec(a - b, b);
		else return 0;
	}
	else if (a >= 0 && b < 0) {
		if (a >= (-b)) return -1 + DivisioneNegativiRec(a + b, b);
		else return 0;
	}
	else if (a <= 0 && b > 0) {
		if ((-a) >= b) return -1 + DivisioneNegativiRec(a + b, b);
		else return 0;
	}
	else {
		if ((-a) >= (-b)) return 1 + DivisioneNegativiRec(a - b, b);
		else return 0;
	}
	
}


int DivisioneNegativi(int a, int b) {
	if (b == 0) {
		return INT_MAX;
	}

	return DivisioneNegativiRec(a, b);
}
