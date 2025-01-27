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

char* get_nome_funcionario(const char* arquivoFuncionario, char cpf_func[13]) {
    FILE* fp = fopen(arquivoFuncionario, "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de funcionários!");
        return NULL;
    }

    Funcionario* funcionario;
    funcionario = (Funcionario*)malloc(sizeof(Funcionario));
    if (funcionario == NULL) {   // Teste de alocação de memória
        perror("Erro de alocação de memória! \n");
        fclose(fp); // Fecha o arquivo antes de retornar
        return NULL;
    }

    char* nome_obtido = NULL;  //recebe nada por enquanto...

    while (fread(funcionario, sizeof(Funcionario), 1, fp)) {
        if (strcmp(funcionario->cpf, cpf_func) == 0) {
            nome_obtido = (char*)malloc(strlen(funcionario->nome) + 1);  //strlen ajusta o tamanho do nome; + 1 para /0
            if (nome_obtido == NULL) {
                perror("Erro de alocação para o nome do funcionário");
                free(funcionario);
                fclose(fp);
                return NULL;
            } 
            strcpy(nome_obtido, funcionario->nome); //o nome é copiado para nome_obtido
            break;
        } 
    }

    if (nome_obtido == NULL) {
        printf("Funcionário não encontrado!\n"); // caso não encontre...
    }

    free(funcionario);
    fclose(fp);
    return nome_obtido; //retorna o nome obtido
}