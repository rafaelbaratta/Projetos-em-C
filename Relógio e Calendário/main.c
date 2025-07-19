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
        printf("       [1] M�s e ano atual\n");
        printf("       [2] Definir m�s e ano\n");
        printf("       [3] Rel�gio\n");
        printf("       [4] Cron�metro\n");
        printf("       [5] Temporizador\n\n");
        printf("       [0] Encerrar o programa\n\n");
        printf("----------------------------------------------\n\n");

        opcao = lerInteiro("Escolha uma das op��es acima: ");

        switch (opcao) {
        case 0: break;
        case 1: calendarioMenu(opcao); break;
        case 2: calendarioMenu(opcao); break;
        case 3: relogio(); break;
        case 4: cronometro(); break;
        case 5: temporizador(); break;
        default: printf("\nOp��o inv�lida! Tente novamente."); getch(); break;
        }

    } while (opcao);

    return 0;
}
