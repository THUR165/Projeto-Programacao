#include <stdio.h>
#include "./interface.h"

void mod_client(void){
    int op;
    printf("Modulo Clientes...");
    do{
        op = mod_func();
        switch (op){
            case 1: printf("Cadastrar Cliente");
                break;
            case 2: printf("Verificar Informações");
                break;
            case 3: printf("Alterar informações");
                break;
            case 4: printf("Excluir informações");
                break;
            case 5: printf("Relátorio");
        }
    }while (op !=0);
        tela_main();

    return 0;
    
    /*
    if (resp == 1 ){
        printf(" Cadastrar Clientes \n"); //função fazer compras
        //cadastrar.c
    } else if (resp == 2){
        printf(" Verificar Dados \n"); 
    } else{
        printf("Resposta inválida. \n");
    }
    */
    
}