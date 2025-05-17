#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "funcionalidades.h"

char* sair[] = { "sair", "finalizar", "encerrar", "fechar", NULL };

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "portuguese");
    char mensagem[300];

    printf("===============================================\n");
    printf("  **********  ASSISTENTE  VIRTUAL  **********  \n");
    printf("===============================================\n");
    printf(" (evite acentos e outros caracteres especiais) \n\n");
    printf("- Olá, eu sou Sara, sua assistente virtual, em que posso ajudar?\n\n");

    do {
        printf("Você: ");
        fgets(mensagem, sizeof(mensagem), stdin);
        setbuf(stdin, NULL);

        mensagem[strcspn(mensagem, "\n")] = '\0';
        minusculas(mensagem);

        if (validarComando(mensagem, sair)) {
            printf("\nSara: Saindo... Espero ter te ajudado com tudo. Te vejo em breve!\n");
            break;
        }

        conversaComando(mensagem);

    } while (!validarComando(mensagem, sair));

    return 0;
}