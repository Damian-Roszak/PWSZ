#include<stdio.h>

//GOTOWE

int main()
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
   while((n < 1) || (n > 15));
   
   
   for (int i = 1; i<=n; i++)
   {
    for (int j = 1; j<=n-i+1; j++)
    {
      printf("*");  
    }
   printf("\n");
   }
    
   stdin = freopen (NULL, "r", stdin);
   printf("\n Zakończyć?: ");
   scanf (" %c", &zakoncz);
   stdin = freopen (NULL, "r", stdin);
 }  
return 0;
}
