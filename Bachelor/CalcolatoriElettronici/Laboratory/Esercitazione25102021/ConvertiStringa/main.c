#include <stdio.h>

__declspec(naked) void convertiStringaMai(char *s) {

	__asm {
		push ebp
		mov ebp,esp
		push ebx
		push esi
		push edi

		mov ebx,dword ptr[ebp + 8]
		mov esi,0
		ciclo:
		cmp byte ptr[ebx + esi*1],0
		je fine
		cmp byte ptr[ebx + esi *1],'a'
		jl incremento
		cmp byte ptr[ebx + esi * 1], 'z'
		jg incremento 
		sub byte ptr[ebx + esi*1],32
		jmp incremento


		incremento:
		inc esi 
		jmp ciclo



		fine:


		pop edi
		pop esi
		pop ebx
		mov esp,ebp
		pop ebp

		ret
	}
}


int main(void) {
	char s[255] = "ciao come va";
	convertiStringaMai(s);
	printf("%s",s);
}