#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
extern void print_board(FILE* f, const unsigned short board[4][4]);

int main(void) {

	FILE* f = fopen("game.txt", "w");
	if (f == NULL) return NULL;
	unsigned short board[4][4] = {
		{256,512,512,2},
		{128,32,32,1024},
		{2,0,128,128},
		{32,256,64,128}
	};
	print_board(f,board);
	return 0;
}