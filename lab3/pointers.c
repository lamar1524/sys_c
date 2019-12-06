#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void pointers() {
	printf("pointers.c\n\n");
		
    int x;
	int y;

    printf("&x = %p\n", &x); /* &x to adres zmiennej x */
    printf("&y = %p\n", &y); /* &y to adres zmiennej y */

	/* deklaracja zmiennej wskaznikowej w */

    int *w; /* w to wskaznik na wartosc typu int
			   w przechowuje adres wartosci typu int */

    w = &x; /* do w podstawiamy adres zmiennej x */

	printf("w = %p\n\n", w);

	*w = 5; /* zapis wartosci 5 do zmiennej x typu int
	           bo w to wskaznik na zmienna x typu int */
	            
    y = *w; /* odczyt wartosci 5 ze zmiennej x typu int
               bo w to wskaznik na zmienna x typu int */
                
    printf("x = %d\n", x);
    printf("y = %d\n", x);
    printf("*w = %d\n", *w);
    
    /*    
    
      adres y      adres x
      |            |                  
    |[5][0][0][0]|[5][0][0][0]|
     \____y____/  \____x____/
     
    */
	
}
