#include<stdio.h>
#include<time.h>
#include<stdlib.h>


// GOTOWE

int tab[10][10], mnoznik, tabT[10][10];


int main()
{
srand(time(NULL));


for(int i=0; i<10; i++)

    for(int j=0; j<10; j++)
    {
        mnoznik = rand()%2;
        tab[i][j] = rand()%11;
        if (mnoznik == 0) tab[i][j] *= -1;
    }


printf("\n Macierz:\n");
for(int i=0; i<10; i++)
{
    for(int j=0; j<10; j++)
    {
        printf("        tab[%d][%d]: \033[96;1m%2d\033[0m", i+1, j+1, tab[i][j]);
    }
    printf("\n");
}


for(int i=0; i<10; i++)

    for(int j=0; j<10; j++)
    {
        tabT[i][j] = tab[j][i];
    }

printf("\n Macierz Transponowana:\n");
for(int i=0; i<10; i++)
{
    for(int j=0; j<10; j++)
    {
        printf("       tabT[%d][%d]: \033[96;1m%2d\033[0m", i+1, j+1, tabT[i][j]);
    }
    printf("\n");
}


return 0;
}
