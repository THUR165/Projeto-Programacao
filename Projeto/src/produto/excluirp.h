#ifndef EXCLUIR_P
#define EXCLUIR_P
#include "cadastrarp.h"
#include "verificarp.h"

//busca produto, depois percorre o arquivo, usa o fseek e desativa o status
int excluirProduto(const char* nomeArquivo);
#endif