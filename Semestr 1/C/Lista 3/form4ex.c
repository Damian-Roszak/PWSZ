#include <stdio.h>



int main(){

char zamknij = 'n', z[256];





while (zamknij != 't' && zamknij != 'T')
{
    zamknij = 'n';
    
    
    
    stdin = freopen(NULL,"r",stdin);    
    printf ("\nCzy chcesz zakończyć? [t/n]: ");
   // fgets(z, sizeof z , stdin);
    //zamknij = z[0];
    scanf ("%c", &zamknij);
//    stdin = freopen(NULL,"r",stdin);
    printf ("\n zamknij = %c\n", zamknij);
};

return 0;
}
