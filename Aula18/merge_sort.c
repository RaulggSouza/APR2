#include <stdio.h>
#include <stdlib.h>

void populaVetor(int* vet, int size){
    for (int i = 0; i < size; i++){
        int n;
        scanf("%d", &n);
        vet[i] = n;
    }
}

void printVetor(int* vet, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void inter(int* vet, int c1, int f1, int c2, int f2){
    int* aux = malloc(sizeof(int) * (f2 - c1) + 1);
    int p1 = c1, p2 = c2; 
    for (int i = 0; i < (f2-c1)+1; i++){
        if (vet[p1] <= vet[p2] || p2 > f2){
            aux[i] = vet[p1];
            p1++;
        }else if (vet[p2] < vet[p1] || p1 > f1){
            aux[i] = vet[p2];
            p2++;
        }
    }
    for (int i = c1, j = 0; i < f2+1; i++, j++){
        vet[i] = aux[j];
    }
}

void merge(int* vet, int comeco, int fim){
    if (fim > comeco){
        int meio = (comeco + fim) / 2;
        merge(vet, comeco, meio);
        merge(vet, meio+1, fim);
        inter(vet, comeco, meio, meio+1, fim);
    }
}

int main(int argc, char const *argv[]){
    int size;
    scanf("%d", &size);
    int* vetor = malloc(sizeof(int) * size);
    populaVetor(vetor, size);
    printVetor(vetor, size);
    merge(vetor, 0, size-1);
    printVetor(vetor, size);
    free(vetor);
    return 0;
}
