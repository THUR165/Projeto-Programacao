#include <stdio.h>
#include <stdlib.h>
#include "cadastrarf.h"
void cadastrar_funcionario(void){
    char nome[50];
    char cpf[20];
    char data_nasc[11];
    printf("\n=========================================================\n");
    printf("=======             Cadastrar Funcionário            ======\n");
    printf("===========================================================\n");
    printf("Digite o nome do funcionário: ");
    scanf(" %[^\n]", nome);
    printf("Digite o CPF do funcionário: ");
    scanf("%s", cpf);
    getchar();
    printf("Digite a data de nascimento (DD/MM/AAAA): ");
    scanf("%s", data_nasc);
    printf("===========================================================\n");
}