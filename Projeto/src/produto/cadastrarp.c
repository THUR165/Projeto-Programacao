#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cadastrarp.h"

/* 
- revisar fluxos de alocação e free nas funções - ok
- revisar returns (1 e 0) - ok
- funções gravarProduto, alterarProduto e excluirProduto retornando int? - ok
- funções de alterar e excluir sem usar buscarProduto... (acrescentando testes de NULL) - ok
- erros de alocação de meória e de abertura de arquivo tem printfs específicos... gravação em arquivo ou erro de cursor
*/

Produto* preencherProduto(void){          
    
    Produto* prod;
    prod = (Produto*)malloc(sizeof(Produto));
    if (prod == NULL) {
        printf("Erro de alocação de memória! \n");
        return NULL; // return NULL;
    }
    int valido = 0;
    
    printf("===========================================================\n");
    printf("=======             Cadastrar Produto                ======\n");
    printf("===========================================================\n");
    do{  //Capturar codigo de barras
        printf("Digite o código de barra: ");
        scanf("%5s", prod->cod_barras); 
        getchar();

        if (validar_codigo(prod->cod_barras)) {
            valido = 1; 
        } else {
             printf("=== Código de barras inválido!\n");
        }
    } while(!valido);
    //Capturar nome
    do{     
        valido = 0;
        printf("Digite o nome do produto: ");
        fgets(prod->nome, sizeof(prod->nome), stdin);       

        prod->nome[strcspn(prod->nome, "\n")] = 0;
     
        if (validar_nome(prod->nome)) {
            valido = 1;  
        }else{
            printf("=== Nome de produto inválido!\n");
        }
    }while(!valido);
    //Capturar marca
    do{
        valido = 0;
        printf("Digite a marca do produto: ");
        fgets(prod->marca, sizeof(prod->marca), stdin);       

        prod->marca[strcspn(prod->marca, "\n")] = 0;

        if (validar_marca(prod->marca)) {
            valido = 1;  
        }else{
            printf("=== Nome de marca inválido!\n");
        }
    } while(!valido);
    //Capturar preço
    do{   
        valido = 0;
        printf("Digite o preço do produto: R$ ");
        scanf("%f", &prod->preco);
        getchar();

        if (validar_preco(prod->preco)) {
            valido = 1;
        } else {
            printf("=== Preço inválido!\n");
        }
    } while(!valido);
    //Capturar categoria
    do{
        valido = 0;
        printf("Digite a categoria do produto: ");
        fgets(prod->categoria, sizeof(prod->categoria), stdin);       

        prod->categoria[strcspn(prod->categoria, "\n")] = 0;

        if (validar_categoria(prod->categoria)) {
            valido = 1;  
        }else{
            printf("=== Nome de categoria inválido!\n");
        }
    } while(!valido);
    //Capturar data de validade
    do{
        valido = 0;
        printf("Digite a data de validade do produto: ");
        fgets(prod->data_validade, sizeof(prod->data_validade), stdin);       

        prod->data_validade[strcspn(prod->data_validade, "\n")] = 0;

        if (validar_data_validade(prod->data_validade)) {
            valido = 1;  
        }else{
            printf("=== Data de validade inválida!\n");
        }
    } while(!valido);
    //Status = 1
    prod->status = 1;

    return prod;
}

int gravarProduto(const char* nomeArquivo, Produto* prod) {
    FILE* fp = fopen(nomeArquivo, "ab");  //ab
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para cadastrar o produto!\n");
        free(prod);
        return 0; //falha...
    }

    //Escreve os dados no arquivo e testa se deu certo
    if (fwrite(prod, sizeof(Produto), 1, fp) != 1) {
        perror("Erro ao gravar os dados\n");
        free(prod);
        return 0; //falha...
    }

    fclose(fp); // Fecha o arquivo
    return 1; //sucess
}