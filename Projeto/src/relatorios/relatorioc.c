#include <stdio.h>
#include <stdlib.h>
#include "relatorioc.h"
#include "../clientes/cliente.h"


void relatorio_cliente(void) {
    FILE *fp = fopen("Cliente.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de clientes!\n");
        return;
    }
    Cliente cliente;
    printf("\n===========================================================\n");
    printf("=====                 Relatório de Clientes           =====\n");
    printf("===========================================================\n");
    while (fread(&cliente, sizeof(Cliente), 1, fp)) {
        if (cliente.status == 1) {
            printf("Nome: %s\n", cliente.nome);
            printf("CPF: %s\n", cliente.cpf);
            printf("Data de Nascimento: %s\n", cliente.nasc);
            printf("Gênero: %s\n", cliente.gen);
            printf("Telefone: %s\n", cliente.tel);
            printf("Cidade: %s\n", cliente.cid);
            printf("Estado: %s\n", cliente.est);
            printf("Rua: %s\n", cliente.rua);
            printf("Número da Casa: %s\n", cliente.num);
            printf("-----------------------------------------------------------\n");
        }
    }
    fclose(fp);
    printf("===========================================================\n");
}