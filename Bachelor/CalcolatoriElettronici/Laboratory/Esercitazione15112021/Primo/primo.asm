.586
.model flat
.code

_primo proc

push ebp 
mov ebp,esp
push ebx
push edi
push esi

mov ecx,dword ptr[ebp + 8]
;Gestire casi 1 e 2(banalmente con una compare)
dec cl

ciclo:
cmp cl,1
je fine

mov eax,dword ptr[ebp + 8]
cwd
idiv cl

cmp ah,0
je non_primo
dec cl
jmp ciclo

fine:
mov eax,1
jmp fine2
non_primo:
mov eax,0

fine2:


pop esi
pop edi
pop ebx
mov esp,ebp
pop ebp

ret

_primo endp

end
