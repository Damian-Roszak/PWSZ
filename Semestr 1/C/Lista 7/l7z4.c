#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// GOTOWE 

void inicjujTab(double t[][5])
{
//printf("\n rand max: %d\n", RAND_MAX);
    int ki;
    double k, s, pomRand;
    for (int i=0; i<5; i++)
        for (int j=0; j<5; j++)
        {
            ki = (double)(rand()%11);
            s =rand()/((double)RAND_MAX + 1);
            //pomRand = rand();
            //s = pomRand / RAND_MAX;
             //printf("\n pomRand: %g   s: %g", pomRand, s);
             //printf("\n[%d,%d] ki: %d   s: %g", i+1, j+1, ki, s);
             printf("\n[%d,%d] ki: %d + s: %g = %5.2f", i+1, j+1, ki, s, ki+s);
            // k += s;
            if (((ki + s)>10))
                j--;
            else
                if (i>j)
                {
                  t[i][j] = 0;
                  // printf("\n[%d,%d] t[i][j]: %g", i+1, j+1, t[i][j]);
                }
                else
                {
                    t[i][j] = ki + s;
                     //printf("\n[%d,%d] ki: %d + s: %g = %5.2f", i+1, j+1, ki, s, t[i][j]);
                }
            //if (() || ()) t[i][j] = ki + s;
        }
}


void pokazTab(double t[][5])
{
    printf ("\n Tablica: \n");
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            //printf ("\ttab[%d][%d]: %3d", i+1, j+1, t[i][j]);
            if (t[i][j]==0)
                printf ("\033[97;1m%5.2f\033[0m", t[i][j]);
            else if(i==j)
                printf ("\033[96;1m%5.2f\033[0m", t[i][j]);
            else
                printf ("\033[93;1m%5.2f\033[0m", t[i][j]);
        }
     printf("\n");
     }
}


double tab[5][5];

int main()
{
    srand(time(0));

    inicjujTab(tab);
    pokazTab(tab);

return 0;
}
