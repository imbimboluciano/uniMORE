#include<stdlib.h>

extern void bad_word_filter(char* s, char** words, size_t nwords);

int main(void) {
	char* words[] = { "carciofo", "broccolo", "cavolfiore" };
	char* s = "sei un carciofo";
	bad_word_filter(s,words,3);
	return 0;
}