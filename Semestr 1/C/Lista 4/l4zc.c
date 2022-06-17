#include<stdio.h>

//GOTOWE


void main(void)
{
   int n;
   char zakoncz = 'n';
   
 while(zakoncz != 't')
 {  
   
   do
   {
        printf ("\n Podaj n: ");
        scanf (" %d", &n);
   }
   while((n< 1) || (n>15));
   printf("\n");
   
   for (int i = 1; i<=n; i++)
   {
    for (int j = 0; j<n-i; j++)
    {
      printf (" "); 
    }
    for (int k=0; k<2*i-1; k++) printf("*");
   printf("\n");
   }
    
    
   stdin = freopen (NULL, "r", stdin);
   printf("\n Zakończyć?: ");
   scanf (" %c", &zakoncz);
   stdin = freopen (NULL, "r", stdin);
 }  
//return 0;
}
