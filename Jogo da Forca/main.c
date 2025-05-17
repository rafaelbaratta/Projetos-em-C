#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include "forca.h"

int main() {
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));
    char* palavraEscolhida;
    int opcao, totalLetras, totalErros, retornoValidacao;
    char letraEscolhida;
    bool ganhou;

    do {
        inicializarJogo();
        palavraEscolhida = sortearPalavra();
        totalLetras = contarLetras(palavraEscolhida);
        ganhou = false;
        totalErros = 0;

        system("cls");
        printf("===============================================\n");
        printf("  *************  JOGO DA FORCA  *************  \n");
        printf("===============================================\n\n");
        printf("       [1] Iniciar o jogo\n");
        printf("       [0] Encerrar o programa\n\n");
        printf("------------------------------------------------\n\n");

        printf("Selecione uma das opções acima: ");
        do {
            while (scanf("%i", &opcao) != 1){
                printf("\nEntrada inválida!\nDigite novamente: ");
                setbuf(stdin, NULL);
            }

            if (opcao != 0 && opcao != 1){
                printf("\nOpção inválida!\nDigite novamente: ");
            }
        } while (opcao != 0 && opcao != 1);
        setbuf(stdin, NULL);

        if (opcao == 0){
            printf("\n\nEncerrando o programa!");
            (void)_getch();
            break;
        }

        do {
            system("cls");
            printf("===============================================\n");
            printf("  *************  JOGO DA FORCA  *************  \n");
            printf("===============================================\n\n");

            exibirForca(totalErros, totalLetras);
            exibirAlfabeto();

            printf("\n\nEscolha uma das letras acima: ");
            while (scanf("%c", &letraEscolhida) != 1){
                printf("\nEntrada inválida!\nDigite novamente: ");
                setbuf(stdin, NULL);
            }

            setbuf(stdin, NULL);
            letraEscolhida = toupper(letraEscolhida);

            if(!validarCaractere(letraEscolhida)){
                printf("\nCaractere inválido inserido");
                (void)_getch();
                continue;
            }

            retornoValidacao = validarLetra(letraEscolhida, totalLetras);

            if(retornoValidacao == -1){
                printf("\nA letra %c não consta na palavra!", letraEscolhida);
                totalErros++;
                (void)_getch();
                continue;
            } else {
                if(retornoValidacao == 0){
                    printf("\nA letra %c já foi escolhida! Tente outra.", letraEscolhida);
                    (void)_getch();
                    continue;
                }
            }
            
            ganhou = verificarVitoria();

        } while (!ganhou && totalErros < 7);

        if(ganhou){
            printf("\n\n|----------------------------|");
			printf("\n|  FIM DE JOGO! VOCÊ VENCEU  |");
			printf("\n|----------------------------|\n\n");
            printf("Você acertou a palavra: %s", palavraEscolhida);
            (void)_getch();
        } else {
            printf("\n\n|--------------------------------|");
			printf("\n|  VOCÊ PERDEU! TENTE NOVAMENTE  |");
			printf("\n|--------------------------------|\n\n");
            printf("A palavra era: %s", palavraEscolhida);
            (void)_getch();
        }

    } while (opcao);

    return 0;
}