#include <stdio.h>

int main(int argc, char const *argv[]){
    int x = 10;
    float y = 3.14f;
    double z = 3.14;
    char nome[10];
    short int a = 3;
    long int b = 10;
    long long int d = 10;
    unsigned int u = 10;
    char c = 'a';

    printf("int: %ld\n", sizeof(x));
    printf("float: %ld\n", sizeof(y));
    printf("double: %ld\n", sizeof(z));
    printf("String: %ld\n", sizeof(nome));
    printf("short int: %ld\n", sizeof(a));
    printf("long int: %ld\n", sizeof(b));
    printf("long long int: %ld\n", sizeof(d));
    printf("unsigned int: %ld\n", sizeof(u));
    printf("char: %ld\n", sizeof(c));


    return 0;
}
