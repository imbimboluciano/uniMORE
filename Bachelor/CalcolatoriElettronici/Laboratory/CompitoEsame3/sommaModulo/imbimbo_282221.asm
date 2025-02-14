.586
.model flat
.code

_somma_modulo proc

push ebp
mov ebp,esp
push ebx
push edi
push esi

mov ebx,dword ptr[ebp + 8]
mov esi,dword ptr[ebp + 12]
dec esi
mov ecx,dword ptr[ebp + 16]

call tuttidivisibili
cmp eax,-1
je fine
call tuttinondivisibili
cmp eax,-2
je fine

mov edi,0


ciclo:
cmp esi,-1
je fine

call divisione
mov dword ptr[ecx + esi*4],edx
add edi,edx
dec esi
jmp ciclo

fine:

mov eax,edi


pop esi
pop edi
pop ebx
mov esp,ebp
pop ebp

ret
_somma_modulo endp



divisione proc

push ecx
mov ecx,dword ptr[ebp + 20]
mov eax,dword ptr[ebx + esi *4]

cdq
idiv ecx

pop ecx
ret

divisione endp


tuttidivisibili proc
push esi
mov edi,-1

ciclo:
cmp esi,-1
je fine
call divisione
cmp edx,0
jne nondivisore 
dec esi
jmp ciclo

nondivisore:
mov edi,0

fine:
mov eax,edi



pop esi
ret
tuttidivisibili endp


tuttinondivisibili proc 
push esi
mov edi,-2

ciclo:
cmp esi,-1
je fine
call divisione
cmp edx,0
je divisore 
dec esi
jmp ciclo

divisore:
mov edi,0

fine:
mov eax,edi



pop esi

ret
tuttinondivisibili endp



end
