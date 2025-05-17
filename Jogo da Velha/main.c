#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>
#include "jogo.h"

int main() {
	setlocale(LC_ALL, "portuguese");
	char tabuleiro[3][3], jogador;
	int opcao, linha, coluna;
	bool jogadaValida, tabuleiroCheio, existeCampeao;

	do {
		existeCampeao =  tabuleiroCheio = false;
		jogador = 'X';
		inicializarTabuleiro(tabuleiro);

		system("cls");
		printf("===============================================\n");
		printf("  *************  JOGO DA VELHA  *************  \n");
		printf("===============================================\n\n");
		printf("       [1] Iniciar o jogo\n");
        printf("       [0] Encerrar o programa\n\n");
        printf("------------------------------------------------\n\n");

        printf("Selecione uma das op��es acima: ");
        do {
            while (scanf("%i", &opcao) != 1){
                printf("\nEntrada inv�lida!\nDigite novamente: ");
                setbuf(stdin, NULL);
            }

            if (opcao != 0 && opcao != 1){
                printf("\nOp��o inv�lida!\nDigite novamente: ");
            }
        } while (opcao != 0 && opcao != 1);
        setbuf(stdin, NULL);

        if (opcao == 0){
            printf("\n\nEncerrando o programa!");
            (void)_getch();
            break;
        }

		while (!existeCampeao && !tabuleiroCheio) {
			system("cls");
			printf("===============================================\n");
			printf("  *************  JOGO DA VELHA  *************  \n");
			printf("===============================================\n\n\n");
			exibirTabuleiro(tabuleiro);

			printf("\n\n\nVez do jogador \'%c\'", jogador);
			printf("\n\nDigite a linha e a coluna (1 a 3): ");
			if (scanf("%i %i", &linha, &coluna) != 2) {
				printf("Erro, entrada inv�lida!\n");
				setbuf(stdin, NULL);
				(void)_getch();
				continue;
			}
			setbuf(stdin, NULL);
			jogadaValida = validacaoJogada(tabuleiro, linha, coluna);
			if (!jogadaValida) {
				printf("\nJogada inv�lida! Jogador %c perdeu a vez!\n", jogador);
				jogador = alternarJogador(jogador);
				(void)_getch();
				continue;
			}
			registrarJogada(tabuleiro, linha, coluna, jogador);

			existeCampeao = verificarVencedor(tabuleiro);
			tabuleiroCheio = verificarTabuleiro(tabuleiro);

			if (!existeCampeao && !tabuleiroCheio) {
				jogador = alternarJogador(jogador);
			}
		}

		if (existeCampeao) {
			printf("\n\n|---------------------------------------|");
			printf("\n|  FIM DE JOGO! VIT�RIA DO JOGADOR \'%c\'  |", jogador);
			printf("\n|---------------------------------------|\n\n");
			exibirTabuleiro(tabuleiro);
		}
		else {
			printf("\n\n|------------------------|");
			printf("\n|  FIM DE JOGO! EMPATE!  |");
			printf("\n|------------------------|\n\n");
			exibirTabuleiro(tabuleiro);
		}

		(void)_getch();

	} while (opcao);

	return 0;
}