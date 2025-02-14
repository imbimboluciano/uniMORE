
.586
.model flat
.code


_numeroprimo proc
push ebp
mov ebp,esp
push ebx
push edi 
push esi

mov ebx,dword ptr[ebp + 8]
mov ecx,1
mov edi,0
mov edx,1
ciclo:
cmp ecx,ebx
jg fine
call resto
cmp eax,0
jne incremento
inc edi


incremento:
inc ecx
jmp ciclo





fine:
cmp edi,3
jge nonprimo 
jmp finefine

nonprimo:
mov edx,0


finefine:
mov eax,edx


pop esi
pop edi
pop ebx
mov esp,ebp
pop ebp


ret



_numeroprimo endp


resto proc

push ebx
push ecx

ciclo:
cmp ebx,ecx
jl fine
sub ebx,ecx
jmp ciclo

fine:
mov eax,ebx

pop ecx
pop ebx
ret


resto endp

end