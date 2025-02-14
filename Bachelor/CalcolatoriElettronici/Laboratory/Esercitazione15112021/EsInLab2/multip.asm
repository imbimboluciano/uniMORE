.586
.model flat 
.code

_multip proc
push ebp
mov ebp,esp
push ebx
push edi
push esi


mov eax,dword ptr[ebp + 8]
mov ebx,dword ptr[ebp + 12]

imul bx

mov ecx,0

shl edx,16
add ecx,edx
mov cx,ax

mov eax,ecx

pop esi
pop edi
pop ebx
mov esp,ebp
pop ebp



_multip endp

end