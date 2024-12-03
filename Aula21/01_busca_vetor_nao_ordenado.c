#include <stdio.h>
#include <stdlib.h>
//Busca sequencial ou linear
// O(n)
int busca(int vetor[], int n, int x){
    for (int i = 0; i < n; i++){
        if (vetor[i] == x){
            return i;
        }
    }
    return -1;
}
//Busca sequencial ou linear com sentinela
// O(n)
int busca(int vetor[], int n, int x){
    vetor[n] = x;
    int i = 0;
    while (vetor[i] != x){
        i++;
    }
    if (i < n) {
        return i;
    }
    return -1;
}

int main(int argc, char const *argv[]){    
    return 0;
}
