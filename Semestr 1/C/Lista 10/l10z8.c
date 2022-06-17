#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>

typedef struct element{
    struct element *next, *befor;
    int id;
    char imie[30];
    char nazwisko[50];
    short wiek;
    char PESEL[12];
    char email[50];
    
}el_listy;


void wypiszListe(el_listy *lista);
void zrobListe();
void czytajPlik();

int main(){
    srand(time(NULL));
    //zrobListe();    
    czytajPlik();
}


void czytajPlik(){
    el_listy s;
    FILE *wsk_plik;
    char *sciezka="bd.txt";
    char *mode="rb";
    wsk_plik = fopen(sciezka,mode);
    
    el_listy *first, *nowy, *wsk;
    int i;
    char *c;
    const int END = 5;
    
    first = malloc (sizeof(el_listy));    
    
    first->next = NULL;
    wsk = first;
    
    
    if (wsk_plik != NULL){     
     printf("\n Tworzenie LISTY\n"); 
    
     while ((fread(&s, sizeof(s), 1 ,wsk_plik)) != 0 ){
        nowy = malloc(sizeof(el_listy));
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
    wypiszListe(first->next);
    }
    else
        printf("\n Nie udało się otworzyć pliku: %s", sciezka);        
    printf("\n");
    fclose(wsk_plik);
}

void zrobListe(){

    el_listy *first, *nowy, *wsk;
    int i;
    char *c;
    const int END = 5;
    srand(time(NULL));
    
    first = malloc (sizeof(el_listy));    
    
    first->next = NULL;
    wsk = first;
    
    for (i = 1; i<=END; i++){
        nowy = malloc(sizeof(el_listy));
        
       // nowy->val = i;
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
    wypiszListe(first->next);
    
}

void wypiszListe(el_listy *lista){
    el_listy *wsk = lista;
    printf("  \n");
    while (wsk != NULL){
       // printf("val %-10d \t", wsk->val);
        printf("id %-10d \t", wsk->id);
        printf("imie %-10s \t", wsk->imie);
        printf("nazwisko %-10s \t", wsk->nazwisko);
        printf("wiek %-10d \t", wsk->wiek);
        printf("PESEL %-10s \t", wsk->PESEL);
        printf("email %-10s \t", wsk->email);
        
        printf("\n");
        wsk=wsk->next;
    }
    printf("\n");
}
