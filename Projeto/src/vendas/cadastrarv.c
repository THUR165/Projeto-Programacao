#include <stdio.h>
#include <stdlib.h>
#include "cadastrarv.h"
void cadastrar_venda(void) {
    int codVenda;
    float valor;
    
    printf("\n===========================================================\n");
    printf("======═             Cadastrar Venda                  ======\n");
    printf("===========================================================\n");
    printf("Digite o código da venda: ");
    scanf("%d", &codVenda);
    printf("Digite o valor da venda: ");
    scanf("%f", &valor);
    printf("Venda cadastrada com sucesso!\n");
    printf("===========================================================\n");
}