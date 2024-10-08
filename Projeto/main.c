#include <stdio.h>
#include <string.h>
#include "./include/interface.h"

//ERROR NA COPILAÇÃO/ NÃO TA CHAMANDO A FUNÇÃO DE TELA PRINCIPAL

//funções principais
//programa principal
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



