#include <stdio.h>
#include <stdlib.h>

void printVetor(int* vet, int size){
    printf("\n");
    for (int i = 0; i < size; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void trocar(int* vet, int index_atual, int index_menor){
    int aux;
    aux = vet[index_atual];
    vet[index_atual] = vet[index_menor];
    vet[index_menor] = aux;
}

int main(int argc, char const *argv[]){
    int size = 10;
    // int vet[10] = {1,5,7,9,2,3,4,5,7,0}; // Random
    // int vet[10] = {1,2,3,4,5,6,7,8,8,9}; // Sorted
    // int vet[10] = {1,2,3,4,5,6,8,7,9,8}; // Nearly Sorted
    int vet[10] = {9,8,7,6,5,4,3,2,1,0}; // Inverse Sorted];
    printVetor(vet, size);
    for (int i = 0; i < size-1; i++){
        int menor = vet[i];
        int indice_menor = i;
        for (int j = i; j < size; j++){
            if (vet[j] < menor){
                menor = vet[j];
                indice_menor = j;
            }
        }
        trocar(vet, i, indice_menor);
    }
    printVetor(vet, size);
    return 0;
}
