#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>



typedef struct mn{ 
    struct mn *next;
    int id;
    char opcja1[30];
    char opcja2[50];
    char opcja3[12];
    char opcja4[50];
} tmenu;

typedef struct tp{ 
    struct tp *next, *befor;
    int id;
    char imie[30];
    char nazwisko[50];
    short wiek;
    char PESEL[12];
    char email[50];
} tperson;


tperson * zrobListe();
void wypiszListe(tperson *lista);
void dodajLISTA(tperson *tosoba, char *sciezka);
void pokazPlik(char *sciezka);
void menu();
void zapiszLISTA(tperson *tosoba, int index);
void usunStruct(char *sciezka);
void dodajStruct(char *sciezka);

void main(){
    srand(time(NULL));
    char *sciezka = "bd.txt";
    tperson *lista;
    
   // pokazPlik(sciezka);
   // dodajStruct(sciezka);
    //usunStruct(sciezka);
    pokazPlik(sciezka);
    //lista = zrobListe();
    //dodajLISTA(lista->next, "bd.txt");
    //wypiszListe(lista->next);
    //usunStruct(sciezka);
}


void dodajStruct(char *sciezka){
 tperson *nowy = malloc(sizeof(tperson));
        nowy->id = rand()%456;
        sprintf(nowy->imie,"imie%d",rand()%66+25);
        sprintf(nowy->nazwisko,"nazwisko%d",rand()%66+25);
        nowy->wiek = rand()%99;
        sprintf(nowy->PESEL,"PESEL%d",rand()%66+25);
        sprintf(nowy->email,"email%d",rand()%66+25);
        
    FILE *wsk_plik;
    //char *sciezka="bd.txt";
    char *mode="ab";
    wsk_plik = fopen(sciezka,mode);

    if (wsk_plik != NULL)
     fwrite(nowy, sizeof(*nowy), 1 ,wsk_plik);
    else
        printf("\n Nie udało się otworzyć pliku: %s", sciezka);
    fclose(wsk_plik);

}

