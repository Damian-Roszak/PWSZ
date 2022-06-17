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
        printf ("\n Podaj n <1,15>: ");
        scanf (" %d", &n);
   }while((n< 1) || (n> 15));
   
   printf("\n");
   
       // printf ("\n Podaj n dowolne: ");
      //  scanf (" %d", &n);
   
   
   printf("\n");
   
   for (int i = n; i>=1; i--)
   {
    for (int j = n-i; j>=1; j--) printf (" "); 
    
    for (int k=2*i-2; k>=0; k--) printf("*");
   printf("\n");
   } 
    
    
   stdin = freopen (NULL, "r", stdin);
   printf("\n Zakończyć?: ");
   scanf (" %c", &zakoncz);
   stdin = freopen (NULL, "r", stdin);
 }  
return 0;
}

/*
  for (int i = n; i>=1; i--)
   {
    for (int j = n-i; j>=1; j--)
    {
      printf (" "); 
    }
    for (int k=2*i-2; k>=0; k--) printf("*");
   printf("\n");
   }

*/
