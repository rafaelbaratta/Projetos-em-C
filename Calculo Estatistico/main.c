#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "estatistica.h"

int main() {
	setlocale(LC_ALL, "portuguese");
	double media, moda, mediana;
	double amplitude, desvPadrao, variancia, coeficienteVariacao;
	double valores[MAX_NUM];
	char continuar;
	int quantidade;

	do {
		system("cls");
		printf("==============================================\n");
		printf("  *********  C�LCULO  ESTAT�STICO  *********  \n");
		printf("==============================================\n\n");

		printf("Digite a quantidade de n�meros (m�x. 100): ");
		do {
			while (scanf("%i", &quantidade) != 1) {
				printf("Erro, entrada inv�lida!\nInsira outro valor: ");
				setbuf(stdin, NULL);
			}

			if (quantidade <= 0) {
				printf("Quantidade deve ser maior que 0!\nInsira outro valor: ");
			}
			else {
				if (quantidade > 100) {
					printf("A quantidade m�xima de n�meros � 100!\nInsira outro valor: ");
				}
			}

			setbuf(stdin, NULL);
		} while (quantidade <= 0 || quantidade > 100);

		printf("\n-----------  Inser��o dos Valores  -----------\n\n");

		for (int i = 0; i < quantidade; i++) {
			printf("Digite o %i� valor da amostra: ", i + 1);
			while (scanf("%lf", &valores[i]) != 1) {
				printf("Erro, entrada inv�lida!\nInsira outro valor: ");
				setbuf(stdin, NULL);
			}
			setbuf(stdin, NULL);
		}

		// Realiza��o das opera��es

		rol(valores, quantidade);
		media = CalculoMedia(valores, quantidade);
		mediana = CalculoMediana(valores, quantidade);
		moda = valores[CalculoModa(valores, quantidade)];

		amplitude = CalculoAmplitude(valores, quantidade);
		variancia = CalculoVariancia(valores, quantidade, media);
		desvPadrao = CalculoDesvio(variancia);
		coeficienteVariacao = CalculoCoeficienteVariacao(desvPadrao, media);

		printf("\n----------  Resultados das Medidas  ----------\n\n");

		printf("Valores organizados em rol: ");
		for (int i = 0; i < quantidade; i++) {
			printf("%.2lf ", valores[i]);
		}

		printf("\n\nM�dia: %.2lf", media);
		printf("\nMediana: %.2lf", mediana);
		printf("\nModa: %.2lf", moda);

		printf("\n\nAmplitude: %.2lf", amplitude);
		printf("\nVari�ncia: %.2lf", variancia);
		printf("\nDesvio Padr�o: %.2lf", desvPadrao);
		printf("\nCoeficiente de Varia��o: %.2lf%%", coeficienteVariacao * 100);

		(void)_getch();
		
		printf("\n\n----------  Reiniciar ou Finalizar  ----------\n\n");

		printf("Fazer um novo c�lculo? (S / N): ");
		do {
			while (scanf("%c", &continuar) != 1) {
				printf("Erro, entrada inv�lida!\nInsira outro valor: ");
				setbuf(stdin, NULL);
			}
			
			continuar = toupper(continuar);
			if (continuar != 'S' && continuar != 'N') {
				printf("\nResponda \'S\' para SIM e \'N\' para N�O: ");
			}
			setbuf(stdin, NULL);

		} while (continuar != 'S' && continuar != 'N');

	} while (continuar != 'N');

	return 0;
}