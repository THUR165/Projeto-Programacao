//fazer compras(add ao carrinho)(mostrar lista de produtos cadastrados pelo modulo funcionário)
//verificar compras/ tipo um extrato com valor.
//altera compras(mostrar tipo o carrinho)
// excluir produto da lista de compras(repor no estoque)
#include <stdio.h>
int mod_vendas(void){
    int op;
    printf("Modulo de Vendas \n");
    do{
        op = mod_venda();
        switch (op){
            case 1: printf("Comprar produto");
                break;
            case 2: printf("Verificar compras");
                break;
            case 3: printf("Alterar compras");
                break;
            case 4: printf("Excluir compras");
                break;
            case 5: printf("Relátorio");
        }
    }while (op !=0);
        tela_main();

    return 0;
    
}
   
 