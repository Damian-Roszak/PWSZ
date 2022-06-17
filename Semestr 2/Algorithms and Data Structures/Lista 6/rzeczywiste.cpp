#include "rzeczywiste.hpp"
#include <fstream>
#include <climits>



void menu4_D (vector <double> &td1,vector <double> &td2,vector <double> &td3,vector <double> &td4,vector <double> &td5,vector <double> &td6,vector <double> &td7,vector <double> &td8,vector <double> &td9,vector <double> &td10)
{
    
char opcja;
                    cout << "\n\t ++++ Sortowanie WYBRANEJ predefiniowanEJ tablicY WSZYSTKIMI algorytmami  ++++\n";
                    cout << "\t 1) 30k \n";
                    cout << "\t 2) 50k \n";
                    cout << "\t 3) 100k \n";
                    cout << "\t 4) 150k \n";
                    cout << "\t 5) 200k \n";
                    cout << "\t 6) 500k \n";
                    cout << "\t 7) 1mln \n";
                    cout << "\t 8) 2mln \n";
                    cout << "\t 9) 5mln \n";
                    cout << "\t 10) 10mln \n";
                    cout << "\n Podaj opcje: ";  
	                cin >> opcja;	   

	  if (opcja == '1')  wszystkie_D_usr( td1);
	  if (opcja == '2')  wszystkie_D_usr( td2);
	  if (opcja == '3')  wszystkie_D_usr( td3);
	  if (opcja == '4')  wszystkie_D_usr( td4);
	  if (opcja == '5')  wszystkie_D_usr( td5);
	  if (opcja == '6')  wszystkie_D_usr( td6);
	  if (opcja == '7')  wszystkie_D_usr( td7);
	  if (opcja == '8')  wszystkie_D_usr( td8); 
	  if (opcja == '9')  wszystkie_D_usr( td9);
	  if (opcja == '0')  wszystkie_D_usr( td10);
}


void menu3_D (vector <double> &t_usr_D)
{
    
char opcja;
                    cout << "\n\t ++++ Wybierz algorytm ++++\n";
                    cout << "\t 1) Bąbelkowe \n";
                    cout << "\t 2) przez wybór (selection sort) \n";
                    cout << "\t 3) przez wstawianie (insertion sort) \n";
                    cout << "\t 4) przez scalanie (merge sort) \n";
                    cout << "\t 5) przez kopcowanie (heap sort) \n";
                    cout << "\t 6) kubełkowe (bucket sort) \n";
                    cout << "\t 7) szybkie (quick sort) \n";
                    cout << "\n Podaj opcje: ";  
	                cin >> opcja;	   

	  if (opcja == '1')  sortowanie_babelkowe_rzeczywiste( t_usr_D);
	  if (opcja == '2')  selection_rzeczywiste( t_usr_D);
	  if (opcja == '3')  insertion_rzeczywiste( t_usr_D);
	  if (opcja == '4')  merge_rzeczywiste( t_usr_D);
	  if (opcja == '5')  heap_rzeczywiste( t_usr_D);
	  if (opcja == '6')  bucket_rzeczywiste( t_usr_D);
	  if (opcja == '7')  quicksort_rzeczywiste( t_usr_D, 0, t_usr_D.size()); 
}

void menu2_D (vector <double> &td1,vector <double> &td2,vector <double> &td3,vector <double> &td4,vector <double> &td5,vector <double> &td6,vector <double> &td7,vector <double> &td8,vector <double> &td9,vector <double> &td10)
{
    
char opcja;
                    cout << "\n\t ++++ Sortowanie WYBRANEJ JEDNEJ -*predefiniowanej*- tablicy WYBRANYM JEDNYM algorytmem  ++++\n";
                    cout << "\t 1) 30k \n";
                    cout << "\t 2) 50k \n";
                    cout << "\t 3) 100k \n";
                    cout << "\t 4) 150k \n";
                    cout << "\t 5) 200k \n";
                    cout << "\t 6) 500k \n";
                    cout << "\t 7) 1mln \n";
                    cout << "\t 8) 2mln \n";
                    cout << "\t 9) 5mln \n";
                    cout << "\t 10) 10mln \n";
                    cout << "\n Podaj opcje: ";  
	                cin >> opcja;	   

	  if (opcja == '1')  menu3_D( td1);
	  if (opcja == '2')  menu3_D( td2);
	  if (opcja == '3')  menu3_D( td3);
	  if (opcja == '4')  menu3_D( td4);
	  if (opcja == '5')  menu3_D( td5);
	  if (opcja == '6')  menu3_D( td6);
	  if (opcja == '7')  menu3_D( td7);
	  if (opcja == '8')  menu3_D( td8); 
	  if (opcja == '9')  menu3_D( td9);
	  if (opcja == '0')  menu3_D( td10);
}

