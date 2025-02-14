#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

void BabboNataleRec(const int* pacchi, size_t pacchi_size, int p,bool *vcurr,int i,bool *vbest,int *max,int sum) {

	int count = 0;
	if (i == (int)pacchi_size) {
		for (int j = 0; j < (int)pacchi_size; j++) {
			if (vcurr[j]) {
				sum += pacchi[j];
				count++;
			}
		}
		if (sum < p) {
			if (count > (*max)) {
				*max = count;
				memcpy(vbest, vcurr, pacchi_size);
			}
		}
		
		sum = 0;
		return;
	}
	vcurr[i] = 0;
	BabboNataleRec(pacchi, pacchi_size, p, vcurr, i + 1,vbest,max,0);

	vcurr[i] = 1;
	BabboNataleRec(pacchi, pacchi_size, p, vcurr, i + 1,vbest,max,0);
}



void BabboNatale(const int* pacchi, size_t pacchi_size, int p) {

	bool* vcurr = calloc(pacchi_size, sizeof(bool));
	bool* vbest = calloc(pacchi_size, sizeof(bool));
	int max = 0;
	BabboNataleRec(pacchi, pacchi_size, p, vcurr, 0,vbest,&max,0);
	for (int j = 0; j < (int)pacchi_size; j++) {
		printf("%d ", vbest[j]);
	}
	free(vcurr);
	free(vbest);
}