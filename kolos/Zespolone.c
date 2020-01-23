#include <stdio.h>
#include <stdlib.h>

struct Zesp {
	int real, imaginary;
	};
//z1 = (a,b), z2 = (c,d), z1+z2 = (a,b)+(c,d) = a+bi+c+di = a+c + bi+di = (a+c) + i*(b+d)
struct Zesp sum(struct Zesp x, struct Zesp y){
	struct Zesp z;
	int a = x.real;
	int b = x.imaginary;
	
	int c = y.real;
	int d = y.imaginary;
	
	z.real = a+c;
	z.imaginary = b+d;
	
	return z;
}

struct Zesp diff(struct Zesp x, struct Zesp y){
	struct Zesp z;
	int a = x.real;
	int b = x.imaginary;
	
	int c = y.real;
	int d = y.imaginary;
	
	z.real = a-c;
	z.imaginary = b-d;
	
	return z;
}

struct Zesp mult(struct Zesp x, struct Zesp y){
	struct Zesp z;
	int a = x.real;
	int b = x.imaginary;
	
	int c = y.real;
	int d = y.imaginary;
	
	z.real = a*c-(b*d);
	z.imaginary = a*d+(b*c);
	
	return z;
}

int main(int argc, char *argv[]) {
	
		struct Zesp a, b, c;
		
		scanf("%d%d%d%d", &a.real, &a.imaginary, &b.real, &b.imaginary);
		c = sum(a, b);
		printf("Dodawanie: %d+%di\n", c.real, c.imaginary);
		c = diff(a, b);
		printf("Odejmowanie: %d+%di\n", c.real, c.imaginary);
		c = mult(a, b);
		printf("Mnozenie: %d+%di\n", c.real, c.imaginary);
		return 0;
	}
	

