#pragma once

#include <stdbool.h>

// FUN합ES PARA MANIPULA플O DO TABULEIRO

void inicializarTabuleiro(char tabuleiro[3][3]);
void exibirTabuleiro(char tabuleiro[3][3]);

// FUN합ES PARA MANIPULA플O DAS JOGADAS

bool validacaoJogada(char tabuleiro[3][3], int linha, int coluna);
void registrarJogada(char tabuleiro[3][3], int linha, int coluna, char jogador);
char alternarJogador(char jogador);

// FUN합ES PARA A MANIPULA플O DO JOGO

bool verificarVencedor(char tabuleiro[3][3]);
bool verificarTabuleiro(char tabuleiro[3][3]);
