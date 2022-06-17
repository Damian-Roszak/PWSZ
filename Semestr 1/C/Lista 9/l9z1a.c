#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>

int rozmiar;
typedef struct {
    char imie[30];
    char nazwisko[50];
    short wiek;
    char PESEL[12];
    char email[50];
} tperson;

int czekMail(char mejl[]);

tperson inicjujElement(tperson elem);
void dodaj(tperson t[], int *flag)
{
  int pom=0;
  for(int index=0; index<100; index++)
  {
    if (flag[index]==0)
    {
      //  printf("\n %d flaga = %d", index, flag[index]);
        tperson elem = inicjujElement(elem);
        t[index]=elem;
        flag[index]=1;
        pom++;
    }
  }
if (pom==0) printf("\n Nie ma miejsca aby dodać element");
}

void usun( int index, int flag[])
{
    flag[index]=0;
}

void szukaj(tperson t[], char peselek[12], int *flag)
{
    printf("\n\t\033[93;1m LP. \t imie  \t\t nazwisko \t wiek  \t  PESEL \t email\033[0m");
    int pom=0;
    for (int i=0; i<=99; i++)
    {
      if (flag[i] != 0) 
            //for (int j=0; j<11; j++) if (t[i].PESEL[j] == peselek[j]) printf("if TAK");
       if(strcmp(t[i].PESEL, peselek)==0) //printf("strcmp Tak");
        {
            printf("\n\t %d \t %s \t %s \t %d \t %s \t %s \t", i, t[i].imie, t[i].nazwisko, t[i].wiek, t[i].PESEL, t[i].email);
            pom++;
        }
    }
    if (pom==0) printf ("\n \t Brak elementów o podanym PESEL'u");
}

void sortuj(tperson t[], int fl[])
{
    tperson pom;
 for (int i=0; i<=99; i++)
 for (int j=0; j<=98; j++)
 {
     if (fl[j] != 0) {
            //for (int j=0; j<11; j++) if (t[i].PESEL[j] == peselek[j]) printf("if TAK");
        if(strcmp(t[j].nazwisko, t[j+1].nazwisko)>0) {
            pom = t[j];
            t[j] = t[j+1];
            t[j+1] = pom;
        }   
    }
 }
}

void ileDorosli(tperson t[])
{
    int pom = 0;
    for (int i=0; i<=99; i++) 
        if (t[i].wiek >= 18) pom++;
    printf(" \n Znaleziono %d dorosłych", pom);
}


int czekMail(char mejl[])
{
   int N = strlen(mejl);
   //printf("\n mejl: %d", N);
   int pom = 0;
   for (int i=0; i<=N; i++)
   {
        if (mejl[i]=='@')
        {
             pom = 1;
            // printf("\n mejl: %s", mejl);
        }
   } 
return pom;
}

char *losujLiterki(char *wyw)
{
//printf("\n losujLiterki");
    char *pom = malloc(sizeof(char)), *tmp = malloc(sizeof(char));
      *pom = rand()%26 + 65;     
  // printf("\n losujLiterki pokaz pom C: %c   s:%s", *pom, pom);
    for (int i=0; i<5; i++)
    {
        *tmp = rand()%26 + 97;
        strncat(pom, tmp, 1);
   //if(*tmp < 97 || *tmp > 122)printf("\n losujLiterki pokaz tmp[%d] c: %c   s:%s", i, *tmp, tmp);
  // printf("\n losujLiterki pokaz tmp[%d] c: %c   s:%s", i, *tmp, tmp);
//   printf("\n losujLiterki pokaz pom[%d] c: %c   s:%s", i, *pom, pom);
    }    
    
//   printf("\n losujLiterki pokaz tmp c: %c   s:%s",  *tmp, tmp);
//   printf("\n losujLiterki pokaz pom c: %c   s:%s",  *pom, pom);
    printf("\n losujLiterki %s pokaz pom C: %c   s:%s", wyw, *pom, pom);
  // if (wyw == "mail") printf("\n losujLiterki %s pokaz pom C: %c   s:%s", wyw, *pom, pom);
return pom;    
}


