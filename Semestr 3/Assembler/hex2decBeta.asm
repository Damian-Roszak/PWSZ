org 0
mov r0, #0h
mov r1, #0h
mov r2, #0h
mov r3, #0h
mov r4, #0h
mov r5, #0h
mov r6, #0h
mov r7, #0h

mov r0, #02h
mov r1, #70h
mov r4, #0h
mov r5, #0h
mov r6, #0h
mov r7, #0h

; L - 1000
DIV_1000:
mov a, r1
subb a, #0e8h
mov r1, a
mov a, r0
subb a, #03h
mov r0, a
inc r4
jnc DIV_1000

dec r4
mov a, r1
add a, #0e8h
mov r1, a
mov a, r0
addc a, #03h
mov r0, a
clr c
; L - 100
DIV_100:
mov a, r1
subb a, #64h
mov r1, a
mov a, r0
subb a, #00h
mov r0, a
inc r5
jnc DIV_100

dec r5
mov a, r1
add a, #064h
mov r1, a
clr c

; L - 10
DIV_10:
subb a, #0Ah
inc r6
jnc DIV_10

dec r6
add a, #0Ah
mov r1, a
clr c

mov r7, a

end
