#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int contacifre(unsigned short x) {
	int c = 0;
	for (int i = 0; x != 0; i++) {
		x = x / 10;
		c++;
	}
	return c;
}
void print_board(FILE* f, const unsigned short board[4][4]) {
	char* riga = "+----+----+----+----+";
	for (int i = 0; i <= 4*2; i++) {
		if (i % 2 == 0) {
			fprintf(stdout, "%s\n", riga);
		}
		else {
			for (int j = 0; j < 4; j++) {
				switch (contacifre(board[i/2][j])){
				case 1: fprintf(stdout, "|   %u",board[i/2][j]);
					if(j == 3) fprintf(stdout, "|\n");
					break;
				case 2: fprintf(stdout, "|  %u", board[i/2][j]);
					if (j == 3) fprintf(stdout, "|\n");
					break;
				case 3: fprintf(stdout, "| %u", board[i/2][j]);
					if (j == 3) fprintf(stdout, "|\n");
					break;
				case 4: fprintf(stdout, "|%u", board[i/2][j]);
					if (j == 3) fprintf(stdout, "|\n");
					break;
				default: fprintf(stdout, "|    ");
					if (j == 3) fprintf(stdout, "|\n");
					break;
				}
			}

		}
	}
}