#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int vetor[] = {1, 3, 5, 3, 5, 6, 2, 9};
    int n = 8;

    int x = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j = j*2){ // (log_2 N) + 1
            x = x + 1; // n * logn
        }
    }
    // Complexidade de tempo O(nlogn)
    return 0;
}
