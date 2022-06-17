#include"mala_klasa.hpp"

void Mala_Klasa::wypelnij()
{
    for (int i=0; i<rand()%10; i++)
    {
        wektor_zbioru.push_back(rand()%100); 
        cout << endl << " wektor_zbioru[" << i+1 << "]= " << wektor_zbioru[i];
    }
}

int Mala_Klasa::minimum()
{
    int mini = wektor_zbioru[0];
    
    for (unsigned int i=0; i<wektor_zbioru.size(); i++)
        if (mini > wektor_zbioru[i]) mini = wektor_zbioru[i];

    cout << endl << " mini = " << mini;
return mini;
}


int Mala_Klasa::maksimum()
{
    int maksi = wektor_zbioru[0];
    for (unsigned int i=0; i<wektor_zbioru.size(); i++)
        if (maksi < wektor_zbioru[i]) maksi = wektor_zbioru[i];  
    
    cout << endl << " maksi = " << maksi;
return maksi;
}

double Mala_Klasa::srednia()
{
    double sr = 0;
    for (unsigned int i=0; i<wektor_zbioru.size(); i++)
        sr += wektor_zbioru[i];  
        
    cout << endl << " sr = " << sr/wektor_zbioru.size(); 
return sr/(double)wektor_zbioru.size();
}


double Mala_Klasa::mediana()
{
    double md =0.0;
    unsigned int i,j, tmp;
    
    for ( i=0; i<wektor_zbioru.size(); i++)
     for ( j=1; j<wektor_zbioru.size()-i; j++)
        if (wektor_zbioru[j-1] > wektor_zbioru[j])
        {
            tmp = wektor_zbioru[j-1];
            wektor_zbioru[j-1] = wektor_zbioru[j];
            wektor_zbioru[j] = tmp;
        }
   
   // for ( i=0; i<wektor_zbioru.size(); i++)
      //  cout << endl << i+1 << " = " << wektor_zbioru[i];
    
    if (wektor_zbioru.size()%2 == 0)
    {
        md = (wektor_zbioru[wektor_zbioru.size()/2-1] + wektor_zbioru[(wektor_zbioru.size()/2)])/2 ;
    }
    else
    {
        md = wektor_zbioru[wektor_zbioru.size()/2];
    }
       
       cout << endl << " md = " << md; 
  cout << endl;      
return md;
}

int Mala_Klasa::dominanta()
{
    int licznik, powt_elem=0, najcz_elem;
        int ile = liczby.size(); 
        int *powtorki = new int[liczby.size()];
        
        for (int i = 0; i < ile; i++) {
            powtorki[i] = liczby[i];
        }
        
        for (int i = 0; i < ile; i++)
        {
            licznik = 0;
            
            for (int j = 0; j < ile; j++) {
                if (powtorki[i] == powtorki[j]) {
                    licznik++;
                }
            }
            if (licznik > powt_elem)
            {
                powt_elem = licznik;
                najcz_elem = powtorki[i];
            }
        }
        cout << "Dominanta: Element " << najcz_elem << " wystepuje " << powt_elem << " razy.";
    
   
    //cout << endl; 
return dom;
}

