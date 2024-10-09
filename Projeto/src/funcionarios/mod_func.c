#include <stdio.h>

int mod_func(void){
    int op;
    printf("\n");
    printf("===========================================================\n");
    printf("=====                Funcionario                      =====\n");
    printf("===========================================================\n");
    printf("=====         [1] - cadastrar Funcionario             =====\n");
    printf("=====         [2] - Exibir Funcionarios               =====\n");
    printf("=====         [3] - modificar Funcionario             =====\n");
    printf("=====         [4] - Excluir Funcionario               =====\n");
    printf("=====         [0] - sair                              =====\n");
    printf("===========================================================\n");
    printf("Sua Escolha: --> ");
    scanf("%d", &op);
    return op;
}