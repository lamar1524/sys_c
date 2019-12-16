#define _GNU_SOUTCE
#include <stdlib.h>
#include <stdlib.h>
#include <crypt.h>

char* crypt_r(const char* key, const char *salt, struct crypt_data *data);

int main(){
    struct crypt_data data;

    data.initialized = 0;
    char* password = "passw0rd";
    char* encrypted;

    encrypted = crypt_r(password, "cd", &data);

    printf("p: %s\n", password);
    printf("e: %s\n", encrypted);
    return 0;
}
