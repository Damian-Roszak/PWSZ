#include <stdio.h>
//#include<cstdio>

int main(){

    printf("\n\t Zadanie 1:\n");
    printf("\nDamian Roszak \n");
    printf("My street \n");
    printf(" My town \n");
    printf("Tel.: +48-private \n\n");
    
    
    printf("\n\t Zadanie 2:\n");
    printf("Poproszę o promień kuli, czyli r tutaj liczba int: ");
    int r;
    scanf("%d", &r);
    printf("\n Objętość kuli wynosi ( z zaokrągleniem do dwóch miejsc po przecinku ): %0.2f\n\n", 3.14*r*r*r*(4.0/3.0));
    
    
    printf("Poproszę o promień kuli, czyli r tutaj liczba float: ");
    float rf;
    scanf("%f", &rf);
    printf("\n Objętość kuli wynosi: %0.4f\n\n", 4.0/3*3.14*rf*rf*rf);
    
 
     printf("\n\t Zadanie 3:\n");   
     printf("Podaj A, B, C jako liczby całkowite:\n ");
     int A = 0, B = 0, C =0, D = 0;
     scanf("%d%d%d", &A,&B,&C);
     D = B*B - 4*A*C;
     printf("Delta wynosi = %d", D);
      
      
     printf("\n\nPodaj A, B, C jako liczby rzeczywiste:\n ");
     double AR = 0.0, BR = 0, CR =0, DR = 0;
     scanf("%le %lf %lg", &AR,&BR,&CR);
     DR = BR*BR - 4*AR*CR;
     printf("Delta wynosi = %f\n", DR);
     
     
     printf("\n\t Zadanie 4:\n"); 
     int zmiennaC;
     printf("\n Podaj zmienną C: ");
     scanf("%d", &zmiennaC);       
      while ( zmiennaC == 0 ){
        printf("\n Podaj zmienną C: ");
        scanf("%d", &zmiennaC);       
      };
     printf("Wyświetlam wartość obliczoną z wzoru = (C*2 - C+5)/(1/(C*C)) = %f\n", ((float)zmiennaC*2 - (float)zmiennaC+5)/(1/((float)zmiennaC*(float)zmiennaC)));
     
     int zmiennaC1;
     printf("\n Podaj zmienną C (wersja z skróconym wzorem): ");
     scanf("%d", &zmiennaC1);       
      while ( zmiennaC1 == 0 ){
        printf("\n Podaj zmienną C: ");
        scanf("%d", &zmiennaC);       
      };
     printf("Wyświetlam wartość obliczoną z wzoru = (C+5)*C*C) = %f\n", (zmiennaC1+5.0)*zmiennaC1*zmiennaC1);
     //((float)zmiennaC*(float)zmiennaC - ((float)zmiennaC+5))/(1/((float)zmiennaC*(float)zmiennaC))
    
     printf("\n\t Zadanie 5:\n");     
     printf("\n Podaj 2 Liczby: ");
     double a,b;
     scanf("%lf %lf", &a,&b);
     printf("\n1) Dodawanie a+b = %f", a+b);
     printf("\n2) Odejmowanie a-b = %f", a-b);
     printf("\n3) Mnożenie a*b = %f", a*b);
     printf("\n4) Dzielenie a/b = %f", a/b);
     printf("\n5) Suma kwadratów a*a + b*b = %f \n", a*a + b*b); 
     
     
return 0;
}
