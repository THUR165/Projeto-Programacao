#include <stdio.h>
#include <stdlib.h>


//funções principais
int tela_main(void);
int mod_vendas(void);
int info_proj(void);
int mod_func(void);
int mod_prod(void);
void tela_funcionario(void);
int mod_client(void);
void tela_cadastrarp(void);
void cadastrar_produto(void);
void exibir_produto(void);
void modificar_produto(void);
void excluir_produto(void);
void cadastrar_funcionario(void);
void exibir_funcionario(void);
void modificar_funcionario(void);
void excluir_funcionario(void);


//programa principal
int chamada(void){
    tela_main();
    mod_vendas();
    info_proj();
    mod_func();
    mod_prod();
    mod_func();
    mod_client();
    tela_cadastrarp();
    cadastrar_produto();
    exibir_produto();
    modificar_produto();
    excluir_produto();
    cadastrar_funcionario();
    exibir_funcionario();
    modificar_funcionario();
    excluir_funcionario();

    return 0;
}

int main(){
    int op;
    printf("Iniciando o programa...\n");
      do {
        op = tela_main();
        switch (op){
            case 1: mod_client();
                    break;
            case 2: mod_vendas();
                    break;
            case 3: mod_func();
                    break;
            case 4: mod_prod();
                    break;
            case 5: info_proj();
                    break;
            
        }
      }while (op !=0);
      printf("FIM DO PROGRAMA!\n");
      return 0;
}

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
    printf("=====                [4] - Produto                    =====\n");
    printf("=====                [5] - Sobre o Projeto            =====\n");
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


int mod_client(void){
    int resp;
    printf("\n");
    printf("===========================================================\n");
    printf("===                SIG-Building                       =====\n");
    printf("===========================================================\n");
    printf("===    Sistema de gestão de material de construção    =====\n");
    printf("===========================================================\n");
    printf("===                [1] - Cadastrar Clientes           =====\n");
    printf("===                [2] - Verificar Dados              =====\n");
    printf("===                [3] - Alterar Dados                =====\n");
    printf("===                [4] - Excluir Dados                =====\n");
    printf("===                [5] - Relatório                    =====\n");
    printf("===                [0] - Sair                         =====\n");
    scanf("%i", &resp);
    printf("===========================================================\n");
    if (resp == 1 ){
        printf(" Cadastrar Clientes \n"); //função fazer compras
        //cadastrar.c
    } else if (resp == 2){
        printf(" Verificar Dados \n"); 
    } else{
        printf("Resposta inválida. \n");
    }
    return 0;
}

void tela_cadastrarp(void){
    int resp;
    printf("\n");
    printf("===========================================================\n");
    printf("===                SIG-Building                       =====\n");
    printf("===========================================================\n");
    printf("===    Sistema de gestão de material de construção    =====\n");
    printf("===========================================================\n");
    printf("===                [1] - Comprar produtos             =====\n");
    printf("===                [2] - Verificar Compras            =====\n");
    printf("===                [3] - Alterar Compras              =====\n");
    printf("===                [4] - Excluir Compras              =====\n");
    printf("===                [5] - Relatório                    =====\n");
    printf("===                [0] - Sair                         =====\n");
    scanf("%i", &resp);
    printf("===========================================================\n");
    if (resp == 1 ){
        printf(" Cadastrar Clientes \n"); //função fazer compras
        //cadastrar.c
    } else if (resp == 2){
        printf(" Verificar Dados \n"); 
    } else{
        printf("Resposta inválida. \n");
    }
    
}


int info_proj(){
    int op;
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
    scanf("%i", &op);
    printf("===                [0] - Sair                         =====\n");
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

void cadastrar_produto(void){
    printf("\n");
    printf("===========================================================\n");
    printf("======═             cadastrar produto                ======\n");
    printf("===========================================================\n");
    printf("======═            codigo de barra:(inserir)(chave)  ======\n");
    printf("======═            nome do produto:(inserir)         ======\n");
    printf("======═            preço do produto:(inserir)        ======\n");
    printf("===========================================================\n");
}

void exibir_produto(void){
    printf("\n");
    printf("===========================================================\n");
    printf("======═                 exibir produto               ======\n");
    printf("===========================================================\n");
    printf("======═            codigo de barra:(chave)           ======\n");
    printf("======═            mostrar(nome do produto)          ======\n");
    printf("======═            mostrar(preço do produto)         ======\n");
    printf("===========================================================\n");
}

void modificar_produto(void){
    printf("\n");
    printf("===========================================================\n");
    printf("======═             modificar produto                ======\n");
    printf("===========================================================\n");
    printf("======═            codigo de barra:(chave)           ======\n");
    printf("======═            modificar(nome do produto)        ======\n");
    printf("======═            modificar(preço do produto)       ======\n");
    printf("===========================================================\n");
}

void excluir_produto(void){
    printf("\n");
    printf("===========================================================\n");
    printf("======═             excluir produto                  ======\n");
    printf("===========================================================\n");
    printf("======═            codigo de barra:(chave)           ======\n");
    printf("======═            (verificar se sim ou nao)         ======\n");
    printf("======═            caso sim excluir(nome do produto) ======\n");
    printf("======═            caso sim excluir(preço do produto)======\n");
    printf("===========================================================\n");
}

void tela_funcionario(void){
    printf("\n");
    printf("===========================================================\n");
    printf("======═                Funcionario                   ======\n");
    printf("===========================================================\n");
    printf("======═         [1]-cadastrar Funcionario            ======\n");
    printf("======═         [2]-Exibir Funcionarios              ======\n");
    printf("======═         [3]-modificar Funcionario            ======\n");
    printf("======═         [4]-Excluir Funcionario              ======\n");
    printf("======═         [0]-sair                             ======\n");
    printf("===========================================================\n");
    printf("===========================================================\n");
    printf("===========================================================\n");
}

void cadastrar_funcionario(void){
    printf("\n");
    printf("===========================================================\n");
    printf("=======             cadastrar funcionario            ======\n");
    printf("===========================================================\n");
    printf("=======            CPF:(inserir)(chave)              ======\n");
    printf("=======            nome do Funcionario:(inserir)     ======\n");
    printf("=======            data de nacimento:(inserir)       ======\n");
    printf("===========================================================\n");
}

void exibir_funcionario(void){
    printf("\n");
    printf("===========================================================\n");
    printf("=======             exibir funcionario               ======\n");
    printf("===========================================================\n");
    printf("=======            CPF:(inserir)(chave)              ======\n");
    printf("=======            mostrar(nome do Funcionario)      ======\n");
    printf("=======            mostrar(data de nacimento)        ======\n");
    printf("===========================================================\n");
}

void modificar_funcionario(void){
    printf("\n");
    printf("===========================================================\n");
    printf("=======             modificar funcionario            ======\n");
    printf("===========================================================\n");
    printf("=======            CPF:(inserir)(chave)              ======\n");
    printf("=======            mostrar(nome do Funcionario)      ======\n");
    printf("=======            mostrar(data de nacimento)        ======\n");
    printf("=======            Perguntar se que modificar(S/N)   ======\n");
    printf("===========================================================\n");
}

void excluir_funcionario(void){
    printf("\n");
    printf("===========================================================\n");
    printf("=======             excluir funcionario              ======\n");
    printf("===========================================================\n");
    printf("=======            CPF:(inserir)(chave)              ======\n");
    printf("=======            mostrar(nome do Funcionario)      ======\n");
    printf("=======            mostrar(data de nacimento)        ======\n");
    printf("=======            Perguntar se que excluir(S/N)     ======\n");
    printf("===========================================================\n");
}