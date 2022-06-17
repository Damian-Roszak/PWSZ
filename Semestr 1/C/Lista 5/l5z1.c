#include<stdio.h>

// GOTOWE

int NWDw1(int a, int b)
{
    while (a!=b)
        if (a>b)
            a-=b; 
        else
            b-=a;
            
return a;
}

int NWDw1rekursja(int a, int b)
{
    if(a!=b)
        return NWDw1rekursja(a>b ? a-b : a , b>a ? b-a : b);
    return a;
}


int NWDw2modulo(int a, int b)
{
    int pom;
    while(b!=0)
    {
        pom = b;
        b = a%b;
        a = pom;
    }
return a;
}


int NWDw2moduloRekursja(int a, int b)
{
    if(b!=0)
        return NWDw2moduloRekursja(b, a%b);
    return a;
}



int main()
{
    int a,b;
    do{
        printf("\n\t\t\033[91;47;4;1m Podaj a i b (obie nieujemne):\033[0m \033[97m");
        scanf("%d %d", &a, &b);   
    }while(a<0 || b<0);
    
printf("\n\033[96m OPCJA 1:\033[93m Algorytm Euklidesa z odejmowaniem NWDw1 \033[0m"); 
    printf("\nNWD %d i %d wynosi: %d\n", a, b, NWDw1(a,b));


printf("\n\033[97m OPCJA 1.a:\033[93m Algorytm Euklidesa rekurencja wersji 1\033[0m");
printf("\nNWD %d i %d wynosi: %d\n", a, b, NWDw1rekursja(a,b));


printf("\n\n\033[93m OPCJA 2:\033[96m Algorytm Euklidesa modulo\033[0m");
printf("\nNWD %d i %d wynosi: %d\n", a, b, NWDw2modulo(a,b));


printf("\n\033[91m OPCJA 2.a:\033[97m Algorytm Euklidesa rekurencja wersji 2\033[0m");
printf("\nNWD %d i %d wynosi: %d\n\n", a, b, NWDw2moduloRekursja(a,b));


return 0;
}
