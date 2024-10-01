#include <stdio.h>
#include <stdlib.h>

int* retorna_vetor(int max){
    int* vet;
    vet = (int*) malloc(sizeof(int)*max);
    for(int i = 0; i < max; i++){
        vet[i] = i*3;
    }
    return vet;
}

int main(int argc, char const *argv[]){
    int maximo = 4;
    int* vetor = retorna_vetor(maximo);
    for(int i = 0; i < maximo; i++){
        printf("%d\n", vetor[i]);
    }
    free(vetor);
    return 0;
}
