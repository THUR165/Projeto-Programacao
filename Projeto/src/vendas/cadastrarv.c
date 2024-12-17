#include <stdio.h>
#include <stdlib.h>
#include "cadastrarv.h"


void cadastrar_venda(void) {
    printf("\n===========================================================\n");
    printf("=============            Cadastrar Venda            =============\n");
    printf("===========================================================\n");

    printf("\nProdutos Disponíveis:\n");

    printf("\n[ MATERIA PRIMA ]\n");
    printf("  [1] - Cimento\n");
    printf("  [2] - Tijolos\n");
    printf("  [3] - Areia\n");

    printf("\n[ FERRAMENTAS ]\n");
    printf("  [4] - Alicates\n");
    printf("  [5] - Chaves\n");

    printf("\n===========================================================\n");

    // Informar ao usuário o valor da compra
    printf("Informe o valor total da compra: R$ ");
    float valor;
    scanf("%f", &valor);

    // Confirmar a compra
    printf("\nVocê deseja confirmar a compra? (S/N): ");
    char confirmacao;
    scanf(" %c", &confirmacao);

    if (confirmacao == 'S' || confirmacao == 's') {
        // Escolher forma de pagamento
        printf("\nSelecione a forma de pagamento:\n");
        printf("  [1] - Cartão de Crédito\n");
        printf("  [2] - Cartão de Débito\n");
        printf("  [3] - Dinheiro\n");
        printf("Opção: ");
        int forma_pagamento;
        scanf("%d", &forma_pagamento);

        printf("\nVenda cadastrada com sucesso!\n");
    } else {
        printf("\nCompra não confirmada. Voltando ao menu principal.\n");
    }

    printf("\n===========================================================\n");
}