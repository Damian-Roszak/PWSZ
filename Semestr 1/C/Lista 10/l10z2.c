#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

       
    
void czytajZPliku(char *sciezka, char *name);

void main(int argc, char *argv[]){

    char dostemp[1000];

    if(argc ==2){
        czytajZPliku(argv[1],argv[0]);
    }else{
        printf("Podaj ścieżkę dostępu do pliku: ");
        scanf("%s", dostemp);
        printf("\n name = %s\n", dostemp);
        czytajZPliku(dostemp, argv[0]);
    }



}

void czytajZPliku(char *sciezka, char *name){
    int max =1000;
    FILE *wsk_Plik;
    //char *sciezka="a.txt";
    char *mode="r";
    char s, ss[max];
    int sumaLiczb=0;
    
    if ((wsk_Plik = fopen (sciezka,mode)) != NULL){
    printf("\n");
    while ((s = fgetc(wsk_Plik)) != EOF){
    //while ((fgets(ss, max ,wsk_Plik)) != NULL){
       //fscanf(wsk_Plik, "%c", &s);
        printf("%c", s); if (s>=48 && s<=57) sumaLiczb++;
       //printf("%s", ss);
    }
    }
  printf("\n\n znaków będących liczbami w piku %s jest: %d\n", name, sumaLiczb);
  fclose(wsk_Plik);
}


