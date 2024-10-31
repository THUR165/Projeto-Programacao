#include <stdio.h>
#include <stdlib.h>
#include "excluirc.h"

void excluir_cliente(void){
    char cpf[20];
    printf("\n===========================================================\n");
    printf("======═             Excluir Cliente                  ======\n");
    printf("===========================================================\n");
    printf("Digite o CPF do cliente a ser excluído: ");
    scanf("%s", cpf);
    printf("===========================================================\n");
}