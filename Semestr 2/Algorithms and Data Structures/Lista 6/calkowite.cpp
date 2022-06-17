#include "calkowite.hpp"
#include <fstream>
#include <climits>



void menu4_C (vector <int> &tc1,vector <int> &tc2,vector <int> &tc3,vector <int> &tc4,vector <int> &tc5,vector <int> &tc6,vector <int> &tc7,vector <int> &tc8,vector <int> &tc9,vector <int> &tc10)
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

	  if (opcja == '1')  wszystkie_C_usr( tc1);
	  if (opcja == '2')  wszystkie_C_usr( tc2);
	  if (opcja == '3')  wszystkie_C_usr( tc3);
	  if (opcja == '4')  wszystkie_C_usr( tc4);
	  if (opcja == '5')  wszystkie_C_usr( tc5);
	  if (opcja == '6')  wszystkie_C_usr( tc6);
	  if (opcja == '7')  wszystkie_C_usr( tc7);
	  if (opcja == '8')  wszystkie_C_usr( tc8); 
	  if (opcja == '9')  wszystkie_C_usr( tc9);
	  if (opcja == '0')  wszystkie_C_usr( tc10);
}


void menu3_C (vector <int> &t_usr_C)
{
    
char opcja;
                    cout << "\n\t ++++ Wybierz algorytm ++++\n";
                    cout << "\t 1) Bąbelkowe \n";
                    cout << "\t 2) przez wybór (selection sort) \n";
                    cout << "\t 3) przez wstawianie (insertion sort) \n";
                    cout << "\t 4) przez scalanie (merge sort) \n";
                    cout << "\t 5) przez zliczanie (counting sort) \n";
                    cout << "\t 6) przez kopcowanie (heap sort) \n";
                    cout << "\t 7) kubełkowe (bucket sort) \n";
                    cout << "\t 8) szybkie (quick sort) \n";
                    cout << "\n Podaj opcje: ";  
	                cin >> opcja;	   

	  if (opcja == '1')  sortowanie_babelkowe_calkowite( t_usr_C);
	  if (opcja == '2')  selection_calkowite( t_usr_C);
	  if (opcja == '3')  insertion_calkowite( t_usr_C);
	  if (opcja == '4')  merge_calkowite( t_usr_C);
	  if (opcja == '5')  counting_calkowite( t_usr_C);
	  if (opcja == '6')  heap_calkowite( t_usr_C);
	  if (opcja == '7')  bucket_calkowite( t_usr_C);
	  if (opcja == '8')  quicksort_calkowite( t_usr_C, 0, t_usr_C.size()); 
}

void menu2_C (vector <int> &tc1,vector <int> &tc2,vector <int> &tc3,vector <int> &tc4,vector <int> &tc5,vector <int> &tc6,vector <int> &tc7,vector <int> &tc8,vector <int> &tc9,vector <int> &tc10)
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

	  if (opcja == '1')  menu3_C( tc1);
	  if (opcja == '2')  menu3_C( tc2);
	  if (opcja == '3')  menu3_C( tc3);
	  if (opcja == '4')  menu3_C( tc4);
	  if (opcja == '5')  menu3_C( tc5);
	  if (opcja == '6')  menu3_C( tc6);
	  if (opcja == '7')  menu3_C( tc7);
	  if (opcja == '8')  menu3_C( tc8); 
	  if (opcja == '9')  menu3_C( tc9);
	  if (opcja == '0')  menu3_C( tc10);
}

