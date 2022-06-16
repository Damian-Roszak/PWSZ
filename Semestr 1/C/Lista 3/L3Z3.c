#include <stdio.h>

//GOTOWE

int main(){
char zamknij = 'n', z[256], c;
int tab[10], maksiu, minimi, pomMaksia, pomMinimi;




while (zamknij != 't' && zamknij != 'T')
{
    zamknij = 'n';
    
    printf ("Podaj 10 liczb int: ");
    for (int i = 0; i<10; i++)
    {
         scanf("%d", &tab[i]);
         //fgets(tab[i], sizeof tab, stdin);
    };
    
    stdin = freopen(NULL,"r",stdin); 
    pomMaksia = tab[0];
    pomMinimi = tab[0];    
    for (int i = 1; i<10; i++)
    {
         if (pomMaksia < tab[i]) pomMaksia = tab[i];
         if (pomMinimi > tab[i]) pomMinimi = tab[i];
    };
    
    printf ("\n Maks = %d \t Min = %d \n", pomMaksia, pomMinimi);


    
    printf ("\nCzy chcesz zakończyć? [t/n]: ");
    fgets(z, sizeof z , stdin);
    zamknij = z[0];
    
    printf ("\n zamknij = %c\n", zamknij);
};

return 0;
}

