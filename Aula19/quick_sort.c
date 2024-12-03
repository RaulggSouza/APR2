#include <stdio.h>
#include <stdlib.h>

int particao(int vetor[], int inicio, int fim){
    int p = (fim - inicio)/2;
    for (int i = inicio; i < fim; i++){
        if (vetor[i] <= vetor[p] && i > p){
            int aux = vetor[i];
            vetor[i] = vetor[p];
            vetor[p] = aux;
        }
    }
    return p;
}

void quick(int vetor[], int inicio, int fim){
    if (inicio >= fim){
        return;
    }   
    int p = particao(vetor, inicio, fim);
    quick(vetor, inicio, p);
    quick(vetor, p+1, fim);
}

int main(int argc, char const *argv[]){
    int size = 7;
    int* vetor = (int*) malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++){
        int num;
        scanf("%d", &num);
        vetor[i] = num;
    }
    //5 3 1 4 9 7 8 
    quick(vetor, 0, size-1);
    return 0;
}
