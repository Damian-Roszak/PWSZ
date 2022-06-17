

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
                    cout << "\n\t ++++ Sortowanie WSZYSTKICH predefiniowanych tablic po kolei wybranym algorytmem ++++\n";
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
	                if (opcja == '9')  wszystkie_C(tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8, tc9, tc10);
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
