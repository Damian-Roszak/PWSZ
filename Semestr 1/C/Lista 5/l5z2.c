#include<stdio.h>
#include<math.h>
#include <limits.h>

//GOTOWE

char zakoncz = 'n';
int liczbaDoKonwersji, liczba, i, n, bin[16], bityNoLimit, bity;
long int zakres, liczbaDoKonwersjiNoLimit, liczbaNoLimit;
double x, potega;  

int main()
{

while ( zakoncz != 't' && zakoncz !='T')
{
  
  do{
    printf("\n\033[97m Podaj liczbę do konwersji <1,65535> :\033[0m ");
    scanf("%d", &liczbaDoKonwersji);
  }while(liczbaDoKonwersji<1 || liczbaDoKonwersji>65535);
  
printf("\n\033[93m OPCJA z stałym rozmiarem tablicy 16\033[0m");  
  liczba = liczbaDoKonwersji;  
  i = 0;
  for (int i = 0; i <= 15; i++) 
  {
    bin[i] = 0;
  }      
  while(liczba != 0)
  {
    bin[i] = liczba % 2;
     liczba /= 2;
     i++;    
  }  
  printf ("\n\033[96;1m liczba = \033[0m");  
  for (int i = 15; i >= 0; i--) 
  {    
    printf ("%d", bin[i]);
    if (i%4 == 0) printf(" ");
  }
    
    
    
printf("\n\n\033[93m OPCJA z obliczaniem ilości bitów potrzebnych do wyrażenia danej liczby dziesiętnej binarnie i na tej podstawie utworzenie tablicy do zapamiętania tej liczby dwójkowej\033[0m");  
     i = 0;
    liczba = liczbaDoKonwersji;
    printf("\nlog2(%g) = %g", liczbaDoKonwersji + 1.0, log2( liczbaDoKonwersji + 1.0));
    //x = log2( liczbaDoKonwersji + 1.0);
    x = ceil(log2( liczbaDoKonwersji + 1.0));
    potega = pow(2,x);
    printf("\n\033[93;1m potęga 2^%g = %g\033[0m", x, potega);
    bity = (int)x;
    int binLiczba[bity];
    while (liczba > 0)
    {
        binLiczba[i] = liczba % 2;
        liczba /= 2;
        i++;
    }
     
  printf ("\n\033[96;1m liczba = \033[0m");  
  for (int i = bity-1; i >= 0; i--) 
  {    
    printf ("%d", binLiczba[i]);
    if (i%4 == 0) printf(" ");
  }
    
 

        
stdin = freopen(NULL, "r", stdin);
zakres = pow(2, (int)(sizeof(int) * 8));
printf("\n\n\033[93m OPCJA z ograniczeniem do int = %d\033[0m", INT_MAX); 

  
  do{
    printf("\n\033[97m Podaj liczbę do konwersji <1, %ld> :\033[0m ", ((zakres/2) - 1));
    scanf("%ld", &liczbaDoKonwersjiNoLimit);    
  }while(liczbaDoKonwersjiNoLimit<1 || liczbaDoKonwersjiNoLimit>INT_MAX);
  
     i = 0;
    liczbaNoLimit = liczbaDoKonwersjiNoLimit;
    
    printf("\nliczba := %ld log2(%ld) = %g",  liczbaDoKonwersjiNoLimit , liczbaDoKonwersjiNoLimit, log2( liczbaDoKonwersjiNoLimit));
    
    //x = log2( liczbaDoKonwersji + 1.0);
    x = ceil(log2( liczbaDoKonwersjiNoLimit ));
    potega = pow(2,x);
    
    printf("\n\033[93;1m potęga 2^%g = %.16g\033[0m", x, potega);

    bityNoLimit = (int)x;
    
    int binLiczbaNoLimit[bityNoLimit];

    while (liczbaNoLimit > 0)
    {
        binLiczbaNoLimit[i] = liczbaNoLimit % 2;
        liczbaNoLimit /= 2;
        i++;
    }
       
  printf ("\n\033[96;1m liczba = \033[0m");  
  for (int i = bityNoLimit-1; i >= 0; i--) 
  {    
    printf ("%d", binLiczbaNoLimit[i]);
    if (i%4 == 0) printf(" ");
  }
    
    
    
stdin = freopen(NULL, "r", stdin);
printf("\n Zakończyć [t/n]: ");
scanf("%c", &zakoncz);
stdin = freopen(NULL, "r", stdin);
}
return 0;
}
