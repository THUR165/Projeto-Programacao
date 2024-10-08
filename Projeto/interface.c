#include <stdio.h>
#include "./include/interface.h"

int tela_main(){
    int op;
    printf("\n");
    printf("===========================================================\n");
    printf("=====                SIG-Building                     =====\n");
    printf("===========================================================\n");
    printf("=====    Sistema de gestão de material de construção  =====\n");
    printf("===========================================================\n");
    printf("=====                [1] - Clientes                   =====\n");
    printf("=====                [2] - Vendas                     =====\n");
    printf("=====                [3] - Funcionário                =====\n");
    printf("=====                [5] - Produto                    =====\n");
    printf("=====                [4] - Sobre o Projeto            =====\n");
    printf("=====                [0] - Sair                       =====\n");
    printf("Sua Escolha: --> ");
    scanf("%d", &op);
    printf("===========================================================\n");
    return op;
  
}