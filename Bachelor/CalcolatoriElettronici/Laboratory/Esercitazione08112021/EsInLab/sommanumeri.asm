
.586
.model flat
.code

_sommanumeri proc
	push ebp
	mov ebp,esp
	push ebx
	push esi
	push edi

	mov eax,0
	mov ebx,dword ptr[ebp + 8]
	mov esi,dword ptr[ebp + 12]
	dec esi
	ciclo:
	cmp esi,-1
	je fine
	add eax,dword ptr[ebx + esi*4]
	dec esi
	jmp ciclo

	fine:

	pop ebp
	mov esp,ebp
	pop ebx
	pop esi
	pop edi

	ret


_sommanumeri endp


end