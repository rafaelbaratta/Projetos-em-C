#include <locale.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "batalhaNaval.h"

int main() {
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));
    char tabuleiroUsuario[TAM_TAB][TAM_TAB], tabuleiroComputador[TAM_TAB][TAM_TAB];
    char mascaraUsuario[TAM_TAB][TAM_TAB], mascaraComputador[TAM_TAB][TAM_TAB];
    int jogadorAtual, existeCampeao, opcao;

    do {
        existeCampeao = 0;
        imprimirMenu();
		printf("       [1] Iniciar o jogo\n");
        printf("       [0] Encerrar o programa\n\n");
        printf("------------------------------------------------\n\n");

        opcao = lerInteiro("Selecione uma das opções acima: ", 0, 1);

        if (opcao == 0){
            printf("\n\nEncerrando o programa!");
            getch();
            break;
        }

        carregarTabuleiros(tabuleiroComputador, tabuleiroUsuario, mascaraComputador, mascaraUsuario);
        jogadorAtual = 1;

        while (!existeCampeao) {
			imprimirMenu();
            printf("Jogador atual: %s\n\n", jogadorAtual == 1 ? "Usuário" : "Computador");
			imprimirTabuleiros(mascaraComputador, mascaraUsuario);

            if (jogadorAtual == 1) {
                if (realizarJogadaUsuario(tabuleiroComputador, mascaraComputador)) {
                    printf("\nVocê acertou uma embarcação! Jogue novamente!\n");
                    if (verificarVitoria(mascaraComputador)) {
                        break;
                    }
                    getch();
                    continue;
                } else {
                    printf("\nVocê acertou o mar! Perca sua vez!\n");
                    jogadorAtual = 2;
                    getch();
                    continue;
                }
            } else {
                if (realizarJogadaComputador(tabuleiroUsuario, mascaraUsuario)) {
                    printf("\nSua embarcação foi acertada! Computador ataca novamente!\n");
                    if (verificarVitoria(mascaraUsuario)) {
                        break;
                    }
                    getch();
                    continue;
                } else {
                    printf("\nComputador acertou o mar! Sua vez!\n");
                    jogadorAtual = 1;
                    getch();
                    continue;
                }
            }
        }

        if (jogadorAtual == 1) {
            printf("\n\n|-----------------------------|");
            printf("\n|  FIM DE JOGO! VOCÊ VENCEU   |");
            printf("\n|-----------------------------|\n\n");
        }
        else {
            printf("\n\n|-----------------------------|");
            printf("\n|  FIM DE JOGO! VOCÊ PERDEU   |");
            printf("\n|-----------------------------|\n\n");
        }
        getch();

	} while (opcao);

    return 0;
}