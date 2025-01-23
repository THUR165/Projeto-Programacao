#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "excluirp.h"

//essa função retorna int?...
int excluirProduto(const char* nomeArquivo){  
    FILE* fp; 
    Produto* prodArqv;
    char codigo_pesquisado[6];
    int encontrado = 0;

    prodArqv = (Produto*)malloc(sizeof(Produto));
    if(prodArqv == NULL) {    //teste de alocação de memória
        printf("Erro de alocação de memória! \n");
        return 0;  //falha...
    }

    //abrir o arquivo "r+b"
    fp = fopen(nomeArquivo, "r+b");
    if (fp == NULL) {     //teste de abertura de arquivo
        perror("Erro ao abrir o arquivo");
        free(prodArqv);
        return 0; //falha...
    }

    printf("\n=========================================================\n");
    printf("=======             Excluir Produto                  ======\n");
    printf("===========================================================\n");
    printf("Digite o codigo de barras do produto que deseja pesquisar: \n");
    scanf("%5s", codigo_pesquisado); 
    getchar();

    //excluindo o produto
     while(fread(prodArqv, sizeof(Produto), 1, fp)) {
        if((strcmp(prodArqv->cod_barras, codigo_pesquisado) == 0) && (prodArqv->status == 1)) {
            encontrado = 1;

            prodArqv->status = 0; //status 0 significa que o produto será excluído logicamente
            if (fseek(fp, -1*sizeof(Produto), SEEK_CUR) != 0) {
                perror("Erro ao posicionar o cursor\n");
                fclose(fp);
                free(prodArqv);
                return 0;  //Falha... return 0?
            }

            if (fwrite(prodArqv, sizeof(Produto), 1, fp) != 1) {
                perror("Erro ao gravar a exclusão do produto\n");
                fclose(fp);
                free(prodArqv);
                return 0; //Falha... return 0?
            }

            break;
        }
    } 
    if(!encontrado) {
        printf("======= Produto não encontrado! =======\n");
        fclose(fp);
        free(prodArqv);
        return 0; 
    }

    fclose(fp);
    free(prodArqv);
    return 1; //sucess
}