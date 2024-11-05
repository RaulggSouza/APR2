#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int n = 10;             // 1*a (a = atribuição)
    int soma = 0;           // 1*a
    int i = 1;              // 1*a
    while (i <= n){         // (n+1)*c (c = comparação)
        soma += i;          // n*(1*a + 1*t) (t = operação aritmetica)
        i++;                // n*(1*a + 1*t)
    }
                            // 1a + 1a + 1a + (n+1)*c + n(1a + 1t) + n(1a + 1t)
                            // 3a + (n+1)*c + 2n(1a + 1t)
                            // 3a + cn+c + 2na + 2nt
                            // n(c+2a+2t) + 3a + c
                            // f(n) = n(c + 2a + 2t) + 3a + c [Fórmula fechada]
    
    //Simplificando
    int n = 10;
    int soma = 0;
    int i = 1;
    while (i <= n){         // n*x -> x são todas as operações executando no while
        soma += i;
        i++;
    }
    // funções linerares
    // f(x) [mat] 
    // o(n) [computação]
    return 0;
}
