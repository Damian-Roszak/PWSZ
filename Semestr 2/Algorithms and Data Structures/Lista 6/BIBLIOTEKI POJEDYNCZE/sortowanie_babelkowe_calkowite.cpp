#include "sortowanie_babelkowe_calkowite.hpp"

void sortowanie_babelkowe_calkowite(vector <int> &tc)
{
    unsigned int i,j,tmp;
    
    clock_t stop, start = clock();    
    
    for ( i=0; i<tc.size(); i++)
     for ( j=1; j<tc.size()-i; j++)
        if (tc[j-1] > tc[j])
        {
            tmp = tc[j-1];
            tc[j-1] = tc[j];
            tc[j] = tmp;
        }
    
    stop = clock();
    cout << "\n sortowanie_babelkowe_calkowite czas: " <<(stop - start)/CLOCKS_PER_SEC;
}

