#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// GOTOWE

void inicjujTab(int t[][10])
{
    int l, k, suma = 0;
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
        {
            l = rand()%2;
            k = rand()%11;
            if (l==0) k *= -1;  
            t[i][j] = k;            
            if((i==j) || (i+j==9)) suma += t[i][j];
        }
     printf("\n Suma inicjujTab(): %d", suma);
}


void pokazTab(int t[][10])
{
    printf ("\n Tablica: \n");
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            //printf ("\ttab[%d][%d]: %3d", i+1, j+1, t[i][j]);
            printf ("%3d", t[i][j]);
        }
     printf("\n");
     }
}

void sumaPrzek(int t[][10])
{
    int suma = 0;
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            if((i==j) || (i+j==9)) 
            {
                suma += t[i][j];
                //printf(" t[%d][%d]: %d -> suma: %d",i , j, t[i][j], suma);
             }   
        }
     }    
     printf("\n Suma sumaPrzek(): %d\n", suma);
}


int tab[10][10];

int main()
{
    srand(time(0));

    inicjujTab(tab);
    pokazTab(tab);
    sumaPrzek(tab);

return 0;
}
