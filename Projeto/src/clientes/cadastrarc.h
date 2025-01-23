#ifndef CADASTRAR_C
#define CADASTRAR_C

#include <stdio.h>
#include <stdlib.h>
#include "../../valida.h"

typedef struct cliente {
    char nome[51];      // Alocação dinâmica para o nome
    char cpf[12];    // Memória estática para CPF (14 + 1 para o caractere nulo)
    char data_nascimento[11];   // Memória estática para data de nascimento (10 + 1)
    char gen[10];     // Memória estática para gênero (1 + 1)
    char tel[16];    // Memória estática para telefone (15 + 1)
    char rua[41];      // Alocação dinâmica para a rua
    char num[7];
    int status;
} Cliente;

Cliente* preencherCliente(void);
int gravarCliente(const char* nomeArquivo, Cliente* clnt);
#endif
