#include<stdlib.h>
#include<stdint.h>

uint32_t vector_MCD(const uint32_t* v, size_t n) {
	if (v == NULL || n == 0)	return 0;
	for (size_t i = 0; i < n; i++) {
		if (v[i] == 0)	return 0;
	}


	int controllo = 1;
	uint32_t MCD = 1;
	uint32_t min = v[0];
	for (size_t i = 1; i < n; i++)
	{
		if (v[i] < min)
		{
			min = v[i];
		}
	}
	for (uint32_t temp = 2; temp < min; temp++)
	{
		controllo = 1;
		for (size_t i = 0; i < n; i++)
		{
			if (v[i] % temp != 0)
			{
				controllo = 0;
			}
		}
		if (controllo == 1)
		{
			MCD = temp;
		}
	}
	return MCD;

}