#include<stdio.h>

// GOTOWE 

long long int suma(long long int t)
{
    long long int i, zwrot = 0;
    for (i=0; i<=t; i++)   zwrot += i*i*i;
        
return zwrot;
}



long long int k, sum;

int main()
{
sum = 0;
printf("\n Podaj k: ");
scanf("%lld", &k);

    sum = suma(k);
    printf ("\n Suma wynosi: %lld\n", sum);
        
return 0;
}
