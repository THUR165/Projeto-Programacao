#include <stdio.h>
#include <stdlib.h>
#include "excluirf.h"
void excluir_funcionario(void){
    char cpf[20];
    printf("\n===========================================================\n");
    printf("======═             Excluir Funcionário              ======\n");
    printf("===========================================================\n");
    printf("Digite o CPF do funcionário a ser excluído: ");
    scanf("%s", cpf);
    printf("===========================================================\n");
}