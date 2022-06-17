#include "selection_calkowite.hpp"

void selection_calkowite(vector <int> &tc)
{
    
   clock_t stop, start = clock();    
   unsigned int i, j, k;
   for(i=0; i<tc.size(); i++) {
      k=i;
      for(j=i+1; j<tc.size(); j++) if(tc[j]<tc[k]) k=j;
      swap(tc[k], tc[i]);
   }
    stop = clock();
    cout << "\n selection_calkowite czas: " <<(stop - start)/CLOCKS_PER_SEC;
    
}
