#include<stdio.h>

//GOTOWE

int main()
{
   int n, k, m;
   char zakoncz = 'n';
 
   
   do
   {
        printf ("\n Podaj n: ");
        scanf (" %d", &n);
   }
   while((n < 1) || (n > 15));
   
   
    
   k=0;

   for (int i = 1; i<=n; i++)
   {
    if (i<=n/2+1) k++;
    else k--;
    
    for (int p = 1; p <= n/2+1-k ; p++) printf(" ");
       
    for (int j = 1; j<= k; j++) printf("*");
          
   printf("\n"); 
   }
   
   
    printf("\n");printf("\n");
      
     
   k=0;
   m=n/2+1;
   for (int i = 1; i<=n; i++)
   {
    if (i<=n/2+1) k++;
    else k--;
    if (i<=n/2+1) {
        m--;
        for (int p = 1; p <= m ; p++) printf(" ");
        }
      else{
      m++;
        for (int p = 1; p <= m ; p++) printf(" ");
      }
    for (int j = 1; j<= k; j++) printf("*");
          
   printf("\n"); 
   }
   
   printf("\n");printf("\n");
  
   
return 0;
}
