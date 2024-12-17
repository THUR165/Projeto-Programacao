#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../clientes/cliente.h"


// possivel erro nessa função na hr de abrir o arquivo

char* pesqClient(char* cpf) {
    printf("Digite o CPF do cliente que deseja buscar: ");
    limparBuffer(); // Certifique-se de limpar o buffer antes da leitura
    scanf("%14[^\n]", cpf);
    return cpf;
}




Cliente* buscarCliente(const char* cpf) {
    FILE* fp;
    Cliente* cliente;

    cliente = (Cliente*) malloc(sizeof(Cliente));
    if (cliente == NULL) {
        perror("Erro ao alocar memória");
        return NULL;
    }

    fp = fopen("cliente.bin", "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        free(cliente);
        return NULL;
    }

    while (fread(cliente, sizeof(Cliente), 1, fp)) {
    printf("Lido do arquivo: CPF=%s, Status=%d\n", cliente->cpf, cliente->status);

    if ((strcmp(cliente->cpf, cpf) == 0) && (cliente->status == 1)) {
        fclose(fp);
        return cliente;
    }
}


    fclose(fp);
    free(cliente);
    return NULL; // Cliente não encontrado
}



/// @brief 
/// @param cliente 
/// @return 
Cliente* exibirCliente(Cliente* cliente) {
    if (cliente == NULL) {
        printf("\n= = = Cliente Inexistente = = =\n");
        //printf("Lido do arquivo: CPF=%s", cliente->cpf);
    } else {
        printf("\n= = = Cliente Cadastrado = = =\n");
        printf("Nome: %s\n", cliente->nome);
        printf("CPF: %s\n", cliente->cpf);
        printf("Data de Nascimento: %s\n", cliente->nasc);
        printf("Gênero: %s\n", cliente->gen);
        printf("Telefone: %s\n", cliente->tel);
        printf("Cidade: %s\n", cliente->cid);
        printf("Estado: %s\n", cliente->est);
        printf("Rua: %s\n", cliente->rua);
        printf("Número da Casa: %s\n", cliente->num);
        printf("Status: %d\n", cliente->status);
    }
    printf("\n\nTecle ENTER para continuar!\n\n");
    getchar();
}

