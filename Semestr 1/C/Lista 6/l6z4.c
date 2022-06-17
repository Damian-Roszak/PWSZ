#include<stdio.h>
#include<time.h>
#include<stdlib.h>


// GOTOWE 

void sortowanieBabelkowe(int tablica[])
{
int licz=100, tmp; 
do{
    for(int i=0; i<99; i++)
    {
        if(tablica[i]>tablica[i+1])
        {
            tmp=tablica[i];
            tablica[i] = tablica[i+1];
            tablica[i+1] = tmp;
        }
    }
licz--;
}while(licz>1);
}


int tab[100], l, pom, n;
char t = 'n';

int main()
{

srand (time(0));
register int si;
//while(t!='t' && t!='T')
for(si=0; si<1E5; si++)
{
if (si%100==0) printf("\n setka: %d",si);
for (int i=0; i<100; i++)
{
    tab[i] = rand()%101;
    l = rand()%2;
    if (l==0) tab[i] *= -1;
}

//printf("\n\033[96;1m Tablica PRZED sortowaniem \033[0m\n");
for(int i=0; i<100; i++)
{
   // printf("\t tab[%d]:= \033[93;1m%d\033[0m", i+1, tab[i]);
   // if (i%10==0) printf("\n");
}

//SORTOWANIE
/*
n=100;
do{
    for(int i=0; i<99; i++)
    {
        if(tab[i]>tab[i+1])
        {
            pom=tab[i];
            tab[i] = tab[i+1];
            tab[i+1] = pom;
        }
    }
n--;
}while(n>1);
*/
// SORTOWANIE FUNKCJĄ - do funkcji przekazywana jest funkcja utworzona przed funkcją main czyli ta tablica jest zmienną globalną, dzięki temu funkcja sortująca mając ją za parametr aktualny może wykonać działanie dokładnie na tej tablicy - czyli ją zmienić - posortować i obywa się bez: zwracania wartości z funkcji i przypisywania zwróconej wartości do zmiennej.
 sortowanieBabelkowe(tab);


//printf("\n\n\033[96;1m Tablica PO sortowaniu \033[0m\n");
for(int i=0; i<100; i++)
{
   // printf("\t tab[%d]:= \033[93;1m%d\033[0m", i+1, tab[i]);
  //  if (i%10==0) printf("\n");
}




stdin = freopen (NULL, "r", stdin);
//printf("\nZakończyć? [t/n]: ");
//scanf("%c", &t);
stdin = freopen (NULL, "r", stdin);
}
return 250;
}
