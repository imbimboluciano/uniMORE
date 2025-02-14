#include <stdio.h>

__declspec(naked) int somma(int a, int b) {
	__asm {
		push ebp
		mov ebp,esp
		push ebx
		push esi
		push edi

		mov eax,dword ptr[ebp + 8]
		add eax,dword ptr[ebp + 12]

		pop edi
		pop esi
		pop ebx 
		mov esp,ebp
		pop ebp

		ret
	}
}
int main(void) {

	int a = 5,b = 7;
	int s = somma(a, b);
	printf("%d", s);
}