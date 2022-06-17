#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>


char * itoa(int i) {
  char * res = malloc(8*sizeof(int));
  sprintf(res, "%d", i);
  // testy działania wyświetlania, są odnośnikiem do poniższego umieszczania znaków w elemencie struktury
  printf("res = s = %s", res);
  printf(" *res = d, %d", *res);
  printf(" res[0] c=, %c", res[0]);
  printf(" res[1] c=,%c ///", res[1]);
  return res;
}

typedef struct{
    int id;
    char imie[20];
    char nazwisko[20];
    int rok_u, mies_u, dzien_u;
}tosoba;


typedef struct{
    int id;
    char *imie;
    char *nazwisko;
    int rok_u, mies_u, dzien_u;
}tsapiens;

void pokazStruct(tosoba ktos)
{
    printf("\n\033[93;1m id \t imie \t\t nazwisko \t data urodzenia [dzień.miesiąc.rok]\033[0m");
    printf("\n %d \t %s \t %s \t\t %d.%d.%d\n",ktos.id, ktos.imie, ktos.nazwisko, ktos.dzien_u, ktos.mies_u, ktos.rok_u);
    printf("\n imie[3] = %d, imie[4] = %c, imie[5] = %c, imie[6] = %d\n", ktos.imie[3], ktos.imie[4], ktos.imie[5], ktos.imie[6]);
}

void pokazStructTsapiens(tsapiens ktos)
{
    printf("\n\033[93;1m id \t imie \t\t nazwisko \t data urodzenia [dzień.miesiąc.rok]\033[0m");
    printf("\n %d \t %s \t %s \t\t %d.%d.%d\n",ktos.id, ktos.imie, ktos.nazwisko, ktos.dzien_u, ktos.mies_u, ktos.rok_u);
    printf("\n imie[3] = %d, imie[4] = %c, imie[5] = %c, imie[6] = %d\n", ktos.imie[3], ktos.imie[4], ktos.imie[5], ktos.imie[6]);
}

//operowanie tablicami
void inicjujStruct( tosoba *ktos)
{
        int i_itoa; char * c_itoa;
    ktos->id = rand()%100;

    c_itoa = itoa(rand()%100); 
    ktos->imie[0] = 'i';
    ktos->imie[1] = 'm';
    ktos->imie[2] = 'i';
    ktos->imie[3] = 'e';
    ktos->imie[4] = c_itoa[0];
    ktos->imie[5] = c_itoa[1];
    ktos->imie[6] = '\0';
    
    c_itoa = itoa(rand()%100);
    ktos->nazwisko[0] = 'n';
    ktos->nazwisko[1] = 'a';
    ktos->nazwisko[2] = 'z';
    ktos->nazwisko[3] = c_itoa[0];
    ktos->nazwisko[4] = c_itoa[1];
    ktos->nazwisko[5] = '\0';

    ktos->rok_u = rand()%100+1900;
    ktos->mies_u = rand()%12+1;
    ktos->dzien_u = rand()%30+1;
    
//czy to jest prawidłowe zwolnienie pamięci w tej sytuacji i czy odnosi się to zwolnienie pamięci do funkcji itoa w której powstała zawartość zmiennej c_itoa czyli zmienna res, jeśli nie to czy należy/jak usuwać zmienną res utworzoną i w innej funkcji? 
free(c_itoa);
}

