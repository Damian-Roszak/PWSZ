#include<stdio.h>

//GOTOWE

int main()
{
   int n;
   char zakoncz = 'n';
   
 
 //for (n = 1; n<=15; n++)
 while(zakoncz != 't')
 {  
   printf ("\n Wersja zgodna z wymaganiami z zajęć dla nieparzystych (dla parzystych wykres zachowuje się jak dla następnej nieparzystej)");
   do
   {
        printf ("\n Podaj n: ");
        scanf (" %d", &n);
   }
   while((n< 1) || (n> 15));
   
   printf("\n");
  
  
  
   for (int i = 1; i<=((n/2)+1); i++)
   {
    for (int j= 1; j<=i; j++) printf("*");
   printf("\n");
   }
   
   for (int k = 1; k<=n/2; k++)
   {
    for (int l = 0; l<(n/2)-k+1; l++) printf("*");
    printf("\n");   
   }
  
    /*   
  
   for (int i = 1; i<=n-n/2; i++)
   {
    for (int j= 1; j<=i-1; j++) printf("*");
   printf("\n");
   }
   
   for (int i = 1; i<n-1; i++)
   {
    for (int j = 0; j<n-i-1; j++) printf("*");
    printf("W\n");   
   }  
    */
    
   stdin = freopen (NULL, "r", stdin);
   printf("\n Zakończyć?: ");
   scanf (" %c", &zakoncz);
   stdin = freopen (NULL, "r", stdin);
 }  
return 0;
}
