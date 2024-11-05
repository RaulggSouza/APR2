#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int n = 10;
    int soma = 0;
    // solucao  1:
    for (int i = 0; i <= n; i++){
        if (i % 2 == 0){            // n vezes -> O(n) 
            soma = soma + i;
        }
    }
    
    // solucao 2:
    soma = 0;
    for (int i = 2; i <= n; i += 2){
        soma = soma + i;            // (n / 2) vezes -> O(n)
    }
    

    return 0;
}
