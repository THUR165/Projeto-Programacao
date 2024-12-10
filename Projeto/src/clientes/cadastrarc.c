#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastrarc.h"
#include "../../valida.h"


// erros a serem corrigidos:
//Se eu sair do mod cliente e voltar não dá opção de escolha
// salva os dados uma vez sim e outra não, talvez seja na chamada 
// da função no main
// erro não ta gravando o nome do cliente



// Função para limpar o buffer do teclado
void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


// Função para validar o nome (simples validação de exemplo)


// Função para gravar o cliente no arquivo
void gravarCliente(const char* nomeArquivo, Cliente* cliente) {
    FILE* fp = fopen(nomeArquivo, "ab"); // Abre em modo binário para adicionar
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    // Escreve os dados no arquivo
    if (fwrite(cliente, sizeof(Cliente), 1, fp) != 1) {
        perror("Erro ao gravar os dados");
    } else {
        printf("Dados gravados com sucesso no arquivo '%s'.\n", nomeArquivo);
    }

    fclose(fp); // Fecha o arquivo
}

// Função para cadastrar cliente
void cad_client(const char* nomeArquivo) {
    Cliente cliente;
    int valido;

    // Capturar e validar nome
    do {
        limparBuffer();
        printf("Digite o nome do cliente: ");
        fgets(cliente.nome, sizeof(cliente.nome), stdin);
        cliente.nome[strcspn(cliente.nome, "\n")] = '\0'; // Remove '\n'

        if (validar_nome(cliente.nome)) {
            valido = 1;
        } else {
            printf("---> Nome inválido! Tente novamente.\n");
            valido = 0;
        }
    } while (!valido);

    // Capturar CPF
    printf("Digite o CPF do cliente (123.456.789-12): ");
    scanf("%14[^\n]", cliente.cpf);
    limparBuffer();

    // Capturar data de nascimento
    printf("Data de Nascimento (xx/xx/xxxx): ");
    scanf("%10[^\n]", cliente.nasc);
    limparBuffer();

    // Capturar gênero
    printf("Gênero (M/F): ");
    scanf("%3[^\n]", cliente.gen);
    limparBuffer();

    // Capturar telefone
    printf("Digite Telefone ((xx) x xxxx-xxxx): ");
    scanf("%15[^\n]", cliente.tel);
    limparBuffer();

    printf("Digite o nome da Cidade: ");
    fgets(cliente.cid, sizeof(cliente.cid), stdin);
    cliente.cid[strcspn(cliente.cid, "\n")] = '\0';

    printf("Digite a sigla do estado: ");
    fgets(cliente.rua, sizeof(cliente.est), stdin);
    cliente.est[strcspn(cliente.est, "\n")] = '\0';
    // Capturar rua
    printf("Digite o nome da Rua: ");
    fgets(cliente.rua, sizeof(cliente.rua), stdin);
    cliente.rua[strcspn(cliente.rua, "\n")] = '\0';

    // Capturar número da casa
    printf("Digite o número da casa: ");
    scanf("%6[^\n]", cliente.num);
    limparBuffer();

    // Exibir dados capturados
    printf("\nInformações do Cliente:\n");
    printf("Nome: %s\n", cliente.nome);
    printf("CPF: %s\n", cliente.cpf);
    printf("Data de Nascimento: %s\n", cliente.nasc);
    printf("Gênero: %s\n", cliente.gen);
    printf("Telefone: %s\n", cliente.tel);
    printf("Rua: %s\n", cliente.rua);
    printf("Número da Casa: %s\n", cliente.num);

    // Perguntar se o usuário deseja salvar os dados
    printf("\nVocê deseja salvar suas informações? (S/N): ");
    char resposta;
    scanf(" %c", &resposta);
    limparBuffer();

    if (resposta == 'S' || resposta == 's') {
        gravarCliente(nomeArquivo, &cliente); // Chama a função de gravação
    } else {
        printf("Os dados não foram salvos. Voltando ao menu...\n");
    }
}



Cliente* buscarCliente(const char* nomeArquivo, const char* cpf) {
    FILE* fp;
    Cliente* cliente;

    // Alocar memória para o cliente
    cliente = (Cliente*) malloc(sizeof(Cliente));
    if (cliente == NULL) {
        perror("Erro ao alocar memória");
        return NULL;
    }

    // Abrir o arquivo em modo de leitura binária
    fp = fopen(nomeArquivo, "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        free(cliente);
        return NULL;
    }

    // Percorrer o arquivo procurando pelo cliente
    while (fread(cliente, sizeof(Cliente), 1, fp)) {
        if ((strcmp(cliente->cpf, cpf) == 0) && (cliente->status == 1)) { // Verifica CPF e status ativo
            fclose(fp);
            return cliente; // Retorna o cliente encontrado
        }
    }

    // Fechar o arquivo e liberar a memória se não encontrar o cliente
    fclose(fp);
    free(cliente);
    return NULL;
}
