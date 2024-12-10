#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../clientes/cadastrarc.h"


Cliente* buscarCliente(const char* nomeArquivo, const char* cpf) {
    FILE* fp;
    Cliente* cliente;

    // Aloca memória para um cliente
    cliente = (Cliente*)malloc(sizeof(Cliente));
    if (cliente == NULL) {
        perror("Erro ao alocar memória para cliente");
        return NULL;
    }

    // Abre o arquivo para leitura binária
    fp = fopen(nomeArquivo, "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        free(cliente); // Libera memória alocada
        return NULL;
    }

    // Procura o cliente no arquivo
    while (fread(cliente, sizeof(Cliente), 1, fp)) {
        if ((strcmp(cliente->cpf, cpf) == 0) && (cliente->status == 1)) {
            fclose(fp);
            return cliente; // Retorna o cliente encontrado
        }
    }

    // Cliente não encontrado
    fclose(fp);
    free(cliente); // Libera memória se não encontrado
    return NULL;
}