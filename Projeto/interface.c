#include <stdio.h>
#include "./include/funcoes.h"


void tela_sobre(){
    printf("\n");
    printf("===========================================================\n");
    printf("=====   Universidade Federal Rio Grande do Norte      =====\n");
    printf("=====   Diciplina Programação  codigo:DCT1106         =====\n");
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

}

void tela_equipe(){
    printf("\n");
    printf("===========================================================\n");
    printf("=====            Equipe de desenvolvimento            =====\n");
    printf("===========================================================\n");
    printf("=====            Leandro Sergio Da Silva              =====\n");
    printf("=====            Arthur De Medeiros Dantas            =====\n");
    printf("===========================================================\n");
}

int tela_principal(){
    int resp;
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
    scanf("%i", &resp);
    printf("===========================================================\n");
    if (resp == 1 ){
        printf(" Modulo Clientes \n");
        //mod_client(); //função fazer compras
    } else if (resp == 2){
        printf("Modulo Funcionário \n"); //function de cadastrar cliente
    } else if (resp == 4){
        tela_sobre();
        tela_equipe();
    } else{
        printf("Resposta inválida. \n");
       
}    
    return 0;
}