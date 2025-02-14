#include "bcd.h"

unsigned short bin2bcd(unsigned short val) {
	unsigned short u = val % 10;
	unsigned short d = (val / 10) % 10;
	unsigned short c = (val / 100) % 10;
	unsigned short m = (val / 1000) % 10;

	return (u) + (d * 16) + (c * 16 * 16) + (m * 16 * 16 * 16);
}