#include<stdio.h>
#include<math.h>

int main(){

// printf ("drukowanie tablicy ASCII: \n");
//for (int i=0; i<=127; i++) printf ("znak %d = %c \t", i, i); 


printf ("\n Lista 2 \n");
printf ("\n Zadanie 1 \n");
char znak;
printf ("\n Podaj znak: ");
scanf ("%c", &znak);
printf ("\n Podany znak liczbowo: %d", znak);

int CtoI;
CtoI = znak;
printf ("\n CtoI: %d\n", CtoI);

if (znak >= 65 && znak <= 90) printf ("Podany znak to: %c, w formie małej litery: %c, w formie dużej litery %c", znak, znak+32, znak);

if (znak >=97 && znak <=122 ) printf ("Podany znak to: %c, w formie małej litery: %c, w formie dużej litery: %c", znak, znak, znak-32);

printf ("\n\n\n");

printf (" wersja z konwersją char na int \n ");

if ( CtoI >= 65 && CtoI <= 90 ) printf ("Podany znak to: %c, w formie małej litery: %c, w formie dużej litery %c", CtoI, CtoI+32, CtoI);  

if ( CtoI >= 97 && CtoI <= 122 ) printf ("Podany znak to: %c, w formie małej litery: %c, w formie dużej litery: %c", CtoI, CtoI, CtoI-32);



printf ("\n Zadanie 2 Sprawdzanie parzystości \n");
int l1, l2, l3;
printf ("Podaj 3 liczby: ");
scanf ("%d  %d  %d", &l1, &l2, &l3);

if ( l1 % 2 == 0 ) printf ("\n %d jest parzysta ", l1);
if ( l2 % 2 == 0 ) printf ("\n %d jest parzysta ", l2);
if ( l3 % 2 == 0 ) printf ("\n %d jest parzysta ", l3);

if ((l1 % 2 == 0) || (l2 % 2 == 0) || (l3 % 2 == 0)) printf ("\n jest parzysta ");
else printf ("\n %d jest parzysta ", l3);







printf ("\n Zadanie 3 \n");
int I1,I2,I3;
printf (" Podaj 3 liczby: ");
scanf ("%d %d %d", &I1, &I2, &I3);

printf ("l1 = %d, l2 = %d, l3 = %d", I1, I2,I3);

int k1,k2,k3;
k1 = I1 * I1;
k2 = I2 * I2;
k3 = I3 * I3;

printf ("\nl1 = %d, l2 = %d, l3 = %d", k1, k2,k3);

if ((k1 <= k2) && (k1 <= k3)) printf ( "\n %d ma najmniejszy kwadrat", I1);
if ((k2 <= k1) && (k2 <= k3)) printf ( "\n %d ma najmniejszy kwadrat", I2);
if ((k3 <= k2) && (k3 <= k1)) printf ( "\n %d ma najmniejszy kwadrat", I3);











printf ("\n Zadanie 4 \n");

int z4i1, z4i2, z4i3, z4i4, z4i5, m;

printf ("Wersja na if'ach, sprawdza wszystkie po kolei\n");


printf ("Podaj 5 liczb: ");
scanf ("%d %d %d %d %d", &z4i1, &z4i2, &z4i3, &z4i4, &z4i5);

if ((z4i1 <= z4i2) && (z4i1<= z4i3) && (z4i1 <= z4i4) && (z4i1 <= z4i5)) printf ("\n Najmniejsza jest %d", z4i1);
else if ((z4i2 <= z4i1) && (z4i2 <= z4i3) && (z4i2 <= z4i4) && (z4i2 <= z4i5)) printf ("\n Najmniejsza jest %d", z4i2);
else if ((z4i3 <= z4i2) && (z4i3 <= z4i1) && (z4i3 <= z4i4) && (z4i3 <= z4i5)) printf ("\n Najmniejsza jest %d", z4i3);
else if ((z4i4 <= z4i2) && (z4i4 <= z4i3) && (z4i4 <= z4i1) && (z4i4 <= z4i5)) printf ("\n Najmniejsza jest %d", z4i4);
else if ((z4i5 <= z4i2) && (z4i5 <= z4i3) && (z4i5 <= z4i4) && (z4i5 <= z4i1)) printf ("\n Najmniejsza jest %d", z4i5);



printf ("\n\nWersja z zmienną pomocniczną m\n");

printf ("Podaj 5 liczb: ");
scanf ("%d %d %d %d %d", &z4i1, &z4i2, &z4i3, &z4i4, &z4i5);

m = z4i1;

printf ("\n opcja z warunkiem typu 'm > zmienna_pomocnicza' \n");

if (m > z4i2) m = z4i2; printf ("\n 1 m= %d", m);
if (m > z4i3) m = z4i3; printf ("\n 2 m= %d", m);
if (m > z4i4) m = z4i4; printf ("\n 3 m= %d", m);
if (m > z4i5) m = z4i5; printf ("\n 4 m= %d", m);

printf ("\n Najmniejsza jest %d", m);

printf ("\n opcja z warunkiem typu 'zmienna_pomocnicza < m' \n");

if (z4i2 < m) m = z4i2; printf ("\n 1 m= %d", m);
if (z4i3 < m) m = z4i3; printf ("\n 2 m= %d", m);
if (z4i4 < m) m = z4i4; printf ("\n 3 m= %d", m);
if (z4i5 < m) m = z4i5; printf ("\n 4 m= %d", m);

printf ("\n Najmniejsza jest %d", m);


int itab[5], pom;

printf ("\n Opcja na tablicy i pętli for \n");

printf ("\n Podaj elementy tablicy: ");
scanf ("%d %d %d %d %d", &itab[0], &itab[1], &itab[2], &itab[3], &itab[4]);

pom = itab[0];
for (int i=1; i<=4; i++) if (pom > itab[i]) pom = itab[i];
printf ("\n Najmniejszy element to: %d", pom);


printf ("\n Opcja na tablicy i pętli while \n");

printf ("\n Podaj elementy tablicy: ");
scanf ("%d %d %d %d %d", &itab[0], &itab[1], &itab[2], &itab[3], &itab[4]);

pom = itab[0];
int licznikWhilea = 1;
while (licznikWhilea!=5) {
     if (pom > itab[licznikWhilea]) pom = itab[licznikWhilea];
     licznikWhilea++;
    };
printf ("\n Najmniejszy element to: %d", pom);


printf ("\n Opcja na tablicy i pętli do...while \n");

printf ("\n Podaj elementy tablicy: ");
scanf ("%d %d %d %d %d", &itab[0], &itab[1], &itab[2], &itab[3], &itab[4]);

pom = itab[0];
int licznikDoWhilea = 1;
 do {
     if (pom > itab[licznikDoWhilea]) pom = itab[licznikDoWhilea];
     licznikDoWhilea++;
    }
 while (licznikDoWhilea!=5);
printf ("\n Najmniejszy element to: %d", pom);












printf ("\n Zadanie 5 \n");
int liczba;
printf (" Podaj liczbę wersja z setkami dla tysięcy i więcej: ");
scanf ("%d", &liczba);
if (liczba<=99) printf ("Do operacji wymagana jest liczba większa od 99");
else printf (" Jedności: %d\t, dziesiątki: %d\t, setki: %d", liczba%10,(liczba%100)/10,liczba/100 );


printf (" \n wersja tylko z setkami: ");
//scanf ("%d", &liczba);
if (liczba<=99) printf ("Do operacji wymagana jest liczba większa od 99");
else printf ("\n Jedności: %d\t, dziesiątki: %d\t, setki: %d\n", liczba%10,(liczba%100)/10,(liczba/100)%10 );












printf ("\n Zadanie 6 \n ");
printf ("Podaj liczbę: ");
int lz6, lc6;
scanf ("%d", &lz6);
printf ("\n pierwiastek wynosi = %f", sqrt(lz6));
lc6 = sqrt(lz6);
if (lc6 == sqrt(lz6)) printf ("\n %d jest liczbą kwadratową", lz6);
else printf ("\n opcja 2 lc6 = %d", lc6);



printf ("\n");
return 0;
}
