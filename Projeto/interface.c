#include <stdio.h>
#include "interface.h"
//Criar um mod relatorio: relatorio clientes,vendas,produtos e funcionários.

int tela_main(){
    int op;
    printf("\n");
    printf("===========================================================\n");
    printf("=====                SIG-Building                     =====\n");
    printf("===========================================================\n");
    printf("=====    Sistema de gestão de material de construção  =====\n");
    printf("===========================================================\n");
    printf("=====                [1] - Clientes                   =====\n");
    printf("=====                [2] - Vendas                     =====\n");
    printf("=====                [3] - Funcionário                =====\n");
    printf("=====                [5] - Produto                    =====\n");
    printf("=====                [4] - Sobre o Projeto            =====\n");
    printf("=====                [0] - Sair                       =====\n");
    printf("Sua Escolha: --> ");
    scanf("%d", &op);
    printf("===========================================================\n");
    return op;
  
}

int mod_vendas(void){
    int op;
    printf("\n");
    printf("===========================================================\n");
    printf("=====                SIG-Building                     =====\n");
    printf("===========================================================\n");
    printf("=====    Sistema de gestão de material de construção  =====\n");
    printf("===========================================================\n");
    printf("=====                [1] - Comprar produtos           =====\n");
    printf("=====                [2] - Verificar Compras          =====\n");
    printf("=====                [3] - Alterar Compras            =====\n");
    printf("=====                [4] - Excluir Compras            =====\n");
    printf("=====                [5] - Relatório                  =====\n");
    printf("=====                [0] - Sair                       =====\n");
    scanf("%i", &op);
    printf("===========================================================\n");
    return 0;
}

int mod_func(void){
    int op;
    printf("\n");
    printf("===========================================================\n");
    printf("=====                Funcionario                      =====\n");
    printf("===========================================================\n");
    printf("=====         [1] - cadastrar Funcionario             =====\n");
    printf("=====         [2] - Exibir Funcionarios               =====\n");
    printf("=====         [3] - modificar Funcionario             =====\n");
    printf("=====         [4] - Excluir Funcionario               =====\n");
    printf("=====         [0] - sair                              =====\n");
    printf("===========================================================\n");
    printf("Sua Escolha: --> ");
    scanf("%d", &op);
    return op;
}

int mod_prod(void){
    int op;
    printf("\n");
    printf("===========================================================\n");
    printf("=====                Produto                          =====\n");
    printf("===========================================================\n");
    printf("=====         [1] - Cadastrar produto                 =====\n");
    printf("=====         [2] - Exibir produto                    =====\n");
    printf("=====         [3] - Modificar produto                 =====\n");
    printf("=====         [4] - Excluir produto                   =====\n");
    printf("=====         [0] - Sair                              =====\n");
    printf("===========================================================\n");
    printf("Sua Escolha: --> ");
    scanf("%i", &op);
    printf("===========================================================\n");
    return 0;
}

int mod_venda(void){
    int op;
    printf("\n");
    printf("===========================================================\n");
    printf("=====                SIG-Building                     =====\n");
    printf("===========================================================\n");
    printf("=====    Sistema de gestão de material de construção  =====\n");
    printf("===========================================================\n");
    printf("=====                [1] - Comprar produtos           =====\n");
    printf("=====                [2] - Verificar Compras          =====\n");
    printf("=====                [3] - Alterar Compras            =====\n");
    printf("=====                [4] - Excluir Compras            =====\n");
    printf("=====                [5] - Relatório                  =====\n");
    printf("=====                [0] - Sair                       =====\n");
    scanf("%i", &op);
    printf("===========================================================\n");
    return 0;
}

int info_proj(){
    printf("\n");
    printf("===========================================================\n");
    printf("=====   Universidade Federal Rio Grande do Norte      =====\n");
    printf("=====   Diciplina: Programação,  codigo: DCT1106      =====\n");
    printf("=====               Programa de Gestão                =====\n");
    printf("=====   Para uma Loja de Material de Construção       =====\n");
    printf("===========================================================\n");
    printf("=====   O Projeto tem o objetivo Criar um programa    =====\n");
    printf("=====   de Gestão para uma Loja de Materais           =====\n");
    printf("=====   de Construção,tem como objetivo ajudar na     =====\n");
    printf("=====   administração da loja,sendo possivel administa=====\n");
    printf("=====   produtos,vendas,clientes,funcionarios e tambem=====\n");
    printf("=====   relatorios                                    =====\n");
    printf("===========================================================\n");

    printf("\n");
    printf("===========================================================\n");
    printf("=====            Equipe de desenvolvimento            =====\n");
    printf("===========================================================\n");
    printf("=====            Leandro Sergio Da Silva              =====\n");
    printf("=====            Arthur De Medeiros Dantas            =====\n");
    printf("===========================================================\n");
    getchar();
    return 0;
}