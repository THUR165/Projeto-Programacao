#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "verificarc.h"

// Função para buscar e exibir informações do cliente pelo CPF
Cliente* buscarCliente(const char* arquivoCliente) {
    FILE* fp;
    Cliente* clnt;
    char cpf_pesquisado[12];
    //int encontrado = 0;

    clnt = (Cliente*) malloc(sizeof(Cliente));
    if (clnt == NULL) {    //teste de alocação
        perror("Erro ao alocar memória\n");
        return NULL;
    }

    fp = fopen(arquivoCliente, "rb");
    if (fp == NULL) {   //teste de abertura de arquivo
        perror("Erro ao abrir o arquivo\n");
        free(clnt);
        return NULL;
    }

    printf("==========================================================\n");
    printf("=======              Buscar Cliente                =======\n");
    printf("==========================================================\n");
    printf("Digite o CPF do cliente que deseja pesquisar: \n");
    scanf("%11s", cpf_pesquisado);  
    getchar();

    while(fread(clnt, sizeof(Cliente), 1, fp)) {
        if((strcmp(clnt->cpf, cpf_pesquisado) == 0) && (clnt->status == 1)) {
            //encontrado = 1;
            fclose(fp);
            printf("Encontrando o cliente...\n");
            return clnt;
        } 
    }

    fclose(fp);  //free é feito na interface........
    return NULL;
}


//essas funções ficarão comentadas, por enquanto
void exibirCliente(Cliente* clnt){
    
    printf("\n=========================================================\n");
    printf("=======            Exibir Dados do Cliente          =======\n");
    printf("===========================================================\n");
    printf("CPF: %s\n", clnt->cpf);
    printf("Nome: %s\n", clnt->nome);
    printf("Data de nascimento: %s\n", clnt->data_nascimento);
    printf("Gênero: %s\n", clnt->gen);
    printf("Telefone: %s\n", clnt->tel);
    printf("Rua: %s\n", clnt->rua);
    printf("Num da casa: %s\n", clnt->num);
    getchar();
    printf("\t\tTecle ENTER para continuar...\n\n");
    printf("===========================================================\n");
    getchar();
}



//void exibir_cliente(/*Cliente *clientes, int size,*/ const char *cpf_busca) {

    //printf("====== Exibindo o cliente com CPF tal\n");

    //printf("Esse é CPF: \n");
    /*Cliente clientes = [];
    int size = 10;
    for (int i = 0; i < size; i++) {
        if (strcmp(clientes[i].cpf, cpf_busca) == 0) {  // CPF encontrado
            printf("\nCliente encontrado:\n");
            printf("Nome: %s\n", clientes[i].nome);
            printf("CPF: %s\n", clientes[i].cpf);
            printf("Data de Nascimento: %s\n", clientes[i].nasc);
            printf("Gênero: %s\n", clientes[i].gen);
            printf("Telefone: %s\n", clientes[i].tel);
            printf("Rua: %s\n", clientes[i].rua);
            printf("Número da casa: %s\n", clientes[i].num);
            
            // Liberando memória alocada dinamicamente
            
            return clientes[i];  // Retorna o cliente encontrado
        }
=======
#include "../clientes/cliente.h"


// possivel erro nessa função na hr de abrir o arquivo

char* pesqClient(char* cpf) {
    printf("Digite o CPF do cliente que deseja buscar: ");
    limparBuffer(); // Certifique-se de limpar o buffer antes da leitura
    scanf("%14[^\n]", cpf);
    return cpf;
}




Cliente* buscarCliente(const char* cpf) {
    FILE* fp;
    Cliente* cliente;

    cliente = (Cliente*) malloc(sizeof(Cliente));
    if (cliente == NULL) {
        perror("Erro ao alocar memória");
        return NULL;
>>>>>>> main
    }

    fp = fopen("cliente.bin", "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        free(cliente);
        return NULL;
    }

<<<<<<< HEAD
    // Retornar um cliente vazio em caso de não encontrado
    Cliente cliente_vazio = {0};  // Inicializa todos os campos com valores padrão
    return cliente_vazio;*/

//}

