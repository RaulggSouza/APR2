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
    // int vet[10] = {1,5,7,9,2,3,4,5,7,0};
    int vet[10] = {1,2,3,4,5,6,8,7,9,8};
    int aux;
    printVetor(vet, size);
    for (int j = 0; size-j > 0; j++){
        for (int i = 0; size-i > 0; i++){
            if(vet[i] > vet[i+1]){
                aux = vet[i+1];
                vet[i+1] = vet[i];
                vet[i] = aux;
            }
            printVetor(vet, size);
        }
    }
    printf("\n");
    printVetor(vet, size);
    return 0;
}
