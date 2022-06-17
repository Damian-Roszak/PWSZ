#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

typedef struct element{
    struct element *next;
    int val;
    int id;
    int wiek;
    
}el_listy;


void wypiszListe(el_listy *lista);

int main(){

    el_listy *first, *nowy, *wsk;
    int i;
    const int END = 5;
    srand(time(NULL));
    
    first = malloc (sizeof(el_listy));
    first->val = 2;
    
    first->next = NULL;
    wsk = first;
    
    for (i = 1; i<=END; i++){
        nowy = malloc(sizeof(el_listy));
        
        nowy->val = i;
        nowy->id = rand()%456;
        nowy->wiek = rand()%99;
        
        nowy->next = NULL;
        wsk->next = nowy;
        wsk=wsk->next;
    }
    wypiszListe(first);
    
return 0;
}

void wypiszListe(el_listy *lista){
    el_listy *wsk = lista;
    printf("  \n");
    while (wsk != NULL){
        printf("val %d \t", wsk->val);
        printf("id %d \t", wsk->id);
        printf("wiek %d \t", wsk->wiek);
        printf("\n");
        wsk=wsk->next;
    }
    printf("\n");
}
