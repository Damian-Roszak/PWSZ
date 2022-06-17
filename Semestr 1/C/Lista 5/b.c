#include <stdio.h>

typedef struct pole_ab {
int a, b;
} Bok;

int f_pole (Bok pole);
int main (void)
{
    typedef int Licznik;
    typedef int Dlugosc;
    Bok pole;
    // struct pole_ab pole;
    Licznik i;
    // int i;
    Dlugosc max = 15;
    // int max = 15;
    for (i = 0; i < max; i++)
    {
        pole.a = i + 3;
        pole.b = pole.a + 7;
        printf("Pole (%d, %d) = %d\n", pole.a, pole.b, f_pole(pole));
    }
return 0;
}
int f_pole (Bok pole)
{
return pole.a * pole.b;
}
