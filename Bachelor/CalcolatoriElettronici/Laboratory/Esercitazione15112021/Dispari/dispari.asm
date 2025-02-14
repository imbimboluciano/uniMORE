.586
.model flat 
.code

_dispari proc
push ebp
mov ebp,esp
push ebx
push edi
push esi

mov ax,word ptr[ebp + 8]
mov cx,2
cwd

div cx
cmp dx,0
je pari
mov eax,1
jmp fine

pari:
mov eax,0

fine:




pop esi
pop edi
pop ebx
mov esp,ebp
pop ebp

ret

_dispari endp

end