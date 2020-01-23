#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    long a, b;
    int dlugoscW, dlugoscA, dlugoscB;
    int wynik[50];
    int temp[50];
    int i, j;
    printf("a = ");
    scanf("%ld", &a);
    printf("b = ");
    scanf("%ld", &b);
    char aString[100];
    char bString[100];
    char wString[100];
    sprintf(aString, "%ld", a);
    sprintf(bString, "%ld", b);
    sprintf(wString, "%ld", a - b);
    dlugoscA = strlen(aString);
    dlugoscB = strlen(bString);
    dlugoscW = strlen(wString);

    for (i = 0; i < dlugoscA; i++)
    {
        temp[i] = aString[i] - 48;
    }
    for (i = dlugoscA - 1, j = dlugoscB - 1; i >= 0; i--, j--)
    {
        if (j >= 0)
        {
            if (aString[i] - 48 < bString[j] - 48)
            {
                temp[i] += 10;
                temp[i - 1]--;
            }
        }
        else
        {
            if (temp[i] == -1)
            {
                temp[i] = 9;
                if (i > 0)
                {
                    temp[i - 1]--;
                }
            }
        }
    }
    printf(" ");
    for (i = 0; i < dlugoscA; i++)
    {
        if (temp[i] >= 10)
        {
            printf("%d", temp[i]);
        }
        else
        {
            printf(" %d", temp[i]);
        }
    }
    printf("\n ");
    for (i = 0; i < dlugoscA; i++)
    {
        printf(" %d", aString[i] - 48);
    }
    printf("\n-");
    int roznica = dlugoscA - dlugoscB;
    for (i = 0; i < roznica; i++)
    {
        printf("  ");
    }
    for (i = 0; i < dlugoscB; i++)
    {
        printf(" %d", bString[i] - 48);
    }
    printf("\n-");
    for (i = 0; i < dlugoscA * 2; i++)
    {
        printf("-");
    }
    printf("\n ");
    for (i = dlugoscA - 1, j = dlugoscB - 1; i >= 0; i--, j--)
    {
        if (j >= 0)
        {
            wynik[i] = temp[i] - (bString[j] - 48);
        }
        else
        {
            wynik[i] = temp[i];
        }
    }
    roznica = dlugoscA - dlugoscW;

    for (i = 0; i < dlugoscA; i++)
    {
        if (i < roznica)
        {
            printf("  ");
        }
        else
        {
            printf(" %d", wynik[i]);
        }
    }
    printf("\n");
    return 0;
}