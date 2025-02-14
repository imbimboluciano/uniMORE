.586
.model flat
.code

_salvaparolaspiazzamento proc

push ebp
mov ebp,esp
push ebx
push esi
push edi

mov bx,00fch

mov ebx,dword ptr[ebp + 8]
mov ecx,dword ptr[ebp + 12]
mov edx,dword ptr[ebp + 16]
mov esi,0

ciclo:
mov edi,0
cmp byte ptr[ebx + esi*1],0
je fine
call trovaparola
cmp eax,0
je spazi
call copiaparola
mov edi,0
jmp ciclo

spazi:
cmp edi,0
jl ciclo
mov byte ptr[ecx + esi*1],' '
dec edi
inc esi
jmp spazi

fine:
mov eax,0
mov byte ptr[ecx + esi*1],0



pop edi
pop esi
pop ebx
mov esp,ebp
pop ebp

ret

_salvaparolaspiazzamento endp


trovaparola proc
push esi

ciclo:
cmp byte ptr[edx + edi*1],0
je fine
mov al,byte ptr[ebx + esi*1]
cmp al,byte ptr[edx + edi*1]
jne no
inc edi
inc esi
jmp ciclo

no:
mov eax,0
jmp finefine

fine:
mov eax,1

finefine:


pop esi
ret

trovaparola endp



copiaparola proc
push ebx
mov ebx,0

ciclo:
cmp ebx,edi
je fine
mov al,byte ptr[edx + ebx*1]
mov byte ptr[ecx + esi*1],al
inc ebx
inc esi
jmp ciclo


fine:

pop ebx
ret
copiaparola endp




end