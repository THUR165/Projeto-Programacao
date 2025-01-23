#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "excluirf.h"

int excluirFuncionario(const char* nomeArquivo){  
    FILE* fp; 
    Funcionario* funcArqv;
    char cpf_pesquisado[12];
    int encontrado = 0;

    funcArqv = (Funcionario*)malloc(sizeof(Funcionario));
    if(funcArqv == NULL) {    //teste de alocação de memória
        printf("Erro de alocação de memória! \n");
        return 0;  //falha...
    }

    //abrir o arquivo "r+b"
    fp = fopen(nomeArquivo, "r+b");
    if (fp == NULL) {     //teste de abertura de arquivo
        perror("Erro ao abrir o arquivo");
        free(funcArqv);
        return 0; //falha...
    }

    printf("\n=========================================================\n");
    printf("=======             Excluir Funcionário              ======\n");
    printf("===========================================================\n");
    printf("Digite o CPF do funcionário que deseja pesquisar: \n");
    scanf("%11s", cpf_pesquisado); 
    getchar();

    //excluindo o funcionario
     while(fread(funcArqv, sizeof(Funcionario), 1, fp)) {
        if((strcmp(funcArqv->cpf, cpf_pesquisado) == 0) && (funcArqv->status == 1)) {
            encontrado = 1;

            funcArqv->status = 0; //status 0 significa que o funcionario será excluído logicamente
            if (fseek(fp, -1*sizeof(Funcionario), SEEK_CUR) != 0) {
                perror("Erro ao posicionar o cursor\n");
                fclose(fp);
                free(funcArqv);
                return 0;  //Falha... return 0?
            }

            if (fwrite(funcArqv, sizeof(Funcionario), 1, fp) != 1) {
                perror("Erro ao gravar a exclusão do funcionário\n");
                fclose(fp);
                free(funcArqv);
                return 0; //Falha... return 0?
            }

            break;
        }
    } 
    if(!encontrado) {
        printf("======= Funcionário não encontrado! =======\n");
        fclose(fp);
        free(funcArqv);
        return 0; 
    }

    fclose(fp);
    free(funcArqv);
    return 1; //sucess
}