#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cadastrarp.h"
#include "../../valida.h"         //inclui a biblioteca valida.h para uso das funções de validação de dados

void cadastrar_produto(void){
    char codigo[20];
    char nome[50];
    float preco; 
    int nome_valido = 0;
    
    printf("===========================================================\n");
    printf("=======             Cadastrar Produto                ======\n");
    printf("===========================================================\n");
    printf("Digite o código de barra: ");
    scanf("%s", codigo);
    getchar();
    do{      //loop para testar a função, podendo ser adaptado de acordo com novas implementações
        printf("Digite o nome do produto: ");
        fgets(nome, sizeof(nome), stdin);       

        nome[strcspn(nome, "\n")] = 0;
     
        if (validar_nome(nome)) {
            nome_valido = 1;
        }else{
            printf("---> Nome inválido!\n");
        }
    }while(!nome_valido);
    printf("Digite o preço do produto: ");
    scanf("%f", &preco);
    getchar();
    printf("\n");
    printf("======= Cadastro de produto realizado com sucesso! ======== \n");
    printf("=========================================================== \n");
    getchar();
}