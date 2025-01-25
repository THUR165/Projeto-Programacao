#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "interface.h"


const char* arquivoCliente = "clientes.dat";
const char* arquivoVenda = "vendas.dat";
const char* arquivoFuncionario = "funcionarios.dat";
const char* arquivoProduto = "produtos.dat";


int tela_main(void){    
    int op;
    printf("\n");
    printf("===========================================================\n");
    printf("=====                SIG-Building                     =====\n");
    printf("===========================================================\n");
    printf("=====    Sistema de gestão de material de construção  =====\n");
    printf("===========================================================\n");
    printf("=====                [1] - Clientes                   =====\n");
    printf("=====                [2] - Vendas                     =====\n");
    printf("=====                [3] - Funcionário                =====\n");
    printf("=====                [4] - Produto                    =====\n");
    printf("=====                [5] - Relatório                  =====\n");
    printf("=====                [6] - Sobre o Projeto            =====\n");
    printf("=====                [0] - Sair                       =====\n");
    printf("===========================================================\n");
    printf("Sua Escolha: --> ");

    if (scanf("%d", &op) != 1) {  // Valida se a entrada foi um número
        while (getchar() != '\n');  // Limpa o buffer de entrada
        return -1;  // Retorna um valor fora do intervalo esperado para indicar erro
    }

    return op;
}


