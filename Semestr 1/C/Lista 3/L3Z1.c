#include <stdio.h>
#include <string.h>

void drukTab(char tab[], int granica)
{

    for (int i=0; i<granica; i++)
    {
        printf("%c",tab[i]);
    }
}
char zamknij = 'n';
int main(){

//char zamknij = 'n', spr;
char spr;
char z[256];

int N, i, j, k, iP, iL;

_Bool t;


while (zamknij != 't' && zamknij != 'T')
{
    //zamknij = 'n';
    
    
    printf("\n Podaj długość łańcucha: ");
    scanf (" %d", &N);
    stdin = freopen(NULL,"r",stdin);   
    
    char s[N];    
    
    printf("\n Podaj łańcuch o długości %d: ",N);
    for (int licznik = 0; licznik<N; licznik++)
    {
        scanf(" %c", &spr);
        if (((spr >= 65 ) && (spr <= 90)) || ((spr >= 97) && (spr <= 122)))
          {
             s[licznik] = spr;
          }
          else
          {
            licznik--;
          };
    };
    
    stdin = freopen(NULL,"r",stdin); 
    
    printf("\n łańcuch długości %d to: ", N);
    for (int l = 0; l < N; l++)
    {
        printf(" %c", s[l]  );
    };
    
    printf ("\n");
    
    
    
    //szukam palindromów
    
    for ( i = 0; i < N-1; i++)
    {
    printf("\ni: %d",i);
        for (j = i + 2; j <= N; j++)
        {
        printf("\t  j: %d",j);
            iL = i; iP = j - 1; t = 1;
            printf ("   Przed while il= %d   iP= %d", iL, iP);
            while (iL < iP)
            {
            printf ("\t Przed if il= %d   iP= %d", iL, iP);
                if (s[iL++] != s[iP--])
                {
                printf ("\t w IFie: il= %d   iP= %d", iL, iP);
                    t = 0;
                     printf(" BREAK  s[%d]: %c,   s[%d]: %c", iL, s[iL], iP, s[iP]);
                     break;
                   
                }
             printf("\tŁ\n");   
            }
            printf("\tZ\n");
            if (t)
            {
                printf ("\n Wynik to: ");
                for (k = 0; k < i; k++) printf (" "); 
                char wynik[j-i];
                memcpy (wynik, &s[i], j-i);
                wynik[j-i] = '\0';
                drukTab(wynik, j-i);
                
            printf("\n\n\n");
            }
        }
    }
    printf ("\n");
    
    
    


    stdin = freopen(NULL,"r",stdin);   
    
    printf ("\nCzy chcesz zakończyć? [t/n]: ");
    fgets(z, sizeof z , stdin);
    zamknij = z[0];
    printf ("\n zamknij = %c\n", zamknij);
    stdin = freopen(NULL,"r",stdin);    
};

return 0;
}

