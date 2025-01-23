#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../valida.h"
#include "alterarp.h"

/*O que pode ser feito: 
- usar buscarProduto antes de modificarProduto (parecido com a função de 'excluir' dos slides)? Não...
- acrescentar validações
- uso de mensagens padrão
*/

//retorna void ou int?
int alterarProduto(const char* nomeArquivo) {   
    FILE* fp; 
    Produto* prodArqv;  
    char codigo_pesquisado[6];
    int encontrado = 0;
    int valido = 0;  

    prodArqv = (Produto*)malloc(sizeof(Produto)); 
    if (prodArqv == NULL) {   //teste de alocação de memória
        printf("Erro de alocação de memória! \n");
        return 0;  //falha...
    }

    fp = fopen(nomeArquivo, "r+b");
    if (fp == NULL) {    //teste de abertura do arquivo
        perror("Erro ao abrir o arquivo");
        free(prodArqv);
        return 0; //falha...
    }

    printf("\n=========================================================\n");
    printf("=======               Alterar Produto                ======\n");
    printf("===========================================================\n");
    printf("Digite novamente o codigo de barras do produto que deseja alterar: \n");
    scanf("%5s", codigo_pesquisado);  //validar codigo aqui tbm? Não precisa...
    getchar();

    //char novo_nome [sizeof(prodArqv->nome)];

    //alterando os dados do produto
    while(fread(prodArqv, sizeof(Produto), 1, fp)) {
        if((strcmp(prodArqv->cod_barras, codigo_pesquisado) == 0) && (prodArqv->status == 1)) {
            encontrado = 1;

            //do while com menu para escolha de dados para alterar
            int opcao_alterar = 0;
            do{
                //exibir menu
                printf("==========================================================\n");
                printf("=======   Quais dados do produto deseja alterar?   =======\n");
                printf("==========================================================\n");
                printf("=======  1 - Código de barras \n");
                printf("=======  2 - Nome \n");
                printf("=======  3 - Marca \n");
                printf("=======  4 - Preço \n");
                printf("=======  5 - Categoria \n");
                printf("=======  6 - Data de validade \n");
                printf("=======  0 - Nenhum dado \n");
                printf("===========================================================\n");
                printf("Sua escolha: --> ");
                scanf("%d", &opcao_alterar);
                getchar();

                //alterando os dados
                switch(opcao_alterar) {
                    case 1: 
                        //Código de barras
                        do{  
                            printf("Digite o novo código de barra: ");
                            scanf("%5s", prodArqv->cod_barras); 
                            getchar();

                            if (validar_codigo(prodArqv->cod_barras)) {
                                valido = 1; 
                            } else {
                                printf("=== Código de barras inválido!\n");
                            }
                        } while(!valido);
                        break;
                    case 2:
                        do{     
                            //char novo_nome [sizeof(prodArqv->nome)];
                            valido = 0;
                            printf("Digite o nome atualizado do produto: ");
                            fgets(prodArqv->nome, sizeof(prodArqv->nome), stdin);       

                            prodArqv->nome[strcspn(prodArqv->nome, "\n")] = 0;
                
                            if (validar_nome(prodArqv->nome)) {
                                valido = 1;
                                //strcpy(prodArqv->nome, novo_nome);
                                printf("======= Nome alterado! =======\n");
                            }else{
                                printf("---> Nome inválido!\n");
                            }
                        }while(!valido);
                        /*strcpy(prodArqv->nome, novo_nome);
                        printf("======= Nome alterado! =======\n");*/
                        break;
                    case 3:
                        //Capturar marca
                        do{
                            valido = 0;
                            printf("Digite a nova marca do produto: ");
                            fgets(prodArqv->marca, sizeof(prodArqv->marca), stdin);       

                            prodArqv->marca[strcspn(prodArqv->marca, "\n")] = 0;

                            if (validar_marca(prodArqv->marca)) {
                                valido = 1;  //??
                            }else{
                                printf("=== Nome de marca inválido!\n");
                            }
                        } while(!valido);
                        break;
                    case 4:
                        //Capturar preço
                        do{   
                            valido = 0;
                            printf("Digite o preço do produto: R$ ");
                            scanf("%f", &prodArqv->preco);            //como é float, põe o '&'
                            getchar();

                            if (validar_preco(prodArqv->preco)) {
                                valido = 1;
                            } else {
                                printf("=== Preço inválido!\n");
                            }
                        } while(!valido);
                        break;
                    case 5: 
                        //Capturar categoria
                        do{
                            valido = 0;
                            printf("Digite a categoria do produto: ");
                            fgets(prodArqv->categoria, sizeof(prodArqv->categoria), stdin);       

                            prodArqv->categoria[strcspn(prodArqv->categoria, "\n")] = 0;

                            if (validar_categoria(prodArqv->categoria)) {
                                valido = 1;  //??
                            }else{
                                printf("=== Nome de categoria inválido!\n");
                            }
                        } while(!valido);
                        break;
                    case 6:
                        //Capturar data de validade
                        do{
                            valido = 0;
                            printf("Digite a data de validade do produto: ");
                            fgets(prodArqv->data_validade, sizeof(prodArqv->data_validade), stdin);       

                            prodArqv->data_validade[strcspn(prodArqv->data_validade, "\n")] = 0;

                            if (validar_data_validade(prodArqv->data_validade)) {
                                valido = 1;  //??
                            }else{
                                printf("=== Data de validade inválida!\n");
                            }
                        } while(!valido);
                        break;
                    case 0:
                        printf("Saindo...\n");
                        break;
                    default:
                        printf("Opção inválida. Tente novamente.\n");
                }

            } while(opcao_alterar != 0);

            //teste de fseek - posicionar cursor nos dados corretos, o teste é 1 ou 0?
            if (fseek(fp, -1*sizeof(Produto), SEEK_CUR) != 0) { 
                perror("Erro ao posicionar o cursor\n");
                fclose(fp);
                free(prodArqv);
                return 0;  //Falha... return 0?
            } 

            if(fwrite(prodArqv, sizeof(Produto), 1, fp) != 1) {
                perror("Erro ao gravar a alteração do produto\n");
                fclose(fp);
                free(prodArqv);
                return 0; //Falha... return 0?
            }
            printf("======= Gravando produto com dados alterados... =======\n");
            break;
        }
    }
    if(!encontrado) {
        printf("======= O produto não foi encontrado =======\n");
        fclose(fp);
        free(prodArqv);
        return 0;
    }
    fclose(fp);
    free(prodArqv); 
    return 1; //Sucesso da função...
}