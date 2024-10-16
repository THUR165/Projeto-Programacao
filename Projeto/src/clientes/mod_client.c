#include <stdio.h>
#include <string.h>
#include "Projeto/interface.h"
#include "cadastrarc.h"

//ERROR NA COPILAÇÃO/ NÃO TA CHAMANDO A FUNÇÃO DE TELA PRINCIPAL

//funções principais
//programa principal
int mod_client(){
    int op;
      do {
        op = tela_mod_cliente();
        switch (op){
            case 1: clientes();
                    break;
        }
      }while (op !=0);
      printf("FIM DO PROGRAMA!\n");
      return 0;
}



