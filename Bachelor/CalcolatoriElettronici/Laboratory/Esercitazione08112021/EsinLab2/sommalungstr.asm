
.586
.model flat
.code

_sommalungstr proc
push ebp 
mov ebp,esp
push ebx
push edi 
push esi



mov ebx,dword ptr[ebp + 8]
mov esi,0
primastringa:
cmp byte ptr[ebx + esi * 1],0
je fineprimastringa
inc esi
jmp primastringa


fineprimastringa:
mov ebx,dword ptr[ebp + 12]
mov edi,0


secondastringa:
cmp byte ptr[ebx + edi * 1],0
je finesecondastringa
inc edi
jmp secondastringa


finesecondastringa:

add esi,edi
mov eax,esi



pop ebx
pop edi
pop esi
mov esp,ebp 
pop ebp

ret





_sommalungstr endp


end