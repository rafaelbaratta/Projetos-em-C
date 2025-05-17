#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include "adivinhacao.h"

int main() {
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));
    int acertou, resultado, valorMaximo, numeroEscolhido, numeroSorteado, vidas, dificuldade;
    char novoJogo;

    do {
        system("cls");
		printf("===============================================\n");
		printf("  **********  JOGO DE ADIVINHA��O  **********  \n");
		printf("===============================================\n\n");
        printf("       [1] Dificuldade f�cil\n");
        printf("       [2] Dificuldade m�dia\n");
        printf("       [3] Dificuldade dif�cil\n\n");
        printf("       [0] Encerrar o programa\n\n");
        printf("------------------------------------------------\n\n");

        printf("Escolha a dificuldade do jogo: ");
        do{
            while(scanf("%i", &dificuldade) != 1){
                printf("Valor inv�lido inserido!\nEscolha novamente: ");
                setbuf(stdin, NULL);
            }
            setbuf(stdin, NULL);

            if(dificuldade < 0 || dificuldade > 3){
                printf("Escolha um n�mero de 0 a 3: ");
            }

        } while(dificuldade < 0 || dificuldade > 3);

        if (dificuldade == 0){
            printf("\nEncerrando o programa!");
            return 0;
        }

        valorMaximo = escolherDificuldade(dificuldade);
        numeroSorteado = sortearNumero(valorMaximo);
        vidas = 10;
        acertou = 0;

        while(!acertou && vidas) {
            system("cls");
            printf("===============================================\n");
            printf("  **********  JOGO DE ADIVINHA��O  **********  \n");
            printf("===============================================\n\n");
            printf("Vidas restantes: %i\n\n", vidas);

            printf("Digite seu chute, um n�mero entre 1 e %i: ", valorMaximo);

            do{
                while(scanf("%i", &numeroEscolhido) != 1){
                    printf("Valor inv�lido inserido!\nEscolha novamente: ");
                    setbuf(stdin, NULL);
                }
                setbuf(stdin, NULL);

                if(numeroEscolhido < 0 || numeroEscolhido > valorMaximo){
                    printf("Escolha um n�mero de 1 a %i!", valorMaximo);
                }

            } while(numeroEscolhido < 0 || numeroEscolhido > valorMaximo);

            resultado = verificarAcerto(numeroEscolhido, numeroSorteado);

            if (resultado == 0){
                acertou = 1;
                break;
            } else {
                if (resultado == 1){
                    printf("\nO n�mero %i � maior que o n�mero sorteado!", numeroEscolhido);
                    vidas--;
                } else {
                    printf("\nO n�mero %i � menor que o n�mero sorteado!", numeroEscolhido);
                    vidas--;
                }
            }
            
            (void)_getch();

        }

        if (acertou){
			printf("\n\n|-------------------------|");
			printf("\n|  PARAB�NS! VOC� VENCEU  |");
			printf("\n|-------------------------|\n\n");
            printf("Voc� acertou o n�mero sorteado: %i", numeroSorteado);
        } else {
            printf("\n\n|-------------------------|");
			printf("\n|  QUE PENA! VOC� PERDEU  |");
			printf("\n|-------------------------|\n\n");
            printf("O n�mero sorteado era: %i", numeroSorteado);
        }

		printf("\n\nJogar novamente? (S / N): ");
        do {
			while (scanf(" %c", &novoJogo) != 1) {
				printf("Erro, entrada inv�lida!\nInsira outro valor: ");
				setbuf(stdin, NULL);
			}
			novoJogo = toupper(novoJogo);
			if (novoJogo != 'S' && novoJogo != 'N') {
				printf("\nResponda \'S\' para SIM e \'N\' para N�O: ");
			}
			setbuf(stdin, NULL);

		} while (novoJogo != 'S' && novoJogo != 'N');

    } while (novoJogo != 'N');

    return 0;
}