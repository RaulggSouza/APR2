#include <stdio.h>
#include <stdlib.h>

void printVetor(int* vet, int size){
    printf("\n");
    for (int i = 0; i < size; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void trocar(int* vet, int index_atual, int index_novo){
    int aux;
    aux = vet[index_atual];
    vet[index_atual] = vet[index_novo];
    vet[index_novo] = aux;
}

int main(int argc, char const *argv[]){
    int size = 10;
    // int vet[10] = {1,5,7,9,2,3,4,5,7,0}; // Random
    // int vet[10] = {1,2,3,4,5,6,7,8,8,9}; // Sorted
    // int vet[10] = {1,2,3,4,5,6,8,7,9,8}; // Nearly Sorted
    // int vet[10] = {9,8,7,6,5,4,3,2,1,0}; // Inverse Sorted
    int vet[9] = {1,5,7,11,9,8,12,15,20};
    size = 9;
    int aux;
    printVetor(vet, size);
    for (int i = 0, k = size-1; i < k; i++, k--){
        int indice_menor = i;
        int indice_maior = k;
        for (int j = i; j < size-i; j++){
            if (vet[j] < vet[indice_menor]){
                indice_menor = j;
            }
            if (vet[j] > vet[indice_maior]){
                indice_maior = j;
            }
        } 
        if (indice_menor != i){
            trocar(vet, i, indice_menor);
        }
        if (indice_maior != k && vet[i] != vet[indice_maior]){
            trocar(vet, k, indice_maior);
        }
    }
    printVetor(vet, size);
    return 0;
}
