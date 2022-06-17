#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char tab[10][100];
int N=2, a=0;
char t = 'n';
char *s;  
int main()
{
 
a=0;
//printf("\n Podaj N: ");
//scanf ("%d", &N);    

for (int i=0; i<N; i++)
{
    printf("\n\nPodaj imie nr %d: ", i+1);
  
    scanf("%255s", tab[i]);
   if((tab[i][strlen(tab[i])-1])=='a')
    printf("\n (tab[i]+strlen(tab[i])-1)= %c", (tab[i][strlen(tab[i])-1]));
    s = tab[i];
    printf("\n ostatni znak tego imienia to: %c", s[strlen(s)-1] );
   if(s[strlen(s)-1] == 'a')a++;
    printf("\n długość tab to: %ld", strlen(tab[i]) );
    printf("\n ostatni znak tab to: %c", (tab[i][strlen(tab[i])-1]) );
    
stdin = freopen (NULL, "r", stdin);
}

printf("\n\n\t Imion kończących się na 'a' jest= %d", a);

    printf("\n\nWczytane imiona: \n");
for (int i=0; i<N; i++)
{
    printf("\nWczytane imie nr %d: %s", i+1, tab[i]);
}

printf("\n");


return 0;
}
