#include <stdio.h>
#include <stdlib.h>

int troco_greedy(int valor, int moedas[], int m){
    int num_moedas = 0;

    for(int i = m - 1; i >= 0; i--){
        while(valor >= moedas[i]){
            num_moedas++;
            valor -= moedas[i];
        }
    }
    return num_moedas;
}

int troco_rec(int valor, int moedas[], int m){
    int min_moedas;
    if (valor == 0){
        return 0;
    }
    min_moedas = valor + 1;
    for(int i = m-1; i >= 0; i--){
        if (valor >= moedas[i]){
            int t = 1 + troco_rec(valor - moedas[i], moedas, m);
            if (t < min_moedas){
                min_moedas = t;
            }
        }
    }
    return min_moedas;
}

int troco_pd(int valor, int moedas[], int m, int cache[]){
    int min_moedas;
    if (cache[valor] == -1){
        if (valor == 0){
            min_moedas = 0;
        } else {
            min_moedas = valor + 1;
            for(int i = m-1; i >= 0; i--){
                if (valor >= moedas[i]){
                    int t = 1 + troco_pd(valor - moedas[i], moedas, m, cache);
                    if (t < min_moedas){
                        min_moedas = t;
                    }
                }
            }
        }
        cache[valor] = min_moedas;
    } else {
        min_moedas = cache[valor];
    }
    return min_moedas;
}

int main(int argc, char const *argv[]){
    int r;
    int n = atoi(argv[1]);
    int moedas[] = {1, 5, 10, 11, 25};

    r = troco_greedy(n, moedas, 5);
    printf("Solucao greedy: %d\n", r);

    int* cache = malloc(sizeof(long) * (n+1));
    for (long i = 0; i < n + 1; i++){
        cache[i] = -1;
    }

    r = troco_pd(n, moedas, 5, cache);
    printf("Solucao Dinamica: %d\n", r);

    r = troco_rec(n, moedas, 5);
    printf("Solucao Recursiva: %d\n", r);
    

    free(cache);
    return 0;
}
