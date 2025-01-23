#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "verificarf.h"

Funcionario* buscarFuncionario(const char* nomeArquivo) {
    FILE* fp;
    Funcionario* func;
    char cpf_pesquisado[12];
    //int encontrado = 0;

    func = (Funcionario*) malloc(sizeof(Funcionario));
    if (func == NULL) {    //teste de alocação
        perror("Erro ao alocar memória\n");
        return NULL;
    }

    fp = fopen(nomeArquivo, "rb");
    if (fp == NULL) {   //teste de abertura de arquivo
        perror("Erro ao abrir o arquivo\n");
        free(func);
        return NULL;
    }

    printf("==========================================================\n");
    printf("=======              Buscar Funcionário            =======\n");
    printf("==========================================================\n");
    printf("Digite o CPF do funcionário que deseja pesquisar: \n");
    scanf("%11s", cpf_pesquisado);  
    getchar();

    while(fread(func, sizeof(Funcionario), 1, fp)) {
        if((strcmp(func->cpf, cpf_pesquisado) == 0) && (func->status == 1)) {
            //encontrado = 1;
            fclose(fp);
            printf("Encontrando o funcionário...\n");
            return func;
        } 
    }

    fclose(fp);  
    return NULL;
}


//essas funções ficarão comentadas, por enquanto
void exibirFuncionario(Funcionario* func){
    
    printf("===============================================================\n");
    printf("=======           Exibir Dados do Funcionário           =======\n");
    printf("===============================================================\n");
    printf("CPF: %s\n", func->cpf);
    printf("Nome: %s\n", func->nome);
    printf("Data de nascimento: %s\n", func->data_nascimento);
    //getchar();
    printf("\t\tTecle ENTER para continuar...\n\n");
    printf("===========================================================\n");
    getchar();
}