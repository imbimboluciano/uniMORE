#include<stdlib.h>
#include<string.h>
#include<math.h>

int AToIRec(const char* str,char c,int unit,int i) {
	if (c == 0) {
		return 0;
	}
	i++;
	return ((c - '0') * unit) + AToIRec(str, str[i], unit / 10, i);
}
int AToI(const char* str) {
	if (str == NULL) {
		return 0;
	}
	return AToIRec(str,str[0],pow(10, strlen(str) - 1),0);
}