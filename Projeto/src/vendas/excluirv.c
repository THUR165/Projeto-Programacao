#include <stdio.h>
#include <stdlib.h>
#include "excluirv.h"
void excluir_venda(void) {
    int codVenda;
    
    printf("\n===========================================================\n");
    printf("======═             Excluir Venda                    ======\n");
    printf("===========================================================\n");
    printf("Digite o código da venda a ser excluída: ");
    scanf("%d", &codVenda);
    printf("===========================================================\n");
}