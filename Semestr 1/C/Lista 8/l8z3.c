#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int N;
void pokazTab(float t[][N], int k);

void inicjujTab(float t[][N], int k)
{
printf("\n inicjujTab: \n");
    int mnoznik, tmp;
    float pom;
    for (int i=0; i<k; i++)
    for (int j=0; j<k; j++)
    {
     do{
        tmp = rand()%10;
        pom = rand()/((float)RAND_MAX+1);
        t[i][j] = tmp + pom;
    }while(t[i][j] > 10);
      //  printf("\n [%d,%d] pom: %f, tmp: %d", i, j, pom, tmp);
        mnoznik = rand()%2;
     //   printf("  mnoznik[%d,%d]: %d", i, j, mnoznik);
        if(mnoznik == 0) t[i][j] *= -1;
      //  printf("  t[%d,%d]: %f", i, j, t[i][j]);
    }
    
pokazTab(t, k);
}


void inicjujTab2(float t[][N], int k)
{

printf("\n inicjujTab 2: \n");
    int mnoznik, tmp;
    float pom;
    for (int i=0; i<k; i++)
    for (int j=0; j<k; j++)
    {
     do{
        tmp = rand()%11;
        pom = rand()/((float)RAND_MAX+1);
    }while(tmp > 10);
    if (tmp == 10) t[i][j] = tmp - pom;
     else
       t[i][j] = tmp + pom;
      //  printf("\n [%d,%d] pom: %f, tmp: %d", i, j, pom, tmp);
        mnoznik = rand()%2;
     //   printf("  mnoznik[%d,%d]: %d", i, j, mnoznik);
        if(mnoznik == 0) t[i][j] *= -1;
      //  printf("  t[%d,%d]: %f", i, j, t[i][j]);
       if (tmp == 10) printf("  t[%d,%d]: %f", i, j, t[i][j]);
    }
    
pokazTab(t, k);
}

void pokazTab(float t[][N], int k)
{
printf("\n pokaz tab: \n");
    for (int i=0; i<k; i++)
    {
        for (int j=0; j<k; j++)
        {
            printf("\033[93;1m%10f\033[0m ", t[i][j]);
        }
    printf("\n");
    }
}


int main()
{
srand(time(NULL));

printf("\n\033[96;1m  Podaj rozmiar tablicy NxN: \033[0m");
scanf("%d", &N);

float tab[N][N];
inicjujTab(tab, N);

    printf("\n");   printf("\n");

float tab2[N][N];
inicjujTab2(tab2, N);


return 1000;
}
