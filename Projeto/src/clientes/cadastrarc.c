#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastrarc.h"
#include "../../valida.h"
/*
1 - Clientes:
Nome:
CPF:
Data de Nascimento:
Gênero:
Telefone:
Rua:
*/
// substituir scanf por fgets, para manuseio de strings
//exemplo de uso no código de Flavius, no slide.
//Trocar o \n por \0.
Cliente cad_client(void) {
    Cliente cliente;

    // Alocação dinâmica para campos de tamanho variável
    cliente.nome = malloc(51 * sizeof(char));
    cliente.rua = malloc(51 * sizeof(char));
    if (!cliente.nome || !cliente.rua) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    printf("===========================================================\n");
    printf("=======             Cadastrar Cliente               ======\n");
    printf("===========================================================\n");

    int nome_valido = 0;
    do {
        printf("Digite o seu nome: ");
        fgets(cliente.nome, 51, stdin);
        cliente.nome[strcspn(cliente.nome, "\n")] = '\0';
        if (validar_nome(cliente.nome)) {
            nome_valido = 1;
        } else {
            printf("---> Nome inválido!\n");
        }
    } while (!nome_valido);

    printf("Digite o CPF: ");
    fgets(cliente.cpf, sizeof(cliente.cpf), stdin);
    cliente.cpf[strcspn(cliente.cpf, "\n")] = '\0';
    
    //teste da função de validar cpf; colocar num loop caso cpf digitado não seja válido
    if (validar_cpf(cliente.cpf)) {
        printf("CPF válido!\n");
    } else {
        printf("CPF inválido!\n");
    }

    printf("Data de Nascimento (DD/MM/AAAA): ");
    fgets(cliente.nasc, sizeof(cliente.nasc), stdin);
    cliente.nasc[strcspn(cliente.nasc, "\n")] = '\0';

    printf("Gênero (M/F): ");
    fgets(cliente.gen, sizeof(cliente.gen), stdin);
    cliente.gen[strcspn(cliente.gen, "\n")] = '\0';

    printf("Digite o telefone ((XX) X XXXX-XXXX): ");
    fgets(cliente.tel, sizeof(cliente.tel), stdin);
    cliente.tel[strcspn(cliente.tel, "\n")] = '\0';

    printf("Digite o nome da rua: ");
    fgets(cliente.rua, 51, stdin);
    cliente.rua[strcspn(cliente.rua, "\n")] = '\0';

    printf("Digite o número da casa: ");
    fgets(cliente.num, sizeof(cliente.num), stdin);
    cliente.num[strcspn(cliente.num, "\n")] = '\0';

    printf("\nInformações do Cliente:\n");
    printf("Nome: %s\n", cliente.nome);
    printf("CPF: %s\n", cliente.cpf);
    printf("Data de Nascimento: %s\n", cliente.nasc);
    printf("Gênero: %s\n", cliente.gen);
    printf("Telefone: %s\n", cliente.tel);
    printf("Rua: %s\n", cliente.rua);
    printf("Número da Casa: %s\n", cliente.num);

    return cliente;
}


/*
void liberar_client(Cliente cliente) {
    free(cliente.nome);
    free(cliente.rua);
}
*/
