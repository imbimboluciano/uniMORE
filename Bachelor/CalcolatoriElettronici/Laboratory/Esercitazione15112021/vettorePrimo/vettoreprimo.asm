.586
.model flat
.code

_vettorePrimo proc

push ebp
mov ebp,esp
push ebx
push esi
push edi

mov ebx,dword ptr[ebp + 8]
mov esi,dword ptr[ebp + 12]
dec esi
mov ecx,1
mov edx,0

ciclo:
cmp esi,-1
je fine
mov eax,dword ptr[ebx + esi *4]
call numeroprimo
cmp edx,1
jne vettorenonprimo
dec esi
jmp ciclo

vettorenonprimo:
mov ecx,0

fine:

mov eax,ecx


pop edi
pop esi
pop ebx
mov ebp,esp
pop ebp

ret


_vettorePrimo endp

numeroprimo proc
push eax
push edi
push ecx

mov edi,eax
mov ecx,0

ciclo:
cmp edi,0
je fineciclo
push eax

cdq
idiv edi

pop eax
cmp edx,0
jne decremento
inc ecx


decremento:
dec edi
jmp ciclo


fineciclo:
cmp ecx,2
jg nonprimo
mov edx,1
jmp fine

nonprimo:
mov edx,0

fine:

pop ecx
pop edi
pop eax

ret

numeroprimo endp



end


