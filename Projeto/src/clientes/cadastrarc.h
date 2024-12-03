#ifndef CADASTRARC_H
#define CADASTRARC_H

typedef struct {
    char *nome;      // Alocação dinâmica para o nome
    char cpf[15];    // Memória estática para CPF (14 + 1 para o caractere nulo)
    char nasc[11];   // Memória estática para data de nascimento (10 + 1)
    char gen[4];     // Memória estática para gênero (1 + 1)
    char tel[16];    // Memória estática para telefone (15 + 1)
    char *rua;      // Alocação dinâmica para a rua
    char num[7];
} Cliente;

Cliente cad_client(void);
//void imprimir_client(Cliente Cliente);
//void liberar_client(Cliente Cliente);
Cliente exibir_cliente(Cliente *clientes,int size, const char *cpf_busca);

#endif
