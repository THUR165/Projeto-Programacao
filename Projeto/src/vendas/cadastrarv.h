
#ifndef ALTERAR_V
#define ALTERAR_V

#include <stdio.h>
#include <stdlib.h>
#include "../../valida.h"

typedef struct venda {
    char cod_venda[6];
    char cod_prod[6];
    char cpf_clnt[12];
    char cpf_func[12];
    char data_venda[11];
} Venda;

Venda* preencherVenda(void);
int gravarVenda(const char* nomeArquivo, Venda* vnd);
#endif