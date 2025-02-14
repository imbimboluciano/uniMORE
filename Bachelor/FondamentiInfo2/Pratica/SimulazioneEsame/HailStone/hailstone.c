#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void Hailstone(int n,int* seq,int* i) {
	if (seq[*i - 1] == 1) {
		return;
	}
	if (seq[*i - 1] % 2 == 0) {
		*i = *i + 1;
		seq = realloc(seq, (*i) * sizeof(int));
		seq[*i - 1] = seq[*i - 2] / 2;
		Hailstone(n, seq, i);
	}
	else {
		*i = *i + 1;
		seq = realloc(seq, (*i) * sizeof(int));
		seq[*i - 1] = 3 * seq[*i - 2] + 1;
		Hailstone(n, seq, i);
	}
}




int main(int argc, char* argv[]) {
	if (argc != 2) {
		return -1;
	}
	int n = atoi(argv[1]);
	if (n <= 0) {
		return 0;
	}
	int* seq = calloc(1, sizeof(int));
	seq[0] = n;
	int i = 1;
	Hailstone(n,seq,&i);

	for (int k = 0; k < i; k++) {
		if (k == i - 1) {
			fprintf(stdout, "%d", seq[k]);
		}
		else {
			fprintf(stdout, "%d, ", seq[k]);
		}
		
	}

	return i;
	
}