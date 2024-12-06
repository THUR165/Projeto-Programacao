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

// Função para capturar, validar, exibir e salvar os dados do cliente
void cad_client(const char *nomeArquivo) {
    Cliente cliente;
    int valido;

    // Capturar e validar nome
    do {
        printf("Digite o nome do cliente: ");
        fgets(cliente.nome, sizeof(cliente.nome), stdin);
        cliente.nome[strcspn(cliente.nome, "\n")] = '\0'; // Remover '\n'

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

    // Capturar rua
    printf("Digite o nome da Rua: ");
    scanf("%50[^\n]", cliente.rua);
    limparBuffer();

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
        FILE *arquivo = fopen(nomeArquivo, "ab");
        if (arquivo == NULL) {
            perror("Erro ao abrir arquivo");
            return;
        }

        // Tente salvar no arquivo
        size_t resultado = fwrite(&cliente, sizeof(Cliente), 1, arquivo);
        if (resultado != 1) {
            perror("Erro ao salvar os dados");
        } else {
            printf("Dados salvos com sucesso no arquivo '%s'!\n", nomeArquivo);
        }

        fclose(arquivo);
    } else {
        printf("Os dados não foram salvos. Voltando ao menu...\n");
    }
}
