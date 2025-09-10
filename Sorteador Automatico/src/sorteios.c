#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include "sorteios.h"

void atribuir(int cjt, int* conjunto) {
	for (int i = 0; i < (cjt); i++) {
		conjunto[i] = i;
	}
}

void embaralhar(int cjt, int* conjunto) {
	int controle, reserva;

	for (int i = cjt - 1; i > 0; i--) {
		controle = rand() % (i + 1);
		reserva = conjunto[i];
		conjunto[i] = conjunto[controle];
		conjunto[controle] = reserva;
	}
}

int sorteio(int cjt) {
	return rand() % (cjt);
}

void numeros() {
	int inicial, final, quantidade, intervalo, resultado[MAX_QTD];
	char repeticao, continuar;

	do {
		system("cls");
		printf("==============================================\n");
		printf("  *********  SORTEADOR AUTOMÁTICO  *********  \n");
		printf("==============================================\n\n");
		printf("-------------  Sortear  Números  -------------\n\n");

		printf("Digite o número inicial: ");
		while (scanf(" %i", &inicial) != 1) {
			printf("\nErro, entrada inválida!\nDigite novamente: ");
			setbuf(stdin, NULL);
		}
		setbuf(stdin, NULL);

		do {
			printf("Digite o número final: ");
			while (scanf(" %i", &final) != 1) {
				printf("\nErro, entrada inválida!\nDigite novamente: ");
				setbuf(stdin, NULL);
			}
			setbuf(stdin, NULL);
			if (final <= inicial) {
				printf("O número final deve ser maior que o inicial!\n");
			}
		} while (final <= inicial);

		intervalo = final - inicial + 1;

		do {
			printf("\nOs números podem repetir?\nS - Sim | N - Não: ");
			while (scanf(" %c", &repeticao) != 1) {
				printf("\nErro, entrada inválida!\nDigite novamente: ");
				setbuf(stdin, NULL);
			}
			setbuf(stdin, NULL);
			repeticao = toupper(repeticao);
			if (repeticao != 'N' && repeticao != 'S') {
				printf("Digite apenas S para sim ou N para não!\n");
			}
		} while (repeticao != 'N' && repeticao != 'S');

		if (repeticao == 'S') {

			do {
				printf("\nDigite a quantidade de números a ser sorteados (máx. 100): ");
				while (scanf(" %i", &quantidade) != 1) {
					printf("\nErro, entrada inválida!\nDigite novamente: ");
					setbuf(stdin, NULL);
				}
				setbuf(stdin, NULL);
				if (quantidade > 100) {
					printf("Quantidade ultrapassa o limite!\n");
				}
				else {
					if (quantidade <= 0) {
						printf("Quantidade não pode ser menor ou igual a 0!\n");
					}
				}
			} while (quantidade > 100 || quantidade <= 0);

			printf("\nValore(s) sorteado(s): ");
			for (int a = 0; a < quantidade; a++) {
				resultado[a] = inicial + sorteio(intervalo);
				printf("%i", resultado[a]);
				if (a < quantidade - 1) {
					printf(", ");
				}
				else {
					printf(".\n\n");
				}
			}
		}
		else {
			do {
				printf("\nDigite a quantidade de números a ser sorteados: ");
				while (scanf(" %i", &quantidade) != 1) {
					printf("\nErro, entrada inválida!\nDigite novamente: ");
					setbuf(stdin, NULL);
				}
				setbuf(stdin, NULL);
				if (quantidade > intervalo) {
					printf("Quantidade é maior que o total de números!\n");
				}
				else {
					if (quantidade <= 0) {
						printf("Quantidade não pode ser menor ou igual a 0!\n");
					}
				}
			} while (quantidade > intervalo || quantidade <= 0);

			int* conjunto;
			conjunto = malloc(intervalo * sizeof(int));
			atribuir(intervalo, conjunto);
			embaralhar(intervalo, conjunto);

			printf("\nValore(s) sorteado(s): ");
			for (int b = 0; b < quantidade; b++) {
				printf("%i", inicial + conjunto[b]);
				if (b < quantidade - 1) {
					printf(", ");
				}
				else {
					printf(".\n\n");
				}
			}
			free(conjunto);
		}

		do {
			printf("Realizar outro sorteio?\nS - Sim | N - Não: ");
			while (scanf(" %c", &continuar) != 1) {
				printf("\nErro, entrada inválida!\nDigite novamente: ");
				setbuf(stdin, NULL);
			}
			setbuf(stdin, NULL);
			continuar = toupper(continuar);
			if (continuar != 'N' && continuar != 'S') {
				printf("Digite apenas S para sim ou N para não!\n");
			}
		} while (continuar != 'N' && continuar != 'S');

	} while (continuar != 'N');

	printf("\nPressione ENTER para retornar\n");
	if (_getch()) {
		return;
	}
}

