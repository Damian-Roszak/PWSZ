#include <stdio.h>
int main(){

char a;
printf ("Podaj znak: ");
scanf ("%c", &a);
int spr_a;
spr_a = a;
int czek = 69;
a = a - 32;
double pi = 3.14159265;
//pi = 3.14159265;
printf ("\n Podany znak to: |%-7.1hd|%-7.1d|%-7.1d| pi = |%.39e|", czek, a, spr_a, pi);

printf ("pi%f,%d", pi, czek = 233.3);

double czek2 = czek;
printf ("\n czek2 = %f \n", czek2);

int I_int = 0x55;
int I_okt = 0351;
printf( "\t I_int = \x55%c|%o|351|%x| \n", I_int, I_okt, I_okt);

enum wylicz {NIE, TAK};
printf ("%d\n", NIE);
printf ("%d\n\'", TAK);

printf ("abc\b\b\b\b\b\b\b\b");
int znaki;
znaki = printf ("abcd");
printf ("ilość znaków = %d", znaki);


printf ("abc\b\b\b\b\b\b\b\babc");


printf("\n");
    char *napis = "\n\x50\x72\x7a\x79\x67\x6f\x64\x79 \x6b\x6f\x74\x61 \x46\x69\x6c\x65\x6d\x6f\x6e\x61 = \n\t=\x69";
printf("%s\n", napis);
return 0;
}
