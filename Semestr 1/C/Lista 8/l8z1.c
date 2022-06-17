#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int sortuj(char t[])
{
    char pom;
    int wynik=0;
    for (int k=0; k<50; k++)
    for (int i=0; i<49; i++)
    {
        if (t[i]>t[i+1])
        {
            pom = t[i+1];
            t[i+1] = t[i];
            t[i] = pom;
            wynik++;
        }
    }
return wynik;
}

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

void inicjujTab(char tZrodlo[], char tCel[])
{
    int losIndex;
    for (int i=0; i<50; i++)
    {
        losIndex = rand()%25;
        tCel[i] = tZrodlo[losIndex];
       // printf ("\n los: %d; \t elem: %d, %c\n", losIndex, tZrodlo[losIndex], tZrodlo[losIndex]); 
    }
}

void inicjujTabPol(char *tZrodlo[], char *tCel[])
{
    int losIndex;
    for (int i=0; i<50; i++)
    {
        losIndex = rand()%41;
        tCel[i] = tZrodlo[losIndex];
       // printf ("\n los: %d; \t elem: %d, %c\n", losIndex, tZrodlo[losIndex], tZrodlo[losIndex]); 
    }
}

void pokazTab(char tab[])
{
    printf("\n\033[93;1m  pokazTab\033[0m Wyświetlam tablicę: ");
    for (int i=0; i<50; i++)
        //printf("%d:%c  ", i, tab[i]);
        printf("%c  ", tab[i]);
 printf("\n");
}

void pokazTabLos(char tab[])
{
    printf("\n \033[93;1m pokazTabLos\033[0m Wyświetlam tablicę: ");
    for (int i=0; i<25; i++)
        printf("%3c", tab[i]);
        
 printf("\n");
}
void pokazTabPl(char *tab[])
{
    printf("\n \033[93;1m pokazTabPl\033[0m Wyświetlam tablicę: ");
    for (int i=0; i<50; i++)
        //printf("%d:%c  ", i, tab[i]);
        printf("\033[93;1m %s \033[0m  ", tab[i]);
        printf("\n");
    for (int i=0; i<50; i++)    
        printf("\033[96;1m\ts:%s c:%c d: %d\033[0m  ", tab[i], *tab[i], *tab[i]);
        //printf("\033[96;1m\ttyp:%s \033[0m  ", typeof(tab[i]));//, *tab[i], *tab[i]);
 printf("\n");
}

void pokazTabPol(char *tab[])
{
    printf("\n\033[93;1m pokazTabPol\033[0m Wyświetlam tablicę: ");
    for (int i=0; i<41; i++)
        //printf("%d:%c  ", i, tab[i]);
        printf("\033[93;1m%s\033[0m  ", tab[i]);
 printf("\n");
}

void pokazTabElem(char tab[], int n)
{
    printf("\n Wyświetlam Element: %3c, %3d", tab[n], tab[n]);        
 printf("\n");
}




char tabLos[] = {'a','z','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t'
,'u','w','x','y'};


char *tabPol[] = {"a","dż","ą","rz","b","c","ć","d","e","ę","f","g","h","i","j","k","l","ł","m","n","ń","o","ó","p","q","r","s","ś","t"
,"u","w","x","y","z","ź","ż","ch","cz","sz","dz","dź"};


char *tabPol2[] ={"a","dż","ą","b","c","ć","d","e","ę","f","g","h","i","j","k","l","ł","m","n","ń","o","ó","p","q","r","s","ś","t","u","w","x","y","z","ź","ż","ch","cz","rz","sz","dz","dź"};

char tab[50], *tabPl[50];
int n, elemDoPokaz;



int main()
{

srand(time(NULL));

printf("\n WERSJA: bez pl char");
pokazTabLos(tabLos);
inicjujTab(tabLos, tab);
printf("\n po inicjacji");
pokazTab(tab);

//printf("\n zerowy elem tabLos: %c,%d", tabLos[0], tabLos[0]);
//printf("\n zerowy elem tab: %c,%d", tab[0], tab[0]);

//printf("\n Podaj element do wyświetlenia: ");
//scanf("%d", &elemDoPokaz);
//pokazTabElem(tab,elemDoPokaz);

n = sortuj(tab);
printf("\n po sortowaniu");
pokazTab(tab);
printf("\n Ilość zamian: \033[93;1m%d\033[0m\n", n);




printf("\n WERSJA: z POLSKIMI znakami i dwuznakami");
pokazTabPol(tabPol);
inicjujTabPol(tabPol, tabPl);
printf("\n tabPl po inicjacji");
pokazTabPl(tabPl);


n = sortujPl(tabPl);
printf("\n tabPl po sortowaniu");
pokazTabPl(tabPl);
printf("\n Ilość zamian: \033[93;1m%d\033[0m\n", n);

return 75;
}
