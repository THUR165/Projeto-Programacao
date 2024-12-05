#include <stdio.h>
#include <stdlib.h>
#include "verificarp.h"

//além de uma função para exibir, poderia ter uma função própria para somente buscar o produto pelo código, separada...
void exibir_produto(void){
    char codigo[20];
    printf("\n=========================================================\n");
    printf("======═                 Exibir Produto               ======\n");
    printf("===========================================================\n");
    printf("Digite o código de barra do produto: ");
    scanf("%s", codigo);;
    printf("===========================================================\n");
}