//z użyciem funkcji strncat
void inicjujStruct2( tosoba *ktos)
{

                printf("\n\033[93;1m w środku inicjujStruct2 \033[0m\n");
        int i_itoa; char * c_itoa3;
    ktos->id = rand()%100;

    c_itoa3 = itoa(rand()%100); 
   /* 
//dlaczego ta konstrukcja zawiodła poprzez dodawanie na końcu -@ a w nazwisku działało, ta funkcja jest kopią powyższej i w tamtej tak się nie działo
    ktos->imie[0] = 'i';
    ktos->imie[1] = 'm';
    ktos->imie[2] = 'i';
    ktos->imie[3] = 'e';*/
    char *a = malloc(8*sizeof(char));
  sprintf(a, "%s", "imiĄŁÓ");
    strncat (ktos->imie, a, 9);
    printf("\n\033[93;1m\n imie=%s =\033[0m",ktos->imie);
    printf("\n\033[95;1m\n c_itoa=%s =\033[0m",c_itoa3);
   strncat (ktos->imie, c_itoa3, 2);
    printf("\n\033[93;1m\n imie=%s =\033[0m\n",ktos->imie);
   // ktos->imie[4] = c_itoa[0];
   // ktos->imie[5] = c_itoa[1];
   // ktos->imie[6] = '\0';

    
    c_itoa3 = itoa(rand()%100);
    /*
    ktos->nazwisko[0] = 'n';
    ktos->nazwisko[1] = 'a';
    ktos->nazwisko[2] = 'z'; */
    strncat (ktos->nazwisko, "naz", 3);
    
   strncat (ktos->nazwisko, c_itoa3, 2);
   
    ktos->rok_u = rand()%100+1900;
    ktos->mies_u = rand()%12+1;
    ktos->dzien_u = rand()%30+1;
       
                printf("\n\033[93;1m koniec inicjujStruct2 \033[0m\n");
       
       
//czy to jest prawidłowe zwolnienie pamięci w tej sytuacji   
free(c_itoa3);
}


// próba zrozumienia tematu zależności tablic od wskaźników i kodowania znaków z poprzedniej funkcji inicjujStruct2 - pytanie powtórzone w ostatnim komentarzu
//kodowanie polskich znaków a stringi (powyższy printf prawidłowo wyświetla polskie znaki), problem pojawia sie w momencie użycia funkcji do dodania znaku i dodawania znaków w funkcji; 
//Jak to jest że po wykonaniu funkcji strncat "Ę" i "ę" jest krzaczkiem? wyskoczył błąd "multicharacter chararcter", raz dotyczył tego że mają być cudzysłowy zamiast apostrofów, a raz że tablica, jeszcze sprawdzałem jak to będzie na char*, ale program kończy działanie błędem w momencie użycia strcpy i strncat? 
void inicjujStruct3( tsapiens *ktos)
{
     int i_itoa; char * c_itoa;

    ktos->id = rand()%100;

    c_itoa = itoa(rand()%100); 

               
         ktos->imie = malloc(20);
    strncat(ktos->imie, "imiA", 4);    // do tego miejsca działa, tzn. tutaj wyrzuca błąd naruszenia ochrony pamięci podczas działania programu
   strncat (ktos->imie, c_itoa, 2);
    
    c_itoa = itoa(rand()%100);       
         ktos->nazwisko = malloc(20);
          printf("\n\033[93;1m w środku inicjujStruct3 \033[0m\n");
    strcpy(ktos->nazwisko, "naz");     
   strncat (ktos->nazwisko, c_itoa, 2);
   

    ktos->rok_u = rand()%100+1900;
    ktos->mies_u = rand()%12+1;
    ktos->dzien_u = rand()%30+1;
    
//czy to jest prawidłowe zwolnienie pamięci w tej sytuacji? 
free(c_itoa);
}

