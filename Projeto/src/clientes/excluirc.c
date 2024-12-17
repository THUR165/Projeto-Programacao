#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cliente.h"
#include "../../valida.h"


void excluir_cliente(const char* nomeArquivo) {
    char cpf[20];
    Cliente cliente;
    int encontrado = 0;

    printf("\nDigite o CPF do cliente a ser excluído (lógica): ");
    scanf("%19s", cpf);

    FILE* fp = fopen(nomeArquivo, "rb+");
    if (fp == NULL) {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    while (fread(&cliente, sizeof(Cliente), 1, fp)) {
        if (strcmp(cliente.cpf, cpf) == 0 && cliente.status == 1) {
            cliente.status = 0; // Define o cliente como inativo
            fseek(fp, -sizeof(Cliente), SEEK_CUR); // Retorna o ponteiro para reescrever o cliente
            fwrite(&cliente, sizeof(Cliente), 1, fp);
            printf("\nCliente com CPF %s excluído logicamente!\n", cpf);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nCliente com CPF %s não encontrado ou já está inativo!\n", cpf);
    }

    fclose(fp);
}
