#include <limits.h>
#include <stdio.h>
#include <unistd.h>


int main()
{
	chdir("Fibo");
	
	char cwd[4096];
	if (getcwd(cwd, sizeof(cwd)) != NULL) {
		printf("Current working dir: %s\n", cwd);
	} else {
		perror("getcwd() error");
	}
	
	return 0;
}
