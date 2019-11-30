#include <stdio.h>
#include <stdlib.h>


double a1(int n){
	if(n == 0){
		return 1.0;
	}
	else if(n == 1){
		return 4.0;
	}
	return 2*a1(n-1) + 0.5*a1(n-2);
}

double a2(int n){
	double r0 = 1.0;
	double r1 = 4.0;
	double r2 = 0;
	int i;
	for(i = 2; i <= n; i++){
		r2 = 2*r1 + 0.5*r0;
		r0 = r1;
		r1 = r2;
	}
	return r2;
}

double a3(int n){
	double r0 = 1.0;
	double r1 = 4.0;
	int i;
	for (i = 2; i <= n; i++){
		r1 = 2.0*r1 + 0.5 * r0;
		if(i==2){
		r0 = 4;
		}
		else{
			r0 = (r1 - 0.5 * r0)/2.0;
		}
	}
	return r1;
}
int main(int argc, const char* argv[] ){
	printf("Podaj liczbe \n");
	int x;
	scanf("%d", &x);
	printf("Funkcja a1: \n %lf \n", a1(x));
	printf("Funkcja a2: \n %lf \n", a2(x));
	printf("Funkcja a3: \n %lf \n", a3(x));
	return 0;
}
