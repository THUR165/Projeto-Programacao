#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatoriof.h"

void relatorio_geral_funcionarios(const char* arquivoFuncionario) {
    printf("===========================================================\n");
    FILE *fp = fopen(arquivoFuncionario, "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de funcionários!\n");
        return;
    }
    Funcionario* funcionario;
    funcionario = (Funcionario*)malloc(sizeof(Funcionario)); 
    if (funcionario == NULL) {   //teste de alocação de memória
        perror("Erro de alocação de memória! \n");
        return;  //falha...
    }

    printf("\n===========================================================\n");
    printf("=====            Relatório Geral de Funcionários       ======\n");
    printf("=============================================================\n");
    // Aqui sera adicionado o codigo para o relatorio de clientes
    while (fread(funcionario, sizeof(Funcionario), 1, fp)) {
        if (funcionario->status == 1) {
            printf("Nome: %s\n", funcionario->nome);
            printf("CPF: %s\n", funcionario->cpf);
            printf("Data de nascimento: %s\n", funcionario->data_nascimento);
            printf("-----------------------------------------------------------\n");
        }
    }
    free(funcionario);
    fclose(fp);
    printf("===========================================================\n");
}