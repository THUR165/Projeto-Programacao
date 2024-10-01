#include <stdio.h>
#include <string.h>



//funções principais
void tela_principal(void);
//void tela_sobre(void);
//void tela_equipe(void);


//programa principal
int main(void){
    tela_principal();
    tela_sobre();
    tela_equipe();
}



void tela_principal(void){
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
    } else if (resp == 3){
        tela_sobre();
        tela_equipe();
    } else{
        printf("Resposta inválida. \n");
       
}     
}
