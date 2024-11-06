#include <stdio.h>
#include <stdlib.h>
#include "cadastrarc.h"

/*
1 - Clientes:
Nome:
CPF:
Data de Nascimento:
Gênero:
Telefone:
Rua:
*/

void cadastrar_cliente(void){
    char nome; //espaço da variavel:indeterminado, alocação dinamica
    char cpf[20];
    char nasc[11];
    char gen[2];
    char tel[16];
    char rua;  //espaço da variavel:indeterminado, alocação dinamica
    char cadastro;
    printf("\n===========================================================\n");
    printf("======═             Cadastrar Cliente                ======\n");
    printf("===========================================================\n");
    printf( "\n");
    printf("Digite o nome do cliente: \n"); //espaço da variavel:indeterminado
    scanf(" %[^\n]", nome);
    printf("Digite o CPF do cliente(123.456.789-12) \n");//espaço da variavel:16
    scanf("%s", cpf);
    print("Data de Nascimento(xx/xx/xxxx): ->   \n"); //espaço da variavel:11
    scanf("%s", nasc);
    printf("Gênero(M/F): ->  \n"); //espaço da variavel:2
    scanf("%s",gen);
    printf("Digite Telefone:(xx) x xxxx-xxxx): ->  \n"); //espaço da variavel:16
    scanf("%s", tel);
    printf("Digite o nome da Rua: ->  \n");
    scanf("%s", rua);

    ~//cadastro = [nome,cpf,nasc,gen,tel,rua];
}