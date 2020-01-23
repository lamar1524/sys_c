#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>


int main() {
	int check;
	char* dirname = "Nowy";
	check = mkdir(dirname, 0700);
	
	if (!check) {
		printf("DIrectory created\n");
	} else {
		printf("Could not create directory. It aleady exists.\n");
		exit(1);
	}
	getchar();
	system("ls -l");
	return 0;
	
}
