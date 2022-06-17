#include "heap_calkowite.hpp"


void heap_calkowite(vector <int> &tc)
{
    clock_t stop, start = clock();
   for (int i = tc.size() / 2 - 1; i >= 0; i--)
        sterta(tc, tc.size(), i);
 
    // One by one extract an element from heap
    for (int i = tc.size() - 1; i > 0; i--) {
        // Move current root to end
        swap(tc[0], tc[i]);
 
        // call max sterta on the reduced heap
        sterta(tc, i, 0);
    }


    stop = clock();
    cout << "\n heap_calkowite czas: " <<(stop - start)/CLOCKS_PER_SEC;  
}


void sterta(vector <int> &tc, int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && tc[l] > tc[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && tc[r] > tc[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(tc[i], tc[largest]);
 
        // Recursively sterta the affected sub-tree
        sterta(tc, n, largest);
    } 
}
