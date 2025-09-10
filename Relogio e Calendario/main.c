#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "calendario_relogio.h"

int main() {
    setlocale(LC_ALL, "portuguese");
    int opcao;

    do{
        imprimirCabecalho();
        printf("       [1] Mês e ano atual\n");
        printf("       [2] Definir mês e ano\n");
        printf("       [3] Relógio\n");
        printf("       [4] Cronômetro\n");
        printf("       [5] Temporizador\n\n");
        printf("       [0] Encerrar o programa\n\n");
        printf("----------------------------------------------\n\n");

        opcao = lerInteiro("Escolha uma das opções acima: ");

        switch (opcao) {
        case 0: break;
        case 1: calendarioMenu(opcao); break;
        case 2: calendarioMenu(opcao); break;
        case 3: relogio(); break;
        case 4: cronometro(); break;
        case 5: temporizador(); break;
        default: printf("\nOpção inválida! Tente novamente."); getch(); break;
        }

    } while (opcao);

    return 0;
}
