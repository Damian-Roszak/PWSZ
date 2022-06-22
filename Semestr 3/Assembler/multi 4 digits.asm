;1298*5669=7 358 362
;4-cyfrowa liczba X4-X3-X2-X1
mov r0, #098h; # 0 X2 X1 h
mov r1, #012h; # 0 X4 X3 h
;4-cyfrowa liczba Y4-Y3-Y2-Y1
mov r2, #069h; # 0 Y2 Y1 h
mov r3, #056h; # 0 Y4 Y3 h
;8-cyfrowa W8-W7-W6-W5-W4-W3-W2-W1
mov r4, #00h; # 0 W2 W1 h
mov r5, #00h; # 0 W4 W3 h
mov r6, #00h; # 0 W6 W5 h
mov r7, #00h; # 0 W8 W7 h

mov 00Ah, #000h;Y1_cyfra
mov 00Bh, #000h;Y2_cyfra
mov 00Ch, #000h;Y3_cyfra
mov 00Dh, #000h;Y4_cyfra
mov 00Eh, #000h;pomocniczy1
mov 00Fh, #000h;pomocniczy2
;wrzuc Y1 do Y1_cyfra
mov A,r2
mov B,#16
div AB
mov 00Ah,B
;wrzuc Y3 do Y3_cyfra
mov A,r3
mov B,#16
div AB
mov 00Ch,B
;wrzuc Y2 do Y2_cyfra
mov A,r2
mov B,#16
div aB
mov 00Bh,A
;wrzuc Y4 do Y4_cyfra
mov A,r3
mov B,#16
div AB
mov 00Dh,A

;1) kazda Y razy X1
;X1 do pomocniczego1
mov A,r0
mov B,#16
div AB
mov 00Eh,B
;---X1*Y1---
;Y1 do B
mov B,00Ah
;X1 do A
mov A,00Eh
;X1*Y1 w hex
mul AB
;zapisz dec wynik X1*Y1
;przedial 0-99 dlatego trzeba
;wyciagnac pierwsza a potem druga
;cyfre i dodac do rejestru z wynikiem
mov B,#10
div AB;A to dziesiatki B to jednosci
xch A,B;zamien A z B
	;ostateczne W1
	add A,r4
	mov r4,A
xch A,B;A to dziesiatki
	;nowe W2
	mov B,#16
	mul AB
	addc A,r4
	mov r4,A
;---X1*Y2---
;Y2 do B
mov B,00Bh
;X1 do A
mov A,00Eh
;X1*Y2 w hex
mul AB
;zapisz dec wynik X1*Y2
mov B,#10
div AB;A to dziesiatki B to setki
xch A,B;zamien A z B
mov 00Fh,B;setki w pomocniczy2
	;nowe W2
	mov B,#16
	mul AB
	add A,r4
	da A
	mov r4,A
	;ewentualne setki do W3
	mov A,r5
	addc A,#0
	mov r5,A
xch A, 00Fh;A to setki
	;nowe W3
	addc A,r5
	mov r5,A
;---X1*Y3---
;Y3 do B
mov B,00Ch
;X1 do A
mov A,00Eh
;X1*Y3 w hex
mul AB
;zapisz dec wynik X1*Y3
mov B,#10
div AB;A to setki B to tysiace
xch A,B;zamien A z B
mov 00Fh,B;tysiace w pomocniczy2
	;nowe W3
	addc A,r5
	da A
	mov r5,A
xch A, 00Fh;A to tysiace
	;nowe W4
	mov B,#16
	mul AB
	addc A,r5
	da A
	mov r5,A
		;ile jeszcze ʘ‿ʘ
;---X1*Y4---
;Y4 do B
mov B,00Dh
;X1 do A
mov A,00Eh
;X1*Y4 w hex
mul AB
;zapisz dec wynik X1*Y4
mov B,#10
div AB;A to tys B to dzies tys
xch A,B;zamien A z B
mov 00Fh,B;dzies tys w pomocniczy2
	;nowe W4
	mov B,#16
	mul AB
	addc A,r5
	da A
	mov r5,A
xch A, 00Fh;A to dzies tys
	;nowe W5
	addc A,r6
	da A
	mov r6,A

