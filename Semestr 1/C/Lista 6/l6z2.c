#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


// GOTOWE


int tab[100];
int N, suma = 0, sumaParzystychDodatnich = 0, sumaParzystychUjemnych = 0;
char t = 'n';


int main()
{
while(t!='t' && t!='T')
{
srand(time(NULL));

for (int i=0; i<100; i++)
{
    
    tab[i] = rand()%41+10;
    N = rand()%2;
   // printf("\n N = %d", N);
    if (N == 0) tab[i] = tab[i] * (-1);
    if (tab[i]%2 == 0) suma = suma + tab[i];
  //  if (tab[i]%2 == 0 && tab[i]>0) sumaParzystychDodatnich = sumaParzystychDodatnich + tab[i];
  //  if (tab[i]%2 == 0 && tab[i]<0) sumaParzystychUjemnych = sumaParzystychUjemnych + tab[i];
 //   if (tab[i] == -10 || tab[i] == -50) printf ("\n tab[%d] = %d", i, tab[i]);
//    if (tab[i] == 10 || tab[i] == 50) printf ("\n tab[%d] = %d", i, tab[i]);
}

    printf("\n\nWylosowane liczby: \n");
for (int i=0; i<100; i++)
{
   // printf("\nWylosowana liczba nr %d: %d", i+1, tab[i]);
}

printf("\n\033[93;1m Suma parzystych wynosi: \033[96;1m%d", suma);
//printf("\n\033[93;1m Suma parzystych Dodatnich wynosi:\033[96;1m %d", sumaParzystychDodatnich);
//printf("\n\033[93;1m Suma parzystych ujemnych wynosi:\033[96;1m %d\033[0m", sumaParzystychUjemnych);



stdin = freopen (NULL, "r", stdin);
printf("\nZakończyć? [t/n]: ");
scanf("%c", &t);
stdin = freopen (NULL, "r", stdin);
}
return 255;
}
