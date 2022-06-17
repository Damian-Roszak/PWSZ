#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int sortujPl(char *t[])
{
    char *pom;
    int wynik=0;
    for (int k=0; k<50; k++)
    for (int i=0; i<49; i++)
    {
        if (t[i]>t[i+1])
        {
            //printf("\t t: %s = %d", t[i], *t[i]);
            pom = t[i+1];
            t[i+1] = t[i];
            t[i] = pom;
            wynik++;
        }
    }
    
return wynik;
}

void inicjujTabPol(char *tZrodlo[], char *tCel[])
{
    int losIndex;
    for (int i=0; i<50; i++)
    {
        losIndex = rand()%41;
        tCel[i] = tZrodlo[losIndex];
    }
}

void pokazTabPl(char *tab[])
{
    printf("\n pokazTabPl Wyświetlam tablicę: ");
    for (int i=0; i<50; i++)
        printf(" %s ", tab[i]);
        printf("\n");
 printf("\n");
}

void pokazTabPol(char *tab[])
{
    printf("\n pokazTabPol Wyświetlam tablicę: ");
    for (int i=0; i<41; i++)
        printf("%s ", tab[i]);
 printf("\n");
}




char *tabPol[] = {"dź","a","ch","dż","ą","rz","b","c","ć","d","e","ę","f","g","h","i","j","k","l","ł","m","n","ń","o","ó","p","q","r","s","ś","t"
,"u","w","x","y","z","ź","ż","cz","sz","dz"};


char tab[50], *tabPl[50];
int n;



int main()
{

srand(time(NULL));

printf("\n WERSJA: z POLSKIMI znakami i dwuznakami");
pokazTabPol(tabPol);
inicjujTabPol(tabPol, tabPl);
printf("\n tabPl po inicjacji");
pokazTabPl(tabPl);


n = sortujPl(tabPl);
printf("\n tabPl po sortowaniu");
pokazTabPl(tabPl);
printf("\n Ilość zamian: %d\n", n);

return 75;
}
