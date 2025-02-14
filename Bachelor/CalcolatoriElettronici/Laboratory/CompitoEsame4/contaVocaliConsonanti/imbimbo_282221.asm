.586
.model flat
.code


_conta_vocali_consonanti proc

push ebp 
mov ebp,esp
push ebx
push esi
push edi

mov ebx,dword ptr[ebp + 8]
mov esi,0
mov edx,0
mov edi,0

call contavocali
mov ecx,dword ptr[ebp + 12]
mov [ecx],eax
add edi,eax
call contaconsonanti
mov ecx,dword ptr[ebp + 16]
mov [ecx],eax
add edi,eax

cmp edi,0
je novc
cmp edi,edx
je tutteUpper
cmp edi,esi
je solovc
jmp fine

novc:
mov eax,-1
jmp fine

solovc:
mov eax,-2
jmp fine

tutteUpper:
mov eax,-3

fine:





pop edi
pop esi
pop ebx
mov esp,ebp
pop ebp

ret


_conta_vocali_consonanti endp

contavocali proc
push ebx
push esi
push edi
mov ecx,0

ciclo:
cmp dword ptr[ebx + esi*1],0
je fine
mov al,byte ptr[ebx + esi * 1]
call vocale
add ecx,eax
inc esi
jmp ciclo

fine:
mov eax,ecx

pop edi
pop esi
pop ebx

ret

contavocali endp


vocale proc 

push edi
mov edi,0

cmp al,'a'
je fine
cmp al,'e'
je fine
cmp al,'i'
je fine
cmp al,'o'
je fine
cmp al,'u'
je fine
call vocaleUpper
jmp finefine
fine:
mov edi,1

finefine:
mov eax,edi

pop edi
ret
vocale endp


vocaleUpper proc

cmp al,'A'
je fine
cmp al,'E'
je fine
cmp al,'I'
je fine
cmp al,'O'
je fine
cmp al,'U'
je fine
jmp finefine
fine:
mov edi,1
inc edx

finefine:

ret
vocaleUpper endp

contaconsonanti proc
push ebx
push edi

mov ecx,0


ciclo:
cmp dword ptr[ebx + esi*1],0
je fine
mov al,byte ptr[ebx + esi * 1]
call consonante
add ecx,eax
inc esi
jmp ciclo

fine:
mov eax,ecx

pop edi
pop ebx

ret

contaconsonanti endp

consonante proc 

push edi
mov edi,0
cmp al,'a'
jl fine
cmp al,'z'
jg fine

cmp al,'a'
je fine
cmp al,'e'
je fine
cmp al,'i'
je fine
cmp al,'o'
je fine
cmp al,'u'
je fine
mov edi,1

fine:
call consonanteUpper
mov eax,edi

pop edi
ret
consonante endp


consonanteUpper proc

cmp al,'A'
jl fine
cmp al,'Z'
jg fine

cmp al,'A'
je fine
cmp al,'E'
je fine
cmp al,'I'
je fine
cmp al,'O'
je fine
cmp al,'U'
je fine
inc edx
mov edi,1

fine:


ret
consonanteUpper endp

end