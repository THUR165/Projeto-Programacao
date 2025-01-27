#ifndef RELATORIO_F
#define RELATORIO_F
#include "../funcionarios/cadastrarf.h"


void relatorio_funcionarios_por_status(const char* arquivoFuncionario, int statusDesejado);
char* get_nome_funcionario(const char* arquivoFuncionario, char cpf_func[13]);
#endif