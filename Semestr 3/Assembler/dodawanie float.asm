;wynik dodawania 
;(02Ah,02Bh,02Ch)
;(matysa, mantysa, cecha)
;------------------------

;liczba temp 
mov r6, #0;mantysa1
mov r7, #0;mantysa2 (mlodsze bity)
mov 018h,#0; cecha

;liczba 1
mov 01Fh, #0;znak +(0) / -(1)
mov 010h, #0
mov 011h, #4
mov 012h, #0
mov 013h, #9
mov 014h, #7

mov 00Ah, #0;mantysa1
mov 00Bh, #0;mantysa2 (mlodsze bity)
mov 00Ch, #0; cecha

;liczba 2
mov 02Fh, #0;znak +(0) / -(1)
mov 020h, #0
mov 021h, #1
mov 022h, #9
mov 023h, #5
mov 024h, #1

mov 01Ah, #0;mantysa1
mov 01Bh, #0;mantysa2 (mlodsze bity)
mov 01Ch, #0; cecha

mov 07Eh, #0;temp1
mov 07Fh, #0;temp2


;-------------------------

;zamien pierwsza
mov 00Fh, 01Fh;znak +(0) / -(1)
mov r0, 010h
mov r1, 011h
mov r2, 012h
mov r3, 013h
mov r4, 014h

call zamienNaHex
call ustawMantyse
call wstawZnak

mov 00Ah, r6;mantysa1
mov 00Bh, r7;mantysa2 (mlodsze bity)
mov 00Ch, 018h; cecha

;zamien druga
mov 018h, #0; cecha
mov 00Fh, 02Fh;znak +(0) / -(1)
mov r0, 020h
mov r1, 021h
mov r2, 022h
mov r3, 023h
mov r4, 024h

call zamienNaHex
call ustawMantyse
call wstawZnak

mov 01Ah, r6;mantysa1
mov 01Bh, r7;mantysa2 (mlodsze bity)
mov 01Ch, 018h; cecha


;---------------------------

;call zrownajMantysy
;call dodajFloat
;zapisz wynik
mov 02Ah, r6;mantysa1
mov 02Bh, r7;mantysa2 (mlodsze bity)
mov 02Ch, 018h; cecha

jmp KONIEC

;------------

;--------------------
wstawZnak:
mov A,r6
jz zEnd;koniec gdy A == 0
subb A,#128;wyrzuc najstarszy bit
mov r6,A

mov A,00Fh
jz zEnd;koniec gdy A == 0
mov A,#128
add A,r6;dodaj 1 na najstarszym bicie
mov r6,A
zEnd:
ret
;------------
ustawMantyse:
clr C

mStart:
mov B, #128
mov A, r6
div AB;A = najstarszy bit

jnz mEnd;koniec gdy A != 0

inc 018h;cecha++

mov A, r6
rlc A
mov r6, A;r6 1bit w lewo

mov A, r7
rlc A
mov r7, A;r7 1bit w lewo

mov A, r6
addc A, #0
mov r6, A;pozostaly bit(flaga C)

jmp mStart; sprawdz jeszcze raz

mEnd:
;koncowa cecha
CLR C
mov A, #15
subb A,018h
mov 018h,A
ret
;-----------
zamienNaHex:
mov A,r0
mov B,#10
mul AB;r0*10

add A,r1;r0*10+r1

mov B,#10
mul AB
mov 07Eh,B
mov 07Fh,A;(r0*10+r1)*10

add A,r2
mov 07Fh,A
mov A,07Eh
addc A,#0
mov 07Eh,A;((r0*10+r1)*10)+r2

mov B,#10
mov A,07Fh
mul AB
mov r7,A
mov r6,B
mov B,#10
mov A,07Eh
mul AB
add A,r6
mov r6,A
mov A,B
addc A,#0
mov 07Fh,A;(((r0*10+r1)*10)+r2)*10

mov A,r7
add A,r3
mov r7,A
mov A,r6
addc A,#0
mov r6,A
mov A,07Fh
addc A,#0
mov 07Fh,A;(((r0*10+r1)*10)+r2)*10+r3

mov B,#10
mov A,r7
mul AB
mov r7,A
mov 07Eh,B
mov B,#10
mov A,r6
mul AB
mov r6,A
mov A,07Eh
add A,r6
mov r6,A;((...)*10+r3)*10

mov A,r7
add A,r4
mov r7,A
mov A,r6
addc A,#0
mov r6,A
mov A,07Fh
addc A,#0
mov 07Fh,A;((...)*10+r3)*10+r4
ret

KONIEC:
;zapisz mantysy liczb 1 i 2
mov 06Ah,00Ah
mov 06Bh,00Bh
mov 07Ah,01Ah
mov 07Bh,01Bh

mov r0,00Ch
mov r1,01Ch
mov a,r1
subb a,r0
jnc sprawdzanie2;jezeli r0 <= r1
cjne a,#00,wiekszyR0;jezeli a!=0
sprawdzanie2:
cjne a,#00,wiekszyR1;r0 < r1
jmp rowne; r0 == r1
;------------------------------------
wiekszyR0:
mov r2,01Ah
mov r3,01Bh
mov 02Ch,r0
lcall wyrownanie;
mov 01Ah,r2
mov 01Bh,r3
lcall dodawanie
jmp checkResult

wiekszyR1:
mov r0,01Ch
mov r1,00Ch
mov r2,00Ah
mov r3,00Bh
mov 02Ch,r0
lcall wyrownanie;
mov 00Ah,r2
mov 00Bh,r3
lcall dodawanie
jmp checkResult

rowne:
lcall dodawanie
jmp normalizacja
;------------------------------------
;====================================
wyrownanie:
mov a,r0
subb a,r1
mov r0,a
inc r0
mov r1,#40h;to jest 1 domyslne
przesuniencie:
dec r0

cjne r0,#00,dalej
ret
dalej:

mov a,r2
rrc a
mov r2,a
mov a,r3
rrc a
mov r3,a

mov a,r2;dodanie 1 domyslnej
add a,r1
mov r2,a
mov r1,#00h;zerowanie 1 domyslnej
		   ;zeby nie dodawala sie
		   ;kazdego razu
jmp przesuniencie
;------------------------------------
dodawanie:
mov r0,00Bh;	r1 r0
mov r1,00Ah;   +
mov r2,01Bh;	r3 r2
mov r3,01Ah;	-----
;				r5 r4
mov a,r0
add a,r2
mov r4,a
mov a,r1
addc a,r3
mov r5,a
mov 02Ah,r5
mov 02Bh,r4

;przywroc mantysy liczb 1 i 2
mov 00Ah,06Ah
mov 00Bh,06Bh
mov 01Ah,07Ah
mov 01Bh,07Bh
mov 06Ah,#0
mov 06Bh,#0
mov 07Ah,#0
mov 07Bh,#0
ret
;------------------------------------
checkResult:
mov a,02Ah
jb acc.7,normalizacja
ending:
jmp ending
;------------------------------------

normalizacja:
mov r0,02Ch
mov r1,02Bh
mov r2,02Ah

mov a,r2
rrc a
mov 02Ah,a
mov a,r1
rrc a
mov 02Bh,a
inc r0
mov 02Ch,r0
jmp ending
