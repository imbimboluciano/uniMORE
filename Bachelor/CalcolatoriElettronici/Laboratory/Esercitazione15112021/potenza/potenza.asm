.586
.model flat
.code

_potenza proc

push ebp
mov ebp,esp
push ebx
push edi
push esi

mov esi,dword ptr[ebp + 12]
mov eax,dword ptr[ebp + 8]
mov ebx,dword ptr[ebp + 8]

ciclo:
cmp esi,1
je fine
imul ebx
dec esi
jmp ciclo

fine:

pop esi
pop edi
pop ebx
mov esp,ebp
pop ebp

ret

_potenza endp

end