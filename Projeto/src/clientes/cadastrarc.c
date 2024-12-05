#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastrarc.h"
#include "../../valida.h"



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastrarc.h"

// Função para limpar o buffer do teclado
void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para capturar os dados do cliente usando scanf e getchar
Cliente cad_client(void) {
    Cliente cliente;

    printf("Digite o nome do cliente: \n");
    scanf("%50[^\n]", cliente.nome); // Lê até 50 caracteres ou até nova linha
    limparBuffer();

    printf("Digite o CPF do cliente (123.456.789-12): \n");
    scanf("%14[^\n]", cliente.cpf); // Lê até 14 caracteres
    limparBuffer();

    printf("Data de Nascimento (xx/xx/xxxx): -> \n");
    scanf("%10[^\n]", cliente.nasc); // Lê até 10 caracteres
    limparBuffer();

    printf("Gênero (M/F): -> \n");
    scanf("%3[^\n]", cliente.gen); // Lê até 3 caracteres
    limparBuffer();

    printf("Digite Telefone ((xx) x xxxx-xxxx): -> \n");
    scanf("%15[^\n]", cliente.tel); // Lê até 15 caracteres
    limparBuffer();

    printf("Digite o nome da Rua: -> \n");
    scanf("%50[^\n]", cliente.rua); // Lê até 50 caracteres
    limparBuffer();

    printf("Digite o número da casa: -> \n");
    scanf("%6[^\n]", cliente.num); // Lê até 6 caracteres
    limparBuffer();

    return cliente;
}

// Função para exibir os dados do cliente
void exibirCliente(Cliente cliente) {
    printf("\nInformações do Cliente:\n");
    printf("Nome: %s\n", cliente.nome);
    printf("CPF: %s\n", cliente.cpf);
    printf("Data de Nascimento: %s\n", cliente.nasc);
    printf("Gênero: %s\n", cliente.gen);
    printf("Telefone: %s\n", cliente.tel);
    printf("Rua: %s\n", cliente.rua);
    printf("Número da Casa: %s\n", cliente.num);
}




// Função para salvar os dados do cliente em arquivo binário
void salvarClienteBinario(Cliente cliente, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "ab");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }

    // Tente escrever no arquivo
    size_t resultado = fwrite(&cliente, sizeof(Cliente), 1, arquivo);
    if (resultado != 1) {
        perror("Erro ao salvar os dados");
    } else {
        printf("Dados salvos com sucesso no arquivo '%s'!\n", nomeArquivo);
    }

    fclose(arquivo);
}


// Função para exibir os dados de um cliente
int saveDate() {
    Cliente cliente = cad_client();

    // Perguntar se o usuário deseja salvar os dados
    printf("Você deseja salvar suas informações? (S/N): ");
    char resposta;
    scanf(" %c", &resposta);
    limparBuffer();

    if (resposta == 'S' || resposta == 's') {
        salvarClienteBinario(cliente, "clientes.bin");
    } else {
        printf("Voltando ao menu...\n");
    }

    return 0;
}
