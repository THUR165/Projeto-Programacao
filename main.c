#include <stdio.h>
#include <string.h>
#include "Projeto/interface.h"
//assinatura para o modulo cliente
#include "Projeto/src/clientes/alterarc.h"
#include "Projeto/src/clientes/cadastrarc.h"
#include "Projeto/src/clientes/excluirc.h"
#include "Projeto/src/clientes/verificarc.h"
//assinatura para o modulo funcionario
#include "Projeto/src/funcionarios/alterarf.h"
#include "Projeto/src/funcionarios/cadastrarf.h"
#include "Projeto/src/funcionarios/excluirf.h"
#include "Projeto/src/funcionarios/verificarf.h"
//assinatura para modulo produtos
#include "Projeto/src/produto/alterarp.h"
#include "Projeto/src/produto/excluirp.h"
#include "Projeto/src/produto/cadastrarp.h"
#include "Projeto/src/produto/verificarp.h"

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



