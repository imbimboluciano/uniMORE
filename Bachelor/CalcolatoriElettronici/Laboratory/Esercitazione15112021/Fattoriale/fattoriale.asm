.586
.model flat
.code

_fattoriale proc

push ebp
mov ebp,esp
push ebx
push edi 
push esi

mov ebx,dword ptr[ebp + 8]
mov eax,dword ptr[ebp + 8]
dec ebx
cmp eax,0
je f0
ciclo:
cmp ebx,0
je fine
imul ebx
dec ebx
jmp ciclo

f0:
mov eax,1

fine:



pop esi
pop edi
pop ebx
mov esp,ebp
push ebp

ret

_fattoriale endp

end