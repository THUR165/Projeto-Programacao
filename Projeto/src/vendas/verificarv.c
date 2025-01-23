#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "verificarv.h"

Venda* buscarVenda(const char* arquivoVenda) {
    FILE* fp;
    Venda* vnd;
    char codigo_pesquisado[6];
    //int encontrado = 0;

    vnd = (Venda*) malloc(sizeof(Venda));
    if (vnd == NULL) {    //teste de alocação
        perror("Erro ao alocar memória\n");
        return NULL;
    }

    fp = fopen(arquivoVenda, "rb");
    if (fp == NULL) {   //teste de abertura de arquivo
        perror("Erro ao abrir o arquivo\n");
        free(vnd);
        return NULL;
    }

    printf("==========================================================\n");
    printf("=======              Buscar Venda                =========\n");
    printf("==========================================================\n");
    printf("Digite o codigo da venda que deseja pesquisar: \n");
    scanf("%5s", codigo_pesquisado);  //validar codigo aqui tbm? Não precisa...
    getchar();

    while(fread(vnd, sizeof(Venda), 1, fp)) {
        if((strcmp(vnd->cod_venda, codigo_pesquisado) == 0)) {
            //encontrado = 1;
            fclose(fp);
            printf("Encontrando a venda...\n");
            return vnd;
        } 
    }

    fclose(fp);  //free é feito na interface........
    return NULL;
}


//essas funções ficarão comentadas, por enquanto
void exibirVenda(Venda* vnd) {
    
    printf("\n=========================================================\n");
    printf("=======            Exibir Dados da Venda            =======\n");
    printf("===========================================================\n");
    printf("Código da venda: %s\n", vnd->cod_venda);
    printf("Código do produto vendido: %s\n", vnd->cod_prod);
    printf("CPF do cliente: %s\n", vnd->cpf_clnt);
    printf("CPF do funcionário: %s\n", vnd->cpf_func);
    printf("Data da venda: %s\n", vnd->data_venda);
    getchar();
    printf("\t\tTecle ENTER para continuar...\n\n");
    printf("===========================================================\n");
    getchar();
}