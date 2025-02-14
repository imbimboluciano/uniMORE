#include<stdbool.h>
#include<math.h>

bool triangolare(int n) {
	if (n <= 0) return false;
	int sum = 0;
	int i = 1;

	while (sum < n) {
		sum += i;
		i++;

	}

	if (sum == n) return true;
	return false;
}