void nomes() {
	char continuar, repeticao, nomes[MAX_QTD][50];
	int quantidade, total;

	do {
		system("cls");
		printf("==============================================\n");
		printf("  *********  SORTEADOR AUTOMÁTICO  *********  \n");
		printf("==============================================\n\n");
		printf("--------------  Sortear  Nomes  --------------\n\n");

		do {
			printf("Digite a quantidade total de nomes que deseja inserir (max. 100): ");
			while (scanf(" %i", &total) != 1) {
				printf("\nErro, entrada inválida!\nDigite novamente: ");
				setbuf(stdin, NULL);
			}
			setbuf(stdin, NULL);
			if (total > 100) {
				printf("Quantidade ultrapassa o limite!\n");
			}
			else {
				if (total <= 0) {
					printf("Quantidade não pode ser menor ou igual a 0!\n");
				}
			}
		} while (total > 100 || total <= 0);

		for (int i = 0; i < total; i++) {
			printf("Digite o %i° nome: ", i + 1);
			fgets(nomes[i], 50, stdin);
			setbuf(stdin, NULL);
			nomes[i][strcspn(nomes[i], "\n")] = '\0';
		}

		do {
			printf("\nOs nomes podem repetir?\nS - Sim | N - não: ");
			while (scanf(" %c", &repeticao) != 1) {
				printf("\nErro, entrada inválida!\nDigite novamente: ");
				setbuf(stdin, NULL);
			}
			setbuf(stdin, NULL);
			repeticao = toupper(repeticao);
			if (repeticao != 'N' && repeticao != 'S') {
				printf("Digite apenas S para sim ou N para não!\n");
			}
		} while (repeticao != 'N' && repeticao != 'S');

		if (repeticao == 'S') {

			do {
				printf("\nDigite a quantidade de nomes a ser sorteados (máx. 100): ");
				while (scanf(" %i", &quantidade) != 1) {
					printf("\nErro, entrada inválida!\nDigite novamente: ");
					setbuf(stdin, NULL);
				}
				setbuf(stdin, NULL);
				if (quantidade > 100) {
					printf("Quantidade ultrapassa o limite!\n");
				}
				else {
					if (quantidade <= 0) {
						printf("Quantidade não pode ser menor ou igual a 0!\n");
					}
				}
			} while (quantidade > 100 || quantidade <= 0);

			printf("\nValore(s) sorteado(s): ");
			for (int a = 0; a < quantidade; a++) {
				printf("%s", nomes[sorteio(total)]);
				if (a < quantidade - 1) {
					printf(", ");
				}
				else {
					printf(".\n\n");
				}
			}
		}
		else {
			do {
				printf("\nDigite a quantidade de nomes a sortear: ");
				while (scanf(" %i", &quantidade) != 1) {
					printf("\nErro, entrada inválida!\nDigite novamente: ");
					setbuf(stdin, NULL);
				}
				setbuf(stdin, NULL);
				if (quantidade > total) {
					printf("Quantidade é maior que o número total de nomes!\n");
				}
				else {
					if (quantidade <= 0) {
						printf("Quantidade não pode ser menor ou igual a 0!\n");
					}
				}
			} while (quantidade > total || quantidade <= 0);

			int* conjunto;
			conjunto = malloc(total * sizeof(int));
			atribuir(total, conjunto);
			embaralhar(total, conjunto);

			printf("\nValore(s) sorteado(s): ");
			for (int b = 0; b < quantidade; b++) {
				printf("%s", nomes[conjunto[b]]);
				if (b < quantidade - 1) {
					printf(", ");
				}
				else {
					printf(".\n\n");
				}
			}
			free(conjunto);
		}

		do {
			printf("Realizar outro sorteio?\nS - Sim | N - Não: ");
			while (scanf(" %c", &continuar) != 1) {
				printf("\nErro, entrada inválida!\nDigite novamente: ");
				setbuf(stdin, NULL);
			}
			setbuf(stdin, NULL);
			continuar = toupper(continuar);
			if (continuar != 'N' && continuar != 'S') {
				printf("Digite apenas S para sim ou N para não!\n");
			}
		} while (continuar != 'N' && continuar != 'S');

	} while (continuar != 'N');

	printf("\nPressione ENTER para retornar\n");
	if (_getch()) {
		return;
	}
}

