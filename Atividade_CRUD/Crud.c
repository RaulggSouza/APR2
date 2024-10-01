#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char CPF[12];
    char nome[64];
    char cargo[32];
    int num_dependentes;
    float salario;
}T_FUNCIONARIO;

int existeFuncionario(T_FUNCIONARIO* funcionarios, int num_funcionarios, char* cpf_buscado){
    for(int i=0; i < num_funcionarios; i++){
        if((strcmp(funcionarios[i].CPF, cpf_buscado)) == 0){
            return i;
        }
    }
    return -1;
}

void imprimirFuncionario(T_FUNCIONARIO* funcionarios, int indice){
    printf("-------------------------------\n");
    printf("CPF: %s\n", funcionarios[indice].CPF);
    printf("Nome: %s\n", funcionarios[indice].nome);
    printf("Cargo: %s\n", funcionarios[indice].cargo);
    printf("Numero de Dependentes: %d\n", funcionarios[indice].num_dependentes);
    printf("Salario: R$%.2f\n", funcionarios[indice].salario);
}

void coletarInformacoes(T_FUNCIONARIO* funcionarios, int indice){
    fflush(stdin);
    printf("Digite o nome do funcionario: ");
    gets(funcionarios[indice].nome);
    
    printf("Digite o cargo do funcionario: ");
    gets(funcionarios[indice].cargo);
    
    printf("Digite o numero de dependentes do funcionario: ");
    scanf("%d",&(funcionarios[indice].num_dependentes));
    
    printf("Digite o salario do funcionario: ");
    scanf("%f",&(funcionarios[indice].salario));
}

int inserirFuncionario(T_FUNCIONARIO* funcionarios, int* num_funcionarios){
    fflush(stdin);
    printf("Digite o CPF do funcionario: ");
    gets(funcionarios[*num_funcionarios].CPF);
    if(existeFuncionario(funcionarios, *num_funcionarios, funcionarios[*num_funcionarios].CPF) < 0){
        coletarInformacoes(funcionarios, *num_funcionarios);
        (*num_funcionarios)++;
        return 1;
    }
    return 0;
}

int consultarFuncionario(T_FUNCIONARIO* funcionarios, int num_funcionarios, char* cpf_buscado){
    int funcionario_encontrado = existeFuncionario(funcionarios, num_funcionarios, cpf_buscado);
    if(funcionario_encontrado >= 0){
        imprimirFuncionario(funcionarios, funcionario_encontrado);
        printf("-------------------------------\n");
        return 1;
    }
    return 0;
}

int imprimirTodosFuncionarios(T_FUNCIONARIO* funcionarios, int num_funcionarios){
    for(int i = 0; i < num_funcionarios; i++){
        imprimirFuncionario(funcionarios, i);
    }
    printf("-------------------------------\n");
}

int excluirFuncionario(T_FUNCIONARIO* funcionarios, int* num_funcionarios, char* cpf_buscado){
    if (existeFuncionario(funcionarios, *num_funcionarios, cpf_buscado) >= 0){
        int comecar_troca = 0;
        for (int i = 0; i < *num_funcionarios; i++){
            if(strcmp(funcionarios[i].CPF, cpf_buscado) == 0){
                comecar_troca = 1;
            }
            if (comecar_troca == 1){
                funcionarios[i] = funcionarios[i+1];
            }
        }
        (*num_funcionarios)--;
        return 1;
    }
    return 0;
}

int alterarFuncionario(T_FUNCIONARIO* funcionarios, int num_funcionarios, char* cpf_buscado){
    int funcionario_encontrado = existeFuncionario(funcionarios, num_funcionarios, cpf_buscado);
    if (funcionario_encontrado >= 0){
        coletarInformacoes(funcionarios,funcionario_encontrado);
        return 1;
    }
    return 0;
}

int menu(){
    int opcao;
    printf("MENU DE OPCOES:\n");
    printf("1. INSERIR UM NOVO FUNCIONARIO\n");
    printf("2. CONSULTAR DADOS DE UM FUNCIONARIO\n");
    printf("3. IMPRIMIR TODOS OS FUNCIONARIOS\n");
    printf("4. EXCLUIR UM FUNCIONARIO\n");
    printf("5. ALTERAR UM FUNCIONARIO\n");
    printf("6. SAIR DO PROGRAMA\n");
    do{
        printf("Digite o valor referente a funcao desejada:\n");
        scanf("%d", &opcao);
    }while(opcao < 1 || opcao > 6);
    return opcao;
}

int main(int argc, char const *argv[]){
    int opcao;
    T_FUNCIONARIO* funcionarios;
    char cpf_inserido[12];
    funcionarios = (T_FUNCIONARIO*) malloc(sizeof(T_FUNCIONARIO)*500);
    int num_funcionarios = 0;
    do{
        opcao = menu();
        switch (opcao){
        case 1:
            if (num_funcionarios < 500){
                if (inserirFuncionario(funcionarios, &num_funcionarios)){
                    printf("Cadastrado com sucesso!\n");
                }else{
                    printf("CPF ja cadastrado!\n");
                }
            }else{
                printf("Numero maximo de funcionarios atingido!\n");
            }
            break;
        case 2:
            printf("Digite o CPF do funcionario que sera buscado: ");
            scanf("%s", cpf_inserido);
            if (consultarFuncionario(funcionarios,num_funcionarios,cpf_inserido)){
                printf("Fim da busca...\n");
            }else{
                printf("CPF inexistente!\n");
            }
            break;
        case 3:
            if(num_funcionarios > 0){
                imprimirTodosFuncionarios(funcionarios, num_funcionarios);
            }else{
                printf("Nenhum cadastro encontrado!\n");
            }
            break;
        case 4:
            printf("Digite o CPF do funcionario que sera excluido: ");
            scanf("%s",cpf_inserido);
            if (excluirFuncionario(funcionarios, &num_funcionarios, cpf_inserido)){
                printf("Excluido com sucesso!\n");
            }else{
                printf("Falha na exclusao!\n");
            }
            break;
        case 5:
            printf("Digite o CPF do funcionario que sera alterado: ");
            scanf("%s", cpf_inserido);
            if (alterarFuncionario(funcionarios, num_funcionarios, cpf_inserido)){
                printf("Alterado com sucesso!\n");
            }else{
                printf("Falha na alteracao!\n");
            }
            break;
        case 6:
            printf("Finalizando o programa...");
            break;
        }
    }while(opcao != 6);
    free(funcionarios);
    return 0;
}
