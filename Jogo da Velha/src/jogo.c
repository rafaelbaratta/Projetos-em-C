#include <stdio.h>
#include <stdbool.h>
#include "jogo.h"

void inicializarTabuleiro(char tabuleiro[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			tabuleiro[i][j] = ' ';
		}
	}
	return;
}

void exibirTabuleiro(char tabuleiro[3][3]) {
	printf("\n    1   2   3 \n\n");
	for (int i = 0; i < 3; i++) {
		printf("%i   %c | %c | %c", i+1, tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
		if (i < 2) {
			printf("\n   ---|---|---\n");
		}
	}
	return;
}

bool validacaoJogada(char tabuleiro[3][3], int linha, int coluna) {
	if ((linha >= 1 && linha <= 3) && (coluna >= 1 && coluna <= 3) && (tabuleiro[linha - 1][coluna - 1] == ' ')) {
		return true;
	}
	return false;
}

void registrarJogada(char tabuleiro[3][3], int linha, int coluna, char jogador) {
	tabuleiro[linha - 1][coluna - 1] = jogador;
}

char alternarJogador(char jogador) {
	if (jogador == 'X') {
		return 'O';
	}
	else {
		return 'X';
	}
}

bool verificarVencedor(char tabuleiro[3][3]) {
	for (int i = 0; i < 3; i++) {
		if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
			return true;
		}
		if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
			return true;
		}
	}

	if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
		return true;
	}
	if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[0][2] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
		return true;
	}

	return false;
}

bool verificarTabuleiro(char tabuleiro[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tabuleiro[i][j] == ' ') {
				return false;
			}
		}
	}
	return true;
}
