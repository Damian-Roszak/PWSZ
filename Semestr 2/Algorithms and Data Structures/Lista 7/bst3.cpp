#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
//definicja wezla
struct wezel
{
int wartosc;           //wartosc przechowywana w wezle
struct wezel *rodzic;  //wskaznik na rodzica
struct wezel *l_syn;   //wskaznik na lewe dziecko
struct wezel *p_syn;   //wskaznik na prawe dziecko
};
struct wezel *root;  //wskaźnik na root'a
 
//funkcja zwraca wskaznik elementu o najmniejszej wartosci (najbardziej na lewo)
struct wezel* naj_lewo(struct wezel *start)
{
if(start->l_syn != NULL)
return naj_lewo(start->l_syn);
else
return start;
}
 
//funkcja zwraca wezel o podanej wartosci, badz NULL, gdy taki wezel nie istnieje
struct wezel* szukaj(struct wezel *start, int wartosc) 
{
//jezeli wezel ma szukana wartosc to odnalezlismy go
    if (start->wartosc == wartosc) return start;
    //jezeli szukana wartosc jest mniejsza to szukamy w lewym poddrzewie o ile istnieje
    else if (wartosc < start->wartosc && start->l_syn != NULL) return szukaj(start->l_syn, wartosc);
    //jezeli szukana wartosc jest wieksza to szukamy w prawym poddrzewie o ile istnieje     
    else if (wartosc > start->wartosc && start->p_syn != NULL) return szukaj(start->p_syn, wartosc);
    return NULL;
}
 
//dodaje wezel o podanej wartosci n, do drzewa o korzeniu start
int dodawanie(int n, struct wezel *start)
{
    //jezeli drzewo jest puste to dodaj korzen
    if (root == NULL)
    {
        root = (wezel*)malloc(sizeof *root);
        root->wartosc = n;
        root->l_syn = NULL;
        root->p_syn = NULL;
        root->rodzic = NULL;
    }
    //jezeli zadana wartosc jest mniejsza od korzenia idz do lewego poddrzewa
    else if(n < start->wartosc)
    {
        //jezeli lewe poddrzewo istnieje wywolaj dla niego ta funkcje rekurencyjnie
        if(start->l_syn != NULL)
        {
             dodawanie(n,start->l_syn);
        }
        //jezeli lewe poddrzewo nie istnieje dodaj nowy wezel o zadanej wartosci
        else
        {
            wezel *nowy = (wezel*)malloc(sizeof *root);
            nowy->wartosc = n;
            nowy->l_syn = NULL;
            nowy->p_syn = NULL;
            nowy->rodzic = start;
            start->l_syn=nowy;
        }
    }
    //jezeli zadana wartosc jest wieksza lub rowna korzeniowi idz do prawego poddrzewa   
    else
    {
        //jezeli prawe poddrzewo istnieje wywolaj dla niego ta funkcje rekurencyjnie      
        if(start->p_syn!=NULL)
        {
            dodawanie(n,start->p_syn);
        }
        //jezeli prawe poddrzewo nie istnieje dodaj nowy wezel o zadanej wartosci     
        else
        {
            wezel *nowy = (wezel*)malloc(sizeof *root);
            nowy->wartosc = n;
            nowy->l_syn = NULL;
            nowy->p_syn = NULL;
            nowy->rodzic = start;
            start->p_syn=nowy;
        }
    }
return 0;
}
 
//usun wezel start
void kasowanie(struct wezel *start)
    {
    //jezeli wezel nie ma dzieci
    if(start->l_syn==NULL && start->p_syn==NULL)
    {
    //jezeli wezel jest korzeniem
    if(start->rodzic==NULL)
    {
    root=NULL;
    }
    //jezeli wezel jest po lewej stronie rodzica,
    else if(start->rodzic->l_syn==start)
    {
    //usun wezel z lewej strony wezla rodzica
    start->rodzic->l_syn=NULL;
    }
    else
    {
    //usun wezel z prawej strony wezla rodzica     
    start->rodzic->p_syn=NULL;
    }
    delete start;
    }
    //jezeli wezel ma tylko jedno dziecko
    else if(start->l_syn==NULL || start->p_syn==NULL)
    {
    //jezeli po lewej stronie nie ma dziecka
    if(start->l_syn==NULL)
    {
    //jezeli wezel jest korzeniem
    if(start->rodzic==NULL)
    {
    root=start->p_syn;
    }
    //jezeli wezel jest po lewej stronie rodzica
    else if(start->rodzic->l_syn==start)
    {
    //przyczep z lewej strony rodzica wezel bedacy po prawej stronie usuwanego wezla
    start->rodzic->l_syn=start->p_syn;
    }
    else
    {
    //przyczep z prawej strony rodzica wezel bedacy po prawej stronie usuwanego wezla
    start->rodzic->p_syn=start->p_syn;
    }
    }
    else
    {
    //jezeli wezel jest korzeniem
    if(start->rodzic==NULL)
    {
    root=start->l_syn;
    }
    //jezeli wezel jest po lewej stronie rodzica
    else if(start->rodzic->l_syn==start)
    {
    //przyczep z lewej strony rodzica wezel bedacy po lewej stronie usuwanego wezla
    start->rodzic->l_syn=start->l_syn;
    }
    else
    {
    //przyczep z prawej strony rodzica wezel bedacy po prawej stronie usuwanego wezla
    start->rodzic->p_syn=start->l_syn;
    }
    }
    delete start;
    }
    else
    {
    //wstaw w miejsce usuwanego elementu - najmniejsza wartosc z prawego poddrzewa
    struct wezel *temp;
    temp=naj_lewo(start->p_syn);
    start->wartosc = temp->wartosc;
    kasowanie(temp);
    }
}
 
//przejdz drzewo w kolejnosci zaczynajac od wezla start
void in_order_tree_walk(struct wezel *start)
{
if(start->l_syn != NULL) //jezeli ma dzieci po lewej stronie wywolaj funkcje rekurencyjnie
in_order_tree_walk(start->l_syn);
 
printf("%d\n", start->wartosc); //wypisz wartosc
 
if(start->p_syn != NULL) //jezeli ma dzieci po prawej stronie wywolaj rekurencyjnie
in_order_tree_walk(start->p_syn);
}
 
//lsouje wartosc w przedziale od a do b
int losowanie(int a, int b)
{
    if(a < b)
        return a + (int)((b-a+1.0)*(rand()/(RAND_MAX+1.0)));
    else
    {
        fprintf(stderr, "złe wartości");
        return -1;
    }
}
 
//przklad uzycia drzewa BST
int main(int argc, char *argv[])
{
int i;
//pobierz rozmiar drzewa z parametru wejsciowego
int a,k,size=atoi(argv[1]);
root = NULL;
 
//struct timezone tz;
//struct timeval tv;
 
//gettimeofday(&tv, &tz);
srand(time(0));
 
//losuj wartosc elementow
for(i=0;i<size;i++)
{
a=losowanie(1,100);
dodawanie(a, root);
}
printf("\n");
 
//przejdz drzewo w kolejnosci
in_order_tree_walk(root);
 
//usun wartosc z drzewa
printf("Wartość węzła do usunięcia: \n");
scanf("%d", &k);
kasowanie(szukaj(root,k));
printf("\n\n");
 
//przejdz drzewo w kolejnosci
in_order_tree_walk(root);
 
return 0;
}
