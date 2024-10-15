#include <stdio.h>
#include "./interface.h"
/*

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
*/

int mod_func(void){
    int op;
    printf("Modulo Funcionario...");
    do{
        op = mod_func();
        switch (op){
            case 1: printf("Cadastrar Funcionario");
                break;
            case 2: printf("Exibir Informações");
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
    
}