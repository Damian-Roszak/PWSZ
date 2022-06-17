#include <iostream>

using namespace std;

void rysuj(int p, int q)
{
    const char stosik[] = { 'a', 'b', 'c' };
    cout << stosik[p] << " -> " << stosik[q] << endl;
}

void Hanoja(int n, int a, int b, int c)
{
    if (n > 1) Hanoja(n - 1, a, c, b);
    rysuj(a, c);
    if (n > 1) Hanoja(n - 1, b, a, c);
}

int main()
{
    int n;
    cout << "Liczba krążków: ";
    cin >> n;
    if (n > 0)
        Hanoja(n, 0, 1, 2);
    else
        cout << "Problem z liczbą krążków.\n";
    return 0;
}