void menu1_D (vector <double> &td1,vector <double> &td2,vector <double> &td3,vector <double> &td4,vector <double> &td5,vector <double> &td6,vector <double> &td7,vector <double> &td8,vector <double> &td9,vector <double> &td10)
{
char opcja;
                    cout << "\n\t ++++ Wybierz algorytm dla wszystkich tablic ++++\n";
                    cout << "\t 1) Bąbelkowe \n";
                    cout << "\t 2) przez wybór (selection sort) \n";
                    cout << "\t 3) przez wstawianie (insertion sort) \n";
                    cout << "\t 4) przez scalanie (merge sort) \n";
                    cout << "\t 5) przez kopcowanie (heap sort) \n";
                    cout << "\t 6) kubełkowe (bucket sort) \n";
                    cout << "\t 7) szybkie (quick sort) \n";
                    cout << "\n Podaj opcje: ";  
	                cin >> opcja;	   
	                
	                if (opcja == '1')  babel_R(td1, td2, td3, td4, td5, td6, td7, td8, td9, td10);
	                if (opcja == '2')  selection_R(td1, td2, td3, td4, td5, td6, td7, td8, td9, td10);
	                    if (opcja == '3')  insertion_R(td1, td2, td3, td4, td5, td6, td7, td8, td9, td10);
	                    if (opcja == '4')  merge_R(td1, td2, td3, td4, td5, td6, td7, td8, td9, td10);
	                    if (opcja == '5')  heap_R(td1, td2, td3, td4, td5, td6, td7, td8, td9, td10);
	                    if (opcja == '6')  bucket_R(td1, td2, td3, td4, td5, td6, td7, td8, td9, td10);
	                    if (opcja == '7')  quicksort_R(td1, td2, td3, td4, td5, td6, td7, td8, td9, td10);    
}

void wszystkie_D (vector <double> &td1,vector <double> &td2,vector <double> &td3,vector <double> &td4,vector <double> &td5,vector <double> &td6,vector <double> &td7,vector <double> &td8,vector <double> &td9,vector <double> &td10)
{
//GOTOWE
    babel_R(td1, td2, td3, td4, td5, td6, td7, td8, td9, td10);
	selection_R(td1, td2, td3, td4, td5, td6, td7, td8, td9, td10);
	insertion_R(td1, td2, td3, td4, td5, td6, td7, td8, td9, td10);
	merge_R(td1, td2, td3, td4, td5, td6, td7, td8, td9, td10);
	heap_R(td1, td2, td3, td4, td5, td6, td7, td8, td9, td10);
	bucket_R(td1, td2, td3, td4, td5, td6, td7, td8, td9, td10);
	quicksort_R(td1, td2, td3, td4, td5, td6, td7, td8, td9, td10);    
}


void wszystkie_D_usr (vector <double> d_vec_usr)
{
    sortowanie_babelkowe_rzeczywiste(d_vec_usr);
	selection_rzeczywiste(d_vec_usr);
	insertion_rzeczywiste(d_vec_usr);
	merge_rzeczywiste(d_vec_usr);
	heap_rzeczywiste(d_vec_usr);
	bucket_rzeczywiste(d_vec_usr);
	quicksort_rzeczywiste(d_vec_usr, 0, d_vec_usr.size());
}

  
void alg_usrD(vector <double> &td)
{
char opcja;
    cout << "\n\t ++++ Sortowanie tablicy użytkownika wybranym algorytmem ++++\n";
    cout << "\t 1) Bąbelkowe +\n";
    cout << "\t 2) przez wybór (selection sort) +\n";
    cout << "\t 3) przez wstawianie (insertion sort) \n";
    cout << "\t 4) przez scalanie (merge sort) \n";
    cout << "\t 5) przez kopcowanie (heap sort) +\n";
    cout << "\t 6) kubełkowe (bucket sort) \n";
    cout << "\t 7) szybkie (quick sort) +\n";
    cout << "\t 8) Wszystkie po kolei \n";
    cout << "\n Podaj opcje: ";  
	cin >> opcja;	   
	  if (opcja == '1')  sortowanie_babelkowe_rzeczywiste( td);
	  if (opcja == '2')  selection_rzeczywiste( td);
	  if (opcja == '3')  insertion_rzeczywiste( td);
	  if (opcja == '4')  merge_rzeczywiste( td);
	  if (opcja == '5')  heap_rzeczywiste( td);
	  if (opcja == '6')  bucket_rzeczywiste( td);
	  if (opcja == '7')  quicksort_rzeczywiste( td, 0, td.size()); 
	  if (opcja == '8')  wszystkie_D_usr( td);
}


