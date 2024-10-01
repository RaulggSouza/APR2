#include <stdio.h>

#define MAX 5

int append(int vet[], int* tamVet, int elem) {
    if (*tamVet < MAX - 1) {
        vet[*tamVet] = elem;
        (*tamVet)++;
        return 1;
    }
    return 0;
}

int pop(int* tamVet) { // remove da ultima posicao do vetor
    if (*tamVet > 0){
        (*tamVet)--;
        return 1;
    }
    return 0;
}

int len(int* tamVet) {
     return *tamVet; //?
}

// int insert(int vet[], int* tamVet, int elem, int posVet) { // adiciona elemento em uma posicao valida do vetor
//     if (*tamVet < MAX - 1) {
//         for(int i = posVet+1; i < *tamVet; i++){
//             int n = vet[i+1];
//             // vet[i] = 
//         }
//         vet[*tamVet] = elem;
//         (*tamVet)++;
//         return 1;
//     }
//     return 0;
// }

// int remove() { // remove elemento de uma posicao valida do vetor
//     return 1;
// }

// int busca() { // busca elemento no vetor. Retorna o indice onde foi encontrado
//     return 1;
// }


int main(int argc, char const *argv[]) {
    int vetor[MAX];
    int tamVet = 0;
	
    append(vetor, &tamVet, 10);

    append(vetor, &tamVet, 32);

    append(vetor, &tamVet, 12);

    printf("%p\n", vetor);


    for (int i = 0; i < tamVet; i++) {
        printf("%d ", *(vetor+i));
    }

    printf("\n");

    for (int i = 0; i < tamVet; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    //printf("%d", len(vetor));

    for (int i = 0; i < tamVet; i++) {
        printf("%p ", &vetor[i]);
    }

    printf("\n");

    for (int i = 0; i < tamVet; i++) {
        printf("%p ", (vetor+i));
    }

    printf("\n");


    return 0;
}
