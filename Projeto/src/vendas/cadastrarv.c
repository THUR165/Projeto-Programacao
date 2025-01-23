#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastrarv.h"


Venda* preencherVenda(void){          
    
    Venda* vnd;
    vnd = (Venda*)malloc(sizeof(Venda));
    if (vnd == NULL) {
        printf("Erro de alocação de memória! \n");
        return NULL; // return NULL;
    }
    
    printf("===========================================================\n");
    printf("========             Cadastrar Venda               ========\n");
    printf("===========================================================\n");
    printf("Digite o código da venda: \n");
    scanf("%5s", vnd->cod_venda);
    getchar();
    printf("Digite o código do produto vendido: \n");
    scanf("%5s", vnd->cod_prod);
    getchar();
    printf("Digite o CPF do cliente que realizou a compra: \n");
    scanf("%11s",vnd->cpf_clnt);
    getchar();
    printf("Digite o CPF do funcionário que realizou a venda: \n");
    scanf("%11s", vnd->cpf_func);
    getchar();

    return vnd;
}

int gravarVenda(const char* nomeArquivo, Venda* vnd) {
    FILE* fp = fopen(nomeArquivo, "ab");  //ab
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para cadastrar a venda!\n");
        free(vnd);
        return 0; //falha...
    }

    //Escreve os dados no arquivo e testa se deu certo
    if (fwrite(vnd, sizeof(Venda), 1, fp) != 1) {
        perror("Erro ao gravar os dados\n");
        free(vnd);
        return 0; //falha...
    }

    fclose(fp); // Fecha o arquivo
    return 1; //sucess
}