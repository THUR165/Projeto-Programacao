#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "excluirc.h"

int excluirCliente(const char* nomeArquivo){  
    FILE* fp; 
    Cliente* clntArqv;
    char cpf_pesquisado[12];
    int encontrado = 0;

    clntArqv = (Cliente*)malloc(sizeof(Cliente));
    if(clntArqv == NULL) {    //teste de alocação de memória
        printf("Erro de alocação de memória! \n");
        return 0;  //falha...
    }

    //abrir o arquivo "r+b"
    fp = fopen(nomeArquivo, "r+b");
    if (fp == NULL) {     //teste de abertura de arquivo
        perror("Erro ao abrir o arquivo");
        free(clntArqv);
        return 0; //falha...
    }

    printf("\n=========================================================\n");
    printf("=======             Excluir Cliente                  ======\n");
    printf("===========================================================\n");
    printf("Digite o CPF do cliente que deseja pesquisar: \n");
    scanf("%11s", cpf_pesquisado); 
    getchar();

    //excluindo o produto
     while(fread(clntArqv, sizeof(Cliente), 1, fp)) {
        if((strcmp(clntArqv->cpf, cpf_pesquisado) == 0) && (clntArqv->status == 1)) {
            encontrado = 1;

            clntArqv->status = 0; //status 0 significa que o clnt será excluído logicamente
            if (fseek(fp, -1*sizeof(Cliente), SEEK_CUR) != 0) {
                perror("Erro ao posicionar o cursor\n");
                fclose(fp);
                free(clntArqv);
                return 0;  //Falha... return 0?
            }

            if (fwrite(clntArqv, sizeof(Cliente), 1, fp) != 1) {
                perror("Erro ao gravar a exclusão do cliente \n");
                fclose(fp);
                free(clntArqv);
                return 0; //Falha... return 0?
            }

            break;
        }
    } 
    if(!encontrado) {
        printf("======= Cliente não encontrado! =======\n");
        fclose(fp);
        free(clntArqv);
        return 0; 
    }

    fclose(fp);
    free(clntArqv);
    return 1; //sucess
}