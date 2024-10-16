#include <stdio.h>
#include <stdlib.h>
#include "cadastrarc.h"

void cadastrar_cliente(void){
    char nome[50];
    char cpf[20];
    printf("\n===========================================================\n");
    printf("======═             Cadastrar Cliente                ======\n");
    printf("===========================================================\n");
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", nome);
    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);
    printf("===========================================================\n");
}