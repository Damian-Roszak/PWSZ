#include <stdio.h>

//GOTOWE

int main(){

char zamknij = 'n', z[256];
int l1, l2;




while (zamknij != 't' && zamknij != 'T')
{
    zamknij = 'n';
    
    printf("\n Podaj 2 liczby całkowite: ");
    scanf (" %d %d", &l1, &l2);
    
    if ((l1>= 0) && (l2 >= 0) ) 
    {
        if (l1 < l2) 
        {
            printf ("\n if 1 : \n");
            printf ("\n Wynik to: ");
            for (int i = l1; i<=l2; i++)
            {
                if ( i % 2 == 0 ) printf ("%d ", i);
            };
        }
        else if ( (l1 == l2) && (l1 % 2 == 0))
        {
            printf ("\n War 1 else IF: \n");
            printf("\n Wynik to: %d", l1);
        } 
        else if ( (l1 == l2) && (l1 % 2 != 0))
        {
            printf ("\n War 1 else IF: \n");
            printf("\n Wynik to: BRAK PARZYSTYCH");
        } 
        else
        {
            printf ("\n War 1 else: \n");
            printf ("\n Wynik to: ");
            for (int i = l1; i>=l2; i--)
            {
                if ( i % 2 == 0 ) printf ("%d ", i);
            };
        }; 
    }
    else if((l1>0)&&(l2<0))
    {
    printf ("\n War 2IF: \n");
         printf ("\n Wynik to: ");
            for (int i = l1; i>=0; i--)
            {
                if ( i % 2 == 0 ) printf ("%d ", i);
            };
    }
    else if( (l1<0) && (l2>0) )
    {
    printf ("\n War 2elseIF: \n");
         printf ("\n Wynik to: ");
            for (int i = 0; i<=l2; i++)
            {
                if ( i % 2 == 0 ) printf ("%d ", i);
            };
    
    }
    else
    {    
       printf ("\n War 2 else : \n");
       printf("\n Wynik to: BRAK PARZYSTYCH DODATNICH");
    };
    
    
    
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