void inicjujPersone(tperson tab[100], int fl[100])
{

    for (int i=0; i<=99; i++)
    {    
    fl[i] = 1;
printf("\n\n\n inicjujPersone imie [%d]", i);
        strncpy (tab[i].imie, losujLiterki("imie"), 6);
        tab[i].imie[6]='\0';
        printf("\n inicjujPersone pokaz imie: %s|", tab[i].imie);

//printf("\n\n inicjujPersone nazwisko");
       // strncat (tab[i].nazwisko, losujLiterki("nazwisko"), 6);
        strncpy (tab[i].nazwisko, losujLiterki("nazwisko"), 6);
        tab[i].nazwisko[6]='\0';
        printf("\n inicjujPersone pokaz nazwisko: %s|", tab[i].nazwisko);
        
//printf("\n inicjujPersone wiek");
        tab[i].wiek = rand()%99+1;
        
//printf("\n inicjujPersone PESEL");
        for (int j=0; j<11; j++)
            tab[i].PESEL[j]=rand()%9+48;  
       tab[i].PESEL[11]='\0';
printf("\n inicjujPersone PESEL: %s", tab[i].PESEL); 

            
//printf("\n\n inicjujPersone email [%d]",i);      
        strncpy (tab[i].email, losujLiterki("mail"), 6);
printf("\n inicjujPersone email po losowaniu: %s", tab[i].email); 
        tab[i].email[6]='\0';
        strncpy (tab[i].email, "@", 1);
printf("\n inicjujPersone email po małpie: %s", tab[i].email); 
        strncat (tab[i].email, "polska-domena.pl", 16);   
printf("\n inicjujPersone email po domenie: %s", tab[i].email);      
        czekMail(tab[i].email);
        
printf("\n\n");
    }
}

void pokazPersone(tperson tab[100], int fl[])
{   
    printf("\n\t\033[93;1m LP. \t imie  \t\t nazwisko \t wiek  \t  PESEL \t email\033[0m");
    for (int i = 0; i<=99; i++)
    {  
        if(fl[i]==1){ 
        printf("\n\t %d", i);
        printf(" \t %s ", tab[i].imie);
        printf(" \t %s ", tab[i].nazwisko);
        printf(" \t %d ", tab[i].wiek);
        printf(" \t %s ", tab[i].PESEL);
        printf(" \t %s ", tab[i].email);
        }
    }
}


tperson inicjujElement(tperson elem)
{

//printf("\n\n\n inicjujElement imie [%d]", i);
        strncpy (elem.imie, losujLiterki("imie"), 6);
        elem.imie[7]='\0';
      //  printf("\n inicjujElement pokaz imie: %s", elem.imie);

//printf("\n\n inicjujElement nazwisko");
        strncpy (elem.nazwisko, losujLiterki("nazwisko"), 6);
        elem.nazwisko[6]='\0';
       // printf("\n inicjujElement pokaz nazwisko: %s", elem.nazwisko);
        
//printf("\n inicjujElement wiek");
        elem.wiek = rand()%99+1;
        
//printf("\n inicjujElement PESEL");
        for (int j=0; j<11; j++)
            elem.PESEL[j]=rand()%9+48;  
        elem.PESEL[11]='\0';
            
//printf("\n\n inicjujElement email [%d]",i);      
        strncpy (elem.email, losujLiterki("mail"), 6);
//printf("\n inicjujElement email po losowaniu: %s", elem.email); 
        elem.email[6]='\0';
        strncat (elem.email, "@", 1);
//printf("\n inicjujElement email po małpie: %s", elem.email); 
        strncat (elem.email, "polska-domena.pl", 16);        
        czekMail(elem.email);  

return  elem;     
}


int main()
{

srand(time(0));
int flaga[100];
char psl[12];
//printf("\n rozmiar flaga = %lu", sizeof(flaga)/sizeof(int));
//printf("\n Przed inicjacją flagi");
for (int i=0; i<=99; i++) flaga[i] = 0;
//for (int i=0; i<=99; i++) printf("%d", flaga[i]);

//printf("\n Przed deklaracją tperson tab[100]");
tperson tab[100];
//losujLiterki("main");
inicjujPersone(tab, flaga);
//pokazPersone(tab, flaga);
//ileDorosli(tab);

/*
printf("\n\n podaj PESEL do odnalezienia: ");
scanf("%s",psl);
szukaj(tab, psl, flaga);
*/

//printf("\n\n Sortowanie: ");
//sortuj(tab, flaga);
//pokazPersone(tab, flaga);
//ileDorosli(tab);

/*
printf("\n\n Usuwanie: ");
for (int i= 0; i<90; i++)
{
    usun(i, flaga);
}
pokazPersone(tab, flaga);
*/

/*
printf("\n\n Sortowanie po usunięciu: ");
sortuj(tab, flaga);
pokazPersone(tab, flaga);
*/

/*
printf("\n\n Dodawanie elementu: ");
dodaj(tab, flaga);
pokazPersone(tab, flaga);
*/
/*
printf("\n\n Sortowanie po dodawaniu: ");
sortuj(tab, flaga);
pokazPersone(tab, flaga);
*/

/*
int u;
printf("\n\n Usuwanie Wybranego Elementu, którego?: ");
scanf("%d", &u);
    usun(u, flaga);
pokazPersone(tab, flaga);
*/

/*
char l;
printf("\n\n wyczyścić ekran poleceniem clear?: ");
scanf("%c", &l);
if (l=='t') system("clear");
*/

printf("\n");
return 0;
}
