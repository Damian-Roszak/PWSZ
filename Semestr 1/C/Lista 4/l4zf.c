#include<stdio.h>

//GOTOWE


int main()
{
   int n;
   char zakoncz = 'n', opcja;
   
   
 while(zakoncz != 't')
 {  
 
 printf ("\n OPCJE: \n");
 printf ("\t a) traktowanie n jako wersów zgodnie z treścią zadania i opisem na zajęciach ma działać dla liczb nieparzystych\n");
 printf ("\t b) traktowanie n jako kolumn - 'warjacja na temat'\n");
 printf ("\t c) opcja odwrotna do zadania e dla nieparzystych\n");
// do {
     printf ("wybieram [tylko małe litery]: ");
     scanf("%c", &opcja);  
     stdin = freopen(NULL, "r",stdin); 
 //}while((opcja != 'a') && (opcja != 'b') && (opcja != 'c'));
 
   //stdin = freopen(NULL, "r",stdin);  
   
   
switch (opcja)
{
  case 'a' :
  {
       
       do
       {    
            printf ("\n Podaj n z przedziału <1,15>: ");
            scanf (" %d", &n);
       }while((n< 1) || (n> 15));
   
   printf("\n");
  
   for (int i = 1; i<=(n/2)+1; i++)
   {
        for (int j = n-i ; j> 1; j--) printf (" "); 
        
        for (int k= 1; k<=i; k++) printf("*");
        
        printf("\n");
   }
   
   for (int l = 1; l<=(n/2); l++)
   {
      for (int m = 1; m<(n/2)+l; m++) printf (" "); 
      for (int p = 1; p<=(n/2)-l+1; p++) printf("*");
    printf("\n");   
   }
   break;
  }
   
  case 'b':
  {
   
        printf ("\n Podaj n dowolna liczba większa od zera: ");
        scanf (" %d", &n);
   
   
   printf("\n");
   for (int i = 1; i<=n; i++)
   {
        for (int j = n-i; j>=1; j--) printf (" ");         
        for (int k= 1; k<=i; k++) printf("*");        
   printf("\n");
   }
   
   for (int i = 1; i< n; i++)
   {
      for (int j = 1; j<=i; j++) printf (" "); 
    for (int k = 0; k<n-i; k++) printf("*");
    printf("\n");   
   }
  break;
  }
   
  case 'c':
  {
        printf ("\nPodaj n dowolna liczba większa od zera: ");
        scanf (" %d", &n);   

  printf("\n");
   for (int i = 1; i<=((n/2)+1); i++)
   {
    for (int k = (n/2)-i; k>=0;  k--) printf(" ");
    for (int j= 1; j<=i; j++) printf("*");
   printf("\n");
   }
   
   for (int k = 1; k<=n/2; k++)
   {
    for (int o = 0; o < k; o++) printf(" ");
    for (int l = 0; l<(n/2)-k+1; l++) printf("*");
    printf("\n");   
   }
 break; 
  }
  
 default:
 printf("Nie ma takiej opcji");
 break; 
}    
    
   stdin = freopen (NULL, "r", stdin);
   printf("\n Zakończyć?: ");
   scanf (" %c", &zakoncz);
   stdin = freopen (NULL, "r", stdin);
 }  
return 0;
}


/*

   for (int i = 1; i<=n; i++)
   {
        for (int j = n-i; j>=1; j--) printf (" "); 
        
        for (int k= 1; k<=i; k++) printf("*");
        
   printf("\n");
   }
   
   for (int i = 1; i< n; i++)
   {
      for (int j = 1; j<=i; j++) printf (" "); 
    for (int k = 0; k<n-i; k++) printf("*");
    printf("\n");   
   }
  

  if (opcja == 'a')
  {
       
       do
       {    
            printf ("\n Podaj n z przedziału <1,15>: ");
            scanf (" %d", &n);
       }while((n< 1) || (n> 15));
   
   printf("\n");
  
   for (int i = 1; i<=(n/2)+1; i++)
   {
        for (int j = n-i ; j> 1; j--) printf (" "); 
        
        for (int k= 1; k<=i; k++) printf("*");
        
        printf("\n");
   }
   
   for (int l = 1; l<=(n/2); l++)
   {
      for (int m = 1; m<(n/2)+l; m++) printf (" "); 
      for (int p = 1; p<=(n/2)-l+1; p++) printf("*");
    printf("\n");   
   }
  }
   
*/


  /*
  if (opcja == 'a')
  {
   
   do
   {    
        printf ("\n Podaj n z przedziału <1,15>: ");
        scanf (" %d", &n);
   }while((n< 1) || (n> 15));
   
   printf("\n");
  
   for (int i = 1; i<n-3; i++)
   {
        for (int j = n-i; j>=1; j--) printf (" "); 
        
        for (int k= 1; k<=i; k++) printf("*");
        
        printf("\n");
   }
   
   for (int l = 1; l< n; l++)
   {
      for (int m = 1; m<=l; m++) printf (" "); 
      for (int p = 1; p<n-l-1; p++) printf("*");
      printf("\n");   
   }
  };
  if (opcja == 'b')
  {
   
        printf ("\n Podaj n dowolna liczba większa od zera: ");
        scanf (" %d", &n);
   
   
   printf("\n");
   for (int i = 1; i<=n; i++)
   {
        for (int j = n-i; j>=1; j--) printf (" "); 
        
        for (int k= 1; k<=i; k++) printf("*");
        
   printf("\n");
   }
   
   for (int i = 1; i< n; i++)
   {
      for (int j = 1; j<=i; j++) printf (" "); 
    for (int k = 0; k<n-i; k++) printf("*");
    printf("\n");   
   }
  
  }
    */
