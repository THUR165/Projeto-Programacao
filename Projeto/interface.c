#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "src\clientes\cadastrarc.h"

//Criar um mod relatorio: relatorio clientes,vendas,produtos e funcionários.

int tela_main(void){
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
    printf("=====                [4] - Produto                    =====\n");
    printf("=====                [5] - Relatório                  =====\n");
    printf("=====                [6] - Sobre o Projeto            =====\n");
    printf("=====                [0] - Sair                       =====\n");
    printf("Sua Escolha: --> ");
    scanf("%d", &op);
    printf("===========================================================\n");
    return op;
  
}



void tela_mod_cliente(Cliente *clientes, int size){
    int op;
    do {
        printf("\n===========================================================\n");
        printf("===                Módulo de Clientes                =====\n");
        printf("===========================================================\n");
        printf("===    [1] - Cadastrar Clientes                      ===\n");
        printf("===    [2] - Exibir Clientes                         ===\n");
        printf("===    [3] - Modificar Clientes                      ===\n");
        printf("===    [4] - Excluir Clientes                        ===\n");
        printf("===    [0] - Voltar ao Menu Principal                ===\n");
        printf("===========================================================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                cad_client();
                break;
            case 2:{
                char cpf_busca[15];
                printf("Digite o CPF do cliente que deseja buscar: ");
                scanf("%s", cpf_busca);
                exibir_cliente(clientes, size, cpf_busca);
                break;
            }            
            case 3:
                modificar_cliente();
                break;
            case 4:
                excluir_cliente();
                break;
            case 0:
                printf("Voltando ao Menu Principal...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(op != 0);
}

void tela_mod_vendas(void) {
    int op;
    do {
        printf("\n===========================================================\n");
        printf("===                   Módulo de Vendas                =====\n");
        printf("===========================================================\n");
        printf("===    [1] - Cadastrar Venda                          ===\n");
        printf("===    [2] - Exibir Venda                             ===\n");
        printf("===    [3] - Modificar Venda                          ===\n");
        printf("===    [4] - Excluir Venda                            ===\n");
        printf("===    [0] - Voltar ao Menu Principal                 ===\n");
        printf("===========================================================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
        switch(op) {
            case 1:
                cadastrar_venda();
                break;
            case 2:
                exibir_venda();
                break;
            case 3:
                modificar_venda();
                break;
            case 4:
                excluir_venda();
                break;
            case 0:
                printf("Voltando ao Menu Principal...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(op != 0);
}

void tela_mod_func(void){
    int op;
    do {
        printf("\n===========================================================\n");
        printf("===               Módulo de Funcionários              =====\n");
        printf("===========================================================\n");
        printf("===    [1] - Cadastrar Funcionário                   ===\n");
        printf("===    [2] - Exibir Funcionários                     ===\n");
        printf("===    [3] - Modificar Funcionário                   ===\n");
        printf("===    [4] - Excluir Funcionário                     ===\n");
        printf("===    [0] - Voltar ao Menu Principal                ===\n");
        printf("===========================================================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                cadastrar_funcionario();
                break;
            case 2:
                exibir_funcionario();
                break;
            case 3:
                modificar_funcionario();
                break;
            case 4:
                excluir_funcionario();
                break;
            case 0:
                printf("Voltando ao Menu Principal...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(op != 0);
}

int tela_mod_prod(void) {
    int op;
    do {
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
        scanf("%d", &op);
        
        switch(op) {
            case 1:
                cadastrar_produto();
                break;
            case 2:
                exibir_produto();
                break;
            case 3:
                modificar_produto();
                break;
            case 4:
                excluir_produto();
                break;
            case 0:
                printf("Saindo do módulo de produto...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (op != 0);  
    
    return 0;
}

void tela_mod_relat(void) {
    int op;
    
    do {
        printf("\n");
        printf("===========================================================\n");
        printf("=====                Relatório                          =====\n");
        printf("===========================================================\n");
        printf("=====         [1] - Relatório geral de clientes         =====\n");
        printf("=====         [2] - Relatório geral de vendas           =====\n");
        printf("=====         [3] - Relatório geral de produtos         =====\n");
        printf("=====         [4] - Relatório geral de funcionários     =====\n");
        printf("=====         [0] - Sair                                =====\n");
        printf("===========================================================\n");
        printf("Sua Escolha: --> ");
        scanf("%i", &op);
        printf("===========================================================\n");

        switch (op) {
            case 1:
                relatorio_cliente();  
                break;
            case 2:
                relatorio_vendas();   
                break;
            case 3:
                relatorio_produtos();  
                break;
            case 4:
                relatorio_funcionarios(); 
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (op != 0);  
}


int tela_mod_venda(void){
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

void tela_info_proj(void){
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
    printf("Pressione <ENTER> para continuar\n");
    getchar();
    getchar();
}