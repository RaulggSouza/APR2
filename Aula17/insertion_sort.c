#include <stdio.h>
#include <stdlib.h>

void printVetor(int* vet, int size){
    printf("\n");
    for (int i = 0; i < size; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void insert(int* vet, int size, int start, int final){
    int aux;
    for(int i = final; i > start; i--){
        aux = vet[i];
        vet[i] = vet[i-1];
        vet[i-1] = aux;
    }
}

int main(int argc, char const *argv[]){
    int size = 10;
    int vet[10] = {1,0,7,9,2,3,4,5,7,5}; // Random
    // int vet[10] = {1,2,3,4,5,6,7,8,8,9}; // Sorted
    // int vet[10] = {1,2,3,4,5,6,8,7,9,8}; // Nearly Sorted
    // int vet[10] = {9,8,7,6,5,4,3,2,1,0}; // Inverse Sorted;
    printVetor(vet, size);
    for (int i = 0; i < size; i++){
        int trade_index = i;
        for (int j = i+1; j < size; j++){
            if (vet[j] < vet[trade_index]){
                trade_index = j;
            }
        }
        if (trade_index > 0){
            insert(vet, size, i, trade_index);
        }
    }
    printVetor(vet, size);
    
    return 0;
}
