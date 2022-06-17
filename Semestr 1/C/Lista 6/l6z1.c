#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// GOTOWE


char *tab[10];
int N, a=0;
char t = 'n';
char *s;  
int main()
{
  s = malloc(256);     
//char tabl[ ] = "tablica";//char *wskaz = "wskaznik";//char *p;
while(t!='t' && t!='T')
{
a=0;
printf("\n Podaj N: ");
scanf ("%d", &N);    

for (int i=0; i<N; i++)
{
    printf("\n\nPodaj imie nr %d: ", i+1);
   //   scanf("%255s", s);// tab[i] = malloc(strlen(s));  strncat(tab[i], s, strlen(s));
     tab[i] = malloc(256);
    scanf("%255s", tab[i]);
//    strncat(tab[i], s, strlen(s));
   // printf(" wczytane imie to: %s", tab[i]);
   if(*(tab[i]+strlen(tab[i])-1)=='a')printf("\n *(tab[i]+strlen(tab[i])-1)= %c",*(tab[i]+(strlen(tab[i])-1)));
    s = tab[i];
    printf("\n ostatni znak tego imienia to: %c", s[strlen(s)-1] );
   if(s[strlen(s)-1] == 'a')a++;
    printf("\n długość tab to: %ld", strlen(tab[i]) );
    printf("\n ostatni znak tab to: %c", *(tab[i]+strlen(tab[i])-1) );
    
stdin = freopen (NULL, "r", stdin);
}

printf("\n\n\t Imion kończących się na 'a' jest= %d", a);

    printf("\n\nWczytane imiona: \n");
for (int i=0; i<N; i++)
{
    printf("\nWczytane imie nr %d: %s", i+1, tab[i]);
}



/*
printf("tabl %s\n", tabl);
printf("wskaz %s\n", wskaz);
printf("tabl[0] %c\n", tabl[0]);
printf("&tabl[0] %s\n", &tabl[0]);
printf("tabl+3 %s\n", tabl+3);
printf("wskaz[4] %c\n", wskaz[4]);
printf("*(wskaz+4)%c\n", *(wskaz+4));
printf("wskaz+4 %s\n", wskaz+4);
p = tabl;
printf(" p %s\n", p);
p = wskaz;
printf(" p%s\n", p);
*/


   // printf("enter the string : ");
   // scanf("%255s", s);
   // printf("you entered %s[\n", s);





stdin = freopen (NULL, "r", stdin);
printf("\nZakończyć? [t/n]: ");
scanf("%c", &t);
stdin = freopen (NULL, "r", stdin);
}
return 0;
}
