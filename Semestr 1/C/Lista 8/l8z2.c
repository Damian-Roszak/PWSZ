#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// GOTOWE

int silnia(int t)
{
    int zwrot =1;
    if (t<0)
        printf ("Silnie liczymy tylko dla naturalnych");
    else if (t!=0 && t!=1)
        for (int i=1; i<=t; i++)   zwrot *= i;
        
return zwrot;
}



int n, sil;
int main()
{
sil = 0;
printf("\n Podaj n: ");
scanf("%d", &n);

sil = silnia(n);
    if (n>=0) 
        printf ("\n Silnia wynosi: %d\n", sil);
    else
        printf ("\n Błąd przetwarzania podane n=%d, jest ujemne\n", n);

return 0;
}
