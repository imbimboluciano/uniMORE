#include<string.h>
#include<stdlib.h>

char* rimuovi_singoli_spazi(const char* s) {

	 size_t l = strlen(s);
	 char* res = NULL;
	 size_t j = 0;
	 for (size_t i = 0; i < l; i++) {
		 if (s[i] != ' ') {
			 j++;
			 res = realloc(res, j * sizeof(char));
			 res[j - 1] = s[i];
		 }
		 else {
			 if (i == 0) {
				 if (s[i + 1] != ' ') {

				 }
				 else {
					 j++;
					 res = realloc(res, j * sizeof(char));
					 res[j - 1] = s[i];
				 }
			 }
			 else if (i == l - 1) {
				 if (s[i - 1] != ' ') {

				 }
				 else {
					 j++;
					 res = realloc(res, j * sizeof(char));
					 res[j - 1] = s[i];
				 }
			 }
			 else {
				 if (s[i + 1] != ' ' && s[i - 1] != ' ') {


				 }
				 else {
					 j++;
					 res = realloc(res, j * sizeof(char));
					 res[j - 1] = s[i];
				 }
			 }


		 }
	 }
	 j++;
	 res = realloc(res, j * sizeof(char));
	 res[j - 1] = '\0';
	 return res;
}