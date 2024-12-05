#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "cadastrarf.h"
#include "../../valida.h"    //inclui biblioteca valida.h para as funções de validação de dados

void cadastrar_funcionario(void){
    char nome[50];
    char cpf[20];  //não seria cpf[12]? Já que são 11 dígitos do CPF + 1 para o 0. Ou 15, contando com pontos e traço?
    char data_nasc[11];  
    int nome_valido = 0;

    printf("===========================================================\n");
    printf("=======             Cadastrar Funcionário            ======\n");
    printf("===========================================================\n");
    getchar();
    do{        //teste do loop para nomes inválidos
        printf("Digite o nome do funcionário: ");
        fgets(nome, sizeof(nome), stdin);       

        nome[strcspn(nome, "\n")] = 0;
     
        if (validar_nome(nome)) {
            nome_valido = 1;
        }else{
            printf("---> Nome inválido!\n");
        }
    }while(!nome_valido);
    
    printf("Digite o CPF do funcionário: ");
    scanf("%s", cpf);
    getchar();
    //teste da função de validar cpf; colocar num loop caso cpf digitado não seja válido
    if (validar_cpf(cpf)) {
        printf("CPF válido!\n");
    } else {
        printf("CPF inválido!\n");
    }
    printf("Digite a data de nascimento (DD/MM/AAAA): ");
    scanf("%s", data_nasc);
    getchar();
    //teste da função de validar data_nascimento
    if (validar_data_nascimento(data_nasc)) {
        printf("Data de nascimento válida e a pessoa tem mais de 18 anos.\n");
    } else {
        printf("Data de nascimento inválida ou a pessoa não tem mais de 18 anos.\n");
    }
    printf("\n");
    printf("======= Cadastro de funcionário realizado com sucesso! ==== \n");
    printf("=========================================================== \n");
    getchar();
}