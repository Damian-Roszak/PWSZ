#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>



void zapiszDoPliku(int tab[], int rozmiar);
void zapiszDoPlikuBin(int tab[], int rozmiar);
void czytajZPlikuBin(int rozmiar);

void main(){

srand(time(NULL));
int rozmiar=36;
int t[rozmiar];

    for (int i=0; i<rozmiar; i++){
        t[i]=rand()%36;
        printf("%d = %d\n", i, t[i]);
    }
    
zapiszDoPliku(t, rozmiar);
zapiszDoPlikuBin(t, rozmiar);
czytajZPlikuBin( rozmiar);

}

void czytajZPlikuBin(int rozmiar){
    int size, tab[rozmiar], elem=0;
    FILE *wsk_plik;
    char *sciezka="aa.txt";
    char *mode="rb";
    wsk_plik = fopen(sciezka,mode);

    if (wsk_plik != NULL){     
     printf("\n Zawartość pliku: %s\n", sciezka);   
     for (int i=0; i<rozmiar; i++){
         fread(&elem, sizeof(int), 1 ,wsk_plik);
         printf("\n\t %d) elem = %d",i, elem);
     }
    }
    else
        printf("\n Nie udało się otworzyć pliku: %s", sciezka);
        
        printf("\n");
    fclose(wsk_plik);
}

void zapiszDoPlikuBin(int tab[], int rozmiar){
    int size;
    FILE *wsk_plik;
    char *sciezka="aa.txt";
    char *mode="wb";
    wsk_plik = fopen(sciezka,mode);

    if (wsk_plik != NULL)
     fwrite(tab, sizeof(int)*rozmiar, rozmiar ,wsk_plik);
    else
        printf("\n Nie udało się otworzyć pliku: %s", sciezka);
    fclose(wsk_plik);
}


void zapiszDoPliku(int tab[], int rozmiar){
    int size;
    FILE *wsk_plik;
    char *sciezka="a.txt";
    char *mode="w";
    wsk_plik = fopen(sciezka,mode);

    if (wsk_plik != NULL)
     for (int i=0; i<rozmiar; i++){       
        char *c = malloc (sizeof(int));
        char *d = malloc (sizeof(int));
        size = sprintf(d, "%d", i); 
        strcat(d," = ");
        fprintf(wsk_plik, d, size);
        
        size = sprintf(c, "%d", tab[i]); 
        fprintf(wsk_plik, c, size);
        fprintf(wsk_plik, "\n");
        
        free(c); free(d);
     }
    fclose(wsk_plik);
}
