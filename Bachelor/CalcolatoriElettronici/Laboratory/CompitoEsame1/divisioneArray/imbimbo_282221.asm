.586
.model flat
.code

_divisione_array proc
push ebp
mov ebp,esp
push ebx
push edi
push esi


mov ebx,dword ptr[ebp + 8]
mov esi,dword ptr[ebp + 16]
dec esi
mov ecx,dword ptr[ebp +20]

ciclo:
cmp esi,-1
je fine
mov eax,dword ptr[ebx + esi *4]
cdq
push ecx
mov ecx,dword ptr[ebp + 12]
idiv ecx
pop ecx
mov dword ptr[ebx + esi * 4],eax
mov dword ptr[ecx + esi * 4],edx
dec esi
jmp ciclo

fine:
call resto0
call resto1
mov eax,edi



pop esi
pop edi
pop ebx
mov esp,ebp
pop ebp 

ret

_divisione_array endp


resto0 proc 
push esi
mov edi,0
mov esi,dword ptr[ebp + 16]
dec esi

cicloresto:
cmp esi,-1
je fineciclo

cmp dword ptr[ecx + esi * 4],0
je tuttizero
mov edi,0
jmp fineciclo


tuttizero:
mov edi,-1
dec esi
jmp cicloresto

fineciclo:

pop esi
ret 
resto0 endp


resto1 proc
push esi
mov edi,1
mov esi,dword ptr[ebp + 16]
dec esi

cicloresto:
cmp esi,-1
je fineciclo

cmp dword ptr[ecx + esi * 4],0
jne tuttidiversizero
mov edi,0
jmp fineciclo


tuttidiversizero:
mov edi,1
dec esi
jmp cicloresto

fineciclo:

pop esi
ret 

resto1 endp

end