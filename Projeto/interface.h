#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>

int tela_main();
void tela_mod_cliente();
void tela_mod_func();
int tela_mod_prod();
void tela_mod_vendas();
int tela_info_proj();
int tela_mod_relat();

void modificar_cliente(void);
void cadastrar_cliente(void);
void excluir_cliente(void);
void exibir_cliente(void);

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
#endif