.586
.model flat
.code


_fattoriali proc

push ebp
mov ebp,esp
push ebx
push edi
push esi

mov esi,dword ptr[ebp + 16]
mov ebx,dword ptr[ebp + 8]
mov ecx,dword ptr[ebp + 12]
dec esi
mov eax,0

ciclo:
cmp esi,-1
je fine

call fattoriale
dec esi
jmp ciclo



fine:


pop esi
pop edi
pop ebx
mov esp,ebp
pop ebp

ret


_fattoriali endp


fattoriale proc
push eax
mov eax,dword ptr[ebx + esi*4]
mov edi,dword ptr[ebx + esi*4]
dec edi

cmp eax,0
je fine0

ciclo:
cmp edi,0
je fine
imul edi
dec edi
jmp ciclo


fine0:
mov eax,1

fine:

mov dword ptr[ecx + esi*4],eax

pop eax
ret
fattoriale endp


end