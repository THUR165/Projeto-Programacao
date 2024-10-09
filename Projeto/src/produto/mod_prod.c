#include <stdio.h>
int mod_prod(void){
    int op;
    printf("\n");
    printf("===========================================================\n");
    printf("=====                Produto                          =====\n");
    printf("===========================================================\n");
    printf("=====         [1] - Cadastrar produto                 =====\n");
    printf("=====         [2] - Exibir produto                    =====\n");
    printf("=====         [3] - Modificar produto                 =====\n");
    printf("=====         [4] - Excluir produto                   =====\n");
    printf("=====         [0] - Sair                              =====\n");
    printf("===========================================================\n");
    printf("Sua Escolha: --> ");
    scanf("%i", &op);
    printf("===========================================================\n");
    return 0;
}