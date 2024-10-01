#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int search(int vetor[], int n, int x){
    for(int i=0; i < n; i++){
        if(vetor[i]==x){
            return 1;
        }
    }
    return 0;
    
}

int index_of(int vetor[], int n, int x){
    for(int i=0; i < n; i++){
        if(vetor[i]==x){
            return i;
        }
    }
    return -1;
    
}

int append(int vet[], int* tamVet, int elem) {
    if (*tamVet < MAX) {
        vet[*tamVet] = elem;
        (*tamVet)++;
        return 1;
    }
    return 0;
}

int insert(int vet[], int* tamVet, int elem, int index){
    if(*tamVet < MAX){
        for (int j = *tamVet; j > 0; j--){
            vet[j+1] = vet[j];
            if(j == index){
                vet[index] = elem;
                (*tamVet)++;
                break;
            }
        }
    }
}

int remover(int vet[], int* tamVet, int elem) {
    int comecarTroca = 0;
    if (*tamVet > 0){
        int i = index_of(vet, *tamVet, elem);
        for (int j = i; j < *tamVet; j++){
            vet[j] = vet[j+1];
        }
        // for (int j = 0; j < *tamVet; j++){
        //     if (vet[j] == elem){
        //         comecarTroca = 1;
        //     }
        //     if (comecarTroca == 1){
        //         vet[j] = vet[j+1];
        //     }
        // }
        (*tamVet)--;
    }else{
        printf("Erro ao remover: Vetor vazio");
    }
}
int update(int vet[], int* tamVet, int elem, int index){
    for (int i=0; i < *tamVet; i++){
        if (i == index){
            vet[i] = elem;
            break;
        }
    }
}

void reverse(int vet[], int* tamVet){
    int auxiliar;
    int j = *tamVet-1;
    for (int i = 0; i < (MAX/2); i++){
        auxiliar = vet[i];
        vet[i] = vet[j];
        vet[j] = auxiliar;
        j--;
    }
}

int sum(int vet[], int* tamVet){
    int soma = 0;
    for(int i = 0; i < *tamVet; i++){
        soma += vet[i];
    }
    return soma;
}

int max_element(int vet[], int* tamVet){
    int maior = vet[0];
    for (int i = 1; i < *tamVet; i++){
        if (vet[i] > maior){
            maior = vet[i];
        }
    }
    return maior;
}

int count_occurrences(int vet[], int* tamVet, int elem){
    int contador = 0;
    for (int i = 0; i < *tamVet; i++){
        if (vet[i] == elem){
            contador++;
        }
    }
    return contador;
}


int main(int argc, char const *argv[]){
    int vetor[MAX];
    int tamanho_vetor = 0;

    append(vetor, &tamanho_vetor, 10);

    append(vetor, &tamanho_vetor, 32);

    append(vetor, &tamanho_vetor, 12);

    insert(vetor, &tamanho_vetor, 56, 1);
    
    append(vetor, &tamanho_vetor, 100);

    // remover(vetor, &tamanho_vetor, 10);

    for(int i = 0; i < tamanho_vetor; i++){
        printf("%d\n",vetor[i]);
    }

    update(vetor, &tamanho_vetor, 89, 0);

    int numero_buscado;
    scanf("%d", &numero_buscado);
    // if(search(vetor, MAX,numero_buscado) == 1){
    //     printf("Existe %d no vetor\n", numero_buscado);
    // }else{
    //     printf("O numero procurado nao existe\n");
    // }
    
    int result = index_of(vetor, MAX,numero_buscado);
    if(result != -1){
        printf("Existe %d no vetor na posicao %d\n", numero_buscado, result);
    }else{
        printf("O numero procurado nao existe\n");
    }

    int maior = max_element(vetor, &tamanho_vetor);
    printf("%d e o maior elemento do vetor\n", maior);

    int soma = sum(vetor, &tamanho_vetor);
    printf("%d e a soma de elementos do vetor\n", soma);

    int num_selecionado;
    printf("Digite o numero que sera contado:\n");
    scanf("%d", &num_selecionado);
    int ocorrencias = count_occurrences(vetor, &tamanho_vetor, num_selecionado);
    printf("%d aparece %d vezes no vetor\n", num_selecionado, ocorrencias);

    for(int i = 0; i < tamanho_vetor; i++){
        printf("%d\t",vetor[i]);
    }
    printf("\n");
    reverse(vetor, &tamanho_vetor);
    for(int i = 0; i < tamanho_vetor; i++){
        printf("%d\t",vetor[i]);
    }

    return 0;
}
