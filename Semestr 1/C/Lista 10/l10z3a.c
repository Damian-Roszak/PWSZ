#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>




typedef struct tp{ 
    //tperson *next, *befor;
    struct tp *next, *befor;
    int id;
    char imie[30];
    char nazwisko[50];
    short wiek;
    char PESEL[12];
    char email[50];
} tperson;

void zapisz(tperson tosoba);
void usun();
void pokazStruktur(tperson s);
void dodaj();
void pokazBD();
void czytajZPlikuBin();
void drukuj(tperson wsk);


void zapiszLISTA(tperson *tosoba, int index);
void usunLISTA();
void pokazStrukturLISTA(tperson *s);
void dodajLISTA();
void pokazBDLISTA();
void czytajZPlikuBinLISTA();



void main(int argc, char *argv[]){

tperson osoba;
    //osoba.id = wstawID();
    osoba.id = 2;
    strcpy(osoba.imie , "DamianR");
    strcpy(osoba.nazwisko , "RoszakD"); //, sizeof(osoba.nazwisko)
    osoba.wiek = 34;
    strncpy(osoba.PESEL , "jijiji", sizeof("jijiji"));
    strcpy(osoba.email , "songoku@matrix.pl"); //, sizeof("songoku@matrix.pl")
    
tperson osoba2;
    //osoba.id = wstawID();
    osoba2.id = 3;
    strncat(osoba2.imie , "Marek", sizeof(osoba2.imie));
    strncat(osoba2.nazwisko , "Robert", sizeof(osoba2.nazwisko));
    osoba2.wiek = 144;
    strncat(osoba2.PESEL , "534534634", sizeof(osoba2.PESEL));
    strncat(osoba2.email , "555@matrix.pl", sizeof(osoba2.email));
  
//dodajLISTA(osoba);
//dodajLISTA(osoba2);
//zapiszLISTA(osoba);
//zapiszLISTA(osoba2);
//pokazStrukturLISTA(osoba);
//czytajZPlikuBinLISTA();
//pokazBDLISTA();
usunLISTA();
 
//dodaj(osoba);
//dodaj(osoba2);
//zapisz(osoba);
//zapisz(osoba2);
//pokazStruktur(osoba);
//czytajZPlikuBin();
//pokazBD();
//usun();

}
  
void usunLISTA(){
    tperson s;
    FILE *wsk_plik;
    char *sciezka="bd.txt";
    char *mode="rb";
    wsk_plik = fopen(sciezka,mode);
    
    tperson *first, *nowy, *wsk;
    int i=2;
    char *c;
    const int END = 5;
    
    first = malloc (sizeof(tperson));    
    
    first->next = NULL;
    wsk = first;
    
    
    if (wsk_plik != NULL){     
     printf("\n Tworzenie LISTY\n"); 
    
     while ((fread(&s, sizeof(s), 1 ,wsk_plik)) != 0 ){
        nowy = malloc(sizeof(tperson));
       // nowy = &s;
        nowy->id = s.id;
        strncpy(nowy->imie , s.imie, sizeof(s.imie));
        strncpy(nowy->nazwisko , s.nazwisko, sizeof(s.nazwisko));
        nowy->wiek = s.wiek;
        strncpy(nowy->PESEL , s.PESEL, sizeof(s.PESEL));
        strncpy(nowy->email , s.email, sizeof(s.email));
      
        nowy->next = NULL;
        wsk->next = nowy;
        wsk=wsk->next;
    }
    pokazStrukturLISTA(first->next);
    zapiszLISTA(first->next, i);
    pokazBDLISTA();
    
    }
    else
        printf("\n Nie udało się otworzyć pliku: %s", sciezka);        
    printf("\n");
    fclose(wsk_plik);
    /*
    zamkinij plik i ponownie otwórz w trybie pisania od początku
    zapisz listę do pliku z pominięciem wskazanego id
    */
}

void dodajLISTA(tperson tosoba){
 int size;
    FILE *wsk_plik;
    char *sciezka="bd.txt";
    char *mode="ab";
    wsk_plik = fopen(sciezka,mode);

    if (wsk_plik != NULL)
     fwrite(&tosoba, sizeof(tosoba), 1 ,wsk_plik);
    else
        printf("\n Nie udało się otworzyć pliku: %s", sciezka);
    fclose(wsk_plik);

}

void pokazBDLISTA(){
printf("\n Funkcja pokazBDLISTA(): \n");
    czytajZPlikuBinLISTA();
}

void zapiszLISTA(tperson *tosoba, int index){
    tperson *wsk = tosoba;
    int size;
    FILE *wsk_plik;
    char *sciezka="bd.txt";
    char *mode="wb";
    wsk_plik = fopen(sciezka,mode);

    if (wsk_plik != NULL)
        while (wsk != NULL){ 
         if(wsk->id != index)
             fwrite(wsk, sizeof(*tosoba), 1 ,wsk_plik);
                          
        wsk=wsk->next;
        }     
    else
        printf("\n Nie udało się otworzyć pliku: %s", sciezka);
    fclose(wsk_plik);
}
 

