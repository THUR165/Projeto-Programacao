
#ifndef INTERFACE_H
#define INTERFACE_H
//Cadastro para cada um dos módulos
#include "src/clientes/cadastrarc.h"
#include "src/funcionarios/cadastrarf.h"
#include "src/produto/cadastrarp.h"
#include "src/vendas/cadastrarv.h"
//Pesquisa para cada um dos módulos
#include "src/clientes/verificarc.h"
#include "src/funcionarios/verificarf.h"
#include "src/produto/verificarp.h"
#include "src/vendas/verificarv.h"
//Alteração para cada um dos módulos
#include "src/clientes/alterarc.h"
#include "src/funcionarios/alterarf.h"
#include "src/produto/alterarp.h"
#include "src/vendas/alterarav.h"
//Exclusão para cada um dos módulos
#include "src/clientes/excluirc.h"
#include "src/funcionarios/excluirf.h"
#include "src/produto/excluirp.h"
#include "src/vendas/excluirv.h"
//Relatórios para cada um dos módulos
#include "src/relatorios/relatorioc.h"
#include "src/relatorios/relatoriof.h"
#include "src/relatorios/relatoriop.h"
#include "src/relatorios/relatoriov.h"

void relatorio_clientes_por_status(const char* arquivoCliente, int statusDesejado);


/* Faltando:
- CRUD para Clientes...
- importar as bibliotecas aqui...?
*/


//Telas
int tela_main();
void tela_mod_cliente(void);
void tela_mod_func(void);
void tela_mod_prod(void);
void tela_mod_vendas(void);
void tela_info_proj(void);
void tela_mod_relat(void);


/*void modificar_cliente(void);
void excluir_cliente(void);*/


/*
//CRUD para Funcionários
void modificar_funcionario(void);
void cadastrar_funcionario(void);
void excluir_funcionario(void);
void exibir_funcionario(void);

//CRUD para Produtos...
Produto* preencherProduto(void);
void gravarProduto(const char* nomeArquivo, Produto* prod);
Produto* buscarProduto(const char* nomeArquivo);
int alterarProduto(const char* nomeArquivo);
void exibirProduto(Produto* prod);
void excluirProduto(const char* nomeArquivo, Produto* prodObtido);

//CRUD para Vendas...
void modificar_venda(void);
void cadastrar_venda(void);
void excluir_venda(void);
void exibir_venda(void);
*/
//Relatórios
/*void relatorio_geral_produtos(void);
void relatorio_funcionarios(void);
void relatorio_vendas(void);
void relatorio_cliente(void);*/

#endif