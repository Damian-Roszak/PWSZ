#include <stdio.h>

struct info {
char imie[30];
int wiek;
float waga;
} dane = {"Kasia", 19, 53.3};

void x (void);
int main (void)
{
    struct info dk, *wsk, *wsk_dk;
    dk = dane;
    wsk = &dane;
    wsk_dk = &dk;
    printf("%s\t%d\t%.2fkg\n", wsk_dk->imie, wsk_dk->wiek, wsk_dk->waga);
    printf("%s\t%d\t%.2fkg\n", (*wsk_dk).imie, (*wsk_dk).wiek, (*wsk_dk).waga);
    printf("%s\t%d\t%.2fkg\n", wsk->imie, wsk->wiek, wsk->waga);
    printf("%s\t%d\t%.2fkg\n", (*wsk).imie, (*wsk).wiek, (*wsk).waga);
    x();
    printf("%s\t%d\t%.2fkg\n", wsk_dk->imie, wsk_dk->wiek, wsk_dk->waga);
    printf("%s\t%d\t%.2fkg\n", (*wsk_dk).imie, (*wsk_dk).wiek, (*wsk_dk).waga);
    printf("%s\t%d\t%.2fkg\n", wsk->imie, wsk->wiek, wsk->waga);
    printf("%s\t%d\t%.2fkg\n", (*wsk).imie, (*wsk).wiek, (*wsk).waga);
return 0;
}
void x (void)
{
dane.wiek = 0;
dane.waga = 0.0;
}
