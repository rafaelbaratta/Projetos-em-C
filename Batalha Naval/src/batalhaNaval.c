#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "batalhaNaval.h"

void imprimirMenu() {
    system("cls");
	printf("===============================================\n");
	printf("  *************  BATALHA NAVAL  *************  \n");
	printf("===============================================\n\n");
}

int lerInteiro(char *mensagem, int min, int max) {
    int valor;

    printf("%s", mensagem);
    do{
        while (scanf(" %i", &valor) != 1) {
            printf("\nErro, entrada inválida!\n%s", mensagem);
            setbuf(stdin, NULL);
        }
        setbuf(stdin, NULL);

        if(valor < min || valor > max){
            printf("\nO valor digitado deve estar entre %i e %i: ", min, max);
        }

    } while (valor < min || valor > max);

    return valor;
}

// Funções para Controle das Jogadas

int realizarJogadaUsuario(char tabuleiro[TAM_TAB][TAM_TAB], char mascara[TAM_TAB][TAM_TAB]) {
    int posicaoX;
    int posicaoY;

    do {
        posicaoX = lerInteiro("\nDigite a posição X que deseja atacar: ", 0, TAM_TAB - 1);
        posicaoY = lerInteiro("Digite a posição Y que deseja atacar: ", 0, TAM_TAB - 1);

        if (mascara[posicaoY][posicaoX] == '~' || mascara[posicaoY][posicaoX] == 'X') {
            printf("\nJogada inválida! A posição já foi atacada!\n");
        }

    } while (mascara[posicaoY][posicaoX] == '~' || mascara[posicaoY][posicaoX] == 'X');

    if (tabuleiro[posicaoY][posicaoX] == '@') {
        mascara[posicaoY][posicaoX] = 'X';
        return 1;
    }
    
    mascara[posicaoY][posicaoX] = '~';
    return 0;
}

int realizarJogadaComputador(char tabuleiro[TAM_TAB][TAM_TAB], char mascara[TAM_TAB][TAM_TAB]) {
    int posicaoX;
    int posicaoY;

    do {
        posicaoX = rand() % TAM_TAB;
        posicaoY = rand() % TAM_TAB;
    } while (mascara[posicaoY][posicaoX] == '~' || mascara[posicaoY][posicaoX] == 'X');

    if (tabuleiro[posicaoY][posicaoX] == '@') {
        mascara[posicaoY][posicaoX] = 'X';
        return 1;
    }
    
    mascara[posicaoY][posicaoX] = '~';
    return 0;
}

int verificarVitoria(char mascara[TAM_TAB][TAM_TAB]) {
    int contador = 0;

    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            if (mascara[i][j] == 'X') {
                contador++;
            }
        }
    }

    if (contador == TOTAL_ESPACOS_NAVIOS) {
        return 1;
    }

    return 0;
}

// Funções para Controle dos Tabuleiros