void quicksort_rzeczywiste( vector <double> td, int lewy, int prawy)
{
   // cout << "\n quicksort_rzeczywiste zawartość przed: ";
   // poka_R(td);

    clock_t stop, start = clock();
    quicki(td, 0, td.size()-1);
    stop = clock();
    
    
  //  cout << "\n quicksort_rzeczywiste zawartość quickiQQQQQQQQQQQQQQ: ";
  //  poka_R(td);
    int dzielnik = CLOCKS_PER_SEC / 1000;
    int czas = (stop - start)/dzielnik;
    cout << "\n quicksort_rzeczywiste czas: " << czas; 
    zapis( "quicksort_rzeczywiste", td.size(), czas);
}

void quicki(vector <double> &td, int lewy, int prawy)
{
//GOTOWE

    double v=td[(lewy+prawy)/2];
    int i,j;
    double x;
    i=lewy;
    j=prawy;
    do
    {
        while (td[i]<v) i++;
        while (td[j]>v) j--;
        if (i<=j)
        {
            x=td[i];
            td[i]=td[j];
            td[j]=x;
            i++; j--;
        }
    }
    while (i<=j);
    if (j>lewy) quicki(td,lewy, j);
    if (i<prawy) quicki(td, i, prawy);
}

void merge_rzeczywiste(vector <double> td)
{

//GOTOWE
         //cout << "\n merge_rzeczywiste zawartość pzed: ";
         // poka_D(td); 
 cout << "\n merge td.size(): " << td.size();


    clock_t stop, start = clock();
      int rzom = td.size();
    double a[rzom];
   for (unsigned int i=0; i<td.size(); i++)
    a[i]=td[i];
    
   mergeSort(a, 0, td.size()-1);
   
    stop = clock();
    
    int dzielnik = CLOCKS_PER_SEC / 1000;
    int czas = (stop - start)/dzielnik;
    //int czas2 = (stop - start);
    cout << "\n merge_rzeczywiste czas: " << czas; 
    zapis( "merge_rzeczywiste", td.size(), czas);
    
         cout << "\n merge_rzeczywiste zawartość po sortowaniu: ";
          //poka_D(td); 
           
   for (unsigned int i=0; i<td.size(); i++)
    cout << "\n a["<<i<<"]="<<a[i];
}

void mergeSort(double arr[], int l, int r) //vector <double> &arr
{

  if (l < r) {

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  
  }
}


void merge(double arr[], int p, int q, int r)
{
  
  int n1 = q - p + 1;
  int n2 = r - q;

  double L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];


  int i, j, k;
  i = 0;
  j = 0;
  k = p;
  

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
  
}

void bucket_rzeczywiste(vector <double> td)
{
        cout << "\n bucket_rzeczywiste: ";
   
    clock_t stop, start = clock();
  bucket(td, td.size());    
    stop = clock();
   

    stop = clock();
    
    int dzielnik = CLOCKS_PER_SEC / 1000;
    int czas = (stop - start)/dzielnik;
    cout << "\n bucket_rzeczywiste czas: " << czas; 
    zapis( "bucket_rzeczywiste", td.size(), czas); 
}


void bucket(vector<double> & td, int roz)
{
    double mini = td[0];
    double maxi = td[0];

    int mini_Index = td[0];
    int maxi_Index = td[0];

    for (int i = 1; i < roz; i++)
    {
        if (td[i] > maxi)
            maxi = td[i];
        if (td[i] < mini)
            mini = td[i];
    }

    int bukiet_Dl = maxi_Index - mini_Index + 1;
    vector<double>* bukiet = new vector<double>[bukiet_Dl];

    for (int i = 0; i < bukiet_Dl; i++)
    {
        bukiet[i] = vector<double>();
    }

    for (int i = 0; i < roz; i++)
    {
        bukiet[(int)td[i] - mini_Index].push_back(td[i]);
    }

    int k = 0;
    for (int i = 0; i < bukiet_Dl; i++)
    {
        int bukiet_Rozm = bukiet[i].size();

        if (bukiet_Rozm > 0)
        {
            for (int j = 0; j < bukiet_Rozm; j++)
            {
                td[k] = bukiet[i][j];
                k++;
            }
        }
    }
delete[] bukiet;
}

