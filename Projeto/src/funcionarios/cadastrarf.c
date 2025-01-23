#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "cadastrarf.h"
 

Funcionario* preencherFuncionario(void){          
    
    Funcionario* func;
    func = (Funcionario*)malloc(sizeof(Funcionario));
    if (func == NULL) {
        printf("Erro de alocação de memória! \n");
        return NULL; // return NULL;
    }
    int valido = 0;
    
    printf("===========================================================\n");
    printf("=======             Cadastrar Funcionário            ======\n");
    printf("===========================================================\n");
    do{  //Capturar cpf
        printf("Digite o CPF do funcionário: ");
        scanf("%11s", func->cpf); 
        getchar();

        if (validar_cpf(func->cpf)) {
            valido = 1; 
        } else {
             printf("=== CPF inválido!\n");
        }
    } while(!valido);
    //Capturar nome
    do{     
        valido = 0;
        printf("Digite o nome do funcionário: ");
        fgets(func->nome, sizeof(func->nome), stdin);       

        func->nome[strcspn(func->nome, "\n")] = 0;
     
        if (validar_nome(func->nome)) {
            valido = 1;  
        }else{
            printf("=== Nome de funcionário inválido!\n");
        }
    }while(!valido);
    //Capturar data de nascimento
    do{
        valido = 0;
        printf("Digite a data de nascimento do funcionário: ");
        fgets(func->data_nascimento, sizeof(func->data_nascimento), stdin);       

        func->data_nascimento[strcspn(func->data_nascimento, "\n")] = 0;

        if (validar_data_nascimento(func->data_nascimento)) {
            valido = 1;  
        }else{
            printf("=== Data de nascimento inválida!\n");
        }
    } while(!valido);
    //Status = 1
    func->status = 1;

    return func;
}

int gravarFuncionario(const char* nomeArquivo, Funcionario* func) {
    FILE* fp = fopen(nomeArquivo, "ab");  //ab
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para cadastrar o funcionário!\n");
        free(func);
        return 0; //falha...
    }

    //Escreve os dados no arquivo e testa se deu certo
    if (fwrite(func, sizeof(Funcionario), 1, fp) != 1) {
        perror("Erro ao gravar os dados\n");
        free(func);
        return 0; //falha...
    }

    fclose(fp); // Fecha o arquivo
    free(func);
    return 1; //sucess
}