void usunStruct(char *sciezka){
    printf("\n Podaj index do usunięcia: ");
    int i;
    scanf("%d",&i);
    tperson s;
    FILE *wsk_plik;
    //char *sciezka="bd.txt";
    char *mode="rb";
    wsk_plik = fopen(sciezka,mode);
    
    tperson *first, *nowy, *wsk;
    char *c;
    const int END = 5;
    
    first = malloc (sizeof(tperson));        
    first->next = NULL;
    wsk = first;    
    
    if (wsk_plik != NULL){
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
    fclose(wsk_plik);
   // wypiszListe(first->next);    
    }
    else
        printf("\n Nie udało się otworzyć pliku: %s", sciezka);        
    printf("\n");
    //zamkinij plik i ponownie otwórz w trybie pisania od początku
    zapiszLISTA(first->next, i);
    //zapisz listę do pliku z pominięciem wskazanego id
    pokazPlik(sciezka);
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


void menu(){

    tmenu *first, *nowy, *wsk;
    int i;
    const int END = 1;
    srand(time(NULL));
    
    first = malloc (sizeof(tperson));    
    
    first->next = NULL;
    wsk = first;
    
    for (i = 1; i<=END; i++){
        nowy = malloc(sizeof(tperson));
        /*
        nowy->id = i;
        sprintf(nowy->imie,"imie%d",rand()%66+25);
        sprintf(nowy->nazwisko,"nazwisko%d",rand()%66+25);
        nowy->wiek = rand()%99;
        sprintf(nowy->PESEL,"PESEL%d",rand()%66+25);
        sprintf(nowy->email,"email%d",rand()%66+25);
        */
        nowy->next = NULL;
        wsk->next = nowy;
        wsk=wsk->next;
    }
   // wypiszListe(first->next);
//return first;    
}

void pokazPlik(char *sciezka){
    tperson s;
    FILE *wsk_plik;
    //char *sciezka="bd.txt";
    char *mode="rb";
    wsk_plik = fopen(sciezka,mode);
    
    tperson *first, *nowy, *wsk;
    int i=2;
    //char *c;
    //const int END = 5;
    
    first = malloc (sizeof(tperson));    
    
    first->next = NULL;
    wsk = first;    
    
    if (wsk_plik != NULL){         
     while ((fread(&s, sizeof(s), 1 ,wsk_plik)) != 0 ){
        nowy = malloc(sizeof(tperson));
        //s.next = NULL;
        *nowy = s;
       /*
        nowy->id = s.id;
        strncpy(nowy->imie , s.imie, sizeof(s.imie));
        strncpy(nowy->nazwisko , s.nazwisko, sizeof(s.nazwisko));
        nowy->wiek = s.wiek;
        strncpy(nowy->PESEL , s.PESEL, sizeof(s.PESEL));
        strncpy(nowy->email , s.email, sizeof(s.email));
      */
        nowy->next = NULL;
        wsk->next = nowy;
        wsk=wsk->next;
    }    
    wypiszListe(first->next);
    }
    else
        printf("\n Nie udało się otworzyć pliku: %s", sciezka);        
    printf("\n");
    fclose(wsk_plik);
   
}

void dodajLISTA(tperson *tosoba, char *sciezka){
    tperson *wsk = tosoba;
    FILE *wsk_plik;
    //char *sciezka="bd.txt";
    char *mode="ab";
    wsk_plik = fopen(sciezka,mode);

    if (wsk_plik != NULL)
    // fwrite(&tosoba, sizeof(tosoba), 1 ,wsk_plik);
     while (wsk != NULL){ 
        // if(wsk->id != index)
         fwrite(wsk, sizeof(*tosoba), 1 ,wsk_plik);
         wsk=wsk->next;
     }  
    else
        printf("\n Nie udało się otworzyć pliku: %s", sciezka);
    fclose(wsk_plik);

}

tperson * zrobListe(){

    tperson *first, *nowy, *wsk;
    int i;
    char *c;
    const int END = 5;
    srand(time(NULL));
    
    first = malloc (sizeof(tperson));    
    
    first->next = NULL;
    wsk = first;
    
    for (i = 1; i<=END; i++){
        nowy = malloc(sizeof(tperson));
        
        nowy->id = rand()%456;
        sprintf(nowy->imie,"imie%d",rand()%66+25);
        sprintf(nowy->nazwisko,"nazwisko%d",rand()%66+25);
        nowy->wiek = rand()%99;
        sprintf(nowy->PESEL,"PESEL%d",rand()%66+25);
        sprintf(nowy->email,"email%d",rand()%66+25);
        
        nowy->next = NULL;
        wsk->next = nowy;
        wsk=wsk->next;
    }
   // wypiszListe(first->next);
return first;    
}


void wypiszListe(tperson *lista){
    tperson *wsk = lista;    
    char id[] ="ID", imie[] ="IMIE", nazwisko[] ="NAZWISKO", wiek[] ="WIEK", pesel[] ="PESEL", email[] ="EMAIL";
     printf("\n %-10s \t %-10s \t %-10s \t %-10s \t %-10s \t %-10s \n", id, imie, nazwisko, wiek, pesel, email);   
    while (wsk != NULL){
    
        printf("%-10d \t ", wsk->id);
        printf("%-10s \t ", wsk->imie);
	    printf("%-10s \t ", wsk->nazwisko);
	    printf("%-10d \t ", wsk->wiek);
        printf("%-10s \t ", wsk->PESEL);
	    printf("%-10s \t", wsk->email);
        
        printf("\n");
        wsk=wsk->next;
    }
    printf("\n");
}
 /*
    while (opcja != 't' && opcja != 'T'){        
        system("@cls||clear");
        printf("1) Dodaj Listę do bd.txt\n");
	    printf("2) Pokaż Listę:\n");
	    printf("3) Pokaż Plik bd.txt\n");
        printf("4) \n");
	    printf("0) Koniec \n");
	    scanf("%d", &opcja);	    
	    stdin = freopen(NULL, "r", stdin);
	    if (opcja == 1){
	        lista = zrobListe();
            dodajLISTA(lista->next, "bd.txt");
	    }
	    if (opcja == 2)  wypiszListe(lista->next);
	    if (opcja == 3)  pokazPlik(sciezka);
	    if (opcja == 4);
	    
    }*/
