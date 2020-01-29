#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{

	chdir("..");

	char cwd[4096];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("Current working directory %s\n", cwd);
	}
	else
	{
		perror("getcwd() error");
	}
	return 0;
}
