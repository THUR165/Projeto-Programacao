#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>

int tela_main();
void tela_mod_cliente();
int tela_mod_func();
int tela_mod_prod();
int tela_mod_vendas();
int tela_info_proj();
int tela_mod_relat();

void modificar_cliente(void);
void cadastrar_cliente(void);
void excluir_cliente(void);
void exibir_cliente(void);
#endif