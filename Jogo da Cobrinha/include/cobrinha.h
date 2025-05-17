#pragma once

#include <stdbool.h>

#define LARGURA 30
#define ALTURA 30
#define TAM_MAX_COBRA 100

typedef struct {
    int x;
    int y;
} Posicao;

typedef enum {
    PARADO,
    CIMA,
    BAIXO,
    ESQUERDA,
    DIREITA
} Direcao;

// FUNÇÕES PARA INICIALIZAÇÃO DO JOGO

int escolherDificuldade(int dificuldadeEscolhida);
void iniciarJogo(void);
void exibirTabuleiro(void);
void posicionarComida(void);

// FUNÇÕES PARA CONTROLE DO JOGO

void identificarComando(void);
void movimentacaoCobra(void);
bool identificarDerrota(void);
void identificarPegouComida(void);
int pontuacaoJogo(void);
