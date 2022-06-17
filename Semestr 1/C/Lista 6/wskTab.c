#include <stdio.h>

#define SIZE 5
int main (void)
{
/*
int x = 10, y, *wsk_x, *w2;
wsk_x = &x;
w2 = wsk_x;
printf("wsk_x:\t%p\t*wsk_x %d\n", wsk_x, *wsk_x);
printf("&x: \t%p\tx: %d\n", &x, x);
*wsk_x = 15;
y = x;
printf("&x: \t%p\tx: %d\n", &x, x);
printf("&y: \t%p\ty: %d\n", &y, y);
*wsk_x += 10;
printf("&x: \t%p\t x:%d\n", &x, x);
++*wsk_x;
printf("wsk_x:\t%p\t*wsk_x %d\n", wsk_x, *wsk_x);
(*wsk_x)++;
printf("wsk_x: \t%p\t*wsk_x %d\n", wsk_x, *wsk_x);
*wsk_x++;
printf("wsk_x: \t%p\t*wsk_x %d\n", wsk_x, *wsk_x);
printf("w2: \t%p\t*w2 %d\n", w2, *w2);


printf("\n");printf("\n");printf("\n");
int tab1[] = {8, 4, 3, 9, 1, 1, 23, 2, 11, 23};
int i;
int *wsk;
wsk = tab1; // wsk = &tab[0] 
for (i = 0; i < sizeof (tab1) / sizeof (tab1[0]); i++)
printf("%d ", *(tab1+i)); //printf("%d ", *(wsk+i));
printf("\n");


int i, *wsk;// , SIZE =5;
int tab[SIZE] = {3, 4, 5, 1, 2};
wsk = tab;
for (i = 0; i < SIZE; i++)
printf("%d ", *(wsk+i));
printf("Wskaznik jest pod adresem: %p\n", wsk);
for (i = 0; i < SIZE; i++)
printf("%d ", *(tab+i));
printf("Wskaznik jest pod adresem: %p\n", tab);
for (i = 0; i < SIZE; i++)
printf("LOL Wskaznik jest %d pod adresem: %d\n",i, *wsk+i);
printf("%d ", *wsk+i);

//for (i = 0; i < SIZE; i++)
//printf("%d ", *tab++);
// Blad
printf("TU Wskaznik jest pod adresem: %p\n", tab);


int MAX=100, tab[MAX];
int *w1, *w2, *w3;
w1 = &tab[MAX-1];
w2 = tab;
if (w2 > w1)
printf("w2 jest wskaznikiem do dalszego elementu\n");
else
{
printf("w2 jest wskaznikiem do blizszego elementu\n");
w3 = NULL;
}
if (w3 == NULL)
printf("Roznica wskaznikow: %ld\n", (w1-w2));
*/


int i;
char *wk = "Muzyka";
char tab[7] = "Strefa";
char tab2[7] = {'S', 't', 'r', 'e', 'f', 'a', '\0'};
printf("wk: \t\t%s\n", wk);
printf("tab: \t\t%s\n", tab);
printf("tab2: \t\t%s\n", tab2);
printf("wk[1]: \t\t%c\n", wk[1]);

printf("wk+1: \t\t%c\n", *(wk+1));
*(wk+1) = 'U';
printf("wk: \t\t%s\n", wk);
// wk[1] = 'U';
// Segmentation fault
wk = tab;
printf("wk: \t\t%s\n", wk);
for (i = 0; i < sizeof (tab)/sizeof (tab[0]); i++)
if (tab[i] == 'e') tab[i] = 'E';

printf("tab: \t\t%s\n", tab);
// tab = wk;
// Blad









return 0;
}
