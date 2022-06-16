#include <stdio.h>

//GOTOWE

int main(){
char zamknij = 'n';
char z[256];
int n;
double suma;


while (zamknij != 't' && zamknij != 'T')
{
    zamknij = 'n';
    suma = 1.0;
    printf("\n Podaj n: ");
    scanf (" %d", &n);    
    stdin = freopen(NULL,"r",stdin);  
    
    printf("\n Elementy: 1 ");
    for (int i=2; i<=n; i++)
    {

        printf ("el i-ty #%d = 1/%d ",  i, i);
        suma = suma + (1.0/(double)(i));
    }; 
    printf("\n Suma: %g", suma);
     
      
    
    
    
    
    
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

