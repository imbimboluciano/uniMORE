#include<stdio.h>
#include<math.h>

int multiplo(int a, int b) {
	if (a % b == 0) {
		return 1;
	}
	return 0;
}


void FrazioneEgiziaRec(int n, int d) {
	
	int nfrUn = 1;
	int dfrUn;
	double dd = d;
	double dn = n;
	double box = ceil((dd / dn));
	dfrUn = (int)box;
	

	fprintf(stdout, "%d/%d", nfrUn, dfrUn);
	if (multiplo(d, n) == 1)	return;
	int newN = (n * dfrUn) - (nfrUn * d);
	int newD = d * dfrUn;

	fprintf(stdout, " + ");
	FrazioneEgiziaRec(newN,newD);

}


void FrazioneEgizia(int n, int d) {
	if (n <= 0 || d <= 0 || n >= d) {
		fprintf(stdout, "%s", "Impossibile convertire la frazione data in frazione egizia.");
		return;
	}

	FrazioneEgiziaRec(n, d);
}