#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


// GOTOWE
char *itoc(int i)
{
    char *result = malloc(sizeof(char));
    sprintf(result, "%c", i);
return result;
}

typedef struct{
    int id;
    int wiek;
    char imie[20];
    char nazwisko[20];
}tosoba;


void pokazTosoba(tosoba *ktos)
{
    printf("\n %d \t %d \t %s \t %s", ktos->id, ktos->wiek, ktos->imie, ktos->nazwisko);
}

tosoba pobierzTosoba()
{
int l, licznik;
    tosoba *rezultat = malloc(sizeof(tosoba));
   // printf("\n Podaj element tosoba: ");
    rezultat->id = rand()%47;
    rezultat->wiek = rand()%100;
    
       // printf(" imie=");
    rezultat->imie[0] = '\0';
    l =rand()%26+65;
     //   printf(" l=%d=%c", l, l);
        strncat(rezultat->imie, itoc(l), 1);      
       
    licznik =rand()%18+2;
      //  printf("\n\033[96;1m przed imie l=%d=%c\033[0m", l, l);
    for (int i=1; i<licznik; i++){
        l =rand()%26+97;
    //    printf("\n\033[93;1m imie l=%d=%c\033[0m", l, l);
        strncat(rezultat->imie, itoc(l), 1);
    }
      //  printf(" nazwisko=");
   rezultat->nazwisko[0] = '\0';
   l =rand()%26+65;
       // printf(" l=%d=%c", l, l);
        strncat(rezultat->nazwisko, itoc(l), 1);        
    licznik =rand()%18+2;
    for (int i=1; i<licznik; i++){
        l =rand()%26+97;
       // printf(" l=%d=%c", l, l);
        strncat(rezultat->nazwisko, itoc(l), 1);
    }
     // pokazTosoba(rezultat);
    
return *rezultat;
}

tosoba pobierzTosobaZKlawiatury()
{
    tosoba *rezultat = malloc(sizeof(tosoba));
    printf("\n Podaj elementy osoby: ");
    printf("\n Podaj id: ");
    scanf("%d", &rezultat->id);    
        stdin = freopen (NULL, "r", stdin);
    printf("\n Podaj wiek: ");
    scanf("%d", &rezultat->wiek);
        stdin = freopen (NULL, "r", stdin);
    printf("\n Podaj imie: ");
    scanf("%s", rezultat->imie);
        stdin = freopen (NULL, "r", stdin);
    printf("\n Podaj nazwisko: ");
    scanf("%s", rezultat->nazwisko);
        stdin = freopen (NULL, "r", stdin);
return *rezultat;
}


tosoba tab[5];
char t = 'n';
int dlimie, dlwzor, porownaj;
char *wzor;

int main()
{

srand(time(NULL));
//tosoba czlowiek;

while(t!='t' && t!='T')
{

for (int i=0; i<5; i++)
{
   tab[i] = pobierzTosoba();
   //tab[i] = pobierzTosobaZKlawiatury();
}


    printf("\n\033[93;1m id: \t wiek \t imie \t\t nazwisko\033[0m");
for (int i=0; i<5; i++)
{
    pokazTosoba(&tab[i]);
}
wzor = malloc(20);
printf("\n Podaj wzór do wyszukania: ");
scanf("%s", wzor);
printf(" wczytany wzór: %s", wzor);

printf("\n\033[93;1m id \t wiek \t imie \t nazwisko\033[0m");
for(int i=0; i<5; i++)
{
    porownaj = strcmp(tab[i].imie, wzor);
    if (porownaj == 0)
    { 
     // printf("\n tab[%d].imie %s i wzor %s są takie same", i, tab[i].imie, wzor);    
      pokazTosoba(&tab[i]);
    }
}



//własne porównywanie napisów = nieskończone
dlwzor = strlen(wzor);
for(int i=0; i<5; i++)
{

    dlimie = strlen(tab[i].imie);
    if(dlimie==dlwzor)
    for(int j=0; j<dlwzor; j++)
    {
        if(wzor[j] == tab[i].imie[j]) ;
    }

}


stdin = freopen (NULL, "r", stdin);
printf("\nZakończyć? [t/n]: ");
scanf("%c", &t);
stdin = freopen (NULL, "r", stdin);
}
return 0;
}
