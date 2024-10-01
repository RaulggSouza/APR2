#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    char nome1[10] = "IFSP"; //o último caractere depois do escrito é "\0" [IFSP1\0], portanto essa "String" tem 9 caracteres;
    char nome2[] = "IFSP Sao Carlos";

    printf("%s %s\n", nome1, nome2);

    nome1[0] = 'i';
    nome2[4] = '-';
    nome1[4] = 'X';


    printf("%s %s\n", nome1, nome2);

    for (int i = 0; i < 10; i++){
        printf("%d ", nome1[i]);
    }
    printf("\n");

    char nome3[100];
    // nome3 = "UFSP"; //Somente se atribui strings na declaração

    return 1;
}