#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[]){
    char nome1[32];
    char nome2[32];
    char nome3[32];

    // scanf("%s", nome1);

    // printf("%s\n", nome1);

    // gets(nome2); //O gets pega todos os caracteres informados na string, mesmo os não utilizados (no caso 32)
    // printf("%s", nome2);

    fgets(nome1, 32, stdin); //Somente para string, pega o valor informado no parametro do meio. Pega o enter digitado
    printf("%s\n", nome1);
    nome1[strlen(nome1)-1] = '\0';

    int n = strlen(nome1);
    printf("%d\n", n);
    puts(nome1); //Imprime e da o \n

    return 1;
}