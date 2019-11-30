#include <stdio.h>

struct Fraction
{
	int num, den;
};

//TODO Zabezpieczenie przed dzieleniem przez 0, i wyswietlanie u�amk�w niew�a�ciwych
struct Fraction sum(struct Fraction x, struct Fraction y)
{
	// a / b + c / d = (a * d + c * b) / ( b * d )
	struct Fraction z;
	int a = x.num;
	int b = x.den;

	int c = y.num;
	int d = y.den;

	z.num = a * d + c * b;
	z.den = b * d;

	return z;
}

struct Fraction diff(struct Fraction x, struct Fraction y)
{
	// a / b - c / d = (a * d - c * b) / ( b * d )
	struct Fraction z;

	int a = x.num;
	int b = x.den;

	int c = y.num;
	int d = y.den;

	z.num = a * d - c * b;
	z.den = b * d;

	return z;
}
struct Fraction mul(struct Fraction x, struct Fraction y)
{
	// a / b * c / d = (a * c)/(b * d)
	struct Fraction z;
	int a = x.num;
	int b = x.den;

	int c = y.num;
	int d = y.den;

	z.num = a * c;
	z.den = b * d;

	return z;
}
struct Fraction div(struct Fraction x, struct Fraction y)
{
	//(a/b)/(c/d) = (a * d) / (b * c)
	struct Fraction z;
	int a = x.num;
	int b = x.den;

	int c = y.num;
	int d = y.den;

	z.num = a * d;
	z.den = c * b;

	return z;
}
// Printowanie ulamka
void printFraction(struct Fraction x)
{
	if (x.den == 0)
	{
		printf("Nie można dzielić przez 0!");
	}
	else if (x.num == x.den)
	{
		printf("1");
	}
	else if (x.num > x.den)
	{
		int calosc = x.num / x.den;
		x.num = x.num % x.den;
		if (x.num == 0)
		{
			printf("%d\n", calosc);
		}
		else
		{
			printf("%d oraz %d/%d\n", calosc, x.num, x.den);
		}
	}
	else if (x.num < 0)
	{
		int calosc = x.num / x.den;
		x.num = x.num % x.den;
		if (x.num == 0)
		{
			printf("%d\n", calosc);
		}
		else
		{
			printf("%d oraz %d/%d\n", calosc, -x.num, x.den);
		}
	}
	else
	{
		printf("%d/%d \n", x.num, x.den);
	}
}
int main()
{
	struct Fraction a, b;
	printf("Podaj dwa ulamki, kazda liczbe z nich oddziel spacja\n");
	scanf("%d%d%d%d", &a.num, &a.den, &b.num, &b.den);
	printf("Ułamek nr 1: ");
	printFraction(a);
	printf("Ułamek nr 2: ");
	printFraction(b);
	printf("Suma = ");
	printFraction(sum(a, b));
	printf("Roznica = ");
	printFraction(diff(a, b));
	printf("Mnozenie = ");
	printFraction(mul(a, b));
	printf("Dzielenie = ");
	printFraction(div(a, b));
	return 0;
}
