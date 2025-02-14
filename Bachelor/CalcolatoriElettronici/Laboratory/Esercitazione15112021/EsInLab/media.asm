.586
.model flat 
.code

_media proc
push ebp
mov ebp,esp
push ebx
push edi
push esi

mov eax,0
mov ebx,dword ptr[ebp + 8]
mov esi,dword ptr[ebp + 12]
mov edi,dword ptr[ebp + 12]
dec esi
ciclosomma:
cmp esi,-1
je finesomma
add eax,dword ptr[ebx + esi*4]
dec esi
jmp ciclosomma


finesomma:
cdq 
idiv edi

mov ecx,dword ptr[ebp + 16]
mov [ecx],edx

pop esi
pop edi
pop ebx
mov esp,ebp
pop ebp 
ret

_media endp


end