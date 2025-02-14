#include <stdio.h>

/*int main() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p;
	p = &a[0];
	int b = 0;
	__asm
	{
		//MOV ebx, p
		//MOV eax, [ebx]
		//ADD eax, [ebx + 4]
		//MOV b, eax
		mov ebx, p
		mov ecx, dword ptr [ebx]
		add ecx,dword ptr [ebx + 4]
		mov eax,ecx
		mov b,eax
		
	}

	printf("%d", b);
	printf("\n");
}*/

//int main() {
//	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p;
//	p = &a[0];
//	int b = 0;
//
//	__asm {
//		mov ebx, p
//		mov esi, 5
//		mov edi, 7
//		mov eax, [ebx + esi * 4]
//		add eax, [ebx + edi * 4]
//		mov b,eax
//	}
//	printf("%d", b);
//}


int main() {
	char a[255] = "simone si scriva con la s maiuscola";
	char* p;
	p = &a[0];

	__asm {
		/*mov ebx, p
		sub [ebx],32*/
		mov ebx,p
		mov esi,0

		mov cl,byte ptr [ebx + esi*1]
		sub cl,32
		mov byte ptr[ebx + esi*1],cl
	}
	printf("%s", a);
}