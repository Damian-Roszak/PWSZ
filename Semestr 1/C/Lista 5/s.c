#include <stdio.h>
struct informacja {
int x, y, z;
};
struct informacja przypiszWartosci (int x, int y, int z)
{
struct informacja tmp;
tmp.x = x;
tmp.y = y;
tmp.z = z;
return tmp;
}
struct informacja dodajWartosci (struct informacja info, int px, int py,
int pz);
void odejmij (struct informacja *info, int px, int py, int pz);
int main (void)
{
struct informacja info1, info2;
info1 = przypiszWartosci(10, 100, 1000);
printf("%d %d %d\n", info1.x, info1.y, info1.z);
info2 = dodajWartosci(info1, 40, 50, 60);
printf("%d %d %d\n", info2.x, info2.y, info2.z);
odejmij(&info2, 100, 300, 500);
printf("%d %d %d\n", info2.x, info2.y, info2.z);
printf("%p %p %p %p\n", &info1, &info1.x, &info1.y, &info1.z);
printf("%p %p %p %p\n", &info2, &info2.x, &info2.y, &info2.z);
return 0;
}
/*
struct informacja przypiszWartosci (int x, int y, int z)
{
struct informacja tmp;
tmp.x = x;
tmp.y = y;
tmp.z = z;
return tmp;
}*/
struct informacja dodajWartosci (struct informacja info, int px, int py, int pz)
{
    info.x += px;
    info.y += py;
    info.z += pz;
return info;
}
void odejmij (struct informacja *info, int px, int py, int pz)
{
info->x -= px;
info->y -= py;
info->z -= pz;
}
