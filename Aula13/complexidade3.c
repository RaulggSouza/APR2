#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int vetor[] = {1, 3, 5, 3, 5, 6, 2, 9};
    int n = 8;

    int ordenado = 1;
    for (int i = 0; i < n - 1 && ordenado; i++){
        if (vetor[i + 1] < vetor[i]) {
            ordenado = 0;
        }
        
    }
    // pior caso: vetor ordenado -> n vezes
    // melhor caso: 2° elemento < 1° elemento -> 1 vez
    // complexidade de tempo: O(n)

    return 0;
}
