#include <stdio.h>
#include <stdlib.h>
#include "excluirp.h"
void excluir_produto(void){
    char codigo[20];
    printf("\n=========================================================\n");
    printf("======═             Excluir Produto                  ======\n");
    printf("===========================================================\n");
    printf("Digite o código de barra do produto a ser excluído: ");
    scanf("%s", codigo);
    printf("===========================================================\n");
}