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

void PrintElements(struct tp *node);
void AddOnStart(struct tp** node, tperson *data);
void zapisz(tperson tosoba);
void usun();
void pokazStruktur(tperson s);
void dodaj();
void pokazBD();
void czytajZPlikuBin();


void zapiszLISTA(tperson tosoba);
void usunLISTA();
void pokazStrukturLISTA(tperson s);
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
    int size, elem=1, czek=0;
    FILE *wsk_plik;
    char *sciezka="bd.txt";
    char *mode="rb";
    wsk_plik = fopen(sciezka,mode);
    //podaj id do usunięcia
    //printf("\n Podaj ID do usnięcia: ");
    //int usuwaneID;
   // scanf("%d", &usuwaneID);
    
    //utwórz listę/stos struktur z pliku bazy danych
    tperson *first, *nowy, *bierzacy, *tmp, *lista;
    first = malloc(sizeof(tperson));
    
    
      // printf("\t first.next %p \n",first->next);
     
    if (wsk_plik != NULL){     
     printf("\n Tworzenie LISTY\n"); 
        fread(&s, sizeof(s), 1 ,wsk_plik);
        first = &s;
        first->next = NULL;
        bierzacy = first;
        
        //first->next = NULL;
       //pokazStruktur(*first);
      // pokazStruktur(*bierzacy);
        
//     printf("\n %p \n", first->next);
     while ((fread(&s, sizeof(s), 1 ,wsk_plik)) != 0 ){
        // pokazStruktur(s);       
        // AddOnStart(&first, &s);   
        nowy = malloc(sizeof(tperson));
        nowy = &s;
        nowy->next = NULL;
                 pokazStruktur(*first);
        bierzacy->next = nowy;
        bierzacy = bierzacy->next;
     } 
    // bierzacy = first;
    pokazStruktur(*first);
   // PrintElements(first);
     while( bierzacy != NULL){
     elem++;     
    // PrintElements(first);
       // pokazStruktur(*bierzacy);
       // bierzacy = bierzacy->next;
        //first = first->next;
      if(elem > 5) break;   
     }
     
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

void PrintElements(struct tp *node)
{
    while(node != NULL)
    {
        //printf("%d ", node->x);
        pokazStruktur(*node);
        node = node->next;
    }
}

void AddOnStart(struct tp** node, tperson *data)
{
    tperson* newNode = malloc(sizeof(tperson));
    newNode = data;
    if(*node == NULL)
    {
        newNode->next = NULL;
        *node = newNode;
        return;
    }
    newNode->next = *node;
    *node = newNode;
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

void zapiszLISTA(tperson tosoba){
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
 

void pokazStrukturLISTA(tperson s){
    printf("%-10d \t ", s.id);
    printf("%-10s \t ", s.imie);
	printf("%-10s \t ", s.nazwisko);
	printf("%-10d \t ", s.wiek);
    printf("%-10s \t ", s.PESEL);
	printf("%-10s \n", s.email);
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
         pokazStrukturLISTA(s);         
     }
    }
    else
        printf("\n Nie udało się otworzyć pliku: %s", sciezka);        
    printf("\n");
    fclose(wsk_plik);
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
