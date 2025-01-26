#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatoriof.h"

void relatorio_funcionarios_por_status(const char* arquivoFuncionario, int statusDesejado) {
    FILE *fp = fopen(arquivoFuncionario, "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de funcionários!\n");
        return;
    }

    Funcionario* funcionario = (Funcionario*)malloc(sizeof(Funcionario));
    if (funcionario == NULL) {   // Teste de alocação de memória
        perror("Erro de alocação de memória!\n");
        fclose(fp); // Certifique-se de fechar o arquivo antes de retornar
        return;
    }

    printf("\n===========================================================\n");
    if (statusDesejado == 1) {
        printf("=====        Relatório de Funcionários Ativos           =====\n");
    } else {
        printf("=====        Relatório de Funcionários Inativos         =====\n");
    }
    printf("===========================================================\n");

    int encontrou = 0; // Flag para verificar se encontrou funcionários no status

    // Percorre os registros no arquivo
    while (fread(funcionario, sizeof(Funcionario), 1, fp)) {
        if (funcionario->status == statusDesejado) {
            encontrou = 1;
            printf("Nome: %s\n", funcionario->nome);
            printf("CPF: %s\n", funcionario->cpf);
            printf("Data de Nascimento: %s\n", funcionario->data_nascimento);
            printf("-----------------------------------------------------------\n");
        }
    }

    if (!encontrou) {
        printf("Nenhum funcionário encontrado no status selecionado.\n");
    }

    printf("===========================================================\n");

    free(funcionario);
    fclose(fp);
}