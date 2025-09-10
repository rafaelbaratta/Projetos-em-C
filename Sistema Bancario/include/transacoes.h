#pragma once

#define MAX_CONTAS 100
#define MAX_TRANSACOES 1000
#define NUM_CPF 12
#define NUM_SENHA 11

#define DADOS_BANCARIOS "./data/Dados_Bancários"
#define TRANSACOES_BANCARIAS "./data/Transações_Bancárias"


// VARIÁVEIS GLOBAIS

extern int numContas;
extern int numTransacoes[MAX_CONTAS];

typedef struct {
    int numero;
    char nome[100];
    char cpf[NUM_CPF];
    char senha[NUM_SENHA];
    double saldo;
} Conta;

typedef struct {
    char data[MAX_TRANSACOES][20];
    char sinal[MAX_TRANSACOES];
    double valor[MAX_TRANSACOES];
} Extrato;

// FUNÇÃO CRIADA APENAS PARA TESTES

void exibirContas(void);

// FUNÇÕES PARA VALIDAÇÕES

int validarCpf(char* cpf);
int validarSenha(char* senha);

// FUNÇÕES DE MANIPULAÇÃO DE CONTAS

void criarConta(void);
void entrarConta(void);
void salvarDadosContas(void);
void carregarDadosContas(void);
void menuConta(Conta* contaAtual);
void registrarTransacao(int id, int sinal, double valor);

// FUNÇÕES DE TRANSAÇÕES

void saldo(int id);
void deposito(int id);
void saque(int id);
void transferencia(int id);
void extrato(int id);