void menu1_C (vector <int> &tc1,vector <int> &tc2,vector <int> &tc3,vector <int> &tc4,vector <int> &tc5,vector <int> &tc6,vector <int> &tc7,vector <int> &tc8,vector <int> &tc9,vector <int> &tc10)
{
char opcja;
                    cout << "\n\t ++++ Wybierz algorytm dla wszystkich tablic ++++\n";
                    cout << "\t 1) Bąbelkowe \n";
                    cout << "\t 2) przez wybór (selection sort) \n";
                    cout << "\t 3) przez wstawianie (insertion sort) \n";
                    cout << "\t 4) przez scalanie (merge sort) \n";
                    cout << "\t 5) przez zliczanie (counting sort) \n";
                    cout << "\t 6) przez kopcowanie (heap sort) \n";
                    cout << "\t 7) kubełkowe (bucket sort) \n";
                    cout << "\t 8) szybkie (quick sort) \n";
                    cout << "\n Podaj opcje: ";  
	                cin >> opcja;	   
	                
	                if (opcja == '1')  babel_C(tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8, tc9, tc10);
	                if (opcja == '2')  selection_C(tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8, tc9, tc10);
	                    if (opcja == '3')  insertion_C(tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8, tc9, tc10);
	                    if (opcja == '4')  merge_C(tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8, tc9, tc10);
	                    if (opcja == '5')  counting_C(tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8, tc9, tc10);
	                    if (opcja == '6')  heap_C(tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8, tc9, tc10);
	                    if (opcja == '7')  bucket_C(tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8, tc9, tc10);
	                    if (opcja == '8')  quicksort_C(tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8, tc9, tc10);    
}

void wszystkie_C (vector <int> &tc1,vector <int> &tc2,vector <int> &tc3,vector <int> &tc4,vector <int> &tc5,vector <int> &tc6,vector <int> &tc7,vector <int> &tc8,vector <int> &tc9,vector <int> &tc10)
{
//GOTOWE
    babel_C(tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8, tc9, tc10);
	selection_C(tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8, tc9, tc10);
	insertion_C(tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8, tc9, tc10);
	merge_C(tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8, tc9, tc10);
	counting_C(tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8, tc9, tc10);
	heap_C(tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8, tc9, tc10);
	bucket_C(tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8, tc9, tc10);
	quicksort_C(tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8, tc9, tc10);    
}

void wszystkie_C_usr (vector <int> &c_vec_usr)
{
//GOTOWE
    sortowanie_babelkowe_calkowite(c_vec_usr);
	selection_calkowite(c_vec_usr);
	insertion_calkowite(c_vec_usr);
	merge_calkowite(c_vec_usr);
	counting_calkowite(c_vec_usr);
	heap_calkowite(c_vec_usr);
	bucket_calkowite(c_vec_usr);
	quicksort_calkowite(c_vec_usr,0,c_vec_usr.size());
}

  
void alg_usr(vector <int> &tc)
{
char opcja;
    cout << "\n\t ++++ Sortowanie tablicy wybranym algorytmem ++++\n";
    cout << "\t 1) Bąbelkowe +\n";
    cout << "\t 2) przez wybór (selection sort) +\n";
    cout << "\t 3) przez wstawianie (insertion sort) +\n";
    cout << "\t 4) przez scalanie (merge sort) +\n";
    cout << "\t 5) przez zliczanie (counting sort) +\n";
    cout << "\t 6) przez kopcowanie (heap sort) +\n";
    cout << "\t 7) kubełkowe (bucket sort) +\n";
    cout << "\t 8) szybkie (quick sort) +\n";
    cout << "\n Podaj opcje: ";  
	cin >> opcja;	   
	  if (opcja == '1')  sortowanie_babelkowe_calkowite( tc);
	  if (opcja == '2')  selection_calkowite( tc);
	  if (opcja == '3')  insertion_calkowite( tc);
	  if (opcja == '4')  merge_calkowite( tc);
	  if (opcja == '5')  counting_calkowite( tc);
	  if (opcja == '6')  heap_calkowite( tc);
	  if (opcja == '7')  bucket_calkowite( tc);
	  if (opcja == '8')  quicksort_calkowite( tc, 0, tc.size()); 
}


