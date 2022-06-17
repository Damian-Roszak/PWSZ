#include "bucket_calkowite.hpp"



void bucket_calkowite(vector <int> &tc)
{
    clock_t stop, start = clock();
   // 1) Create n empty buckets
    vector<float> b[tc.size()];
 
    // 2) Put array elements
    // in different buckets
    for (unsigned int i = 0; i < tc.size(); i++) {
        int bi = tc.size() * tc[i]; // Index in bucket
        b[bi].push_back(tc[i]);
    }
 
    // 3) Sort individual buckets
   // for (unsigned int i = 0; i < tc.size(); i++)
       // sort(b[i].begin(), b[i].end());
 
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (unsigned int i = 0; i < tc.size(); i++)
        for (unsigned int j = 0; j < b[i].size(); j++)
            tc[index++] = b[i][j];

    stop = clock();
    cout << "\n bucket_calkowite czas: " <<(stop - start)/CLOCKS_PER_SEC;  
}
