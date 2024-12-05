#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cadastrarp.h"
#include "../../valida.h"         //inclui a biblioteca valida.h para uso das funções de validação de dados

//struct para produto
typedef struct produto {
    char codigo[6];
    char nome[31];
    float preco;
    int status;
} Produto;

void cadastrar_produto(void){          //sendo ainda a leitura, então a função não retornaria Produto* ainda...
    
    Produto* produto;
    produto = (Produto*)malloc(sizeof(Produto));
    
    printf("===========================================================\n");
    printf("=======             Cadastrar Produto                ======\n");
    printf("===========================================================\n");
    printf("Digite o código de barra: ");
    scanf("%s", &produto->codigo); 
    getchar();
    do{      //loop para testar a função, podendo ser adaptado de acordo com novas implementações
        printf("Digite o nome do produto: ");
        fgets(&produto->nome, sizeof(&produto->nome), stdin);       

        nome[strcspn(nome, "\n")] = 0;
     
        if (validar_nome(nome)) {
            nome_valido = 1;
        }else{
            printf("---> Nome inválido!\n");
        }
    }while(!nome_valido);
    printf("Digite o preço do produto: ");
    scanf("%f", &produto->preco);
    getchar();
    printf("\n");
    printf("======= Cadastro de produto realizado com sucesso! ======== \n");
    printf("=========================================================== \n");
    getchar();
}