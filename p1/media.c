#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    float atual = atoi(argv[1]);
    for (float i = 0.0; i <= 10; i+=0.1){
        float media = atual + i;
        media /= 3.0;
        media *= 0.85;
        if (media >= 6){
            printf("%f", i);
            break;
        }
    }
    return 0;
}
