#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char* argv[]){
    printf("Podaj liczbę double(float) \n");
    float x;
    scanf("%f", &x);
    printf("%f", x);
    printf("Podaj teraz liczbę double \n");
    double y;
    scanf("%lf", &y);
    printf("%lf", y);
    return 0;
}