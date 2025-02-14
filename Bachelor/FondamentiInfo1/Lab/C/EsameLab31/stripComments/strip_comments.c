#include "strip_comments.h"

void strip_comments(const char* in_filename, const char* out_filename){
	FILE* in = fopen(in_filename, "r");
	if (in == NULL) return;
	FILE* out = fopen(out_filename, "w");
	if (out == NULL) return;
	int new_line = 0;
	int no = 0;
	while (1) {
		int c = fgetc(in);
		if (new_line == 0) {
			new_line = 1;
			if (c == '#') {
				no = 1;
			}
			else {
				fputc(c, out);
				no = 0;
			} 
		}
		else {
			if (c == EOF) break;
			if (c == '\n') new_line = 0;
			if (no == 0) {
				fputc(c, out);
			}
		}
	}

	fclose(in);
	fclose(out);
}