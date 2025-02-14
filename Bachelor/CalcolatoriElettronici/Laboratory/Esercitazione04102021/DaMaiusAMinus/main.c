#include <stdio.h>

int main() {

	char str[255] = "Ciao";
	char* p;
	p = &str[0];

	__asm {
		mov ebx,p
		add dword ptr[ebx],32
	}

	printf("%s", str);
}