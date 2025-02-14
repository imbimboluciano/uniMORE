#include <stdio.h>

int main(void)
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p;
	p = &a[0];
	int s = 0;
	__asm {
		mov ebx,p
		mov eax,0
		mov esi,0
		ciclo: 
		cmp esi, 10
		jnl fine
		add eax, dword ptr[ebx + esi * 4]
		inc esi
		jmp ciclo
		fine:
		mov s,eax
	}
	printf("%d", s);
}