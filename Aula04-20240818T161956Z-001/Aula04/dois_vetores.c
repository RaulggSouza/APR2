#include <stdio.h>

#define MAX 5

int main(int argc, char const *argv[]) {
    int vetor1[MAX] = {1,2,3,4,5};
    int vetor2[MAX] = {10,20,30,40,50};
    int tamVet = MAX;

    for (int i = 0; i < tamVet; i++) {
        printf("%d ", vetor1[i]);
    }
    for (int i = 0; i < tamVet; i++) {
        printf("%ld ", (long int) &(vetor1[i]));
    }
    printf("\n");

    for (int i = 0; i < tamVet; i++) {
        printf("%d ", vetor2[i]);
    }
    for (int i = 0; i < tamVet; i++) {
        printf("%ld ", (long int) &(vetor2[i]));
    }
    printf("\n");
    return 0;
}
