#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatoriov.h"
#include "relatorioc.h"
#include "relatoriop.h"
#include "relatoriof.h"

void relatorio_geral_vendas(const char* arquivoVenda, const char* arquivoCliente, const char* arquivoProduto, const char* arquivoFuncionario) {

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

    char pesquisa_venda[7];
    char* nome_cliente = NULL;
    char* nome_produto = NULL;
    float preco_produto = -1.0f;
    char* nome_funcionario = NULL;

    printf("\n===========================================================\n");
    printf("=====                 Relatório de Venda               ======\n");
    printf("=============================================================\n");
    printf("\n");
     printf("Digite o código da venda que deseja pesquisar: \n");
    scanf("%5s", pesquisa_venda);  
    getchar();
    // Aqui sera adicionado o codigo para o relatorio de clientes
    while (fread(venda, sizeof(Venda), 1, fp)) {
        if (strcmp(venda->cod_venda, pesquisa_venda) == 0) {
            nome_cliente = get_nome_cliente(arquivoCliente, venda->cpf_clnt);
            nome_produto = get_nome_produto(arquivoProduto, venda->cod_prod);
            preco_produto = get_preco_produto(arquivoProduto, venda->cod_prod);
            nome_funcionario = get_nome_funcionario(arquivoFuncionario, venda->cpf_func);

            printf("==============       Dados da Venda      =============\n");
            printf("=== Código da venda: %s \n", venda->cod_venda);
            if (nome_cliente == NULL) {
                printf("Cliente não encontrado!");
            } else {
                printf("=== Nome do cliente: %s\n", nome_cliente);
            }
            if (nome_produto == NULL) {
                printf("Produto não encontrado!");
            } else {
                printf("=== Produto adquirido: %s\n", nome_produto);
            }
            if (preco_produto == -1.0f) {
                printf("Preço não disponível!");
            } else {
                printf("=== Preço pago: %2.f \n", preco_produto);
            }
            if (nome_funcionario == NULL) {
                printf("Funcionário não encontrado!");
            }
            else {
                printf("=== Funcionário responsável: %s \n", nome_funcionario);
            }
            printf("======================================================\n");
        }
    }
    free(venda);
    free(nome_cliente);
    free(nome_produto);
    free(nome_funcionario);
    fclose(fp);
}
