#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 64

typedef struct {
    char nome[MAX_NOME];
    char cpf[12]; 
    float salario;
} T_FUNCIONARIO;

T_FUNCIONARIO* criar_vetor_funcionarios(int tamanho) {
    T_FUNCIONARIO *vetor = (T_FUNCIONARIO *)malloc(tamanho * sizeof(T_FUNCIONARIO));
    return vetor;
}

T_FUNCIONARIO criar_funcionario(char *nome, char *cpf, float salario) {
    T_FUNCIONARIO f;
    strcpy(f.nome, nome);
    strcpy(f.cpf, cpf);
    f.salario = salario;
    return f;
}

int inserir_funcionario(T_FUNCIONARIO funcionario, T_FUNCIONARIO* funcionarios, int* n) {
    funcionarios[*n] = funcionario;
    (*n)++;
}

void liberar_vetor_funcionarios(T_FUNCIONARIO *vetor) {
    free(vetor);
}

void imprimir_funcionario(T_FUNCIONARIO f) {
    printf("Nome: %s\n", f.nome);
    printf("CPF: %s\n", f.cpf);
    printf("Salario: %.2f\n", f.salario);
}

void imprimir_funcionarios(T_FUNCIONARIO* vetor, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nFuncionario %d:\n", i + 1);
        imprimir_funcionario(vetor[i]);
    }
}

int main() {
    int n = 0;
    T_FUNCIONARIO funcionario;
    T_FUNCIONARIO *funcionarios = criar_vetor_funcionarios(500);


    funcionario = criar_funcionario("Ana", "123.321.213", 21543.50);
    inserir_funcionario(funcionario, funcionarios, &n);

    funcionario = criar_funcionario("Maria", "98q749873", 9867.00);
    inserir_funcionario(funcionario, funcionarios, &n);
    
    funcionario = criar_funcionario("Jao", "1q98724312", 4563.70);
    inserir_funcionario(funcionario, funcionarios, &n);

    funcionario = criar_funcionario("Ze", "009990099090", 6754.50);
    inserir_funcionario(funcionario, funcionarios, &n);

    imprimir_funcionarios(funcionarios, n);

    // trocar dois funciorios
    funcionario = funcionarios[1];
    funcionarios[1] = funcionarios[2];
    funcionarios[2] = funcionario;

    imprimir_funcionarios(funcionarios, n);


    liberar_vetor_funcionarios(funcionarios);

    return 0;
}
