#include <stdio.h>
struct dane {
int wiek;
int *wsk_wiek;
};
struct info {
struct dane *z_dan;
};
int main (void)
{
    struct info inf1, *wsk_inf;
    wsk_inf = &inf1;
    struct dane dan1;
    dan1.wsk_wiek = &dan1.wiek;
    wsk_inf->z_dan = &dan1;
    wsk_inf->z_dan->wiek = 80;
    printf("%d\n", wsk_inf->z_dan->wiek);
    printf("%d\n", *wsk_inf->z_dan->wsk_wiek);
return 0;
}
