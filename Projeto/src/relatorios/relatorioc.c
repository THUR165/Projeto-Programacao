#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorioc.h"


void relatorio_clientes_por_status(const char* arquivoCliente, int statusDesejado) {
    FILE *fp = fopen(arquivoCliente, "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de clientes!\n");
        return;
    }

    Cliente* cliente = (Cliente*)malloc(sizeof(Cliente)); 
    if (cliente == NULL) {   // Teste de alocação de memória
        perror("Erro de alocação de memória! \n");
        fclose(fp); // Certifique-se de fechar o arquivo antes de retornar
        return;
    }

    printf("\n===========================================================\n");
    if (statusDesejado == 1) {
        printf("=====          Relatório de Clientes Ativos            =====\n");
    } else {
        printf("=====          Relatório de Clientes Inativos          =====\n");
    }
    printf("===========================================================\n");

    int encontrou = 0; // Flag para verificar se encontrou clientes no status

    // Percorre os registros no arquivo
    while (fread(cliente, sizeof(Cliente), 1, fp)) {
        if (cliente->status == statusDesejado) {
            encontrou = 1;
            printf("Nome: %s\n", cliente->nome);
            printf("CPF: %s\n", cliente->cpf);
            printf("Data de Nascimento: %s\n", cliente->data_nascimento);
            printf("Gênero: %s\n", cliente->gen);
            printf("Telefone: %s\n", cliente->tel);
            printf("Rua: %s\n", cliente->rua);
            printf("Número da Casa: %s\n", cliente->num);
            printf("-----------------------------------------------------------\n");
        }
    }

    if (!encontrou) {
        printf("Nenhum cliente encontrado no status selecionado.\n");
    }

    printf("===========================================================\n");

    free(cliente);
    fclose(fp);
}
