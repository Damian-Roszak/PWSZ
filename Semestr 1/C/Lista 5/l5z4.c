#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>
#include <limits.h>

int main()
{

srand(time(NULL));
 
int tab[5], tab1[5], pom, nowaTab[899], inJ, inD, tabPotasowana[5];

printf("\n\033[96;1m\tOPCJA: Losowanie funkcją rand() do tablicy 5 liczb z sprawdzaniem:\033[0m\n");
    for (int i = 0; i < 5; i++)
    {
        tab[i] = rand()%900+100; 
        if (i>0)
        {
            pom = tab[i];
            printf("%d) tabI[%d] = %d\n", i, i, tab[i]);     
            for (int k = 0; k<i; k++)
            {
                if (pom == tab[k]) i--;
                printf("%d) tabK[%d] = %d\n", k, k, tab[k]);
            }
        }
       // printf("%d) tabI[%d] = %d\n", i+1, i+1, tab[i]);
    }


printf("\n\033[93;1m\tOPCJA: Tasowanie nowej tablicy:\033[0m\n");
for(int i=0; i<900; i++)
{
    nowaTab[i]=i+100;
    //printf(" tab: %d", nowaTab[i]);
   // if (i%15==0) printf("\n");
}
/*
for(int i=0; i<900; i++)
{
    printf(" tab[%d]: %d", i, nowaTab[i]);
    if (i%15==0) printf("\n");
}*/
for(int i=0; i<899; i++)
{
    inJ = rand()%900;
    inD = rand()%900;
    pom = nowaTab[inJ];
    nowaTab[inJ] = nowaTab[inD];
    nowaTab[inD] = pom;
}
/*
printf("\n");printf("\n");
for(int i=0; i<900; i++)
{
    printf(" tab[%d]: %d", i, nowaTab[i]);
    if (i%15==0) printf("\n");
}
printf("\n");printf("\n");
*/
for (int i = 0; i<5; i++)
{
    pom = rand()%900;
    tabPotasowana[i]= nowaTab[pom];
   // printf("%d) tabPotasowana[%d] = %d \t l = %d\n", i+1, i+1, tabPotasowana[i], pom);
}

//printf("\n");printf("\n");
 for (int i = 0; i < 5; i++) 
    printf("%d) tabPotasowana[%d] = %d\n", i+1, i+1, tabPotasowana[i]);
    





printf("\n\033[96;1m\tOPCJA: Losowanie funkcją rand()/RAND_MAX * 900 + 100 do tablicy 5 liczb:\033[0m\n");
    for (int i = 0; i < 5; i++)
    {
        tab1[i] = (double)(rand())/RAND_MAX * 900 + 100;  
        printf("%d) tab1[%d] = %d\n", i+1, i+1, tab1[i]);
    }
    
    
    

printf("\n\t\033[96;1m OPCJA: Mój random:\033[0m\n");
long long int tab2[5];
long int l;
  // for (int k = 0; k<10; k++)
     for (int i = 0; i < 5; i++)
    {
        l = (log(clock())*tan(clock()))/sin(cos(clock()));
        tab2[i] = (long long)(((((clock()*(abs(l*1103515245 + 12345)))/INT_MAX)%(long)clock())/(long )log10(clock()))/log(clock()))%537;
       // if (tab2[i] < 100) 
        {
            printf ("=IF=");
            tab2[i] = tab2[i] + l; 
        }
        printf("%d) tab2[%d] = %lld\n", i+1, i+1, tab2[i]);
        //sleep(0.0001);
    }
    




printf(" \n RAND_MAX: %d\n", RAND_MAX);

//struct timespec* czas = 10;

//nanosleep(2, czas);
//sleep(3);
char koniec;
//scanf("%c",&koniec);
return 0;
}