void moeda() {
	char continuar;
	int moeda;

	do {
		system("cls");
		printf("==============================================\n");
		printf("  *********  SORTEADOR AUTOMÁTICO  *********  \n");
		printf("==============================================\n\n");
		printf("---------------  Cara ou Coroa  --------------\n\n");

		printf("Aperte qualquer tecla para jogar a moeda\n");
		if (_getch()) {
			moeda = 1 + sorteio(2);
		}

		if (moeda == 1) {
			printf("CARA!\n");
		}
		else {
			printf("COROA!\n");
		}

		do {
			printf("\nJogar a moeda novamente?\nS - Sim | N - Não: ");
			while (scanf(" %c", &continuar) != 1) {
				printf("\nErro, entrada inválida!\nDigite novamente: ");
				setbuf(stdin, NULL);
			}
			setbuf(stdin, NULL);
			continuar = toupper(continuar);
			if (continuar != 'N' && continuar != 'S') {
				printf("Digite apenas S para sim ou N para não!\n");
			}
		} while (continuar != 'N' && continuar != 'S');

	} while (continuar != 'N');

	printf("\nPressione ENTER para retornar\n");
	if (_getch()) {
		return;
	}

}

void dados() {
	char continuar;
	int lados, dados, valor;

	do {
		system("cls");
		printf("==============================================\n");
		printf("  *********  SORTEADOR AUTOMÁTICO  *********  \n");
		printf("==============================================\n\n");
		printf("---------------  Jogar  Dados  ---------------\n\n");

		do {
			printf("Digite o número de lados do dado (min. 4): ");
			while (scanf(" %i", &lados) != 1) {
				printf("\nErro, entrada inválida!\nDigite novamente: ");
				setbuf(stdin, NULL);
			}
			setbuf(stdin, NULL);;
			if (lados < 4) {
				printf("número de lados do dado não pode ser menor que 4!\n");
			}
		} while (lados < 4);

		do {
			printf("Digite o número de dados a jogar: ");
			while (scanf(" %i", &dados) != 1) {
				printf("\nErro, entrada inválida!\nDigite novamente: ");
				setbuf(stdin, NULL);
			}
			setbuf(stdin, NULL);
			if (dados <= 0) {
				printf("número de dados deve ser maior que 0!\n");
			}
		} while (dados <= 0);

		printf("\nValore(s) sorteado(s): ");
		for (int a = 0; a < dados; a++) {
			valor = 1 + sorteio(lados);
			printf("%i ", valor);
		}

		do {
			printf("\n\nJogar os dados novamente?\nS - Sim | N - Não: ");
			while (scanf(" %c", &continuar) != 1) {
				printf("\nErro, entrada inválida!\nDigite novamente: ");
				setbuf(stdin, NULL);
			}
			setbuf(stdin, NULL);
			continuar = toupper(continuar);
			if (continuar != 'N' && continuar != 'S') {
				printf("Digite apenas S para sim ou N para não!\n");
			}
		} while (continuar != 'N' && continuar != 'S');

	} while (continuar != 'N');

	printf("\nPressione ENTER para retornar\n");
	if (_getch()) {
		return;
	}
}

void loteria() {
	bool invalido;
	int escolha[6], loteria[60];
	char continuar;

	do {
		system("cls");
		printf("==============================================\n");
		printf("  *********  SORTEADOR AUTOMÁTICO  *********  \n");
		printf("==============================================\n\n");
		printf("-----------  Simulador de Loteria  -----------\n\n");

		printf("Escolha 6 números de 1 a 60: \n");
		for (int i = 0; i < 6; i++) {
			do {
				invalido = false;
				printf(" - %i° Valor: ", i + 1);
				while (scanf(" %i", &escolha[i]) != 1) {
					printf("\nErro, entrada inválida!\nDigite novamente: ");
					setbuf(stdin, NULL);
				}
				setbuf(stdin, NULL);
				if (escolha[i] > 60 || escolha[i] < 1) {
					printf("Escolha um valor de 1 a 60!\n");
				}
				for (int j = 0; j < i; j++) {
					if (escolha[i] == escolha[j]) {
						printf("Não é possível escolher números repetidos!\n");
						invalido = true;
						break;
					}
				}
			} while (escolha[i] > 60 || escolha[i] < 1 || invalido == true);
		}

		atribuir(60, loteria);
		embaralhar(60, loteria);

		printf("\nValores escolhidos: ");
		for (int j = 0; j < 6; j++) {
			printf("%i ", escolha[j]);
		}

		printf("\n\nValores sorteados: ");
		for (int j = 0; j < 6; j++) {
			printf("%i ", loteria[j] + 1);
		}

		do {
			printf("\n\nRealizar um novo sorteio?\nS - Sim | N - Não: ");
			while (scanf(" %c", &continuar) != 1) {
				printf("\nErro, entrada inválida!\nDigite novamente: ");
				setbuf(stdin, NULL);
			}
			setbuf(stdin, NULL);
			continuar = toupper(continuar);
			if (continuar != 'N' && continuar != 'S') {
				printf("Digite apenas S para sim ou N para não!\n");
			}
		} while (continuar != 'N' && continuar != 'S');

	} while (continuar != 'N');

	printf("\nPressione ENTER para retornar\n");
	if (_getch()) {
	}

}
