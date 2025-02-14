.586
.model flat
.code


_sommalunghezzastringhe proc 

push ebp 
mov ebp,esp
push ebx
push edi 
push esi

mov ebx,dword ptr[ebp + 8]
call strlen
mov ecx,esi
mov ebx,dword ptr[ebp + 12]
call strlen
add ecx,esi
mov eax,ecx


pop esi
pop edi 
pop ebx
mov esp,ebp
pop ebp

ret



_sommalunghezzastringhe endp


strlen proc 

mov esi,0

ciclo:
cmp byte ptr[ebx + esi*1],0
je fine
inc esi 
jmp ciclo

fine:

ret

strlen endp

end