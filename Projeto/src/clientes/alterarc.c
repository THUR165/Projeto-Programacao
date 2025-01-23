#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alterarc.h"

int alterarCliente(const char* nomeArquivo) {   
    FILE* fp; 
    Cliente* clntArqv;  
    char cpf_pesquisado[12];
    int encontrado = 0;
    int valido = 0;  

    clntArqv = (Cliente*)malloc(sizeof(Cliente)); 
    if (clntArqv == NULL) {   //teste de alocação de memória
        printf("Erro de alocação de memória! \n");
        return 0;  //falha...
    }

    fp = fopen(nomeArquivo, "r+b");
    if (fp == NULL) {    //teste de abertura do arquivo
        perror("Erro ao abrir o arquivo");
        free(clntArqv);
        return 0; //falha...
    }

    printf("\n=========================================================\n");
    printf("=======               Alterar Cliente                ======\n");
    printf("===========================================================\n");
    printf("Digite novamente o CPF do cliente que deseja alterar: \n");
    scanf("%11s", cpf_pesquisado);  
    getchar();

    //char novo_nome [sizeof(prodArqv->nome)];

    //alterando os dados do produto
    while(fread(clntArqv, sizeof(Cliente), 1, fp)) {
        if((strcmp(clntArqv->cpf, cpf_pesquisado) == 0) && (clntArqv->status == 1)) {
            encontrado = 1;

            //do while com menu para escolha de dados para alterar
            int opcao_alterar = 0;
            do{
                //exibir menu
                printf("==========================================================\n");
                printf("=======   Quais dados do cliente deseja alterar?   =======\n");
                printf("==========================================================\n");
                printf("=======  1 - CPF \n");
                printf("=======  2 - Nome \n");
                printf("=======  3 - Data de nascimento \n");
                printf("=======  4 - Gênero \n");
                printf("=======  5 - Telefone \n");
                printf("=======  6 - Rua \n");
                printf("=======  7 - Número da casa \n");
                printf("=======  0 - Nenhum dado \n");
                printf("===========================================================\n");
                printf("Sua escolha: --> ");
                scanf("%d", &opcao_alterar);
                getchar();

                //alterando os dados
                switch(opcao_alterar) {
                    case 1: 
                        //Cpf
                        do{  
                            printf("Digite o novo CPF: ");
                            scanf("%11s", clntArqv->cpf); 
                            getchar();

                            if (validar_cpf(clntArqv->cpf)) {
                                valido = 1; 
                            } else {
                                printf("=== CPF inválido!\n");
                            }
                        } while(!valido);
                        break;
                    case 2:
                        do{     
                            //char novo_nome [sizeof(prodArqv->nome)];
                            valido = 0;
                            printf("Digite o nome atualizado do cliente: ");
                            fgets(clntArqv->nome, sizeof(clntArqv->nome), stdin);       

                            clntArqv->nome[strcspn(clntArqv->nome, "\n")] = 0;
                
                            if (validar_nome(clntArqv->nome)) {
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
                        //data de anscimento
                        do{
                            valido = 0;
                            printf("Digite a data de nascimento do cliente: ");
                            fgets(clntArqv->data_nascimento, sizeof(clntArqv->data_nascimento), stdin);       

                            clntArqv->data_nascimento[strcspn(clntArqv->data_nascimento, "\n")] = 0;

                            if (validar_data_nascimento(clntArqv->data_nascimento)) {
                                valido = 1;  
                            }else{
                                printf("=== Data de nascimento inválida!\n");
                            }
                        } while(!valido);
                        break;
                    case 4:
                        //gênero
                        printf("Digite o novo gênero do cliente: \n");
                        scanf("%9s", clntArqv->gen);
                        getchar();
                        break;
                    case 5: 
                        //telefone
                        printf("Digite o telefone do cliente: \n");
                        scanf("%15s", clntArqv->tel);
                        getchar();
                        break;
                    case 6:
                        //rua
                        printf("Digite a rua do cliente: \n");
                        scanf("%40s", clntArqv->rua);
                        getchar();
                        break;
                    case 7:
                        printf("Digite o número da casa do cliente: \n");
                        scanf("%6s", clntArqv->num);
                        getchar();
                        break;
                    case 0:
                        printf("Saindo...\n");
                        break;
                    default:
                        printf("Opção inválida. Tente novamente.\n");
                }

            } while(opcao_alterar != 0);

            //teste de fseek - posicionar cursor nos dados corretos, o teste é 1 ou 0?
            if (fseek(fp, -1*sizeof(Cliente), SEEK_CUR) != 0) { 
                perror("Erro ao posicionar o cursor\n");
                fclose(fp);
                free(clntArqv);
                return 0;  //Falha... return 0?
            } 

            if(fwrite(clntArqv, sizeof(Cliente), 1, fp) != 1) {
                perror("Erro ao gravar a alteração do cliente\n");
                fclose(fp);
                free(clntArqv);
                return 0; //Falha... return 0?
            }
            printf("======= Gravando cliente com dados alterados... =======\n");
            break;
        }
    }
    if(!encontrado) {
        printf("======= O cliente não foi encontrado =======\n");
        fclose(fp);
        free(clntArqv);
        return 0;
    }
    fclose(fp);
    free(clntArqv); 
    return 1; //Sucesso da função...
}