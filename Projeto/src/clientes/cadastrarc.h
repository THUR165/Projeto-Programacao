#ifndef CADASTRARC_H
#define CADASTRARC_H

typedef struct {
    char nome[51];      
    char cpf[14];    // Memória estática para CPF (14 + 1 para o caractere nulo)
    char nasc[10];   // Memória estática para data de nascimento (10 + 1)
    char gen[3];     // Memória estática para gênero (1 + 1)
    char tel[15];    // Memória estática para telefone (15 + 1)
    char cid[51];
    char est[4];     // sigla do estado
    char rua[51];    
    char num[6];
    int status;
} Cliente;

void cad_client(const char *nomeArquivo);
//void imprimir_client(Cliente Cliente);
//void liberar_client(Cliente Cliente);
void exibirClientePorCPF(const char *nomeArquivo, const char *cpfBuscado);

#endif
