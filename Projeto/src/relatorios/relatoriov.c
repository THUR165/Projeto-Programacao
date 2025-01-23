#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatoriov.h"

void relatorio_geral_vendas(const char* arquivoVenda) {

    printf("===========================================================\n");
    FILE *fp = fopen(arquivoVenda, "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de clientes!\n");
        return;
    }
    Venda* venda;
    venda = (Venda*)malloc(sizeof(Venda)); 
    if (venda == NULL) {   //teste de alocação de memória
        perror("Erro de alocação de memória! \n");
        return;  //falha...
    }

    printf("\n===========================================================\n");
    printf("=====            Relatório Geral de Vendas             ======\n");
    printf("=============================================================\n");
    // Aqui sera adicionado o codigo para o relatorio de clientes
    while (fread(venda, sizeof(Venda), 1, fp)) {
        if (venda->cod_venda != 0) {
            printf("Código da venda: %s\n", venda->cod_venda);
            printf("Código do produto: %s\n", venda->cod_prod);
            printf("CPF do cliente:: %s\n", venda->cpf_clnt);
            printf("CPF do funcionário: %s\n", venda->cpf_func);
            printf("Data da venda: %s\n", venda->data_venda);
            printf("-----------------------------------------------------------\n");
        }
    }
    free(venda);
    fclose(fp);
    printf("===========================================================\n");
}
