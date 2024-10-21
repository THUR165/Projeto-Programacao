#include <stdio.h>
#include <stdlib.h>
#include "alterarav.h"

void modificar_venda(void) {
    int codVenda;
    
    printf("\n===========================================================\n");
    printf("======═             Modificar Venda                  ======\n");
    printf("===========================================================\n");
    printf("Digite o código da venda a ser modificada: ");
    scanf("%d", &codVenda);
    printf("===========================================================\n");
}