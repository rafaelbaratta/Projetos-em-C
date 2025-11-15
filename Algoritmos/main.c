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
        printf("       [1] Insertion sort\n");
        printf("       [2] Selection sort\n");
        printf("       [3] Bubble sort\n");
        printf("       [4] Merge sort\n\n");
        printf("       [5] Busca Sequencial\n");
        printf("       [6] Busca Binária\n\n");
        printf("       [0] Encerrar o programa\n\n");
        printf("-----------------------------------------------\n\n");

        opcao = lerInteiroPositivo("Escolha uma das opções acima: ");

        switch (opcao) {
        case 0: break;
        case 1: insertionSortMenu(); break;
        case 2: selectionSortMenu(); break;
        case 3: bubbleSortMenu(); break;
        case 4: mergeSortMenu(); break;
        case 5: buscaSequencialMenu(); break;
        case 6: buscaBinariaMenu(); break;
        default: printf("\nOpção inválida! Tente novamente."); getch(); break;
        }

    } while (opcao != 0);
    
    return 0;
}
