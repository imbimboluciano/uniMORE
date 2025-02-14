.586
.model flat 
.code


_NumeroDiPari proc

push ebp
mov ebp,esp
push ebx
push esi
push edi

mov edi,dword ptr[ebp + 12]
dec edi
mov ebx,dword ptr[ebp + 8]
mov esi,0
mov cl,2

ciclo:
cmp edi,-1
je fine
mov ax,word ptr[ebx + edi * 1]
mov ah,0
div cl
cmp ah,0
jne decremento
inc esi


decremento:
dec edi
jmp ciclo




fine:
mov eax,esi


pop edi
pop esi
pop ebx
mov esp,ebp
pop ebp

ret


_NumeroDiPari endp


end