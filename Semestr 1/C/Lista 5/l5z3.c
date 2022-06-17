#include <stdio.h>




char zakoncz = 'n', bin[16];

int liczbaDoKonwersji, liczba, i, n, bityNoLimit, bity;
long int zakres, liczbaDoKonwersjiNoLimit, liczbaNoLimit;
double x, potega; 

int main()
{

while ( zakoncz != 't' && zakoncz !='T')
{
  
  do{
    printf("\n\033[97m Podaj liczbę do konwersji <1,65535> :\033[0m ");
    scanf("%d", &liczbaDoKonwersji);
  }while(liczbaDoKonwersji<0 || liczbaDoKonwersji>65535);
  
printf("\n\033[93m OPCJA z stałym rozmiarem tablicy 16\033[0m");  
  liczba = liczbaDoKonwersji;  
  i = 0;
  for (int i = 0; i <= 15; i++) 
  {
    bin[i] = 0;
  }      
  while(liczba != 0)
  {
    int reszta = liczba % 16;
    switch (reszta)
    {
        case 0 :
             bin[i] = 48;
             break;
        case 1:
             bin[i] = 49;
             break;
        case 2:
             bin[i] = 50;
             break;
        case 3:
             bin[i] = 51;
             break;
        case 4:
             bin[i] = 52;
             break;
        case 5 :
             bin[i] = 53;
             break;
        case 6:
             bin[i] = 54;
             break;
        case 7:
             bin[i] = 55;
             break;
        case 8:
             bin[i] = 56;
             break;
        case 9:
             bin[i] = 57;
             break;
        case 10 :
             bin[i] = 'A';
             break;
        case 11:
             bin[i] = 'B';
             break;
        case 12:
             bin[i] = 'C';
             break;
        case 13:
             bin[i] = 'D';
             break;
        case 14:
             bin[i] = 'E';
             break;
        case 15:
             bin[i] = 'F';
             break;
        default:
            printf(" Błąd zakresu liczba modulo 16 ");
    }
   
     liczba /= 16;
     i++;    
  }  
  printf ("\n\033[96;1m liczba = \033[0m");  
  for (int i = 15; i >= 0; i--) 
  {    
    printf ("%c", bin[i]);
  }
    


  
stdin = freopen(NULL, "r", stdin);
printf("\n Zakończyć [t/n]: ");
scanf("%c", &zakoncz);
stdin = freopen(NULL, "r", stdin);
}
return 0;
}
