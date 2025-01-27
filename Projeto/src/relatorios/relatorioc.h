#ifndef RELATORIO_C
#define RELATORIO_C
#include "../clientes/cadastrarc.h"

void relatorio_clientes_por_status(const char* arquivoCliente, int statusDesejado);
char* get_nome_cliente(const char* arquivoCliente, char cpf_clnt[13]);
#endif