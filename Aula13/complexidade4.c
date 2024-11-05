#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int vetor[] = {1, 3, 5, 3, 5, 6, 2, 9};
    int n = 8;

    int x = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            x = x + 1; // n² vezes
        }
    }
    
    int repetido = 0;
    for (int i = 0; i < n-1 && !repetido; i++){
        for (int j = i + 1 ; j < n; j++){
            x = x+1;
            if (vetor[i] == vetor[j]){ // x
                repetido = 1;
                break;
            }
        }
    }

    /*
    1a          -> 7x
    2a          -> 6x
    ...
    7a (n-1)a   -> 1x ou (n-7)x

    Σ i = 1 até  i = n-1

    ((1 + (n-1)) * (n-1)) / 2 - > formula fechada: (n² - n)/2
    */

    return 0;
}
