#include "quicksort_calkowite.hpp"


void quicksort_calkowite(vector <int> &tc, int lewy, int prawy)
{
    clock_t stop, start = clock();
    int v=tc[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do
    {
        while (tc[i]<v) i++;
        while (tc[j]>v) j--;
        if (i<=j)
        {
            x=tc[i];
            tc[i]=tc[j];
            tc[j]=x;
            i++; j--;
        }
    }
    while (i<=j);
    if (j>lewy) quicksort_calkowite(tc,lewy, j);
    if (i<prawy) quicksort_calkowite(tc, i, prawy);
    
    stop = clock();
    cout << "\n quicksort_calkowite czas: " <<(stop - start)/CLOCKS_PER_SEC; 
}
