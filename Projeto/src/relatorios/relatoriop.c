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

char* get_nome_produto(const char* arquivoProduto, char cod_prod[6]) {
    FILE* fp = fopen(arquivoProduto, "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de produtos!");
        return NULL;
    }

    Produto* produto;
    produto = (Produto*)malloc(sizeof(Produto));
    if (produto == NULL) {   // Teste de alocação de memória
        perror("Erro de alocação de memória! \n");
        fclose(fp); // Fecha o arquivo antes de retornar
        return;
    }

    char* nome_obtido = NULL;  //recebe nada por enquanto...

    while (fread(produto, sizeof(Produto), 1, fp)) {
        if (strcmp(produto->cod_barras, cod_prod) == 0) {
            nome_obtido = (char*)malloc(strlen(produto->nome) + 1);  //strlen ajusta o tamanho do nome do prod; + 1 para /0
            if (nome_obtido == NULL) {
                perror("Erro de alocação para o nome do produto");
                free(produto);
                fclose(fp);
                return NULL;
            } 
            strcpy(nome_obtido, produto->nome); //o nome do produto é copiado para nome_obtido
            break;
        } 
    }

    if (nome_obtido == NULL) {
        printf("Produto não encontrado!\n"); // caso não encontre...
    }

    free(produto);
    fclose(fp);
    return nome_obtido; //retorna o nome do produto
}

float get_preco_produto(const char* arquivoProduto, char cod_prod[6]) { //retorna preço do produto
    FILE* fp = fopen(arquivoProduto, "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de produtos!");
        return -1.0f; // Retorna -1.0 para indicar erro na abertura
    }

    Produto* produto = (Produto*)malloc(sizeof(Produto));
    if (produto == NULL) {
        perror("Erro de alocação de memória para o produto!");
        fclose(fp);
        return -1.0f; // Retorna -1.0 para indicar erro de memória
    }

    float preco_obtido = -1.0f; // Inicializa com um valor inválido

    while (fread(produto, sizeof(Produto), 1, fp)) {
        if (strcmp(produto->cod_barras, cod_prod) == 0) {
            preco_obtido = produto->preco; // Armazena o preço do produto
            break; // Produto encontrado, interrompe o loop
        }
    }

    if (preco_obtido == -1.0f) {
        printf("Produto não encontrado!\n");
    }

    free(produto); // Libera a memória alocada para o produto
    fclose(fp); // Fecha o arquivo
    return preco_obtido; // Retorna o preço do produto ou -1.0f
}
