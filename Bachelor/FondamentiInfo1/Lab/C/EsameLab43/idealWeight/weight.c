#include "weight.h"
#include<math.h>

double ideal_weight(int h, int age, char sex, enum formula f) {
	if (h < 0 || age < 0) return -1;
	if (sex != 'F' && sex != 'M') return -1;
	if (f != lorenz && f != berthean && f != keys) return -1;
	double peso = 0;
	double hd = (double) h;
	if (sex == 'F') {
		switch (f)
		{
		case lorenz:	peso = hd - 100 - (hd - 150) / 2;
			break;
		case berthean:	peso = 0.8 * (hd - 100.0) + ((double)age / 2);
			break;
		case keys:	peso = pow(hd / 100, 2) * 20.6;
			break;
		default:
			break;
		}
	}
	else {
		switch (f)
		{
		case lorenz: peso = hd - 100 - (hd - 150) / 4;
			break;
		case berthean:	peso = 0.8 * (hd - 100) + ((double)age / 2);
			break;
		case keys: 	peso = pow(hd / 100, 2) * 22.1;
			break;
		default:
			break;
		}
	}

	return peso;


}