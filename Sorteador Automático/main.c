#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "sorteios.h"

int main() {
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));
    int opcao;

    do {
        system("cls");
        printf("==============================================\n");
        printf("  *********  SORTEADOR AUTOMÁTICO  *********  \n");
        printf("==============================================\n\n");
        printf("       [1] Sortear números\n");
        printf("       [2] Sortear nomes\n");
        printf("       [3] Cara ou coroa\n");
        printf("       [4] Jogar dados\n");
        printf("       [5] Simulador de loteria\n\n");
        printf("       [0] Encerrar o programa\n\n");
        printf("----------------------------------------------\n\n");
        printf("Escolha uma das opções acima: ");
        while (scanf(" %i", &opcao) != 1) {
            printf("\nErro, entrada inválida!\nEscolha novamente: ");
            setbuf(stdin, NULL);
        }
        setbuf(stdin, NULL);

        switch (opcao) {

        case 1: numeros(); break;
        case 2: nomes(); break;
        case 3: moeda(); break;
        case 4: dados(); break;
        case 5: loteria(); break;

        case 0: printf("\nEncerrando o programa...\n");
            (void)_getch(); break;

        default: printf("\nOpção inválida! Tente novamente.");
            (void)_getch(); break;
        }

    } while (opcao != 0);

    return 0;
}
