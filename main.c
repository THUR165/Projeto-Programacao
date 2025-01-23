#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include "Projeto/interface.h"
#include "Projeto/valida.h"
//testando rep
//assinatura para o modulo cliente

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
//assinatura para modulo vendas
#include "Projeto/src/vendas/alterarav.h"
#include "Projeto/src/vendas/cadastrarv.h"
#include "Projeto/src/vendas/excluirv.h"
#include "Projeto/src/vendas/verificarv.h"
//assinatura para modulo de relatorios
#include "Projeto/src/relatorios/relatorioc.h"
#include "Projeto/src/relatorios/relatoriof.h"
#include "Projeto/src/relatorios/relatoriop.h"
#include "Projeto/src/relatorios/relatoriov.h"


int main() {
    int op;

    printf("Iniciando o programa...\n");

    do {
        op = tela_main(); // Supomos que tela_main exibe o menu e retorna uma opção válida ou inválida
        if (op >= 0 && op <= 6) {  // Verifica se a opção está no intervalo esperado
            switch (op) {
                case 1:
                    tela_mod_cliente();
                    break;
                case 2:
                    tela_mod_vendas();
                    break;
                case 3:
                    tela_mod_func();
                    break;
                case 4:
                    tela_mod_prod();
                    break;
                case 5:
                    tela_mod_relat();
                    break;
                case 6:
                    tela_info_proj();
                    break;
                case 0:
                    printf("Saindo...\n");
                    break;
            }
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (op != 0);

    printf("FIM DO PROGRAMA!\n");
    return 0;
}