void heap_rzeczywiste(vector <double> td)
{
//GOTOWE
        cout << "\n heap_rzeczywiste: ";
       // poka_R(td);
                
    clock_t stop, start = clock();
   for (int i = td.size() / 2 - 1; i >= 0; i--)
        sterta(td, td.size(), i);
     for (int i = td.size() - 1; i > 0; i--) {

        swap(td[0], td[i]);
 
        sterta(td, i, 0);
    }


    stop = clock();
    int dzielnik = CLOCKS_PER_SEC / 1000;
    int czas = (stop - start)/dzielnik;
    cout << "\n heap_rzeczywiste czas: " << czas; 
    zapis( "heap_rzeczywiste", td.size(), czas);
	          //  cout << "\n heap_rzeczywiste po: ";
               // poka_R(td);
}


void sterta(vector <double> &td, int n, int i)
{//GOTOWE
    int largest = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2; 

    if (l < n && td[l] > td[largest])
        largest = l; 

    if (r < n && td[r] > td[largest])
        largest = r; 

    if (largest != i) {
        swap(td[i], td[largest]); 

        sterta(td, n, largest);
    } 
}



void insertion_rzeczywiste(vector <double> td)
{
   clock_t stop, start = clock();
   
   insertionSort(td,td.size());  

    stop = clock();
    
     int dzielnik = CLOCKS_PER_SEC / 1000;
     int czas = (stop - start)/dzielnik;
    cout << "\n insertion_rzeczywiste czas: " << czas; 
    zapis( "insertion_rzeczywiste", td.size(), czas);    

}


void insertionSort(vector <double> &td, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = td[i];
        j = i - 1;
 
        while (j >= 0 && td[j] > key)
        {
            td[j + 1] = td[j];
            j = j - 1;
        }
        td[j + 1] = key;
    }
}

void selection_rzeczywiste(vector <double> td)
{
    //GOTOWE 
   cout << "\n selection_rzeczywiste: ";
  //  poka_R(td); 
   unsigned int i, j, k;
   
   clock_t stop, start = clock();   
       for(i=0; i<td.size(); i++) {
          k=i;
          for(j=i+1; j<td.size(); j++) if(td[j]<td[k]) k=j;
          swap(td[k], td[i]);
       }
    stop = clock();
    
    int dzielnik = CLOCKS_PER_SEC / 1000;
    int czas = (stop - start)/dzielnik;
    cout << "\n selection_rzeczywiste czas: " << czas; 
    zapis( "selection_rzeczywiste", td.size(), czas);  
	     //   cout << "\n selection_rzeczywiste zawartość po: ";
         //   poka_R(td);     
}

void sortowanie_babelkowe_rzeczywiste(vector <double> td)
{
//GOTOWE
        cout << "\n sortowanie_babelkowe_rzeczywiste: ";
       //     poka_R(td); 
     unsigned int i, licz=td.size();
     double tmp; 

    clock_t stop, start = clock();    
    do{
        for(i=0; i<td.size()-1; i++)
        {
            if(td[i]>td[i+1])
            {
                tmp=td[i];
                td[i] = td[i+1];
                td[i+1] = tmp;
            }
        }
    licz--;
    }while(licz>1);

  
    stop = clock();
    int dzielnik = CLOCKS_PER_SEC / 1000;
    int czas = (stop - start)/dzielnik;
    cout << "\n sortowanie_babelkowe_rzeczywiste czas: " << czas; 
    zapis( "sortowanie_babelkowe_rzeczywiste", td.size(), czas);  
	    //        cout << "\n sortowanie_babelkowe_rzeczywiste zawartość po: ";
        //        poka_R(td); 
}


void quicksort_R(vector <double> &td1,  vector <double> &td2, vector <double> &td3, vector <double> &td4, vector <double> &td5, vector <double> &td6,    vector <double> &td7, vector <double> &td8,  vector <double> &td9, vector <double> &td10)
{
    quicksort_rzeczywiste(td1,0,td1.size());
    quicksort_rzeczywiste(td2,0,td2.size());
    quicksort_rzeczywiste(td3,0,td3.size());
    quicksort_rzeczywiste(td4,0,td4.size());
    quicksort_rzeczywiste(td5,0,td5.size());
    
    quicksort_rzeczywiste(td6,0,td6.size());
    quicksort_rzeczywiste(td7,0,td7.size());
    quicksort_rzeczywiste(td8,0,td8.size());
    quicksort_rzeczywiste(td9,0,td9.size());
    quicksort_rzeczywiste(td10,0,td10.size());
}

