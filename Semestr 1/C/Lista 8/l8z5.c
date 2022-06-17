#include<stdio.h>

// GOTOWE 


int dostawcaPoteg( int m)
{
    int wynik = 1, i;
    for (i=1; i<=m+1; i++)
      wynik *= (-1);

return wynik;    
}

float sumexSpZoo( int t)
{
    int i;
    float zwrot = 0;
    for (i=1; i<=t; i++) 
     zwrot += (1/(float)i)*(float)dostawcaPoteg(i);
            
return zwrot;
}


float sumeria(int l)
{
    int i;
    float elem = 0;
    for (i=1; i<=l; i++) 
    {
      if (i%2==0) elem += (1/(float)i)*(-1);
      if (i%2==1) elem += (1/(float)i)*(1);
    }
        
return elem;
}



int n;
float suma, sumka;

int main()
{
suma = 0;
do {
    printf("\n Podaj n: ");
    scanf("%d", &n);
} while(n<1);

    suma = sumexSpZoo(n);
    printf ("\n sumexSpZoo wynosi: %f", suma);
        
    sumka = sumeria(n);
    printf ("\n sumeria wynosi: %f\n\n", sumka);
        
        
return 0;
}
