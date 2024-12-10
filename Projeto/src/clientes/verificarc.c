#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../clientes/cadastrarc.h"


void exibirCliente(Cliente* cliente) {
    if (cliente == NULL) {
        printf("\n= = = Cliente Inexistente = = =\n");
    } else {
        printf("\n= = = Cliente Cadastrado = = =\n");
        printf("Nome: %s\n", cliente->nome);
        printf("CPF: %s\n", cliente->cpf);
        printf("Data de Nascimento: %s\n", cliente->nasc);
        printf("Gênero: %s\n", cliente->gen);
        printf("Telefone: %s\n", cliente->tel);
        printf("Rua: %s\n", cliente->rua);
        printf("Número da Casa: %s\n", cliente->num);
        printf("Status: %s\n", cliente->status ? "Ativo" : "Inativo");
    }
    printf("\n\nTecle ENTER para continuar!\n\n");
    getchar();
}
