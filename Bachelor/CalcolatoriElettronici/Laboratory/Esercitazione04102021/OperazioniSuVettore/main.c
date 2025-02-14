#include <stdio.h>

int main() {

	int vet[5] = { 1,2,3,4,5 };
	int* p;
	p = &vet[0];

	__asm {
		mov ebx, p
		mov eax,dword ptr[ebx]
		add eax,dword ptr[ebx + 4]
		mov dword ptr[ebx],eax
	}
	printf("%d", vet[0]);
}