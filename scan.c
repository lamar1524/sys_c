#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char* argv[]){
    printf("--------SPOSÓB 1-------- \n");
    printf("Podaj zdanie \n");
    char string1[81];
    fgets(string1, 81, stdin);
    printf("%s", string1);
    printf("--------SPOSÓB 2-------- \n");
    char string2[0];
    scanf("%[^\n]c", string2);
	printf("%s \n", string2);
    return 0;
}