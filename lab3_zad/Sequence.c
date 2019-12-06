#include <stdio.h>
#include <stdlib.h>

double a1(int n)
{
	if (n == 0)
	{
		return 1.0;
	}
	else if (n == 1)
	{
		return 4.0;
	}
	return 2 * a1(n - 1) + 0.5 * a1(n - 2);
}
/* 
	n = 4
	a1(4) = 2*a2(3) + 0.5*a7(2) = 2*19 + 0.5*8.5 = 42.25
	a2(3) = 2*a3(2) + 0.5*a6(1) = 2*8.5 + 0.5*4.0 = 17 + 2 = 19
	a3(2) = 2*a4(1) + 0.5*a5(0) = 2*4 + 0.5*1 = 8 + 0.5 = 8.5
	a4(1) = 4.0
	a5(0) = 1.0
	a6(1) = 4.0
	a7(2) = 2*a8(1) + 0.5*a9(0) = 2*4 + 0.5 * 1 = 8 + 0.5 = 8.5
	a8(1) = 4
	a9(0) = 1
*/

double a2(int n)
{
	double r0 = 1.0;
	double r1 = 4.0;
	if (n == 0)
	{
		return 1.0;
	}
	if (n == 1)
	{
		return 4.0;
	}
	double r2 = 0;
	int i;
	for (i = 2; i <= n; i++)
	{
		r2 = 2 * r1 + 0.5 * r0;
		r0 = r1;
		r1 = r2;
	}
	return r2;
	/*
		n = 4
		a2(4) 
		r0 = 1.0
		r1 = 4.0
		r2 = 0;	i = 2
		2 <= 4 true
		r2 = 2*r1 + 0.5 * r0 = 2*4 + 0.5*1 = 8.5
		r0 = r1 = 4.0
		r1 = r2 = 8.5
		i++
		3 <= 4 true
		r2 = 2*r1 + 0.5 * r0 = 2*8.5 + 0.5*4 = 17 + 2 = 19
		r0 = r1 = 8.5
		r1 = r2 = 19
		i++
		4 <= 4 true
		r2 = 2*r1 + 0.5 * r0 = 2*19 + 0.5*8.5 = 38 + 4.25 = 42.25 
		r0 = r1 = 19
		r1 = r2 = 42.25
		i++
		5 <= 4 false
		return r2
	*/
}

double a3(int n)
{
	double r0 = 1.0;
	double r1 = 4.0;
	if (n == 0)
	{
		return 1.0;
	}
	if (n == 1)
	{
		return 4.0;
	}
	int i;
	for (i = 2; i <= n; i++)
	{
		r1 = 2.0 * r1 + 0.5 * r0;
		if (i == 2)
		{
			r0 = 4;
		}
		else
		{
			r0 = (r1 - 0.5 * r0) / 2.0;
		}
	}
	return r1;
	/*
		n = 4
		a2(4) 
		r0 = 1.0
		r1 = 4.0
		2 <= 4 true
		r1 = 2*r1 + 0.5 * r0 = 2*4 + 0.5*1.0 = 8.5
		r0 = (r1 - 0.5 * r0) / 2.0 = (8.5 - 0.5 * 1)/2 = 4
		i++
		3 <= 4 true
		r1 = 2*r1 + 0.5 * r0 = 2*8.5 + 0.5*4.0 = 17 + 2 = 19
		r0 = (r1 - 0.5 * r0) / 2.0 = (19 - 0.5 * 4)/2 = 17/2 =  8.5
		i++
		4 <= 4 true
		r1 = 2*r1 + 0.5 * r0 = 2*19 + 0.5*8.5 = 38 + 4.25 = 42.25
		r0 = (r1 - 0.5 * r0) / 2.0 = (42.25 - 0.5 * 8.5)/2 = 38
		i++
		5 <= 4 false
		return r2
	*/
}
int main(int argc, const char *argv[])
{
	printf("Podaj liczbe \n");
	int x;
	scanf("%d", &x);
	printf("Funkcja a1: \n %lf \n", a1(x));
	printf("Funkcja a2: \n %lf \n", a2(x));
	printf("Funkcja a3: \n %lf \n", a3(x));
	return 0;
}
