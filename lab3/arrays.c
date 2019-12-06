#include <stdio.h>

void arrays() {
    printf("arrays.c\n\n");

  	int i;
    int t[3] = {1, 5, 9};

  	printf("sizeof(i) = %d\n", sizeof(i));
  	printf("sizeof(t) = %d\n\n", sizeof(t));

    printf("&t = %p\n", &t);
    printf("t = %p\n", t);
    printf("t+1 = %p\n", t+1);
    printf("t+2 = %p\n\n", t+2);

    printf("*t = %d\n", *t);
    printf("*(t+1) = %d\n", *(t+1));
    printf("*(t+2) = %d\n\n", *(t+2));

    printf("t[0] = %d\n", t[0]);
    printf("t[1] = %d\n", t[1]);
    printf("t[2] = %d\n\n", t[2]);
	/*
    printf("*((int*)0x23FF34) = %d\n", *((int*)0x23FF34));
    printf("*((int*)0x23FF38) = %d\n", *((int*)0x23FF38));
    printf("*((int*)0x23FF3C) = %d\n\n", *((int*)0x23FF3C));
	*/
    printf("*t = %d\n", *t);
    printf("*t+1 = %d\n", *t+1);
    printf("*t+2 = %d\n", *t+2);
}
