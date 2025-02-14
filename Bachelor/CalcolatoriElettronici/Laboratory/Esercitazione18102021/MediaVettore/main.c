

int main(void) {

	int a[2] = { 8,6 };
	int* p;
	p = &a[0];
	int media = 0;
	__asm {
		mov eax, p
		mov ecx,2
		mov esi,0
		mov ebx,0
		mov edx,0

		ciclosomma:
		cmp esi,ecx
		je divisione
		add ebx,dword ptr[eax + esi*4]
		inc esi
		jmp ciclosomma

		divisione:
		cmp ebx,ecx
		jl fine
		sub ebx,ecx
		inc edx
		jmp divisione

		fine:
		mov media,edx


	}
	return 0;
}