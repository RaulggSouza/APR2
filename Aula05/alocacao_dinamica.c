#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int* vetor;

    int tamanho_vetor = 5;
    //Usando memória heap. Heap > stack
    //malloc() = aloca memória na memória heap
    vetor = (int*) malloc(sizeof(int) * tamanho_vetor);
    //calloc() = aloca memória e passa zerando todos os valores
    // vetor = (int*) calloc(sizeof(int), tamanho_vetor);

    for (int i = 0; i < tamanho_vetor; i++){
        printf("%d\t", vetor[i]);
    }
    free(vetor);
    printf("%f\n", (float)(sizeof(vetor)/1024.0/1024.0));
}