void limparTabuleiro(char tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void imprimirTabuleiro(char tabuleiro[TAM_TAB][TAM_TAB]) {
    printf("    0 1 2 3 4 5 6 7 8 9\n");
    printf("  # # # # # # # # # # # #\n");

    for (int i = 0; i < TAM_TAB; i++) {
        printf("%i #", i);

        for (int y = 0; y < TAM_TAB; y++) {
            printf(" %c", tabuleiro[i][y]);
        }

        printf(" #\n");
    }

    printf("  # # # # # # # # # # # #\n");
}

void imprimirTabuleiros(char mascaraComputador[TAM_TAB][TAM_TAB], char mascaraUsuario[TAM_TAB][TAM_TAB]) {
    printf("  ====== COMPUTADOR =====   \n");
    imprimirTabuleiro(mascaraComputador);
    printf("\n  ======  USUÁRIO  ======   \n");
    imprimirTabuleiro(mascaraUsuario);
}

void carregarTabuleiroComputador(char tabuleiroComputador[TAM_TAB][TAM_TAB]) {

    for (int i = 0; i < QTD_NAVIOS_GRANDES; i++) {
        int direcao = 1 + (rand() % 2); // 1 - vertical || 2 - horizontal

        int posicaoX;
        int posicaoY;

        if (direcao == 1) {

            do {
                posicaoX = rand() % TAM_TAB;
                posicaoY = rand() % (TAM_TAB - TAM_NAVIO_GRANDE + 1);
            } while (tabuleiroComputador[posicaoY][posicaoX] == '@' ||
                     tabuleiroComputador[posicaoY + 1][posicaoX] == '@' ||
                     tabuleiroComputador[posicaoY + 2][posicaoX] == '@');

            for (int j = 0; j < TAM_NAVIO_GRANDE; j++) {
                tabuleiroComputador[posicaoY][posicaoX] = '@';
                posicaoY++;
            }

        } else {

            do {
                posicaoX = rand() % (TAM_TAB - TAM_NAVIO_GRANDE + 1);
                posicaoY = rand() % TAM_TAB;
            } while (tabuleiroComputador[posicaoY][posicaoX] == '@' ||
                     tabuleiroComputador[posicaoY][posicaoX + 1] == '@' ||
                     tabuleiroComputador[posicaoY][posicaoX + 2] == '@');

            for (int j = 0; j < TAM_NAVIO_GRANDE; j++) {
                tabuleiroComputador[posicaoY][posicaoX] = '@';
                posicaoX++;
            }
        }
    }

    for (int i = 0; i < QTD_NAVIOS_PEQUENOS; i++) {
        int direcao = 1 + (rand() % 2); // 1 - vertical || 2 - horizontal
        
        int posicaoX;
        int posicaoY;

        if (direcao == 1) {

            do {
                posicaoX = rand() % TAM_TAB;
                posicaoY = rand() % (TAM_TAB - TAM_NAVIO_PEQUENO + 1);
            } while (tabuleiroComputador[posicaoY][posicaoX] == '@' ||
                     tabuleiroComputador[posicaoY + 1][posicaoX] == '@');

            for (int j = 0; j < TAM_NAVIO_PEQUENO; j++) {
                tabuleiroComputador[posicaoY][posicaoX] = '@';
                posicaoY++;
            }

        } else {

            do {
                posicaoX = rand() % (TAM_TAB - TAM_NAVIO_PEQUENO + 1);
                posicaoY = rand() % TAM_TAB;
            } while (tabuleiroComputador[posicaoY][posicaoX] == '@' ||
                     tabuleiroComputador[posicaoY][posicaoX + 1] == '@');

            for (int j = 0; j < TAM_NAVIO_PEQUENO; j++) {
                tabuleiroComputador[posicaoY][posicaoX] = '@';
                posicaoX++;
            }
        }
    }

}

void carregarTabuleiroUsuario(char tabuleiroUsuario[TAM_TAB][TAM_TAB]) {

    for (int i = 0; i < QTD_NAVIOS_GRANDES; i++) {
        imprimirMenu();
        printf(" Posicione seus navios de tamanho 3 | Qtde.: %i\n\n", QTD_NAVIOS_GRANDES - i);
        int direcao = lerInteiro("----- Escolha a direção do navio -----\n(1) Vertical | (2) Horizontal: ", 1, 2);

        int posicaoX;
        int posicaoY;

        if (direcao == 1) {

            do {
                posicaoX = lerInteiro("\nEscolha a posição x do navio (0 a 9): ", 0, TAM_TAB - 1);
                posicaoY = lerInteiro("Escolha a posição Y do navio (0 a 7): ", 0, TAM_TAB - TAM_NAVIO_GRANDE);

                if (tabuleiroUsuario[posicaoY][posicaoX] == '@' ||
                    tabuleiroUsuario[posicaoY + 1][posicaoX] == '@' ||
                    tabuleiroUsuario[posicaoY + 2][posicaoX] == '@') {
                        printf("\nPosição indicada é inválida!\n");
                }

            } while (tabuleiroUsuario[posicaoY][posicaoX] == '@' ||
                     tabuleiroUsuario[posicaoY + 1][posicaoX] == '@' ||
                     tabuleiroUsuario[posicaoY + 2][posicaoX] == '@');

            for (int j = 0; j < TAM_NAVIO_GRANDE; j++) {
                tabuleiroUsuario[posicaoY][posicaoX] = '@';
                posicaoY++;
            }

        } else {

            do {
                posicaoX = lerInteiro("\nEscolha a posição x do navio (0 a 7): ", 0, TAM_TAB - TAM_NAVIO_GRANDE);
                posicaoY = lerInteiro("Escolha a posição Y do navio (0 a 9): ", 0, TAM_TAB - 1);

                if (tabuleiroUsuario[posicaoY][posicaoX] == '@' ||
                    tabuleiroUsuario[posicaoY][posicaoX + 1] == '@' ||
                    tabuleiroUsuario[posicaoY][posicaoX + 2] == '@') {
                        printf("\nPosição indicada é inválida!\n");
                }

            } while (tabuleiroUsuario[posicaoY][posicaoX] == '@' ||
                     tabuleiroUsuario[posicaoY][posicaoX + 1] == '@' ||
                     tabuleiroUsuario[posicaoY][posicaoX + 2] == '@');

            for (int j = 0; j < TAM_NAVIO_GRANDE; j++) {
                tabuleiroUsuario[posicaoY][posicaoX] = '@';
                posicaoX++;
            }
        }

        printf("Navio inserido corretamente\n");
        imprimirTabuleiro(tabuleiroUsuario);
        getch();
    }

    for (int i = 0; i < QTD_NAVIOS_PEQUENOS; i++) {
        imprimirMenu();
        printf(" Posicione seus navios de tamanho 2 | Qtde.: %i\n\n", QTD_NAVIOS_PEQUENOS - i);
        int direcao = lerInteiro("----- Escolha a direção do navio -----\n(1) Vertical | (2) Horizontal: ", 1, 2);
        
        int posicaoX;
        int posicaoY;

        if (direcao == 1) {

            do {
                posicaoX = lerInteiro("\nEscolha a posição x do navio (0 a 9): ", 0, TAM_TAB - 1);
                posicaoY = lerInteiro("Escolha a posição Y do navio (0 a 7): ", 0, TAM_TAB - TAM_NAVIO_PEQUENO);

                if (tabuleiroUsuario[posicaoY][posicaoX] == '@' ||
                    tabuleiroUsuario[posicaoY + 1][posicaoX] == '@') {
                        printf("\nPosição indicada é inválida!\n");
                }

            } while (tabuleiroUsuario[posicaoY][posicaoX] == '@' ||
                     tabuleiroUsuario[posicaoY + 1][posicaoX] == '@');

            for (int j = 0; j < TAM_NAVIO_PEQUENO; j++) {
                tabuleiroUsuario[posicaoY][posicaoX] = '@';
                posicaoY++;
            }

        } else {

            do {
                posicaoX = lerInteiro("\nEscolha a posição x do navio (0 a 7): ", 0, TAM_TAB - TAM_NAVIO_PEQUENO);
                posicaoY = lerInteiro("Escolha a posição Y do navio (0 a 9): ", 0, TAM_TAB - 1);

                if (tabuleiroUsuario[posicaoY][posicaoX] == '@' ||
                    tabuleiroUsuario[posicaoY][posicaoX + 1] == '@') {
                        printf("\nPosição indicada é inválida!\n");
                }

            } while (tabuleiroUsuario[posicaoY][posicaoX] == '@' ||
                     tabuleiroUsuario[posicaoY][posicaoX + 1] == '@');

            for (int j = 0; j < TAM_NAVIO_PEQUENO; j++) {
                tabuleiroUsuario[posicaoY][posicaoX] = '@';
                posicaoX++;
            }
        }

        printf("Navio inserido corretamente\n");
        imprimirTabuleiro(tabuleiroUsuario);
        getch();
    }
}

void carregarTabuleiros(char tabuleiroComputador[TAM_TAB][TAM_TAB], char tabuleiroUsuario[TAM_TAB][TAM_TAB], char mascaraComputador[TAM_TAB][TAM_TAB], char mascaraUsuario[TAM_TAB][TAM_TAB]) {

    limparTabuleiro(mascaraComputador);
    limparTabuleiro(mascaraUsuario);

    limparTabuleiro(tabuleiroComputador);
    limparTabuleiro(tabuleiroUsuario);

    carregarTabuleiroComputador(tabuleiroComputador);
    carregarTabuleiroUsuario(tabuleiroUsuario);
}
