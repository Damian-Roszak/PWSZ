/*
 *  Napisz deklaracje: wskaźnik do znaku, tablica 10 liczb całkowitych, referencja do tablicy 10 liczb całkowitych, wskaźnik do tablicy napisów, wskaźnik 
 * do wskaźnika do znaku, stała całkowita, wskaźnik do stałej całkowitej, stały wskaźnik do liczby całkowitej. W kaźdej deklaracji dokonaj inicjowania.
 * 
 * 
 *  Jakie są w twoim systemie ograniczenia na typy wskaźnikowe char*, int*, void* Czy np. int* może mieć wartość nieparzystą? Czy np. int* może mieć wartość
 *nieparzystą? Wskazówka: wyrównanie.
 *  
 *  Użyj typedef do zdefiniowania podanych typów: typ unsigned char, const unsigned char, wskaźnik do liczby całkowitej, wskaźnik do wskaźnika do znaku,
 *wskaźnik to tablicy znaków do liczb całkowitych, tablica 8 tablic z 7 wskaźnikami do liczb całkowitych.
 *
 */
1)
 wskaźnik do znaku, char c = 'a';  char* pc = &c;
 
 tablica 10 liczb całkowitych int tab[10] = {1,2,3,4,5,6,7,8,9,10};
 
 referencja do tablicy 10 liczb całkowitych  int tab[10]; int &ref = tab;
 wskaźnik do tablicy napisów string tab[]; string* p = &tab;
 wskaźnik do wskaźnika do znaku, char** ppc;
 stała całkowita, const int stala;
 wskaźnik do stałej całkowitej, const int stala_calkowita; int* wskaźnik_do_stalej_calkowitej = &stala_calkowita; 
 stały wskaźnik do liczby całkowitej int liczba_calkowita; const int* p_do_int = &liczba_calkowita;
 
2) 
 Jakie są w twoim systemie ograniczenia na typy wskaźnikowe char*, int*, void* Czy np. int* może mieć wartość nieparzystą? Wskazówka: wyrównanie.

 