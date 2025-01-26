#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatoriop.h"

void relatorio_produtos_por_status(const char* arquivoProduto, int statusDesejado) {
    FILE *fp = fopen(arquivoProduto, "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de produtos!\n");
        return;
    }

    Produto* produto = (Produto*)malloc(sizeof(Produto));
    if (produto == NULL) {   // Teste de alocação de memória
        perror("Erro de alocação de memória! \n");
        fclose(fp); // Fecha o arquivo antes de retornar
        return;
    }

    printf("\n===========================================================\n");
    if (statusDesejado == 1) {
        printf("=====          Relatório de Produtos Ativos            =====\n");
    } else {
        printf("=====          Relatório de Produtos Inativos          =====\n");
    }
    printf("===========================================================\n");

    int encontrou = 0; 

    while (fread(produto, sizeof(Produto), 1, fp)) {
        if (produto->status == statusDesejado) {
            encontrou = 1;
            printf("Nome: %s\n", produto->nome);
            printf("Código de barras: %s\n", produto->cod_barras);
            printf("Preço: R$ %.2f\n", produto->preco);
            printf("Categoria: %s\n", produto->categoria);
            printf("Marca: %s\n", produto->marca);
            printf("Data de validade: %s\n", produto->data_validade);
            printf("-----------------------------------------------------------\n");
        }
    }

    if (!encontrou) {
        printf("Nenhum produto encontrado no status selecionado.\n");
    }

    printf("===========================================================\n");

    free(produto);
    fclose(fp);
}