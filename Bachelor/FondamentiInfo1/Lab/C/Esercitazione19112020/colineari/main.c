#include "geometria.h"
int main()
{
	struct punto p1 = { 8.0,2.0 };
	struct punto p2 = { 2.0,3.0 };
	struct punto p3 = { 4.0,5.0 };
	int col = colineari(p1, p2, p3);
	return 0;
}