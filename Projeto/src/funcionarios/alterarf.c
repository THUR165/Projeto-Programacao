#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alterarf.h"

int alterarFuncionario(const char* nomeArquivo) {   
    FILE* fp; 
    Funcionario* funcArqv;  
    char cpf_pesquisado[12];
    int encontrado = 0;
    int valido = 0;  

    funcArqv = (Funcionario*)malloc(sizeof(Funcionario)); 
    if (funcArqv == NULL) {   //teste de alocação de memória
        printf("Erro de alocação de memória! \n");
        return 0;  //falha...
    }

    fp = fopen(nomeArquivo, "r+b");
    if (fp == NULL) {    //teste de abertura do arquivo
        perror("Erro ao abrir o arquivo");
        free(funcArqv);
        return 0; //falha...
    }

    printf("===================================================================\n");
    printf("=======                Alterar Funcionário           ==============\n");
    printf("===================================================================\n");
    printf("Digite novamente o CPF do funcionário que deseja alterar: \n");
    scanf("%11s", cpf_pesquisado); 
    getchar();

    //alterando os dados do funcionário
    while(fread(funcArqv, sizeof(Funcionario), 1, fp)) {
        if((strcmp(funcArqv->cpf, cpf_pesquisado) == 0) && (funcArqv->status == 1)) {
            encontrado = 1;

            //do while com menu para escolha de dados para alterar
            int opcao_alterar = 0;
            do{
                //exibir menu
                printf("============================================================\n");
                printf("=======   Quais dados do funcionário deseja alterar?   =====\n");
                printf("============================================================\n");
                printf("=======  1 - CPF \n");
                printf("=======  2 - Nome \n");
                printf("=======  3 - Data de nascimento \n");
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
                            scanf("%11s", funcArqv->cpf); 
                            getchar();

                            if (validar_cpf(funcArqv->cpf)) {
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
                            printf("Digite o nome atualizado do funcionário: ");
                            fgets(funcArqv->nome, sizeof(funcArqv->nome), stdin);       

                            funcArqv->nome[strcspn(funcArqv->nome, "\n")] = 0;
                
                            if (validar_nome(funcArqv->nome)) {
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
                        //Capturar data de nascimento
                        do{
                            valido = 0;
                            printf("Digite a data de nascimento do funcionario: ");
                            fgets(funcArqv->data_nascimento, sizeof(funcArqv->data_nascimento), stdin);       

                            funcArqv->data_nascimento[strcspn(funcArqv->data_nascimento, "\n")] = 0;

                            if (validar_data_nascimento(funcArqv->data_nascimento)) {
                                valido = 1;  
                            }else{
                                printf("=== Data de nascimento inválida!\n");
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
            if (fseek(fp, -1*sizeof(Funcionario), SEEK_CUR) != 0) { 
                perror("Erro ao posicionar o cursor\n");
                fclose(fp);
                free(funcArqv);
                return 0;  //Falha... return 0?
            } 

            if(fwrite(funcArqv, sizeof(Funcionario), 1, fp) != 1) {
                perror("Erro ao gravar a alteração do funcionário\n");
                fclose(fp);
                free(funcArqv);
                return 0; //Falha... return 0?
            }
            printf("======= Gravando funcionário com dados alterados... =======\n");
            break;
        }
    }
    if(!encontrado) {
        printf("======= O funcionário não foi encontrado =======\n");
        fclose(fp);
        free(funcArqv);
        return 0;
    }
    fclose(fp);
    free(funcArqv); 
    return 1; //Sucesso da função...
}