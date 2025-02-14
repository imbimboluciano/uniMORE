#include <stdio.h>

int main() {
	
	int vet[5] = { 1,2,3,4,5 };
	int* p;
	p = &vet[0];
	int b = 0;
	__asm{
		mov ebx, p
		mov eax, dword ptr[ebx]
		add eax, dword ptr[ebx + 4]
		add eax, dword ptr[ebx + 8]
		add eax, dword ptr[ebx + 12]
		add eax, dword ptr[ebx + 16]
		mov b, eax

	}

	printf("%d", b);
	return 0;
}