void quicksort_calkowite( vector <int> tc, int lewy, int prawy)
{
	           cout << "\n quicksort_calkowite: ";
             //   poka_C(tc);
   
    clock_t stop, start = clock();
    quicki(tc, 0, tc.size()-1);
    stop = clock();
    
    int dzielnik = CLOCKS_PER_SEC / 1000;
    int czas = (stop - start)/dzielnik;
    
     //int czas2 = (stop - start);
    cout << "\n quicksort_calkowite czas: " << czas ; 
    zapis( "quicksort_calkowite", tc.size(), czas);
	         //   cout << "\n quicksort_calkowite zawartość po: ";
              //  poka_C(tc);
}

void quicki(vector <int> &tc, int lewy, int prawy)
{
//GOTOWE

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
    if (j>lewy) quicki(tc,lewy, j);
    if (i<prawy) quicki(tc, i, prawy);
}

void merge_calkowite(vector <int> tc)
{

//GOTOWE
        cout << "\n merge_calkowite: ";
         // poka_C(tc); 
 //cout << "\n merge tc.size(): " << tc.size();


    clock_t stop, start = clock();
      int rzom = tc.size();
    int a[rzom];
   for (unsigned int i=0; i<tc.size(); i++)
    a[i]=tc[i];
    
   mergeSort(a, 0, tc.size()-1);
   
    stop = clock();
    
    int dzielnik = CLOCKS_PER_SEC / 1000;
    int czas = (stop - start)/dzielnik;
   // int czas2 = (stop - start);
    cout << "\n merge_calkowite czas: " << czas; 
    zapis( "merge_calkowite", tc.size(), czas);
    
        // cout << "\n merge_calkowite zawartość po sortowaniu: ";
          //poka_C(tc); 
           
  // for (unsigned int i=0; i<tc.size(); i++)
   // cout << "\n a["<<i<<"]="<<a[i];
}


void mergeSort(int arr[], int l, int r) //vector <int> &arr
{

  if (l < r) {

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  
  }
}


