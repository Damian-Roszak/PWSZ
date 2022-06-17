#include <stdio.h> 
#include <math.h>
void main () 
{

int x = 10, y, *wsk_x, *w2; 
wsk_x = &x; 
w2 = wsk_x; 
printf("1 wsk:\t%p\t%d\n", wsk_x, *wsk_x); 		//1. Jaki wydruk ?
printf("2 x:  \t%p\t%d\n", &x, x); 			//2. Jaki wydruk ?
*wsk_x = 15; 
y = x; 
printf("3 x: \t%p\t%d\n", &x, x); 				//3. Jaki wydruk ?
printf("4 y: \t%p\t%d\n", &y, y); 				//4. Jaki wydruk ?
*wsk_x += 10; 
printf("5 x:  \t%p\t%d\n", &x, x); 			//5. Jaki wydruk ?
++*wsk_x; 
printf("6 wsk:  \t%p\t%d\n", wsk_x, *wsk_x);		//6. Jaki wydruk ?
(*wsk_x)++; 
printf("7 x:  \t%p\t%d\n", wsk_x, *wsk_x); 		//7. Jaki wydruk ?
*wsk_x++; 
printf("8 x:  \t%p\t%d\n", wsk_x, *wsk_x); 		//8. Jaki wydruk ?
printf("9 w2: \t%p\t%d\n", w2, *w2); 		

}	
