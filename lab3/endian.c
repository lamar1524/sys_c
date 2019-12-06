#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("endian.c\n\n");

    printf("sizeof(short) = %d\n\n", sizeof(short));

    short i = 1;

    char *w = (char*)&i;

    printf("*w = %d\n", *w);
    printf("*(w+1) = %d\n", *(w+1));
}
