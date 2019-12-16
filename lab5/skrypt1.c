#define _GNU_SOUTCE
#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>

int main(int argc, char* argv[]){
    const char input[] = "baza.txt";

    FILE *file = fopen(input, "r");
    if (file == NULL){
    perror(input);
    return EXIT_FAILURE;
    }
    char line[100];
    struct crypt_data data;
    data.initialized = 0;
    while(fgets(line, sizeof line, file) != NULL)
    {
        char login[32+1] = "";
        char full_name[50];
        char password[8+1];

        char *token =  strok(line, ";");
        strncat(login, token, 1);
        strncat(full_name, " ");

        token = strok(NULL, ";");

        int n = strlen(token);

        if (token[n-2] == '\r')
            token[n-2] = '\0';
        else
            token[n-1] = '\0';

        if strlen(token) > 8)
            token[8] = 0;

        strcpy(password, token);

        char* encrypted = crypt_r(password, "cd",&data);

        char command[100] = "useradd -m -p";
        strcat(command, encrypted);
        strcat(command, " -c \"");
        strcat(command, full_name);
        strcat(command, "\" -s /bin/bash -g student ");

        system(command);
    }
    fclose(file);
    return 0;
}
