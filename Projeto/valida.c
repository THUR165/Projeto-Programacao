// ------------ Funções de validação serão colocadas aqui -------------
// Estão faltando: validação de datas (atual e validade), validação de códigos de barra 

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include <time.h>

//Funções de validação 

// --- Função que identifica se cada caractere digitado no nome é válido, incluindo acentos e 'ç'desenvolvida pelo ChatGPT, acesso em 11/11/2024: 
// --- Desenvolvida pelo ChatGPT; acesso em 11/11/2024
int caractere_valido(char nome) {
    setlocale(LC_CTYPE, "pt_BR.UTF-8");   
    return (isalpha(nome) ||          
            (unsigned char)nome >= 192); // Inclui letras acentuadas e 'ç'
}

// --- Função que valida nome de produto digitado desenvolvida pelo ChatGPT, acesso em 11/11/2024
// --- Desenvolvida pelo ChatGPT; acesso em 11/11/2024
int validar_nome(char *nome) {   
    size_t len = strlen(nome);
    int min = 2, max = 50;   //define comprimentos do nome

    if (len < min || len > max) {
        return 0; // Inválido se muito curto ou muito longo
    }

    for (size_t i = 0; i < len; i++) {
        if (!caractere_valido(nome[i]) && nome[i] != ' ') {
            return 0; // Inválido se não for uma letra ou espaço
            }
    }

    return 1; // Válido se passou por todas as verificações
}

// --- Função que valida o CPF digitado pelo usuário
// --- Desenvolvida pelo ChatGPT, acesso em 16/11/2024
int validar_cpf(char *cpf) {
    // Verifica se o CPF tem 11 caracteres
    if (strlen(cpf) != 11) {
        return 0; // Inválido se não tiver 11 dígitos
    }

    // Verifica se todos os caracteres são dígitos
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            return 0; // Inválido se contiver algo que não seja dígito
        }
    }

    // Cálculo do primeiro dígito verificador
    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }
    int primeiro_digito = (soma * 10) % 11;
    if (primeiro_digito == 10) {
        primeiro_digito = 0;
    }

    // Verifica o primeiro dígito verificador
    if (primeiro_digito != (cpf[9] - '0')) {
        return 0; // Inválido se o primeiro dígito verificador não confere
    }

    // Cálculo do segundo dígito verificador
    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }
    int segundo_digito = (soma * 10) % 11;
    if (segundo_digito == 10) {
        segundo_digito = 0;
    }

    // Verifica o segundo dígito verificador
    if (segundo_digito != (cpf[10] - '0')) {
        return 0; // Inválido se o segundo dígito verificador não confere
    }

    return 1; // CPF válido
}

// --- Função que verifica se a data de nascimento é válida e se a pessoa tem mais de 18 anos
// --- Desenvolvida pelo ChatGPT; acesso em 16/11/2024
int validar_data_nascimento(char data_nascimento[11]) {
    int dia, mes, ano;

    // Verifica se a string tem o formato correto (10 caracteres: dd/mm/aaaa)
    if (strlen(data_nascimento) != 10 || data_nascimento[2] != '/' || data_nascimento[5] != '/') {
        return 0; // Formato inválido
    }

    // Extrai dia, mês e ano da string
    dia = atoi(&data_nascimento[0]); // Pega os dois primeiros caracteres e converte para int
    mes = atoi(&data_nascimento[3]); // Pega os caracteres na posição 3 e 4
    ano = atoi(&data_nascimento[6]); // Pega os caracteres a partir da posição 6

    // Verifica se a data está em um formato válido
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1900) {
        return 0; // Data inválida
    }

    // Verifica os dias máximos de cada mês
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        return 0; // Meses com 30 dias
    }
    if (mes == 2) {
        // Verifica se é ano bissexto
        int bissexto = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
        if ((bissexto && dia > 29) || (!bissexto && dia > 28)) {
            return 0; // Fevereiro com dias inválidos
        }
    }

    // Obtém a data atual
    time_t t = time(NULL);
    struct tm *data_atual = localtime(&t);
    int ano_atual = data_atual->tm_year + 1900;
    int mes_atual = data_atual->tm_mon + 1;
    int dia_atual = data_atual->tm_mday;

    // Verifica se a pessoa tem mais de 18 anos
    if (ano_atual - ano > 18 || (ano_atual - ano == 18 && (mes < mes_atual || (mes == mes_atual && dia <= dia_atual)))) {
        return 1; // Pessoa tem 18 anos ou mais
    }

    return 0; // Pessoa não tem 18 anos
}
