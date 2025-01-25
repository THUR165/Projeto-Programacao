
#ifndef ALTERAR_V
#define ALTERAR_V

#include <stdio.h>
#include <stdlib.h>
#include "../../valida.h"

typedef struct venda {
    char cod_venda[6];
    char cod_prod[6];
    char cpf_clnt[13];
    char cpf_func[13];
    char data_venda[12];
} Venda;

Venda* preencherVenda(void);
int gravarVenda(const char* nomeArquivo, Venda* vnd);
#endif