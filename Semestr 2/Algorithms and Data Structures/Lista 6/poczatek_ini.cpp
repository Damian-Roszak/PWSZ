#include "poczatek_ini.hpp"


    

void wypelnij_calkowite( vector <int> &tc1)
{
   // clock_t start = clock();
    
    unsigned int i;
    for( i=0; i<tc1.size(); i++)
    {
        tc1[i] = rand();
    }
    //clock_t stop = clock();
    //cout << "\n czas: " <<(stop - start)/CLOCKS_PER_SEC;
    
}
void wypelnij_calkowite2( vector <int> &tc1, int zakres)
{
   // clock_t start = clock();
    
    unsigned int i;
    for( i=0; i<tc1.size(); i++)
    {
        tc1[i] = rand()%zakres;
    }
    //clock_t stop = clock();
    //cout << "\n czas: " <<(stop - start)/CLOCKS_PER_SEC;
    
}

void wypelnij_rzeczywiste(  vector <double> &td)
{
    double tmp = 0.0;
    //cout.setf(ios::fixed); cout.precision(5);
    unsigned int i;
    for(i=0; i<td.capacity() ; i++)
    {
        tmp = (double)rand() + (double)(rand())/RAND_MAX;
        td[i]=tmp;
    //cout << "\n td["<<i<<"]; " <<  td[i];
    }
   // cout << "\n td.size(); " <<  td.size();
   // cout << "\n td.capacity(); " <<  td.capacity();
   // cout << endl;
    
}

/*
void poka_C(vector <int> &tc)
{
    unsigned int i;
    cout << "\n Pokazuje całkowite: ";
    for ( i=0; i<tc.capacity(); i++)
    {
        cout << "\n t[" << i+1 << "]=" << tc[i];
    }
}

void poka_D(vector <double> &td)
{
    unsigned int i;
    cout << "\n Pokazuje rzeczywiste: " << td.size();
    //cout.setf(ios::fixed); cout.precision(5);
    for ( i=0; i<td.capacity(); i++)
    {
        cout << "\n t[" << i+1 << "]=" << td[i];
    }
}
*/

