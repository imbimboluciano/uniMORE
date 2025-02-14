.586
.model flat
.code

_togli_dispari proc

push ebp
mov ebp,esp
push ebx
push edi
push esi

mov ecx,0
mov ebx,dword ptr[ebp + 8]
mov esi,dword ptr[ebp + 12]
dec esi
mov edi,1

call tuttidispari
cmp eax,-1
je fine
call tuttipari
cmp eax,-2
je fine



ciclo:
cmp edi,esi
je fineciclo
mov al,byte ptr[ebx + edi*1]
call dispari
cmp ah,0
je incremento
mov al,byte ptr[ebx + edi-1*1]
call dispari
cmp ah,0
jne incremento
mov al,byte ptr[ebx + edi+1*1]
call dispari
cmp ah,0
jne incremento
inc ecx
call media
mov byte ptr[ebx + edi*1],al


incremento:
inc edi
jmp ciclo





fineciclo:
cmp cl,0
je fine
mov al,cl
call dispari
cmp ah,0
jne fine
mov eax,ecx

fine:

pop esi
pop edi
pop ebx
mov esp,ebp
pop ebp

ret

_togli_dispari endp


dispari proc 
 
push cx
mov cl,2
mov ah,0
div cl

pop cx

ret 

dispari endp


media proc 

push cx
push dx

mov cl,byte ptr[ebx + edi-1*1]
add cl,byte ptr[ebx + edi+1*1]
mov al,cl
mov dl,2

div dl
mov cl,al
call dispari
cmp ah,0
je pari
inc cl

pari:
mov al,cl

pop dx
pop cx


ret
media endp

tuttidispari proc
push edi
push esi
mov edi,-1
mov esi,dword ptr[ebp + 12]
dec esi


ciclo:
cmp esi,-1
je fine
mov al,byte ptr[ebx + esi*1]
call dispari 
cmp ah,0
je pari
dec esi
jmp ciclo

pari:
mov edi,0

fine:
mov eax,edi

pop esi
pop edi
ret
tuttidispari endp


tuttipari proc

push edi
push esi
mov edi,-2
mov esi,dword ptr[ebp + 12]
dec esi


ciclo:
cmp esi,-1
je fine
mov al,byte ptr[ebx + esi*1]
call dispari 
cmp ah,0
jne nonpari
dec esi
jmp ciclo

nonpari:
mov edi,0

fine:
mov eax,edi

pop esi
pop edi
ret

tuttipari endp



end
