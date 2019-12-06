#include <stdlib.h>
#include <stdio.h>
int fibo1(int n)
{
    int n0 = 1;
    int n1 = 1;
    int i;
    for (i = 2; i < n; i++)
    {
        n1 = n1 + n0;
        n0 = n1 - n0;
    }
    return n1;
}

int fibo2(int n)
{
    int tab[n + 1];
    tab[0] = 1;
    tab[1] = 1;
    int i;
    for (i = 2; i < n; i++)
    {
        tab[i] = tab[i - 1] + tab[i - 2];
    }
    return tab[n - 1];
}

int fibo3(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    return fibo3(n - 1) + fibo3(n - 2);
}

int main(int argc, const char *argv[])
{
    printf("--------SPOSÓB 1-------- \n");
    printf("Podaj który wyraz ciągu chcesz \n");
    int a;
    scanf("%d", &a);
    printf("%d \n", fibo3(a));
    printTree(kolejnosc);
    /*
    printf("--------SPOSÓB 2-------- \n");
    printf("Podaj który wyraz ciągu chcesz \n");
    int b;
    scanf("%d", &b);
    printf("%d \n", fibo2(b));
    printf("--------SPOSÓB 3-------- \n");
    printf("Podaj który wyraz ciągu chcesz \n");
    int c;
    scanf("%d", &c);
    printf("%d \n", fibo3(c));
    printf("------------------------ \n");*/
    return 0;
}