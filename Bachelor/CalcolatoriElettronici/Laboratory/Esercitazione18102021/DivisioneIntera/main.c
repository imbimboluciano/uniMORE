
int main(void) {

	int a = 7, b = 3, d = 0;

	__asm {
		mov eax,a
		mov ebx,b
		mov ecx,d

		ciclo:
		cmp eax,ebx
		jl fine
		sub eax,ebx
		inc ecx
		jmp ciclo


		fine:
		mov ecx,d
	}
	return 0;
}