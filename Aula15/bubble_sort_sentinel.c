#include <stdio.h>
#include <stdlib.h>

void printVetor(int* vet, int size){
    printf("\n");
    for (int i = 0; i < size; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[]){
    int size = 10;
    // int vet[10] = {1,5,7,9,2,3,4,5,7,0}; // Random
    // int vet[10] = {1,2,3,4,5,6,7,8,8,9}; // Sorted
    int vet[10] = {1,2,3,4,5,6,8,7,9,8}; // Nearly Sorted
    // int vet[10] = {9,8,7,6,5,4,3,2,1,0}; // Inverse Sorted
    int aux;
    int sentinel = 10;
    int last = 0;
    for (int i = 0; i < size; i++){
        printf("%d ", vet[i]);
    }
    for (int j = 0; size-j > 0; j++){
        for (int i = 0; i < sentinel; i++){
            last = 0;
            if(vet[i] > vet[i+1]){
                aux = vet[i+1];
                vet[i+1] = vet[i];
                vet[i] = aux;
                last = i;
            }
        }
        sentinel = last;
        if (last == 0){
            break;
        }
    }
    printVetor(vet, size);
    return 0;
}
