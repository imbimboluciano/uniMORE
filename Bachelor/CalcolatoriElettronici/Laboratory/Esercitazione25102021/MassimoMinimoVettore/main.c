#include <stdio.h>

//Massimo e minimo del vettore
__declspec(naked) int somma(int* vet, int lung,int *max,int *min) {

	__asm {
		push ebp
		mov ebp, esp
		push ebx
		push esi
		push edi

		mov eax, 0
		mov esi, dword ptr[ebp + 12]
		dec esi
		mov ebx, dword ptr[ebp + 8]
		mov ecx,dword ptr[ebx + esi * 4]
		//minimo
		minimo:
		cmp esi,-1
		je fineminimo
		cmp dword ptr[ebx + esi * 4],ecx
		jl scambiominimo
		dec esi 
		jmp minimo

		scambiominimo:
		mov ecx,dword ptr[ebx + esi * 4]
		dec esi
		jmp minimo
		
			
		fineminimo:

		mov edx,dword ptr[ebp + 20]
		mov [edx],ecx


		mov eax, 0
		mov esi, dword ptr[ebp + 12]
		dec esi
		mov ebx, dword ptr[ebp + 8]
		mov ecx, dword ptr[ebx + esi * 4]
		//massimo
		massimo:
		cmp esi, -1
		je finemassimo
		cmp dword ptr[ebx + esi * 4],ecx
		jg scambiomassimo
		dec esi
		jmp massimo

		scambiomassimo:
		mov ecx, dword ptr[ebx + esi * 4]
		dec esi
		jmp massimo


		finemassimo:

		mov edx, dword ptr[ebp + 16]
		mov[edx], ecx

		mov eax, 0
		mov esi, dword ptr[ebp + 12]
		dec esi
		mov ebx, dword ptr[ebp + 8]

		//somma
		

		ciclo:
		cmp esi, -1
			je finesomma
			add eax, dword ptr[ebx + esi * 4]
			dec esi
			jmp ciclo

			finesomma :

		pop edi
			pop esi
			pop ebx
			mov esp, ebp
			pop ebp

			ret
	}
}

int main(void) {

	int a[10] = {5,3,7,8,9,10,1,15,2,6};
	int max = -1, min = -1;
	int s = somma(a, 10, &max, &min);
	printf("%d %d %d", s, max, min);
}
