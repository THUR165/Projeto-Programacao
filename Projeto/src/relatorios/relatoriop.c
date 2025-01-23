#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatoriop.h"

void relatorio_geral_produtos(const char* arquivoProduto) {
    printf("===========================================================\n");
    FILE *fp = fopen(arquivoProduto, "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de clientes!\n");
        return;
    }
    Produto* produto;
    produto = (Produto*)malloc(sizeof(Produto)); 
    if (produto == NULL) {   //teste de alocação de memória
        perror("Erro de alocação de memória! \n");
        return;  //falha...
    }

    printf("\n===========================================================\n");
    printf("=====            Relatório Geral de Produtos           ======\n");
    printf("=============================================================\n");
    // Aqui sera adicionado o codigo para o relatorio de clientes
    while (fread(produto, sizeof(Produto), 1, fp)) {
        if (produto->status == 1) {
            printf("Nome: %s\n", produto->nome);
            printf("Código de barras: %s\n", produto->cod_barras);
            printf("Preço: R$ %2.f \n", produto->preco); //float
            printf("Categoria: %s\n", produto->categoria);
            printf("Marca: %s\n", produto->marca);
            printf("Data de validade: %s\n", produto->data_validade);
            printf("-----------------------------------------------------------\n");
        }
    }
    free(produto);
    fclose(fp);
    printf("===========================================================\n");
}