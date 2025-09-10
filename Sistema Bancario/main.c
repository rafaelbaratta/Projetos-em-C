#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include "transacoes.h"

int main() {
    setlocale(LC_ALL, "portuguese");
    int opcao;
    carregarDadosContas();

    do {
        system("cls");
        printf("==============================================\n");
        printf("  ***********  SISTEMA BANCÁRIO  ***********  \n");
        printf("==============================================\n\n");
        printf("       [1] Criar uma nova conta\n");
        printf("       [2] Entar com uma conta existente\n\n");
        printf("       [0] Encerrar o programa\n\n");
        printf("----------------------------------------------\n\n");
        printf("Escolha uma das opções acima: ");
        if (scanf(" %i", &opcao) != 1) {
            printf("\nErro, entrada inválida!");
            if (_getch()) {
                while (getchar() != '\n');
                opcao = -1;
                continue;
            }
        }
        while (getchar() != '\n');

        switch (opcao) {

        case 1: criarConta(); break;
        case 2: entrarConta(); break;

        case 0: printf("\nEncerrando o programa...\n"); 
            if (_getch()) {
                break;
            }

        default: printf("\nOpção inválida! Tente novamente.");
            if (_getch()) {
                break;
            }
        }

    } while (opcao != 0);

    salvarDadosContas();
    return 0;
}

