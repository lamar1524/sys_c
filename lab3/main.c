#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void pointers();

int main(int argc, char *argv[]) {
	int test1 = 0;
	int test2 = 1;
	
	if (test1) pointers();
	if (test2) arrays();
	return 0;
}

