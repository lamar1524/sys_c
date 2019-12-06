#include <stdio.h>

void wartosc(int a) {
	a = 1;
}

void zmienna(int *a) {
	*a = 1;
}

int main(int argc, char *argv[]) {
	printf("przekazywanie.c\n\n");
	
	int a = 0;

	printf("a = %d\n", a);

	wartosc(a);

	printf("a = %d\n", a);

	zmienna(&a);

	printf("a = %d\n", a);
}
