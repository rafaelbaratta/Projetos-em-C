#pragma once

#include <stdbool.h>

// FUN��ES PARA MANIPULA��O DO TABULEIRO

void inicializarTabuleiro(char tabuleiro[3][3]);
void exibirTabuleiro(char tabuleiro[3][3]);

// FUN��ES PARA MANIPULA��O DAS JOGADAS

bool validacaoJogada(char tabuleiro[3][3], int linha, int coluna);
void registrarJogada(char tabuleiro[3][3], int linha, int coluna, char jogador);
char alternarJogador(char jogador);

// FUN��ES PARA A MANIPULA��O DO JOGO

bool verificarVencedor(char tabuleiro[3][3]);
bool verificarTabuleiro(char tabuleiro[3][3]);