void pokazStrukturLISTA(tperson *s){
    tperson *wsk = s;
    printf("  \n");
    while (wsk != NULL){ 
        printf("%-10d \t ", wsk->id);
        printf("%-10s \t ", wsk->imie);
	    printf("%-10s \t ", wsk->nazwisko);
	    printf("%-10d \t ", wsk->wiek);
        printf("%-10s \t ", wsk->PESEL);
	    printf("%-10s \n", wsk->email);
	
       // printf("\n");
        wsk=wsk->next;
    }
   // printf("\n");
}


void czytajZPlikuBinLISTA(){
    tperson s;
    int size, elem=1;
    FILE *wsk_plik;
    char *sciezka="bd.txt";
    char *mode="rb";
    wsk_plik = fopen(sciezka,mode);
char id[] ="ID", imie[] ="IMIE", nazwisko[] ="NAZWISKO", wiek[] ="WIEK", pesel[] ="PESEL", email[] ="EMAIL";
    if (wsk_plik != NULL){     
     printf("\n Zawartość struktury: %s\n", sciezka); 
     printf("\n %-10s \t %-10s \t %-10s \t %-10s \t %-10s \t %-10s \n", id, imie, nazwisko, wiek, pesel, email);   
     
     while ((fread(&s, sizeof(s), 1 ,wsk_plik)) != 0 ){
         drukuj(s);         
     }
    }
    else
        printf("\n Nie udało się otworzyć pliku: %s", sciezka);        
    printf("\n");
    fclose(wsk_plik);
}

void drukuj(tperson wsk){
  //  tperson *wsk = s;
    printf("  \n");
  //  while (wsk != NULL){ 
        printf("%-10d \t ", wsk.id);
        printf("%-10s \t ", wsk.imie);
	    printf("%-10s \t ", wsk.nazwisko);
	    printf("%-10d \t ", wsk.wiek);
        printf("%-10s \t ", wsk.PESEL);
	    printf("%-10s \n", wsk.email);
	
       // printf("\n");
    //    wsk=wsk->next;
    //}
   // printf("\n");
}

//BACKUP
void usun(){
    //    podaj id do usunięcia
    printf("\n Podaj ID do usnięcia: ");
    int usuwaneID;
    scanf("%d", &usuwaneID);
    /*
    utwórz listę/stos struktur z pliku bazy danych
    zamkinij plik i ponownie otwórz w trybie pisania od początku
    zapisz listę do pliku z pominięciem wskazanego id
    */
}

void dodaj(tperson tosoba){
 int size;
    FILE *wsk_plik;
    char *sciezka="bd.txt";
    char *mode="ab";
    wsk_plik = fopen(sciezka,mode);

    if (wsk_plik != NULL)
     fwrite(&tosoba, sizeof(tosoba), 1 ,wsk_plik);
    else
        printf("\n Nie udało się otworzyć pliku: %s", sciezka);
    fclose(wsk_plik);

}

void pokazBD(){
printf("\n Funkcja pokazBD(): \n");
    czytajZPlikuBin();
}

void zapisz(tperson tosoba){
    int size;
    FILE *wsk_plik;
    char *sciezka="bd.txt";
    char *mode="wb";
    wsk_plik = fopen(sciezka,mode);

    if (wsk_plik != NULL)
     fwrite(&tosoba, sizeof(tosoba), 1 ,wsk_plik);
    else
        printf("\n Nie udało się otworzyć pliku: %s", sciezka);
    fclose(wsk_plik);
}
 

void pokazStruktur(tperson s){
    //printf("%-10d \t ", s.id);
    printf("%-10d \t ", s.id);
    printf("%-10s \t ", s.imie);
	printf("%-10s \t ", s.nazwisko);
	printf("%-10d \t ", s.wiek);
    printf("%-10s \t ", s.PESEL);
	printf("%-10s \n", s.email);
}


void czytajZPlikuBin(){
    tperson s;
    int size, elem=1;
    FILE *wsk_plik;
    char *sciezka="bd.txt";
    char *mode="rb";
    wsk_plik = fopen(sciezka,mode);
char id[] ="ID", imie[] ="IMIE", nazwisko[] ="NAZWISKO", wiek[] ="WIEK", pesel[] ="PESEL", email[] ="EMAIL";
    if (wsk_plik != NULL){     
     printf("\n Zawartość struktury: %s\n", sciezka); 
     printf("\n %-10s \t %-10s \t %-10s \t %-10s \t %-10s \t %-10s \n", id, imie, nazwisko, wiek, pesel, email);   
     while ((fread(&s, sizeof(s), 1 ,wsk_plik)) != 0 ){
         pokazStruktur(s);         
     }
    }
    else
        printf("\n Nie udało się otworzyć pliku: %s", sciezka);        
    printf("\n");
    fclose(wsk_plik);
}
