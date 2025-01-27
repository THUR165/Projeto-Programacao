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

char* get_nome_cliente(const char* arquivoCliente, char cpf_clnt[13]) {
    FILE* fp = fopen(arquivoCliente, "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de clientes!");
        return NULL;
    }

    Cliente* cliente;
    cliente = (Cliente*)malloc(sizeof(Cliente));
    if (cliente == NULL) {   // Teste de alocação de memória
        perror("Erro de alocação de memória! \n");
        fclose(fp); // Fecha o arquivo antes de retornar
        return NULL;
    }

    char* nome_obtido = NULL;  //recebe nada por enquanto...

    while (fread(cliente, sizeof(Cliente), 1, fp)) {
        if (strcmp(cliente->cpf, cpf_clnt) == 0) {
            nome_obtido = (char*)malloc(strlen(cliente->nome) + 1);  //strlen ajusta o tamanho do nome; + 1 para /0
            if (nome_obtido == NULL) {
                perror("Erro de alocação para o nome do cliente");
                free(cliente);
                fclose(fp);
                return NULL;
            } 
            strcpy(nome_obtido, cliente->nome); //o nome é copiado para nome_obtido
            break;
        } 
    }

    if (nome_obtido == NULL) {
        printf("Cliente não encontrado!\n"); // caso não encontre...
    }

    free(cliente);
    fclose(fp);
    return nome_obtido; //retorna o nome obtido
}