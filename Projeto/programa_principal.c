#include <stdio.h>
#include <stdlib.h>

/*
#include <stdio.h>
char nome[21];
float alt;
float peso;
float imc;

void main(void){   
    printf("Qual o seu nome? ");
    scanf("%c", &nome);
    printf("Digite sua Altura: ");
    scanf("%f",alt);
    printf("Qual o seu peso? ");
    scanf("%f",&peso);

    printf("Seu imc é: %.f",imc);
    
    
// peso / altura**2
}


*/



//funções principais
void tela_client(void);
void tela_sobre(void);
void tela_equipe(void);
void modulo_funcionario(void);
void tela_produto(void);
void tela_funcionario(void);
void tela_cadastrarc(void);
void tela_cadastrarp(void);
void cadastrar_produto(void);


//programa principal
int main(void){
    tela_client();
    tela_sobre();
    tela_equipe();
    modulo_funcionario();
    tela_produto();
    tela_funcionario();
    tela_cadastrarc();
    tela_cadastrarp();
    cadastrar_produto();
}


#include <stdio.h>
void tela_client(void){
    int resp;
    printf("\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══                SIG-Building                       ═════\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══    Sistema de gestão de material de construção    ═════\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══                [1] - Cadastrar Clientes           ═════\n");
    printf("═══                [2] - Fazer Compras                ═════\n");
    scanf("%i", &resp);
    printf("═══════════════════════════════════════════════════════════\n");
    if (resp == 1 ){
        printf(" Modulo Clientes \n");
        //cad_client(); //função fazer compras
    } else if (resp == 2){
        printf("Modulo Funcionário \n"); //function de cadastrar cliente
    } else{
        printf("Resposta inválida. \n");
    }
    
}

void tela_cadastrarc(void){
    int resp;
    printf("\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══                SIG-Building                       ═════\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══    Sistema de gestão de material de construção    ═════\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══                [1] - Cadastrar Clientes           ═════\n");
    printf("═══                [2] - Verificar Dados              ═════\n");
    printf("═══                [3] - Alterar Dados                ═════\n");
    printf("═══                [4] - Excluir Dados                ═════\n");
    printf("═══                [5] - Relatório                    ═════\n");
    printf("═══                [0] - Sair                         ═════\n");
    scanf("%i", &resp);
    printf("═══════════════════════════════════════════════════════════\n");
    if (resp == 1 ){
        printf(" Cadastrar Clientes \n"); //função fazer compras
        //cadastrar.c
    } else if (resp == 2){
        printf(" Verificar Dados \n"); 
    } else{
        printf("Resposta inválida. \n");
    }
    
}

void tela_cadastrarp(void){
    int resp;
    printf("\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══                SIG-Building                       ═════\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══    Sistema de gestão de material de construção    ═════\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══                [1] - Comprar produtos             ═════\n");
    printf("═══                [2] - Verificar Compras            ═════\n");
    printf("═══                [3] - Alterar Compras              ═════\n");
    printf("═══                [4] - Excluir Compras              ═════\n");
    printf("═══                [5] - Relatório                    ═════\n");
    printf("═══                [0] - Sair                         ═════\n");
    scanf("%i", &resp);
    printf("═══════════════════════════════════════════════════════════\n");
    if (resp == 1 ){
        printf(" Cadastrar Clientes \n"); //função fazer compras
        //cadastrar.c
    } else if (resp == 2){
        printf(" Verificar Dados \n"); 
    } else{
        printf("Resposta inválida. \n");
    }
    
}

//void clientes(void){
    //printf("Modulo Clientes \n");
    /*
    char resp[1];
    printf("Já possui cadastro de Cliente? S/N: \n");
    scanf("%c", &resp);
    if (resp == "S" || resp == "s"){
        printf("Fazer Compras"); //função fazer compras
    } else if (resp == "N"  || resp == "n"){
        printf("Cadastramento de Cliente\n"); //function de cadastrar cliente
    } else{
        printf("Resposta inválida. \n");
    }
    
     */
    

void tela_sobre(void){
    printf("\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══   Universidade Federal Rio Grande do Norte        ═════\n");
    printf("═══   Diciplina Programação  codigo:DCT1106           ═════\n");
    printf("═══               Programa de Gestão                  ═════\n");
    printf("═══   Para uma Loja de Material de Construção         ═════\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══   O Projeto tem o objetivo Criar um programa      ═════\n");
    printf("═══   de Gestão para uma Loja de Materais             ═════\n");
    printf("═══   de Construção,tem como objetivo ajudar na       ═════\n");
    printf("═══   administração da loja,sendo possivel administar ═════\n");
    printf("═══   produtos,vendas,clientes,funcionarios e tambem  ═════\n");
    printf("═══   relatorios                                      ═════\n");
    printf("═══════════════════════════════════════════════════════════\n");

}

void tela_equipe(void){
    printf("\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══            Equipe de desenvolvimento              ═════\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══            Leandro Sergio Da Silva                ═════\n");
    printf("═══            Arthur De Medeiros Dantas              ═════\n");
    printf("═══════════════════════════════════════════════════════════\n");
}

void modulo_funcionario(void){
    printf("\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══════            Modulo Funcionario                ══════\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══════         1-produtos                           ══════\n");
    printf("═══════         2-Funcionarios                       ══════\n");
    printf("═══════         0-sair                               ══════\n");
    printf("═══════════════════════════════════════════════════════════\n");
}

void tela_produto(void){
    printf("\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══════                Produto                       ══════\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══════         1-cadastrar produto                  ══════\n");
    printf("═══════         2-exibir produto                     ══════\n");
    printf("═══════         3-modificar produto                  ══════\n");
    printf("═══════         4-excluir produto                    ══════\n");
    printf("═══════         0- sair                              ══════\n");
    printf("═══════════════════════════════════════════════════════════\n");
}

void cadastrar_produto(void){
    printf("\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══════             cadastrar produto                ══════\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══════            codigo de barra:(inserir)(chave)  ══════\n");
    printf("═══════            nome do produto:(inserir)         ══════\n");
    printf("═══════            preço do produto:(inserir)        ══════\n");
    printf("═══════════════════════════════════════════════════════════\n");
}

void tela_funcionario(void){
    printf("\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══════                Funcionario                   ══════\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══════         1-cadastrar Funcionario              ══════\n");
    printf("═══════         2-Exibir Funcionarios                ══════\n");
    printf("═══════         3-modificar Funcionario              ══════\n");
    printf("═══════         4-Excluir Funcionario                ══════\n");
    printf("═══════         0-sair                               ══════\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══════════════════════════════════════════════════════════\n");
    printf("═══════════════════════════════════════════════════════════\n");
}