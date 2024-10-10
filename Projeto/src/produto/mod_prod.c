#include <stdio.h>
#include "./interface.h"
int mod_prod(void){
    int op;
    printf("Modulo Funcionario...");
    do{
        op = mod_prod();
        switch (op){
            case 1: printf("Cadastrar Produto");
                break;
            case 2: printf("Verificar Produtos");
                break;
            case 3: printf("Alterar Produto");
                break;
            case 4: printf("Excluir produto");
                break;
            case 5: printf("Relátorio");
        }
    }while (op !=0);
        tela_main();

    return 0;
    
}