void merge(int arr[], int p, int q, int r)
{
  
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

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

void mergeofarrays(int tab[], int low, int mid, int high) {
  int i = low, j = mid + 1, index = low, k;
  int *temp = new int [high+1];
  while ((i <= mid) && (j <= high)) {
    if (tab[i] < tab[j]) {
      temp[index] = tab[i];
      i++;
    } else {
      temp[index] = tab[j];
      j++;
    }
    index++;
  }
  //copy the remaining elements of right array
  if (i > mid) {
    while (j <= high) {
      temp[index] = tab[j];
      j++;
      index++;
    }
  } else //remaining elements of left array
  {
    while (i <= mid) {
      temp[index] = tab[i];
      i++;
      index++;
    }
  }
  for (k = low; k < index; k++) //copying into original array
  {
    tab[k] = temp[k];
  }
  delete[] temp;
}

void mergeSorta(int tab[], int low, int high) 
{
  if (low < high) {
    int middle = (low + high) / 2; //calculating middle index of array to divide it in two halves
    mergeSorta(tab, low, middle); //sorting first half
    mergeSorta(tab, middle + 1, high); //sorting second half
    mergeofarrays(tab, low, middle, high); //merging 2 sorted halves
  }
}

void heap_calkowite(vector <int> tc)
{
//GOTOWE
        cout << "\n heap_calkowite: ";
         // poka_C(tc); 
    clock_t stop, start = clock();
   for (int i = tc.size() / 2 - 1; i >= 0; i--)
        sterta(tc, tc.size(), i);
     for (int i = tc.size() - 1; i > 0; i--) {

        swap(tc[0], tc[i]);
 
        sterta(tc, i, 0);
    }


    stop = clock();
    int dzielnik = CLOCKS_PER_SEC / 1000;
    int czas = (stop - start)/dzielnik;
    cout << "\n heap_calkowite czas: " << czas; 
    zapis( "heap_calkowite", tc.size(), czas);
	            //cout << "\n heap_calkowite zawartość po: ";
                //poka_C(tc);
}


void sterta(vector <int> &tc, int n, int i)
{//GOTOWE
    int largest = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2; 

    if (l < n && tc[l] > tc[largest])
        largest = l; 

    if (r < n && tc[r] > tc[largest])
        largest = r; 

    if (largest != i) {
        swap(tc[i], tc[largest]); 

        sterta(tc, n, largest);
    } 
}

void counting_calkowite(vector <int> tc)
{
      cout << "\n counting_calkowite: ";
      //   poka_C(tc); 
         
    clock_t stop, start = clock();
      int rzom = tc.size();
    int T[rzom];
   for (unsigned int i=0; i<tc.size(); i++)
    T[i]=tc[i];
   const int k = 77; 
const int n = tc.size();
int Tp[n];
int TPom[k];
 
int i; 

  for(i = 0 ; i < k ; ++i)
    TPom[i] = 0;                // zerowanie tablicy

  for(i = 0 ; i < n ; ++i)
    ++TPom[T[i]];               // po tych operacjach TPom[i] będzie zawierała 
                                // liczbę wystąpień kolejnego elementu o wartości T[i]
  for(i = 1 ; i < k ; ++i)
    TPom[i] += TPom[i-1];       // teraz TPom[i] zawiera pozycje w posortowanej
                                // tablicy ostatniego elementu o kluczu i
  for(i = n-1 ; i >= 0 ; --i)
     Tp[--TPom[T[i]]] = T[i];   // wstawienie elementu na odpowiednią pozycję 
                              
   
    stop = clock();
  //  int czas2 = (stop - start);  
    int dzielnik = CLOCKS_PER_SEC / 1000;
    int czas = (stop - start)/dzielnik;
    cout << "\n counting_calkowite czas: " << czas; 
    zapis( "counting_calkowite", tc.size(), czas);  
    
   for (unsigned int i=0; i<tc.size(); i++)
    cout << "\n Tp["<<i<<"]="<<Tp[i];
}


void bucket_calkowite(vector <int> tc)
{
// GOTOWE
        cout << "\n bucket_calkowite: ";
         // poka_C(tc); 
      //  cout << "\n bucket_calkowite zawartość przed: ";
     //    poka_C(tc); 
    //   char l;
   //      cout << "\n bucket_calkowite rozmiar: "<< tc.size();
    //     cin >> l;
    
    clock_t stop, start = clock();
  bucket(tc, tc.size());    
    stop = clock();
    
    int dzielnik = CLOCKS_PER_SEC / 1000;
    int czas = (stop - start)/dzielnik;
    cout << "\n bucket_calkowite czas: " << czas; 
    zapis( "bucket_calkowite", tc.size(), czas); 
       //  cout << "\n bucket_calkowite zawartość po sortowaniu: ";
      //   poka_C(tc); 
}

void bucket(vector<int> & tc, int roz) 
{
    int mini = tc[0];
    int maxi = tc[0];

    for (int i = 1; i < roz; i++)
    {
        if (tc[i] > maxi)
            maxi = tc[i];
        if (tc[i] < mini)
            mini = tc[i];
    }

    int bukiet_Dl = maxi - mini + 1;
    vector<int>* bukiet = new vector<int>[bukiet_Dl];

    for (int i = 0; i < bukiet_Dl; i++)
    {
        bukiet[i] = vector<int>();
    }

    for (int i = 0; i < roz; i++)
    {
        bukiet[tc[i] - mini].push_back(tc[i]);
    }

    int k = 0;
    for (int i = 0; i < bukiet_Dl; i++)
    {
        int bukiet_Rozm = bukiet[i].size();

        if (bukiet_Rozm > 0)
        {
            for (int j = 0; j < bukiet_Rozm; j++)
            {
                tc[k] = bukiet[i][j];
                k++;
            }
        }
    }
delete[] bukiet;
}

void insertionSort(vector <int> &tc, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = tc[i];
        j = i - 1;
 
        while (j >= 0 && tc[j] > key)
        {
            tc[j + 1] = tc[j];
            j = j - 1;
        }
        tc[j + 1] = key;
    }
}

