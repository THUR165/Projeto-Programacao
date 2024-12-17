#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cliente.h"
#include "../../valida.h"


void modificar_cliente(const char* nomeArquivo) {
    FILE* fp;
    Cliente cliente;
    char cpf[20];
    int encontrado = 0; // Flag para indicar se o cliente foi encontrado

    // Solicitar o CPF do cliente
    printf("\n===========================================================\n");
    printf("======═             Modificar Cliente                ======\n");
    printf("===========================================================\n");
    printf("Digite o CPF do cliente a ser modificado: ");
    scanf("%19s", cpf);
    limparBuffer();

    // Abrir o arquivo no modo de leitura e escrita
    fp = fopen(nomeArquivo, "rb+");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    // Ler cada registro até encontrar o CPF correspondente
    while (fread(&cliente, sizeof(Cliente), 1, fp)) {
        if (strcmp(cliente.cpf, cpf) == 0 && cliente.status == 1) {
            encontrado = 1;

            // Exibir o menu para escolher qual dado modificar
            int opcao;
            do {
                printf("===========================================================\n");
                printf("Quais dados você quer modificar:\n");
                printf("===========================================================\n");
                printf("1 - Nome\n");
                printf("2 - CPF\n");
                printf("3 - Data de Nascimento\n");
                printf("4 - Gênero\n");
                printf("5 - Telefone\n");
                printf("6 - Cidade\n");
                printf("7 - Estado\n");
                printf("8 - Rua\n");
                printf("9 - Número da Casa\n");
                printf("0 - Sair\n");
                printf("===========================================================\n");
                printf("Sua Escolha: --> ");
                scanf("%d", &opcao);
                limparBuffer();

                // Modificar o dado escolhido
                switch (opcao) {
                    case 1:
                        printf("Digite o novo nome: ");
                        fgets(cliente.nome, sizeof(cliente.nome), stdin);
                        cliente.nome[strcspn(cliente.nome, "\n")] = '\0';
                        break;
                    case 2:
                        printf("Digite o novo CPF: ");
                        scanf("%19s", cliente.cpf);
                        limparBuffer();
                        break;
                    case 3:
                        printf("Digite a nova data de nascimento (xx/xx/xxxx): ");
                        scanf("%10s", cliente.nasc);
                        limparBuffer();
                        break;
                    case 4:
                        printf("Digite o novo gênero (M/F): ");
                        scanf("%3s", cliente.gen);
                        limparBuffer();
                        break;
                    case 5:
                        printf("Digite o novo telefone ((xx) x xxxx-xxxx): ");
                        scanf("%15s", cliente.tel);
                        limparBuffer();
                        break;
                    case 6:
                        printf("Digite a nova cidade: ");
                        fgets(cliente.cid, sizeof(cliente.cid), stdin);
                        cliente.cid[strcspn(cliente.cid, "\n")] = '\0';
                        break;
                    case 7:
                        printf("Digite o novo estado: ");
                        fgets(cliente.est, sizeof(cliente.est), stdin);
                        cliente.est[strcspn(cliente.est, "\n")] = '\0';
                        break;
                    case 8:
                        printf("Digite a nova rua: ");
                        fgets(cliente.rua, sizeof(cliente.rua), stdin);
                        cliente.rua[strcspn(cliente.rua, "\n")] = '\0';
                        break;
                    case 9:
                        printf("Digite o novo número da casa: ");
                        scanf("%6s", cliente.num);
                        limparBuffer();
                        break;
                    case 0:
                        printf("Saindo...\n");
                        break;
                    default:
                        printf("Opção inválida. Tente novamente.\n");
                }
            } while (opcao != 0);

            // Voltar para o início do registro encontrado e atualizar
            fseek(fp, -sizeof(Cliente), SEEK_CUR);
            fwrite(&cliente, sizeof(Cliente), 1, fp);
            printf("Cliente atualizado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente com o CPF %s não encontrado ou inativo.\n", cpf);
    }

    fclose(fp);
}