void tela_mod_cliente(void) {
    Cliente* cliente;
    //char arquivo[] = "produtos.dat";
    //const char* arquivoCliente = "clientes.dat"; 
    
    
    int op;

    do {
        printf("\n===========================================================\n");
        printf("===                Módulo de Clientes                =====\n");
        printf("===========================================================\n");
        printf("===    [1] - Cadastrar Clientes                      ===\n");
        printf("===    [2] - Exibir Clientes                         ===\n");
        printf("===    [3] - Modificar Clientes                      ===\n");
        printf("===    [4] - Excluir Clientes                        ===\n");
        printf("===    [0] - Voltar ao Menu Principal                ===\n");
        printf("===========================================================\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &op) != 1) {
            printf("Entrada inválida! Por favor, insira um número.\n");
            while (getchar() != '\n');  // Limpa o buffer
            continue;  // Retorna ao início do loop
        }

        if (op >= 0 && op <= 4) {
            switch (op) {
                case 1:
                    cliente = preencherCliente();
                    if (cliente == NULL) {   //testa se retorno é NULL
                        printf("======= Erro ao preencher os dados do cliente. =======\n");
                        printf("=======      O cliente não foi cadastrado!     =======\n");
                        printf("======================================================\n");
                    } else {  
                        exibirCliente(cliente);
                        char resposta;

                        printf("==== Tem certeza que deseja cadastrar esse cliente? Sim -> digite S; Não -> digite N: \n");  //conferindo os dados
                        scanf("%c", &resposta);
                        getchar();

                        int retorno = 0;
                        if (resposta == 'S' || resposta == 's') {
                            retorno = gravarCliente(arquivoCliente, cliente);   //dados confirmados, gravação
                            if (retorno == 0) {
                                printf("=======    O cliente não foi cadastrado!   =======\n");
                                printf("==================================================\n");
                            } else {
                                printf("======= Cliente cadastrado com sucesso! =======\n");
                                printf("===============================================\n"); 
                            } 
                        } else {   //dados incorretos
                            printf("==== Dados incorretos! O cliente não foi cadastrado! ====\n");
                            printf("=========================================================\n");
                        }
                    } 
                    free(cliente);  //libera produto
                    break;
                case 2: 
                    cliente = buscarCliente(arquivoCliente);   //2 opções: buscar clnt e exibir em uma só, a outra volta a posição... 
                    if (cliente == NULL) {       //busco cliente; se for NULL, não vai pra exibir...
                        printf("======= O cliente não foi encontrado! =======\n");
                        printf("=============================================\n");
                    } else {
                        printf("======= Cliente encontrado com sucesso! =======\n");
                        printf("===============================================\n");
                        exibirCliente(cliente); //exibe dados do clnt
                    }
                    free(cliente);  //libera
                    break;
                case 3:
                    cliente = buscarCliente(arquivoCliente); 
                    if (cliente == NULL) {  //testa se clnt retornado é NULL
                        printf("======= Cliente não encontrado! =======\n");
                        printf("=======================================\n");
                    } else {
                        exibirCliente(cliente);  //exibe clnt
                        char resposta;

                        printf("==== Tem certeza que deseja alterar esse cliente? Sim -> digite S; Não -> digite N: \n");  //conferindo os dados
                        scanf("%c", &resposta);
                        getchar();

                        int retorno = 0;
                        if (resposta == 'S' || resposta == 's') {
                            retorno = alterarCliente(arquivoCliente);   //dados confirmados, alteração  
                            if (retorno == 0) {
                                printf("======= Erro: o cliente não foi alterado! =======\n");
                                printf("=================================================\n");
                            } else {
                                printf("======= Cliente alterado com sucesso! =======\n");
                                printf("=============================================\n"); //mudando pra testes...
                                
                            }
                        } else {   //dados incorretos
                            printf("=======  Dados incorrretos: O cliente não foi alterado!  =======\n");
                            printf("================================================================\n");
                        }
                    }
                    free(cliente); //libera...
                    break;
                case 4:
                    cliente = buscarCliente(arquivoCliente); 
                    if (cliente == NULL) {             //testa se clnt retornado é NULL
                        printf("=======   Cliente não encontrado!    =======\n");
                        printf("=============================================\n");
                    } else {
                        exibirCliente(cliente);   //exibe
                        char resposta;

                        printf("==== Tem certeza que deseja excluir esse cliente? Sim -> digite S; Não -> digite N: \n");  //conferindo os dados
                        scanf("%c", &resposta);
                        getchar();

                        int retorno = 0; //AQUI AGORA: ajeitar função de excluir
                        if (resposta == 'S' || resposta == 's') {
                            retorno = excluirCliente(arquivoCliente);   //dados confirmados, exclusão    
                            if (retorno == 0) {
                                printf("======= Erro: o cliente não foi excluído! =======\n");
                                printf("=================================================\n");
                            } else {
                                printf("======= Cliente excluído com sucesso! =======\n");
                                printf("=============================================\n"); 
                            }
                        } else {   //dados incorretos
                            printf("======= Dados incorretos: O cliente não foi excluído! =======\n");
                            printf("=============================================================\n");
                        }
                    }
                    free(cliente);  //libera
                    break;
                case 0:
                    printf("Voltando ao Menu Principal...\n");
                    break;
            }
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (op != 0);
}

void tela_mod_vendas(void) {
    Venda* venda;
    //const char* arquivoVenda = "vendas.dat";

    int op;
    do {
        printf("\n");
        printf("===========================================================\n");
        printf("=====                SIG-Building                     =====\n");
        printf("===========================================================\n");
        printf("=====    Sistema de gestão de material de construção  =====\n");
        printf("===========================================================\n");
        printf("=====                [1] - Comprar produtos           =====\n");
        printf("=====                [2] - Verificar Compras          =====\n");
        printf("=====                [0] - Sair                       =====\n");
        printf("===========================================================\n");

        printf("Escolha uma opção: ");

        if (scanf("%d", &op) != 1) {  // Verifica se a entrada é um número
            printf("Entrada inválida! Por favor, insira um número.\n");
            while (getchar() != '\n');  // Limpa o buffer de entrada
            continue;  // Retorna ao início do loop
        }

        if (op >= 0 && op <= 4) {  // Verifica se a opção está no intervalo permitido
            switch (op) {
                case 1:
                    venda = preencherVenda();
                if (venda == NULL) {   //testa se  retorno é NULL
                    printf("======= Erro ao preencher os dados da venda. =======\n");
                    printf("=======      A venda não foi cadastrada!     =======\n");
                    printf("======================================================\n");
                } else {  
                    exibirVenda(venda);
                    char resposta;

                    printf("==== Tem certeza que deseja cadastrar essa venda? Sim -> digite S; Não -> digite N: \n");  //conferindo os dados
                    scanf("%c", &resposta);
                    getchar();

                    int retorno = 0;
                    if (resposta == 'S' || resposta == 's') {
                        retorno = gravarVenda(arquivoVenda, venda);   //dados confirmados, gravação
                        if (retorno == 0) {
                            printf("=======    A venda não foi cadastrada!   =======\n");
                            printf("==================================================\n");
                        } else {
                            printf("=======   Venda cadastrada com sucesso! =======\n");
                            printf("===============================================\n"); 
                        } 
                    } else {   //dados incorretos
                        printf("==== Dados incorretos! A venda não foi cadastrada! ====\n");
                        printf("=========================================================\n");
                    }
                } 
                free(venda);  //libera produto
                break;
            case 2:
                venda = buscarVenda(arquivoVenda);    
                if (venda == NULL) {      
                    printf("=======   A venda não foi encontrada! =======\n");
                    printf("=============================================\n");
                } else {
                    printf("======= A venda foi encontrada com sucesso! =======\n");
                    printf("===================================================\n");
                    exibirVenda(venda); //exibe dados do produto
                }
                free(venda);  //libera
                break;
            case 0:
                printf("Voltando ao Menu Principal...\n");
                break;
                
            }
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (op != 0);
    
}

void tela_mod_func(void){
    Funcionario* funcionario;
    //const char* arquivoFuncionario = "funcionarios.dat";

    int op;
    do {
        printf("\n===========================================================\n");
        printf("===               Módulo de Funcionários              =====\n");
        printf("===========================================================\n");
        printf("===    [1] - Cadastrar Funcionário                   ===\n");
        printf("===    [2] - Exibir Funcionários                     ===\n");
        printf("===    [3] - Modificar Funcionário                   ===\n");
        printf("===    [4] - Excluir Funcionário                     ===\n");
        printf("===    [0] - Voltar ao Menu Principal                ===\n");
        printf("===========================================================\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &op) != 1) {  // Verifica se a entrada é um número
            printf("Entrada inválida! Por favor, insira um número.\n");
            while (getchar() != '\n');  // Limpa o buffer de entrada
            continue;  // Retorna ao início do loop
        }
        if (op >= 0 && op <= 4){
            switch(op){
            case 1:
                funcionario = preencherFuncionario();
                if (funcionario == NULL) {   //testa se  retorno é NULL
                    printf("======= Erro ao preencher os dados do funcionário. =======\n");
                    printf("=======      O funcionário não foi cadastrado!     =======\n");
                    printf("======================================================\n");
                } else {  
                    exibirFuncionario(funcionario);
                    char resposta;

                    printf("==== Tem certeza que deseja cadastrar esse funcionário? Sim -> digite S; Não -> digite N: \n");  //conferindo os dados
                    scanf("%c", &resposta);
                    getchar();

                    int retorno = 0;
                    if (resposta == 'S' || resposta == 's') {
                        retorno = gravarFuncionario(arquivoFuncionario, funcionario);   //dados confirmados, gravação
                        if (retorno == 0) {
                            printf("=======    O funcionário não foi cadastrado!   =======\n");
                            printf("==================================================\n");
                        } else {
                            printf("======= Funcionário cadastrado com sucesso! =======\n");
                            printf("===============================================\n"); 
                        } 
                    } else {   //dados incorretos
                        printf("==== Dados incorretos! O funcionário não foi cadastrado! ====\n");
                        printf("=========================================================\n");
                    }
                } 
                free(funcionario);  //libera produto
                break;
            case 2:
                funcionario = buscarFuncionario(arquivoFuncionario);    
                if (funcionario == NULL) {      
                    printf("======= O funcionário não foi encontrado! =======\n");
                    printf("=============================================\n");
                } else {
                    printf("======= Funcionário encontrado com sucesso! =======\n");
                    printf("===============================================\n");
                    exibirFuncionario(funcionario); //exibe dados do produto
                }
                free(funcionario);  //libera
                break;
            case 3:
                funcionario = buscarFuncionario(arquivoFuncionario); 
                if (funcionario == NULL) {  //testa se retorno é NULL
                    printf("======= Funcionário não encontrado! =======\n");
                    printf("=======================================\n");
                } else {
                    exibirFuncionario(funcionario);  //exibe 
                    char resposta;

                    printf("==== Tem certeza que deseja alterar esse funcionário? Sim -> digite S; Não -> digite N: \n");  //conferindo os dados
                    scanf("%c", &resposta);
                    getchar();

                    int retorno = 0;
                    if (resposta == 'S' || resposta == 's') {
                        retorno = alterarFuncionario(arquivoFuncionario);   //dados confirmados, alteração  
                        if (retorno == 0) {
                            printf("======= Erro: o funcionário não foi alterado! =======\n");
                            printf("=================================================\n");
                        } else {
                            printf("======= Funcionário alterado com sucesso! =======\n");
                            printf("=============================================\n"); //mudando pra testes...
                            
                        }
                    } else {   //dados incorretos
                        printf("=======  Dados incorrretos: O funcionário não foi alterado!  =======\n");
                        printf("================================================================\n");
                    }
                }
                free(funcionario); //libera...
                break;
            case 4:
                funcionario = buscarFuncionario(arquivoFuncionario); 
                if (funcionario == NULL) {             
                    printf("=======    Funcionário não encontrado!    =======\n");
                    printf("=============================================\n");
                } else {
                    exibirFuncionario(funcionario);   //exibe 
                    char resposta;

                    printf("==== Tem certeza que deseja excluir esse funcionário? Sim -> digite S; Não -> digite N: \n");  //conferindo os dados
                    scanf("%c", &resposta);
                    getchar();

                    int retorno = 0; //AQUI AGORA: ajeitar função de excluir
                    if (resposta == 'S' || resposta == 's') {
                        retorno = excluirFuncionario(arquivoFuncionario);   //dados confirmados, exclusão    
                        if (retorno == 0) {
                            printf("======= Erro: o funcionário não foi excluído! =======\n");
                            printf("=================================================\n");
                        } else {
                            printf("======= Funcionário excluído com sucesso! =======\n");
                            printf("=============================================\n"); 
                        }
                    } else {   //dados incorretos
                        printf("======= Dados incorretos: O funcionário não foi excluído! =======\n");
                        printf("=============================================================\n");
                    }
                }
                free(funcionario);  //libera
                break;
            case 0:
                printf("Voltando ao Menu Principal...\n");
                break;
            }
        }else {
            printf("Opção inválida! Tente novamente.\n");
        }
        
    } while(op != 0);
}

void tela_mod_prod(void) {
    Produto* produto;
    //char arquivo[] = "produtos.dat";
    //const char* nomeArquivo = "produtos.dat";  
     
    int op;
    do {
        printf("\n");
        printf("===========================================================\n");
        printf("=====                Produto                          =====\n");
        printf("===========================================================\n");
        printf("=====         [1] - Cadastrar produto                 =====\n");
        printf("=====         [2] - Exibir produto                    =====\n");
        printf("=====         [3] - Alterar produto                 =====\n");
        printf("=====         [4] - Excluir produto                   =====\n");
        printf("=====         [0] - Sair                              =====\n");
        printf("===========================================================\n");
        printf("Sua Escolha: --> ");
        
        if (scanf("%d", &op) != 1) {  // Verifica se a entrada é um número
            printf("Entrada inválida! Por favor, insira um número.\n");
            while (getchar() != '\n');  // Limpa o buffer de entrada
            continue;  // Retorna ao início do loop
        }
        if (op >= 0 && op <= 4){
            switch(op) {
            case 1:
                produto = preencherProduto();
                if (produto == NULL) {   //testa se produto retornado é NULL
                    printf("======= Erro ao preencher os dados do produto. =======\n");
                    printf("=======      O produto não foi cadastrado!     =======\n");
                    printf("======================================================\n");
                } else {  
                    exibirProduto(produto);
                    char resposta;

                    printf("==== Tem certeza que deseja cadastrar esse produto? Sim -> digite S; Não -> digite N: \n");  //conferindo os dados
                    scanf("%c", &resposta);
                    getchar();

                    int retorno = 0;
                    if (resposta == 'S' || resposta == 's') {
                        retorno = gravarProduto(arquivoProduto, produto);   //dados confirmados, gravação
                        if (retorno == 0) {
                            printf("=======    O produto não foi cadastrado!   =======\n");
                            printf("==================================================\n");
                        } else {
                            printf("======= Produto cadastrado com sucesso! =======\n");
                            printf("===============================================\n"); 
                        } 
                    } else {   //dados incorretos
                        printf("==== Dados incorretos! O produto não foi cadastrado! ====\n");
                        printf("=========================================================\n");
                    }
                } 
                free(produto);  //libera produto
                break;
            case 2:
                produto = buscarProduto(arquivoProduto);   //2 opções: buscar_produto e exibir em uma só, a outra volta a posição... 
                if (produto == NULL) {       //busco produto; se for NULL, não vai pra exibir...
                    printf("======= O produto não foi encontrado! =======\n");
                    printf("=============================================\n");
                } else {
                    printf("======= Produto encontrado com sucesso! =======\n");
                    printf("===============================================\n");
                    exibirProduto(produto); //exibe dados do produto
                }
                free(produto);  //libera
                break;
            case 3:
                produto = buscarProduto(arquivoProduto); 
                if (produto == NULL) {  //testa se produto retornado é NULL
                    printf("======= Produto não encontrado! =======\n");
                    printf("=======================================\n");
                } else {
                    exibirProduto(produto);  //exibe produto
                    char resposta;

                    printf("==== Tem certeza que deseja alterar esse produto? Sim -> digite S; Não -> digite N: \n");  //conferindo os dados
                    scanf("%c", &resposta);
                    getchar();

                    int retorno = 0;
                    if (resposta == 'S' || resposta == 's') {
                        retorno = alterarProduto(arquivoProduto);   //dados confirmados, alteração  
                        if (retorno == 0) {
                            printf("======= Erro: o produto não foi alterado! =======\n");
                            printf("=================================================\n");
                        } else {
                            printf("======= Produto alterado com sucesso! =======\n");
                            printf("=============================================\n"); //mudando pra testes...
                            
                        }
                    } else {   //dados incorretos
                        printf("=======  Dados incorrretos: O produto não foi alterado!  =======\n");
                        printf("================================================================\n");
                    }
                }
                free(produto); //libera...
                break;
            case 4:
                produto = buscarProduto(arquivoProduto); 
                if (produto == NULL) {             //testa se produto retornado é NULL
                    printf("=======    Produto não encontrado!    =======\n");
                    printf("=============================================\n");
                } else {
                    exibirProduto(produto);   //exibe o produto
                    char resposta;

                    printf("==== Tem certeza que deseja excluir esse produto? Sim -> digite S; Não -> digite N: \n");  //conferindo os dados
                    scanf("%c", &resposta);
                    getchar();

                    int retorno = 0; //AQUI AGORA: ajeitar função de excluir
                    if (resposta == 'S' || resposta == 's') {
                        retorno = excluirProduto(arquivoProduto);   //dados confirmados, exclusão    
                        if (retorno == 0) {
                            printf("======= Erro: o produto não foi excluído! =======\n");
                            printf("=================================================\n");
                        } else {
                            printf("======= Produto excluído com sucesso! =======\n");
                            printf("=============================================\n"); 
                        }
                    } else {   //dados incorretos
                        printf("======= Dados incorretos: O produto não foi excluído! =======\n");
                        printf("=============================================================\n");
                    }
                }
                free(produto);  //libera
                break;
            case 0:
                printf("Saindo do módulo de produto...\n");
                break;
            }

        }else{
            printf("Opção inválida! Tente novamente.\n");
        }
        
    } while (op != 0);  
}

void tela_mod_relat(void) {
    int op;
    
    do {
        printf("\n");
        printf("===========================================================\n");
        printf("=====                Relatório                          =====\n");
        printf("===========================================================\n");
        printf("=====         [1] - Relatório geral de clientes         =====\n");
        printf("=====         [2] - Relatório geral de vendas           =====\n");
        printf("=====         [3] - Relatório geral de produtos         =====\n");
        printf("=====         [4] - Relatório geral de funcionários     =====\n");
        printf("=====         [0] - Sair                                =====\n");
        printf("===========================================================\n");
        printf("Sua Escolha: --> ");

        if (scanf("%d", &op) != 1) {  // Verifica se a entrada é um número
            printf("Entrada inválida! Por favor, insira um número.\n");
            while (getchar() != '\n');  // Limpa o buffer de entrada
            continue;  // Retorna ao início do loop
        }
        if (op >= 0 && op <= 4){
            switch (op) {
            case 1:
                //menu...
                relatorio_geral_clientes(arquivoCliente);  
                break;
            case 2:
                //menu...
                relatorio_geral_vendas(arquivoVenda);   
                break;
            case 3:
                //menu
                relatorio_geral_produtos(arquivoProduto);  
                break;
            case 4:
                //menu
                relatorio_geral_funcionarios(arquivoFuncionario); 
                break;
            case 0:
                printf("Saindo...\n");
                break;
            }
        }else{
             printf("Opção inválida! Tente novamente.\n");
        }
    } while (op != 0);  
}




void tela_info_proj(void){
    printf("\n");
    printf("===========================================================\n");
    printf("=====   Universidade Federal Rio Grande do Norte      =====\n");
    printf("=====   Diciplina: Programação,  codigo: DCT1106      =====\n");
    printf("=====               Programa de Gestão                =====\n");
    printf("=====   Para uma Loja de Material de Construção       =====\n");
    printf("===========================================================\n");
    printf("=====   O Projeto tem o objetivo Criar um programa    =====\n");
    printf("=====   de Gestão para uma Loja de Materais           =====\n");
    printf("=====   de Construção,tem como objetivo ajudar na     =====\n");
    printf("=====   administração da loja,sendo possivel administa=====\n");
    printf("=====   produtos,vendas,clientes,funcionarios e tambem=====\n");
    printf("=====   relatorios                                    =====\n");
    printf("===========================================================\n");
    //getchar();
    printf("\n");
    printf("===========================================================\n");
    printf("=====            Equipe de desenvolvimento            =====\n");
    printf("===========================================================\n");
    printf("=====            Leandro Sergio Da Silva              =====\n");
    printf("=====            Arthur De Medeiros Dantas            =====\n");
    printf("=====            Juliany Tairis de Oliveira Borges    =====\n");
    printf("=====             Júlia Lilian Prudêncio da Costa     =====\n");
    printf("===========================================================\n");
    printf("Pressione <ENTER> para continuar\n");
    getchar();
}