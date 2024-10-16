#include <stdio.h>
#include <string.h>
#include "Projeto/interface.h"

//ERROR NA COPILAÇÃO/ NÃO TA CHAMANDO A FUNÇÃO DE TELA PRINCIPAL
//gcc -o programa Projeto/interface.o main.o (apenas atalho para testes)
//funções principais
//programa principal
int main(){
    int op;
    printf("Iniciando o programa...\n");
      do {
        op = tela_main();
        switch (op){
            case 1: tela_mod_cliente();
                    break;
            case 2: tela_mod_vendas();
                    break;
            case 3: tela_mod_func();
                    break;
            case 4: tela_mod_prod();
                    break;
            case 5: tela_mod_relat();
                    break;
            case 6: tela_info_proj();
                    break;    
        }
      }while (op !=0);
      printf("FIM DO PROGRAMA!\n");
      return 0;
}



