#include <stdio.h>
#include <string.h>
#include "src/clientes/cadastrarc.h"

// Função para buscar e exibir informações do cliente pelo CPF
Cliente exibir_cliente(Cliente *clientes, int size, const char *cpf_busca) {
    for (int i = 0; i < size; i++) {
        if (strcmp(clientes[i].cpf, cpf_busca) == 0) {  // CPF encontrado
            printf("\nCliente encontrado:\n");
            printf("Nome: %s\n", clientes[i].nome);
            printf("CPF: %s\n", clientes[i].cpf);
            printf("Data de Nascimento: %s\n", clientes[i].nasc);
            printf("Gênero: %s\n", clientes[i].gen);
            printf("Telefone: %s\n", clientes[i].tel);
            printf("Rua: %s\n", clientes[i].rua);
            printf("Número da casa: %s\n", clientes[i].num);
            
            // Liberando memória alocada dinamicamente
            free(clientes[i].nome);
            free(clientes[i].rua);
            
            return clientes[i];  // Retorna o cliente encontrado
        }
    }

    // Caso o CPF não seja encontrado
    printf("\nCliente com CPF %s não encontrado.\n", cpf_busca);

    // Retornar um cliente vazio em caso de não encontrado
    Cliente cliente_vazio = {0};  // Inicializa todos os campos com valores padrão
    return cliente_vazio;
}
