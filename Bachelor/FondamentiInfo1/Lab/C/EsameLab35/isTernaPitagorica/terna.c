#include<stdbool.h>
#include<math.h>

bool is_terna_pitagorica(unsigned int v[3]) {
	bool is = false;
	if (pow(v[0], 2) == (pow(v[1], 2) + pow(v[2], 2))) {
		is = true;
	}
	if (pow(v[1], 2) == (pow(v[0], 2) + pow(v[2], 2))) {
		is = true;
	}
	if (pow(v[2], 2) == (pow(v[0], 2) + pow(v[1], 2))) {
		is = true;
	}
	return is;
}