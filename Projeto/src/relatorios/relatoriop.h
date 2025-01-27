#ifndef RELATORIO_P
#define RELATORIO_P
#include "../produto/cadastrarp.h"
#include "../../interface.h"

void relatorio_produtos_por_status(const char* arquivoProduto, int statusDesejado);
char* get_nome_produto(const char* arquivoCliente, char cod_prod[6]);
float get_preco_produto(const char* arquivoProduto, char cod_prod[6]);
#endif