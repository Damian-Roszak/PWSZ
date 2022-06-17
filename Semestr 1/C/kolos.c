#include<stdio.h>
//#include<

int main(){

int i,j,k=0,N=17;

//printf("Podaj N: ");
//scanf("%d", &N);
char tab[] = {'$','#','!','\0'};

for (i = 0; i<N; i++){
for (j=0; j<N; j++){
    if(k>2) k=0;    
    printf("%c", tab[k]);
    k++;
}
printf("\n");
}





return 0;
}
