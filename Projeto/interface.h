
#ifndef INTERFACE_H
#define INTERFACE_H


int tela_main();
void tela_mod_cliente();
void tela_mod_func();
int tela_mod_prod();
void tela_mod_vendas();
void tela_info_proj();
void tela_mod_relat();

void modificar_cliente(const char* nomeArquivo);
void excluir_cliente(const char* nomeArquivo);


void modificar_funcionario(void);
void cadastrar_funcionario(void);
void excluir_funcionario(void);
void exibir_funcionario(void);

void modificar_produto(void);
void excluir_produto(void);
void cadastrar_produto(void);
void exibir_produto(void);

void modificar_venda(void);
void cadastrar_venda(void);
void excluir_venda(void);
void exibir_venda(void);

void relatorio_produtos(void);
void relatorio_funcionarios(void);
void relatorio_vendas(void);
void relatorio_cliente(void);

#endif