//FUNKCJA NIE SKOŃCZONA miała służyć jako odnośnik do wersji 3 powyżej
void inicjujStruct4( tsapiens *ktos)
{
        int i_itoa; char * c_itoa3;
    ktos->id = rand()%100;

    c_itoa3 = itoa(rand()%100); 
   /* 

    ktos->imie[0] = 'i';
    ktos->imie[1] = 'm';
    ktos->imie[2] = 'i';
    ktos->imie[3] = 'e';*/
    strncat (ktos->imie, "imiĘ", 4);
    printf("\n\033[93;1m\n imie=%s =\033[0m",ktos->imie);
    printf("\n\033[95;1m\n c_itoa=%s =\033[0m",c_itoa3);
   strncat (ktos->imie, c_itoa3, 2);
    printf("\n\033[93;1m\n imie=%s =\033[0m\n",ktos->imie);
   // ktos->imie[4] = c_itoa[0];
   // ktos->imie[5] = c_itoa[1];
   // ktos->imie[6] = '\0';

    
    c_itoa3 = itoa(rand()%100);
    /*
    ktos->nazwisko[0] = 'n';
    ktos->nazwisko[1] = 'a';
    ktos->nazwisko[2] = 'z'; */
    strncat (ktos->nazwisko, "naz", 3);
    
   strncat (ktos->nazwisko, c_itoa3, 2);
   
    ktos->rok_u = rand()%100+1900;
    ktos->mies_u = rand()%12+1;
    ktos->dzien_u = rand()%30+1;
       
//czy to jest prawidłowe zwolnienie pamięci w tej sytuacji   
free(c_itoa3);
}

int main()
{

   
srand(time(NULL));

tosoba czlowiek;
// inicjacja w bez dodatkowej funkcji
    czlowiek.id = rand()%100;
    char * c_itoa2;
    
    c_itoa2 = itoa(rand()%100);
    czlowiek.imie[0] = 'i';
    czlowiek.imie[1] = 'm';
    czlowiek.imie[2] = 'i';
    czlowiek.imie[3] = 'e';
    czlowiek.imie[4] = c_itoa2[0];
    czlowiek.imie[5] = c_itoa2[1];
    czlowiek.imie[6] = '\0';
    
    c_itoa2 = itoa(rand()%100);    
    czlowiek.nazwisko[0] = 'n';
    czlowiek.nazwisko[1] = 'a';
    czlowiek.nazwisko[2] = 'z';
    czlowiek.nazwisko[3] = c_itoa2[0];
    czlowiek.nazwisko[4] = c_itoa2[1];
    czlowiek.nazwisko[5] = '\0';

    czlowiek.rok_u = rand()%100+1900;
    czlowiek.mies_u = rand()%12+1;
    czlowiek.dzien_u = rand()%30+1;
   
//czy to jest prawidłowe zwolnienie pamięci w tej sytuacji   
free(c_itoa2);

tosoba czlowiek2;
inicjujStruct(&czlowiek2);

tosoba czlowiek3;
inicjujStruct2(&czlowiek3);

tsapiens homo;
printf("\n\033[93;1m przed pokaż struct 3 \033[0m\n");
inicjujStruct3(&homo);

printf("\n\033[93;1m czlowiek 1 \033[0m\n");
pokazStruct(czlowiek);

printf("\n\033[93;1m czlowiek 2 \033[0m\n");
pokazStruct(czlowiek2);

printf("\n\033[93;1m czlowiek 3 \033[0m\n");
pokazStruct(czlowiek3);

printf("\n\033[93;1m pokazStructTsapiens \033[0m\n");
pokazStructTsapiens(homo);

printf("\n\nPolskie znaki: ąęćżźółń\n");

tosoba os;
strcpy (os.imie , "imie");
printf("\nos.imie: %s\n", os.imie);

//kodowanie polskich znaków a stringi (powyższy printf prawidłowo wyświetla polskie znaki), problem pojawia sie w momencie użycia funkcji do dodania znaku i dodawania znaków w funkcji; Jak to jest że po wykonaniu funkcji strncat "Ę" i "ę" jest krzaczkiem? wyskoczył błąd "multicharacter chararcter", raz dotyczył tego że mają być cudzysłowy zamiast apostrofów, a raz że tablica, jeszcze sprawdzałem jak to będzie na char*, ale program kończy działanie błędem w momencie użycia strcpy i strncat? 
//char koniec;
//scanf("%c",&koniec);
return 0;
}
