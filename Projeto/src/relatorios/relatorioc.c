#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorioc.h"

void relatorio_geral_clientes(const char* arquivoCliente) {

    printf("===========================================================\n");
    FILE *fp = fopen(arquivoCliente, "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de clientes!\n");
        return;
    }
    Cliente* cliente;
    cliente = (Cliente*)malloc(sizeof(Cliente)); 
    if (cliente == NULL) {   //teste de alocação de memória
        perror("Erro de alocação de memória! \n");
        return;  //falha...
    }

    printf("\n===========================================================\n");
    printf("=====            Relatório Geral de Clientes           ======\n");
    printf("=============================================================\n");
    // Aqui sera adicionado o codigo para o relatorio de clientes
    while (fread(cliente, sizeof(Cliente), 1, fp)) {
        if (cliente->status == 1) {
            printf("Nome: %s\n", cliente->nome);
            printf("CPF: %s\n", cliente->cpf);
            printf("Data de Nascimento: %s\n", cliente->data_nascimento);
            printf("Gênero: %s\n", cliente->gen);
            printf("Telefone: %s\n", cliente->tel);
            /*printf("Cidade: %s\n", cliente.cid);
            printf("Estado: %s\n", cliente.est);*/ //acrescenta sim ou não?
            printf("Rua: %s\n", cliente->rua);
            printf("Número da Casa: %s\n", cliente->num);
            printf("-----------------------------------------------------------\n");
        }
    }
    free(cliente);
    fclose(fp);
    printf("===========================================================\n");
}

