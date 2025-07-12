#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include "manipulacao.h"

int main() {
    setlocale(LC_ALL, "portuguese");
    int opcao;

    do {
        imprimirCabecalho();
        printf("       [1] Transformar em letras mai�sculas\n");
        printf("       [2] Transformar em letras min�sculas\n");
        printf("       [3] Inverter caixa dos caracteres\n");
        printf("       [4] Inverter string\n");
        printf("       [5] Concatenar strings\n");
        printf("       [6] Comparar strings\n");
        printf("       [7] Contar letras e palavras\n");
        printf("       [8] Verificar Pal�ndromos\n");
        printf("       [9] Cifra de C�sar\n");
        printf("       [10] Cifra de Substitui��o\n\n");
        printf("       [0] Encerrar o programa\n\n");
        printf("----------------------------------------------\n\n");

        opcao = lerInteiro("Escolha uma das op��es acima: ");

        switch (opcao) {
        case 0: break;
        case 1: alterarCaixaMenu(opcao); break;
        case 2: alterarCaixaMenu(opcao); break;
        case 3: alterarCaixaMenu(opcao); break;
        case 4: inverterStringMenu(); break;
        case 5: concatenarStringsMenu(); break;
        case 6: compararStringsMenu(); break;
        case 7: contagemMenu(); break;
        case 8: verificarPalindromoMenu(); break;
        case 9: cifraCesarMenu(); break;
        case 10: cifraSubstituicaoMenu(); break;
        default: printf("\nOp��o inv�lida! Tente novamente."); getch(); break;
        }

    } while (opcao != 0);
    
    return 0;
}
