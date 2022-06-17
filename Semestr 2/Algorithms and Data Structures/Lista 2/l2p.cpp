#include <iostream>


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