;2) kazda Y razy X2
;X2 do pomocniczego1
mov A,r0
mov B,#16
div AB
mov 00Eh,A
;---X2*Y1---
;Y1 do B
mov B,00Ah
;X2 do A
mov A,00Eh
;X2*Y1 w hex
mul AB
;zapisz dec wynik X2*Y1
mov B,#10
div AB;A to setki B to dziesiatki
mov 00Fh, A;setki w pomocniczy2
xch A,B;zamien A z B
	;ostateczne W2
	mov B,#16
	mul AB
	add A,r4
	da A
	mov r4,A
	;ewentualne setki do W3
	mov A,r5
	addc A,#0
	da A
	mov r5,A
	;ewentualne dzies tys do W5
	mov A,r6
	addc A,#0
	da A
	mov r6,A
mov A,00Fh;A to setki
	;nowe W3
	addc A,r5
	da A
	mov r5,A
;---X2*Y2---
;Y2 do B
mov B,00Bh
;X2 do A
mov A,00Eh
;X2*Y2 w hex
mul AB
;zapisz dec wynik X2*Y2
mov B,#10
div AB;A to tysiace B to setki
mov 00Fh, A;tysiace w pomocniczy2
xch A,B;zamien A z B
	;nowe W3
	addc A,r5
	da A
	mov r5,A
xch A,B;A to tysiace
	;nowe W4
	mov B,#16
	mul AB
	addc A,r5
	da A
	mov r5,A
	;ewentualne dzies tys do W5
	mov A,r6
	addc A,#0
	mov r6,A
;---X2*Y3---
;Y3 do B
mov B,00Ch
;X2 do A
mov A,00Eh
;X2*Y3 w hex
mul AB
;zapisz dec wynik X2*Y3
mov B,#10
div AB;A to dzies tys B to tysiace
mov 00Fh, A;dzies tys w pomocniczy2
xch A,B;zamien A z B
	;nowe W4
	mov B,#16
	mul AB
	addc A,r5
	da A
	mov r5,A
	;ewentualne dzies tys do W5
	mov A,r6
	addc A,#0
	mov r6,A
mov A,00Fh;A to dzies tys
	;nowe W5
	addc A,r6
	da A
	mov r6,A
;---X2*Y4---
;Y4 do B
mov B,00Dh
;X2 do A
mov A,00Eh
;X2*Y4 w hex
mul AB
;zapisz dec wynik X2*Y4
mov B,#10
div AB;A to set tys B to dzies tys
mov 00Fh, A;set tys w pomocniczy2
xch A,B;zamien A z B
	;nowe W5
	add A,r6
	da A
	mov r6,A
mov A,00Fh;A to set tys
	;nowe W6
	mov B,#16
	mul AB
	addc A,r6
	da A
	mov r6,A

;1) kazda Y razy X3
;X3 do pomocniczego1
mov A,r1
mov B,#16
div AB
mov 00Eh,B
;---X3*Y1---
;Y1 do B
mov B,00Ah
;X3 do A
mov A,00Eh
;X3*Y1 w hex
mul AB
;zapisz dec wynik X3*Y1
mov B,#10
div AB;A to tysiace B to setki
mov 00Fh, A;tysiace w pomocniczy2
xch A,B;zamien A z B
	;ostateczne W3
	addc A,r5
	da A
	mov r5,A
	;ewentualne dzies tys do W5
	mov A,r6
	addc A,#0
	da A
	mov r6,A
mov A,00Fh;A to tysiace
	;nowe W4
	mov B,#16
	mul AB
	addc A,r5
	da A
	mov r5,A
	;ewentualne dzies tys do W5
	mov A,r6
	addc A,#0
	da A
	mov r6,A
	;ewentualne mln do W7
	mov A,r7
	addc A,#0
	da A
	mov r7,A
;---X3*Y2---
;Y2 do B
mov B,00Bh
;X3 do A
mov A,00Eh
;X3*Y2 w hex
mul AB
;zapisz dec wynik X3*Y2
mov B,#10
div AB;A to dzies tys B to tys
xch A,B;zamien A z B
mov 00Fh,B;dzies tys w pomocniczy2
	;nowe W4
	mov B,#16
	mul AB
	addc A,r5
	da A
	mov r5,A
	;ewentualne dzies tys do W5
	mov A,r6
	addc A,#0
	da A
	mov r6,A
	;ewentualne mln do W7
	mov A,r7
	addc A,#0
	da A
	mov r7,A
mov A, 00Fh;A to dzies tys
	;nowe W5
	addc A,r6
	da A
	mov r6,A
	;ewentualne mln do W7
	mov A,r7
	addc A,#0
	da A
	mov r7,A
