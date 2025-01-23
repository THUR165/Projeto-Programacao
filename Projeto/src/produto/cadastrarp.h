#ifndef CADASTRAR_P
#define CADASTRAR_P

#include <stdio.h>
#include <stdlib.h>
#include "../../valida.h"

//definição da struct   //definir const char* nomeArquivo aqui tbm?
typedef struct produto {
    char cod_barras[6];       //futuramente, essas variáveis serão alocadas dinamicaente...?
    char nome[31];
    char marca[21];      
    float preco;         
    char categoria[21];
    char data_validade [11];      
    int status;
} Produto;

Produto* preencherProduto(void);
int gravarProduto(const char* nomeArquivo, Produto* prod);
#endif