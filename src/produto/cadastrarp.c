#include <stdio.h>
#include <stdlib.h>
#include "cadastrarp.h"
void cadastrar_produto(void){
    char codigo[20];
    char nome[50];
    float preco;
    
    printf("\n=========================================================\n");
    printf("======═             Cadastrar Produto                ======\n");
    printf("===========================================================\n");
    printf("Digite o código de barra: ");
    scanf("%s", codigo);
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", nome);  
    printf("Digite o preço do produto: ");
    scanf("%f", &preco);   
    printf("===========================================================\n");
}