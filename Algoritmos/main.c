#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include "algoritmos.h"

int main() {
    setlocale(LC_ALL, "portuguese");
    int opcao;

    do {
        imprimirCabecalho();
        printf("       [1] Selection sort\n");
        printf("       [2] Bubble sort\n");
        printf("       [3] Merge sort\n\n");
        printf("       [0] Encerrar o programa\n\n");
        printf("-----------------------------------------------\n\n");

        opcao = lerInteiro("Escolha uma das opções acima: ");

        switch (opcao) {
        case 0: break;
        case 1: selectionSortMenu(); break;
        case 2: bubbleSortMenu(); break;
        case 3: mergeSortMenu(); break;

        default: printf("\nOpção inválida! Tente novamente."); getch(); break;
        }

    } while (opcao != 0);
    
    return 0;
}