void insertion_calkowite(vector <int> tc)
{ 
// GOTOWE 
        cout << "\n insertion_calkowite: ";
         // poka_C(tc); 
    //  cout << "\n insertion_calkowite zawartość przed: ";
    //  poka_C(tc);
           
     clock_t stop, start = clock();
    insertionSort(tc,tc.size());    
     stop = clock();    
    
     int dzielnik = CLOCKS_PER_SEC / 1000;
     int czas = (stop - start)/dzielnik;
    // int czas2 = (stop - start);
     
    cout << "\n insertion_calkowite czas: " << czas; 
    zapis( "insertion_calkowite", tc.size(), czas); 
	//     cout << "\n insertion_calkowite zawartość po sortowaniu: ";
    //     poka_C(tc);  
       
}
  

void selection_calkowite(vector <int> tc)
{
    //GOTOWE
        cout << "\n selection_calkowite: ";
         // poka_C(tc); 
   clock_t stop, start = clock();    
   
   
   unsigned int i, j, k;   
   
   for(i=0; i<tc.size(); i++) {
      k=i;
      for(j=i+1; j<tc.size(); j++) if(tc[j]<tc[k]) k=j;
      swap(tc[k], tc[i]);
   }
   
   
   
    stop = clock();
    int dzielnik = CLOCKS_PER_SEC / 1000;
    int czas = (stop - start)/dzielnik;
    cout << "\n selection_calkowite czas: " << czas; 
    zapis( "selection_calkowite", tc.size(), czas);  
	        //    cout << "\n selection_calkowite zawartość po: ";
               // poka_C(tc);     
}

void sortowanie_babelkowe_calkowite(vector <int> tc)
{
//GOTOWE
        cout << "\n sortowanie_babelkowe_calkowite: ";
         // poka_C(tc);
     unsigned int i, licz=tc.size(), tmp; 

    clock_t stop, start = clock();    
    do{
        for(i=0; i<tc.size()-1; i++)
        {
            if(tc[i]>tc[i+1])
            {
                tmp=tc[i];
                tc[i] = tc[i+1];
                tc[i+1] = tmp;
            }
        }
    licz--;
    }while(licz>1);

  
    stop = clock();
    int dzielnik = CLOCKS_PER_SEC / 1000;
    int czas = (stop - start)/dzielnik;
    cout << "\n sortowanie_babelkowe_calkowite czas: " << czas; 
    zapis( "sortowanie_babelkowe_calkowite", tc.size(), czas);  
	            //cout << "\n sortowanie_babelkowe_calkowite zawartość po: ";
               // poka_C(tc); 
}



void quicksort_C(vector <int> tc1,  vector <int> tc2, vector <int> tc3, vector <int> tc4, vector <int> tc5, vector <int> tc6,    vector <int> tc7, vector <int> tc8,  vector <int> tc9, vector <int> tc10)
{
    quicksort_calkowite(tc1,0,tc1.size());
    quicksort_calkowite(tc2,0,tc2.size());
    quicksort_calkowite(tc3,0,tc3.size());
    quicksort_calkowite(tc4,0,tc4.size());
    quicksort_calkowite(tc5,0,tc5.size());
    
    quicksort_calkowite(tc6,0,tc6.size());
    quicksort_calkowite(tc7,0,tc7.size());
    quicksort_calkowite(tc8,0,tc8.size());
    quicksort_calkowite(tc9,0,tc9.size());
    quicksort_calkowite(tc10,0,tc10.size());
}

void bucket_C(vector <int> tc1,  vector <int> tc2, vector <int> tc3, vector <int> tc4, vector <int> tc5, vector <int> tc6,    vector <int> tc7, vector <int> tc8,  vector <int> tc9, vector <int> tc10)
{
    bucket_calkowite(tc1);
    bucket_calkowite(tc2);
    bucket_calkowite(tc3);
    bucket_calkowite(tc4);
    bucket_calkowite(tc5);
    
    bucket_calkowite(tc6);
    bucket_calkowite(tc7);
    bucket_calkowite(tc8);
    bucket_calkowite(tc9);
    bucket_calkowite(tc10);
}

