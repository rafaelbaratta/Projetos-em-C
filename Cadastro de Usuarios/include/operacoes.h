#pragma once

#include <stdbool.h>
#include <time.h>

#define SCANF_INT "%i"
#define SCANF_DOUBLE "%lf"

#define ARQUIVO "./data/cadastros.dat"
#define RELATORIO "./data/relat�rio.txt"

#define TAM_PADRAO 100
#define TAM_CPF_TELEFONE 15
#define TAM_UF 5

typedef struct {
    char estado[TAM_UF];
    char cidade[TAM_PADRAO];
    char bairro[TAM_PADRAO];
    char rua[TAM_PADRAO];
    int numero;
} Endereco;

typedef struct {
    int codigo;
    char nome[TAM_PADRAO];
    char cpf[TAM_CPF_TELEFONE];
    char telefone[TAM_CPF_TELEFONE];
    char email[TAM_PADRAO];
    double salario;
    Endereco endereco;
    struct tm data;
    bool removido;
} Cadastro;

// FUN��ES PARA VERIFICA��ES

void arquivoAberto(FILE *ponteiro);
bool validarCpf(const char *cpf);
bool validarTelefone(const char *telefone);
bool validarEmail(const char *email);
bool validarUnidadeFederativa(const char *estado);

// FUN��ES PARA ENTRADA DE DADOS

void lerEntradaAlfanumerica(char *destino, size_t tamanho);
int lerEntradaNumericaInteira();
double lerEntradaNumericaDecimal();

// FUN��ES PARA MANIPULA��O DE USU�RIOS

void imprimirDados(Cadastro imprimir);
bool buscarDados(FILE *ponteiro, int codigoProcura, Cadastro *cadastros);
bool buscarDadosRemovidos(FILE *ponteiro, int codigoProcura, Cadastro *cadastros);

// OUTRAS FUN��ES

void imprimirCabecalho();
void limpezaBuffer();
int contarRegistros();
char validarCaractere();
