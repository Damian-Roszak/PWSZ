#include <stdio.h>

//GOTOWE

char zamknij = 'n';


int main(){


char z[256];
int n;



while (zamknij != 't' && zamknij != 'T')
{
   // zamknij = 'n';
    

    int silnia=1;
    printf("\n Podaj liczbę do silni = ");
    scanf ("%d", &n);
    if (n>0 && n<11)
    {
    
        for (int i=1; i<=n; i++)
        {
            silnia = silnia * i;
        };
    }
    else
    {
        printf ("\n n musi być z przedziału 1 do 10 \n");
    };
    printf("n! = %d", silnia);
    
    
    
    
    stdin = freopen(NULL,"r",stdin);    
    printf ("\nCzy chcesz zakończyć? [t/n]: ");
   // fgets(z, sizeof z , stdin);
    //zamknij = z[0];
    scanf ("%c", &zamknij);
//    stdin = freopen(NULL,"r",stdin);
    printf ("\n zamknij = %c\n", zamknij);
    stdin = freopen(NULL,"r",stdin);    
};

return 0;
}

