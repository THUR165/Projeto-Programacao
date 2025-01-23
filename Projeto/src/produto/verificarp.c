#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "verificarp.h"
//#include "cadastrarp.h"

/*
- mudar as funções...
*/


//essa função pesquisa um cóidigo e o retorna...
/*char* pesqCodProduto(void) {   //ela recebe char* cpf como parâmetro?... ou void?...
    char* codigo[5];

    printf("==========================================================\n");
    printf("=======              Buscar Produto                =======\n");
    printf("==========================================================\n");
    printf("Digite o código do produto que deseja buscar: ");
    //limparBuffer(); // Certifique-se de limpar o buffer antes da leitura
    scanf("%5s", codigo);
    getchar();
    return codigo;
}*/

//essa função recebe o códido da anterior, e o utiliza para pesquisar no arquivo e encontrar o prod que o possui, e retornar esse prod
Produto* buscarProduto(const char* nomeArquivo) {
    FILE* fp;
    Produto* prod;
    char codigo_pesquisado[6];
    //int encontrado = 0;

    prod = (Produto*) malloc(sizeof(Produto));
    if (prod == NULL) {    //teste de alocação
        perror("Erro ao alocar memória\n");
        return NULL;
    }

    fp = fopen(nomeArquivo, "rb");
    if (fp == NULL) {   //teste de abertura de arquivo
        perror("Erro ao abrir o arquivo\n");
        free(prod);
        return NULL;
    }

    printf("==========================================================\n");
    printf("=======              Buscar Produto                =======\n");
    printf("==========================================================\n");
    printf("Digite o codigo de barras do produto que deseja pesquisar: \n");
    scanf("%5s", codigo_pesquisado);  //validar codigo aqui tbm? Não precisa...
    getchar();

    while(fread(prod, sizeof(Produto), 1, fp)) {
        if((strcmp(prod->cod_barras, codigo_pesquisado) == 0) && (prod->status == 1)) {
            //encontrado = 1;
            fclose(fp);
            printf("Encontrando o produto...\n");
            return prod;
        } 
    }

    fclose(fp);  //free é feito na interface........
    return NULL;
}


//essas funções ficarão comentadas, por enquanto
void exibirProduto(Produto* prod){
    
    printf("\n=========================================================\n");
    printf("=======            Exibir Dados do Produto          =======\n");
    printf("===========================================================\n");
    printf("Código de barras: %s\n", prod->cod_barras);
    printf("Nome: %s\n", prod->nome);
    printf("Marca: %s\n", prod->marca);
    printf("Preço; R$ %2.f\n", prod->preco);
    printf("Categoria: %s\n", prod->categoria);
    printf("Data de validade: %s\n", prod->data_validade);
    getchar();
    printf("\t\tTecle ENTER para continuar...\n\n");
    printf("===========================================================\n");
    getchar();
}

/*Produto* buscarProduto(const char* nomeArquivo) { //passa codigo como parametro tbm...
    //abertura do arquivo
    FILE* fp = fopen(nomeArquivo, "rb");
    Produto* prod;
    int encontrado = 0;

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        free(prod);
        exit(1); //return NULL
    }
    //char codigo_barras[6];  //variável que guardará o código do prod que se quer buscar

    //alocação de memória
    prod = (Produto*)malloc(sizeof(Produto));
    if (prod == NULL) {
        printf("Erro de alocação de memória! Encerrando...\n");
        exit(1); //encerra programa...(?) //return NULL
    }

    printf("==========================================================\n");
    printf("=======              Buscar Produto                =======\n");
    printf("==========================================================\n");
    //printf("Digite o codigo de barras do produto que deseja pesquisar: \n");
    //scanf("%s \n", codigo_barras);  //validar codigo aqui tbm
    //getchar();

    while(fread(prod, sizeof(Produto), 1, fp)) {
        if((strcmp(prod->cod_barras, codigo_barras) == 0) && (prod->status == 1)) {
            encontrado = 1;
            fclose(fp);
            return prod;
        } 
    }

    if(!encontrado) {
        fclose()
        return NULL;
    }

    fclose(fp);
} */