#include <stdio.h>
// metti in b1 1 se ai è maggiore di c, 0 altrimenti
/*int main(void) {
	int a[5] = { 1,2,3,4,5 };
	int b[5] = { 0,0,0,0,0 };
	int c = 3;
	int* p0,* p1;
	p0 = &a[0];
	p1 = &b[0];
	__asm {
		mov ecx,p0
		mov edx,p1
		mov ebx,c
		mov esi,0
		ciclo:
		cmp esi,5
		jge fine

		mov eax, dword ptr[ecx + esi * 4]
		cmp eax,c
		jng incremento
		mov dword ptr[edx + esi*4],1
		jmp incremento

		incremento:
		inc esi
		jmp ciclo

		fine:
	}

	for (int i = 0; i < 5; i++) {
		printf("%d", b[i]);
		
	}
	return 0;
}*/

// metti in bi 0 se bi è minore della somma di a, altrimenti lascia bi 
/*int main(void) {
	int a[5] = { 1,2,3,4,5 };
	int b[5] = { 10,20,30,7,50 };
	int* p0, *p1;
	p0 = &a[0];
	p1 = &b[0];
	__asm {
		mov ecx, p0
		mov edx, p1
		mov esi, 0
		mov eax,0
		ciclosomma:
			cmp esi,5
			jge fineciclosomma
			add eax,dword ptr[ecx + esi*4]
			inc esi
			jmp ciclosomma

		fineciclosomma:
		mov esi,0
		ciclo:
			cmp esi, 5
			jge fine
			mov ebx, dword ptr[edx + esi * 4]
			cmp ebx,eax 
			jnl incremento
			mov dword ptr[edx + esi * 4], 0
			jmp incremento

		incremento :
			inc esi
			jmp ciclo

		fine :
	}

	for (int i = 0; i < 5; i++) {
		printf("%d", b[i]);

	}
	return 0;
}*/

// conta numero di a nella stringa
int main(void) {
	char str[255] = "blanchito baby";
	char* p;
	p = &str[0];
	int b = 0;
	__asm {
		mov ebx, p
		mov edx, b
		mov esi,0
		ciclo:
			mov al, byte ptr[ebx + esi * 1]
			cmp al,0
			je fine
		
			cmp al,97
			jne incremento
			inc edx
			
		
			incremento:
				inc esi 
				jmp ciclo

		fine:
			mov b, edx;
	}
	printf("%d", b);
	return 0;
}

