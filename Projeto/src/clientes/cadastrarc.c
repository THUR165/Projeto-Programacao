#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../valida.h"
#include "cadastrarc.h"

/*
1 - Clientes:
Nome:
CPF:
Data de Nascimento:
Gênero:
Telefone:
Rua:
*/
// substituir scanf por fgets, para manuseio de strings
//exemplo de uso no código de Flavius, no slide.
//Trocar o \n por \0.
Cliente* preencherCliente(void) {          
    
    Cliente* clnt;
    clnt = (Cliente*)malloc(sizeof(Cliente));
    if (clnt == NULL) {
        printf("Erro de alocação de memória! \n");
        return NULL; // return NULL;
    }
    int valido = 0;
    
    printf("===========================================================\n");
    printf("=======             Cadastrar Cliente                ======\n");
    printf("===========================================================\n");
    do{  //Capturar cpf
        printf("Digite o CPF: ");
        scanf("%11s", clnt->cpf); 
        getchar();

        if (validar_cpf(clnt->cpf)) {
            valido = 1; 
        } else {
             printf("=== CPF inválido!\n");
        }
    } while(!valido);
    //Capturar nome
    do{     
        valido = 0;
        printf("Digite o nome do cliente: ");
        fgets(clnt->nome, sizeof(clnt->nome), stdin);       

        clnt->nome[strcspn(clnt->nome, "\n")] = 0;
     
        if (validar_nome(clnt->nome)) {
            valido = 1;  
        }else{
            printf("=== Nome inválido!\n");
        }
    }while(!valido);
    //Capturar data de nascimento
    do{
        valido = 0;
        printf("Digite a data de nascimento do cliente: ");
        fgets(clnt->data_nascimento, sizeof(clnt->data_nascimento), stdin);       

        clnt->data_nascimento[strcspn(clnt->data_nascimento, "\n")] = 0;

        if (validar_data_nascimento(clnt->data_nascimento)) {
            valido = 1;  
        }else{
            printf("=== Data de nascimento inválida!\n");
        }
    } while(!valido);
    printf("Digite o gênero do cliente: \n");
    scanf("%9s", clnt->gen);
    getchar();
    printf("Digite o telefone do cliente: \n");
    scanf("%15s", clnt->tel);
    getchar();
    printf("Digite a rua do cliente: \n");
    scanf("%40s", clnt->rua);
    getchar();
    printf("Digite o número da casa do cliente: \n");
    scanf("%6s", clnt->num);
    getchar();
    //Status = 1
    clnt->status = 1;

    return clnt;
}

int gravarCliente(const char* nomeArquivo, Cliente* clnt) {
    FILE* fp = fopen(nomeArquivo, "ab");  //ab
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para cadastrar o produto!\n");
        free(clnt);
        return 0; //falha...
    }

    //Escreve os dados no arquivo e testa se deu certo
    if (fwrite(clnt, sizeof(Cliente), 1, fp) != 1) {
        perror("Erro ao gravar os dados\n");
        free(clnt);
        return 0; //falha...
    }

    fclose(fp); // Fecha o arquivo
    return 1; //sucess
}