;---X3*Y3---
;Y3 do B
mov B,00Ch
;X3 do A
mov A,00Eh
;X3*Y3 w hex
mul AB
;zapisz dec wynik X3*Y3
mov B,#10
div AB;A to setki tys B to dzies tys
xch A,B;zamien A z B
mov 00Fh,B;setki tys w pomocniczy2
	;nowe W5
	addc A,r6
	da A
	mov r6,A
	;ewentualne mln do W7
	mov A,r7
	addc A,#0
	da A
	mov r7,A
xch A, 00Fh;A to setki tys
	;nowe W6
	mov B,#16
	mul AB
	addc A,r6
	da A
	mov r6,A
	;ewentualne mln do W7
	mov A,r7
	addc A,#0
	da A
	mov r7,A
;---X3*Y4---
;Y4 do B
mov B,00Dh
;X3 do A
mov A,00Eh
;X3*Y4 w hex
mul AB
;zapisz dec wynik X3*Y4
mov B,#10
div AB;A to mln B to setki tys
xch A,B;zamien A z B
mov 00Fh,B;mln w pomocniczy2
	;nowe W6
	mov B,#16
	mul AB
	addc A,r6
	da A
	mov r6,A
	;ewentualne mln do W7
	mov A,r7
	addc A,#0
	da A
	mov r7,A
xch A, 00Fh;A to mln
	;nowe W7
	addc A,r7
	da A
	mov r7,A

;2) kazda Y razy X4
;X4 do pomocniczego1
mov A,r1
mov B,#16
div AB
mov 00Eh,A
;---X4*Y1---
;Y1 do B
mov B,00Ah
;X4 do A
mov A,00Eh
;X4*Y1 w hex
mul AB
;zapisz dec wynik X4*Y1
mov B,#10
div AB;A to dzies tys B to tys
mov 00Fh, A;dzies tys w pomocniczy2
xch A,B;zamien A z B
	;ostateczne W4
	mov B,#16
	mul AB
	add A,r5
	da A
	mov r5,A
	;ewentualne dzies tys do W5
	mov A,r6
	addc A,#0
	da A
	mov r6,A
	;ewentualne mln do W7
	mov A,r7
	addc A,#0
	da A
	mov r7,A
mov A,00Fh;A to dzies tys
	;nowe W5
	addc A,r6
	da A
	mov r6,A
	;ewentualne mln do W7
	mov A,r7
	addc A,#0
	da A
	mov r7,A
;---X4*Y2---
;Y2 do B
mov B,00Bh
;X4 do A
mov A,00Eh
;X4*Y2 w hex
mul AB
;zapisz dec wynik X4*Y2
mov B,#10
div AB;A to setki tys B to dzies tys
mov 00Fh, A;setki tys w pomocniczy2
xch A,B;zamien A z B
	;nowe W5
	addc A,r6
	da A
	mov r6,A
	;ewentualne mln do W7
	mov A,r7
	addc A,#0
	da A
	mov r7,A
xch A,B;A to setki tys
	;nowe W6
	mov B,#16
	mul AB
	addc A,r6
	da A
	mov r6,A
	;ewentualne mln do W7
	mov A,r7
	addc A,#0
	da A
	mov r7,A
;---X4*Y3---
;Y3 do B
mov B,00Ch
;X4 do A
mov A,00Eh
;X4*Y3 w hex
mul AB
;zapisz dec wynik X4*Y3
mov B,#10
div AB;A to mln B to setki tys
mov 00Fh, A;mln w pomocniczy2
xch A,B;zamien A z B
	;nowe W6
	mov B,#16
	mul AB
	addc A,r6
	da A
	mov r6,A
	;ewentualne mln do W7
	mov A,r7
	addc A,#0
	da A
	mov r7,A
mov A,00Fh;A to mln
	;nowe W5
	addc A,r7
	da A
	mov r7,A
;---X4*Y4---
;Y4 do B
mov B,00Dh
;X4 do A
mov A,00Eh
;X4*Y4 w hex
mul AB
;zapisz dec wynik X4*Y4
mov B,#10
div AB;A to dzies mln B to mln
mov 00Fh, A;dzies mln w pomocniczy2
xch A,B;zamien A z B
	;nowe W7
	add A,r7
	da A
	mov r7,A
mov A,00Fh;A to dzies mln
	;nowe W8
	mov B,#16
	mul AB
	addc A,r7
	da A
	mov r7,A