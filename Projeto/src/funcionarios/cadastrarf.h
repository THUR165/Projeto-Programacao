#ifndef CADASTRAR_F
#define CADASTRAR_F

#include <stdio.h>
#include <stdlib.h>
#include "../../valida.h"

//struct para funcionario
typedef struct funcionario {
    char nome[51];
    char cpf[13];       //12 pq seriam 11 dígitos + 1 para o 0.
    char data_nascimento[12];
    int status;
} Funcionario;

Funcionario* preencherFuncionario(void);
int gravarFuncionario(const char* nomeArquivo, Funcionario* func);
#endif