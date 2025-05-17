#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include "cobrinha.h"

int main() {
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));
    int opcao;
    int velocidade;

    do {
        system("cls");
        printf("==============================================\n");
        printf("  ***********  JOGO DA COBRINHA  ***********  \n");
        printf("==============================================\n\n");
        printf("       [1] Dificuldade fácil\n");
        printf("       [2] Dificuldade média\n");
        printf("       [3] Dificuldade difícil\n\n");
        printf("       [0] Encerrar o programa\n\n");
        printf("------------------------------------------------\n\n");

        printf("Escolha a dificuldade do jogo: ");
        do {
            while (scanf("%i", &opcao) != 1){
                printf("\nEntrada inválida!\nDigite novamente: ");
                setbuf(stdin, NULL);
            }

            if (opcao != 0 && opcao != 1){
                printf("\nOpção inválida!\nDigite novamente: ");
            }
        } while (opcao < 0 && opcao > 3);
        setbuf(stdin, NULL);

        if (opcao == 0){
            printf("\n\nEncerrando o programa!");
            (void)_getch();
            break;
        }

        velocidade = escolherDificuldade(opcao);
        bool perdeu = false;
        int pontuacao = 0;
        iniciarJogo();

        do {
            system("cls");
            printf("==============================================\n");
            printf("  ***********  JOGO DA COBRINHA  ***********  \n");
            printf("==============================================\n\n");

            exibirTabuleiro();
            identificarComando();
            movimentacaoCobra();

            printf("\n\nPontuação total = %i", pontuacao);

            perdeu = identificarDerrota();
            pontuacao = pontuacaoJogo();

            Sleep(velocidade);

        } while (!perdeu);

        if(perdeu){
            printf("\n\n|----------------------------|");
			printf("\n|  FIM DE JOGO! VOCÊ PERDEU  |");
			printf("\n|----------------------------|\n\n");
            printf("Pontuação total = %i", pontuacao);
            (void)_getch();
        }
            

    } while (opcao);

    return 0;
}
