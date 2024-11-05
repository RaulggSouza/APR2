#include <stdio.h>
#include <stdlib.h>

void inter(int* vet, int c1, int f1, int c2, int f2){
    int* aux = malloc(sizeof(int) * (c1 + f2 + 1));
}

void merge(int* vet, int comeco, int fim){
    if (fim > comeco){
        int meio = (comeco + fim) / 2;
        merge(vet, comeco, meio);
        merge(vet, meio+1, fim);
        inter(vet, comeco, meio, meio+1, fim);
    }
}

void populaVetor(int* vet, int size){
    for (int i = 0; i < size; i++){
        int n;
        scanf("%d", &n);
        vet[i] = n;
    }
}

int main(int argc, char const *argv[]){
    int size = 10;
    int* vetor = malloc(sizeof(int) * size);
    populaVetor(vetor, size);
    merge(vetor, 0, size-1);
    free(vetor);
    return 0;
}