void heap_C(vector <int> tc1,  vector <int> tc2, vector <int> tc3, vector <int> tc4, vector <int> tc5, vector <int> tc6,    vector <int> tc7, vector <int> tc8,  vector <int> tc9, vector <int> tc10)
{
    heap_calkowite(tc1);
    heap_calkowite(tc2);
    heap_calkowite(tc3);
    heap_calkowite(tc4);
    heap_calkowite(tc5);
    
    heap_calkowite(tc6);
    heap_calkowite(tc7);
    heap_calkowite(tc8);
    heap_calkowite(tc9);
    heap_calkowite(tc10);
}

void counting_C(vector <int> tc1,  vector <int> tc2, vector <int> tc3, vector <int> tc4, vector <int> tc5, vector <int> tc6,    vector <int> tc7, vector <int> tc8,  vector <int> tc9, vector <int> tc10)
{
    counting_calkowite(tc1);
    counting_calkowite(tc2);
    counting_calkowite(tc3);
    counting_calkowite(tc4);
    counting_calkowite(tc5);
    
    counting_calkowite(tc6);
    counting_calkowite(tc7);
    counting_calkowite(tc8);
    counting_calkowite(tc9);
    counting_calkowite(tc10);
}

void merge_C(vector <int> tc1,  vector <int> tc2, vector <int> tc3, vector <int> tc4, vector <int> tc5, vector <int> tc6,    vector <int> tc7, vector <int> tc8,  vector <int> tc9, vector <int> tc10)
{
    merge_calkowite(tc1);
    merge_calkowite(tc2);
    merge_calkowite(tc3);
    merge_calkowite(tc4);
    merge_calkowite(tc5);
    
    merge_calkowite(tc6);
    merge_calkowite(tc7);
    merge_calkowite(tc8);
    merge_calkowite(tc9);
    merge_calkowite(tc10);
}

void insertion_C(vector <int> tc1,  vector <int> tc2, vector <int> tc3, vector <int> tc4, vector <int> tc5, vector <int> tc6,    vector <int> tc7, vector <int> tc8,  vector <int> tc9, vector <int> tc10)
{
    insertion_calkowite(tc1);
    insertion_calkowite(tc2);
    insertion_calkowite(tc3);
    insertion_calkowite(tc4);
    insertion_calkowite(tc5);
    
    insertion_calkowite(tc6);
    insertion_calkowite(tc7);
    insertion_calkowite(tc8);
    insertion_calkowite(tc9);
    insertion_calkowite(tc10);
}

void selection_C(vector <int> tc1,  vector <int> tc2, vector <int> tc3, vector <int> tc4, vector <int> tc5, vector <int> tc6,    vector <int> tc7, vector <int> tc8,  vector <int> tc9, vector <int> tc10)
{
    selection_calkowite(tc1);
    selection_calkowite(tc2);
    selection_calkowite(tc3);
    selection_calkowite(tc4);
    selection_calkowite(tc5);
    
    selection_calkowite(tc6);
    selection_calkowite(tc7);
    selection_calkowite(tc8);
    selection_calkowite(tc9);
    selection_calkowite(tc10);
}
 
void babel_C(vector <int> tc1,  vector <int> tc2, vector <int> tc3, vector <int> tc4, vector <int> tc5, vector <int> tc6,    vector <int> tc7, vector <int> tc8,  vector <int> tc9, vector <int> tc10)
{
    sortowanie_babelkowe_calkowite(tc1);
    sortowanie_babelkowe_calkowite(tc2);
    sortowanie_babelkowe_calkowite(tc3);
    sortowanie_babelkowe_calkowite(tc4);
    sortowanie_babelkowe_calkowite(tc5);
    
    sortowanie_babelkowe_calkowite(tc6);
    sortowanie_babelkowe_calkowite(tc7);
    sortowanie_babelkowe_calkowite(tc8);
    sortowanie_babelkowe_calkowite(tc9);
    sortowanie_babelkowe_calkowite(tc10);
}
 
    


