#include<stdio.h>

//GOTOWE

int main()
{
   int n, k, m=0;
   char zakoncz = 'n';
 
   
   do
   {
        printf ("\n Podaj n: ");
        scanf (" %d", &n);
   }
   while((n < 1) || (n > 15));
   
   
   
   k=n;
   
   for (int i = 1; i<=n; i++)
   {
    
    //for (int p = k; p > 1 ; p-- ) printf(" ");
    for (int p = 1; p <k ; p++) printf(" ");
    
    for (int j = 1; j<= 2*i-1; j++) printf("*");  
    
   printf("\n"); k--;
   }
   
   printf("\n");printf("\n");
   
  
   k=0;
   
   for (int i = 1; i<=n; i++)
   {
    
    //for (int p = k; p > 1 ; p-- ) printf(" ");
    for (int p = 1; p <= n-i ; p++) printf(" ");
    
    for (int j = 1; j<= i+ k; j++) printf("*");  
    
   printf("\n"); k++;
   }
   
return 0;
}
