.586
.model flat 
.code

_assitoa proc 

push ebp 
mov ebp,esp
push ebx
push esi
push edi

mov ebx,dword ptr[ebp + 8]
mov ecx,dword ptr[ebp + 16]
mov edi,0

cmp src,0
je fine0

call contacifre
call tostring

mov byte ptr[ecx + edi*1],0


fine0:
mov eax,-1

pop edi
pop esi
pop ebx
mov esp,ebp
pop ebp 



ret

_assitoa endp


contacifre proc
push ebx
mov eax,ebx
mov esi,10

ciclo:
cmp eax,0
je fine
cdq
idiv esi
inc edi
jmp ciclo

fine:

pop ebx

ret
contacifre endp

tostring proc
push edi
push ebx
mov eax,ebx
mov esi,10


ciclo:
cmp eax,0
je fine
cdq 
idiv esi
add dl,48
mov byte ptr[ecx + edi-1 * 1],dl
dec edi
jmp ciclo


fine:




pop ebx
pop edi

ret

tostring endp


end