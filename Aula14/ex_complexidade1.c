#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* aloca_vetor(int max){
   //int *v = (int *) malloc(sizeof(int) * max); // O(1) = independente da entrada, mesmo número de operações. Alocação é O(1)
    int *v = (int *) calloc(sizeof(int), max); // O(n)
    return v;
}

int index_of(int* vet, int n, int max, int x) {
    for (int i = 0; i < n; i++){
        if(vet[i] == x){ //O(n)
            return i;
        }
    }
}

int is_palindrome_v1(char *s){
    for (int i = 0, j = strlen(s)-1; i < j; i++, j--){
        if (s[i] != s[j]){ //n/2 vezes: O(n) 
            return 0;
        }
    }
    return 1;
}

int is_palindrome_v2(char *s1){
    char s2[100];
    strcpy(s2, s1);
    reverse(s1); // O(n)
    int res = is_equal_str(s1, s2); // O(n)
    return res;
}

void reverse(char *s){
    for (int i = 0, j = strlen(s)-1; i < j; i++, j--){ // n/2 vezes
        char aux = s[i];
        s[i] = s[j];
        s[j] = aux;
    }
    return 1;
}

int is_equal_str(char* s1, char* s2){
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    if (n1 != n2){
        return 0;
    }
    for (int i = 0; i < n1; i++){
        if (s1[i] != s2[i]){ // n é o tamanho da string -> O(n)
            return 0;
        }
    }
    return 1;
}

int append(int *vet, int max, int *n, int x){
    if (*n < max) {
        vet[*n] = x;
        (*n)++;
        return 1;
    }
    return 0;
}

int f(int* vet, int max, int* n, int index, int x){
    if (*n < max) {
        for (int i = *n; i > index; i--){
            vet[i + 1] = vet[i];
        }
        vet[index] = x;
        (*n)++; 
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[]){
    int max = 10;
    int size = 0;

    int* vet = aloca_vetor(max);

    return 0;
}
// O(1) -> Constante
// O(log N) -> logarítmico