#include "utf8.h"


size_t utf8_encode(uint32_t codepoint, uint8_t seq[4]){
	if (codepoint > 0x10FFFF)	return 0;

	uint32_t box = codepoint;
	uint32_t* res = NULL;
	size_t j = 0;
	for (size_t i = 0; box != 0; i++) {
		j++;
		res = realloc(res, j * sizeof(uint32_t));
		res[j - 1] = box % 16;
		box /= 16;
	}

	size_t n = 0;
	if (codepoint < 0x007F) {
		n = 1;
		seq[0] = codepoint;
	}
	else if (codepoint < 0x07FF) {
		n = 2;
		seq[0] = res[1] + 128 + 64;
		seq[1] = res[0] + 128;
		
	}
	else if (codepoint < 0xFFFF) {
		n = 3;
	}
	else if (codepoint < 0x10FFFF) {
		n = 4;
	}


	free(res);
	return n;


}