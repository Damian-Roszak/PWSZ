#include<iostream>
#include<cstring>

int main (int argc, char *argv[]){
	char const *klucz = (argc>=2)? argv[1]: "";
	size_t dlugosc_klucza = (argc>=2)? std::strlen(klucz): 1;
	char ch;
	for (std::size_t k = 0; std::cin.get(ch); k = (k+1)%dlugosc_klucza)	
		std::cout.put(ch^klucz[k]);
	return 0;
}