void bucket_R(vector <double> &td1,  vector <double> &td2, vector <double> &td3, vector <double> &td4, vector <double> &td5, vector <double> &td6,    vector <double> &td7, vector <double> &td8,  vector <double> &td9, vector <double> &td10)
{
    bucket_rzeczywiste(td1);
    bucket_rzeczywiste(td2);
    bucket_rzeczywiste(td3);
    bucket_rzeczywiste(td4);
    bucket_rzeczywiste(td5);
    
    bucket_rzeczywiste(td6);
    bucket_rzeczywiste(td7);
    bucket_rzeczywiste(td8);
    bucket_rzeczywiste(td9);
    bucket_rzeczywiste(td10);
}

void heap_R(vector <double> &td1,  vector <double> &td2, vector <double> &td3, vector <double> &td4, vector <double> &td5, vector <double> &td6,    vector <double> &td7, vector <double> &td8,  vector <double> &td9, vector <double> &td10)
{
    heap_rzeczywiste(td1);
    heap_rzeczywiste(td2);
    heap_rzeczywiste(td3);
    heap_rzeczywiste(td4);
    heap_rzeczywiste(td5);
    
    heap_rzeczywiste(td6);
    heap_rzeczywiste(td7);
    heap_rzeczywiste(td8);
    heap_rzeczywiste(td9);
    heap_rzeczywiste(td10);
}

void merge_R(vector <double> &td1,  vector <double> &td2, vector <double> &td3, vector <double> &td4, vector <double> &td5, vector <double> &td6,    vector <double> &td7, vector <double> &td8,  vector <double> &td9, vector <double> &td10)
{
    merge_rzeczywiste(td1);
    merge_rzeczywiste(td2);
    merge_rzeczywiste(td3);
    merge_rzeczywiste(td4);
    merge_rzeczywiste(td5);
    
    merge_rzeczywiste(td6);
    merge_rzeczywiste(td7);
    merge_rzeczywiste(td8);
    merge_rzeczywiste(td9);
    merge_rzeczywiste(td10);
}

void insertion_R(vector <double> &td1,  vector <double> &td2, vector <double> &td3, vector <double> &td4, vector <double> &td5, vector <double> &td6,    vector <double> &td7, vector <double> &td8,  vector <double> &td9, vector <double> &td10)
{
    insertion_rzeczywiste(td1);
    insertion_rzeczywiste(td2);
    insertion_rzeczywiste(td3);
    insertion_rzeczywiste(td4);
    insertion_rzeczywiste(td5);
    
    insertion_rzeczywiste(td6);
    insertion_rzeczywiste(td7);
    insertion_rzeczywiste(td8);
    insertion_rzeczywiste(td9);
    insertion_rzeczywiste(td10);
}

void selection_R(vector <double> &td1,  vector <double> &td2, vector <double> &td3, vector <double> &td4, vector <double> &td5, vector <double> &td6,    vector <double> &td7, vector <double> &td8,  vector <double> &td9, vector <double> &td10)
{
    selection_rzeczywiste(td1);
    selection_rzeczywiste(td2);
    selection_rzeczywiste(td3);
    selection_rzeczywiste(td4);
    selection_rzeczywiste(td5);
    
    selection_rzeczywiste(td6);
    selection_rzeczywiste(td7);
    selection_rzeczywiste(td8);
    selection_rzeczywiste(td9);
    selection_rzeczywiste(td10);
}
 
void babel_R(vector <double> &td1,  vector <double> &td2, vector <double> &td3, vector <double> &td4, vector <double> &td5, vector <double> &td6,    vector <double> &td7, vector <double> &td8,  vector <double> &td9, vector <double> &td10)
{
    sortowanie_babelkowe_rzeczywiste(td1);
    sortowanie_babelkowe_rzeczywiste(td2);
    sortowanie_babelkowe_rzeczywiste(td3);
    sortowanie_babelkowe_rzeczywiste(td4);
    sortowanie_babelkowe_rzeczywiste(td5);
    
    sortowanie_babelkowe_rzeczywiste(td6);
    sortowanie_babelkowe_rzeczywiste(td7);
    sortowanie_babelkowe_rzeczywiste(td8);
    sortowanie_babelkowe_rzeczywiste(td9);
    sortowanie_babelkowe_rzeczywiste(td10);
}
    
    
