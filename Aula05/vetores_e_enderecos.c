#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int vetor_estatico[3];
    int* vetor_dinamico;

    int tamanho_vetor = 3;

    vetor_dinamico = (int*) malloc(sizeof(int) * tamanho_vetor);

    for (int i = 0; i < tamanho_vetor; i++){
        printf("est: %p\t", &(vetor_estatico[i]));
    }

    printf("\n");

    for (int i = 0; i < tamanho_vetor; i++){
        printf("din: %p\t", &(vetor_dinamico[i]));
    }

    printf("\n");

    printf("%p\n", vetor_dinamico); //endereço na heap
    printf("%p\n", &vetor_dinamico); //endereço na stack

    free(vetor_dinamico);
    // printf("%f\n", (float)(sizeof(vetor_dinamico)/1024.0/1024.0));
}
