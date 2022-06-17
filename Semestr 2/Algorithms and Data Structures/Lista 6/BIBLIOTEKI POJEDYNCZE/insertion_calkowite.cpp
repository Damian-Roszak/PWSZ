#include "insertion_calkowite.hpp"



void insertion_calkowite(vector <int> &tc)
{ 
   clock_t stop, start = clock();
   
   unsigned int i, j;
    int k;
  /*for(i=1; i<tc.size(); i++) {
      k=tc[i];
      j=i-1;
      while (j>0 && tc[j]>k)
      {
        tc[j+1] = tc[j];
        j--;
      }
      tc[j+1] = k;
   } */
   
   for(i=1; i<tc.size(); i++) {
      k=tc[i];
      j=i-1;
      while (j>0 && tc[j]>k)
      {
        tc[j+1] = tc[j];
        j--;
      }
      tc[j+1] = k;
   } 

    stop = clock();
    cout << "\n insertion_calkowite czas: " <<(stop - start)/CLOCKS_PER_SEC;
    
}
