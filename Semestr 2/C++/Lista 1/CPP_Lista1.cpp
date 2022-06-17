#include<stdio.h>

int main(){

printf("\nrysunek 1: \n");
char a[]={'*','.'};
int k = 0;
    for (int i = 0; i<3; i++){
        printf("%c",a[k]);
        k++;
        if (k>1) k=0;
        if (i>1) for(int j = 0; j<2; j++) {
            printf("%c",a[k]);
            k++;
            if (k>1) k=0;
        }
        printf("\n");
    }

printf("\nrysunek 2: \n");
k = 0;
    for (int i = 0; i<3; i++){
       if (i<2) printf("  %c",a[k]);
        k++;
        if (i>1) for(int j = 0; j<3; j++) {
        if (k>1) k=0;
            printf("%c",a[k]);
            k++;
            
        }
        printf("\n");
    }

printf("\nrysunek 3: \n");
int n = 3;
for (int i = 1; i<=n; i++)
   {
    for (int j = 0; j<n-i; j++)
    {
      printf (" "); 
    }
    for (int k=0; k<2*i-1; k++) printf("*");
   printf("\n");
   }


printf("\nrysunek 4: \n");
for (int i = 0; i <5; i++){
 for (int j = 0; j<5; j++){
    if((i==j) || (i+j==4)) printf("*");
    else
    printf(" ");
}
printf("\n");
}
return 5;
}
