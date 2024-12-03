#include <stdio.h>
#include <stdlib.h>
//Busca sequencial ou linear
// O(n)
int busca(int vetor[], int n, int x){
    for (int i = 0; i < n && vetor[i] <= x; i++){
        if (vetor[i] == x){
            return i;
        }
    }
    return -1;
}

//busca binaria
//O (log(n))
int busca(int vetor[], int n, int x){
    int comeco = 0;
    int fim = n-1;
    while (comeco <= fim){
        int meio = (comeco + fim)/2;
        if (vetor[meio] == x){
            return meio;
        } else {
            if (vetor[meio] > x){
                fim = meio-1;
            } else {
                comeco = meio+1;
            }
        }
    }
    return -1;
}

int busca(int vetor[], int n, int x){
    return busca_rec(vetor, 0, n-1, x);
}

int busca_rec(int vetor[], int c, int f, int x){
    if (c > f){
        return -1;
    }
    int meio = (c + f)/2;
    if (vetor[meio] == x){
        return meio;
    } else {
        if (vetor[meio] > x){
            return busca_rec(vetor, c, meio-1, x);
        } else {
            return busca_rec(vetor, meio+1, f, x);    
        }
    }
}

// Busca por interpolacao
// Só funciona bem com vetores ordenados uniformemente (aleatório)
// O(log log n)
int busca(int vetor[], int n, int x){
    int comeco = 0;
    int fim = n-1;
    while (comeco <= fim){
        // A -> (x - vetor[comeco])
        // B -> (vetor[fim] - vetor[comeco])
        // C -> (meio - comeco)
        // D -> (fim - comeco)

        /*
        A/B = C/D
        A/B = (m-c)/D
        A*D = Bm -Bc
        m = A*D+Bc/B
        m = (x - vet[c] * (f - c) + (vet[f] - vet[c]) * c))/vet[f] - vet[c]
        */

        int meio = ((x - vetor[comeco]) * (fim - comeco) + (vetor[fim] - vetor[comeco]) * comeco)/(vetor[fim] - vetor[comeco]);
        if (vetor[meio] == x){
            return meio;
        } else {
            if (vetor[meio] > x){
                fim = meio-1;
            } else {
                comeco = meio+1;
            }
        }
    }
    return -1;
}