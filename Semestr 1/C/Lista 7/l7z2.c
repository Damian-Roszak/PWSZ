#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// GOTOWE


void podajTab(int t[][5])
{
    int pom;
    printf ("\n Podaj elementy tablicy: \n");
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            do{
                printf (" Podaj element %d, %d: ", i+1, j+1);
                scanf("%d", &t[i][j]);
            }while(t[i][j]<-5 || t[i][j]>=10 || t[i][j]==0);
        }
     printf("\n");
     }
}

void inicjujTab(int t[][5])
{
    int l, k;
    for (int i=0; i<5; i++)
        for (int j=0; j<5; j++)
        {
            l = rand()%2;
            k = rand()%10;
            if (l==0) k *= -1;            
            if (k==0 || k<-5) j--;
            if (k != 0 ) t[i][j] = k;
        }
}


int sumuj(int t[][5], int k)
{
    int licz = 0;
    for (int i=0; i<5; i++)
    {
        licz += t[i][k];    
    }
return licz;
}

int sumuj2(int (*t)[5], int k)
{
    int licz = 0;
    for (int i=0; i<5; i++)
    {
        licz += t[i][k];    
    }
return licz;
}

void pokazTab(int t[][5])
{
    printf ("\n Tablica: \n");
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            printf ("\ttab[%d][%d]: %3d", i+1, j+1, t[i][j]);
        }
     printf("\n");
     }
}


int tab[5][5], suma, wybor;

int main()
{
suma =0;
srand(time(NULL));

podajTab(tab);
//inicjujTab(tab);


do {
printf("\n Którą kolumnę zsumować? [1..5]: ");
scanf("%d", &wybor);
}while(wybor<1 || wybor >5);
    suma = sumuj2(tab, wybor-1);
    //suma = sumuj(tab, wybor-1);
printf("\n suma to: %3d", suma);

pokazTab(tab);



return 0;
}
