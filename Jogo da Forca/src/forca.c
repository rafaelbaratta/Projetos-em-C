#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "forca.h"

char alfabeto [26];
char resultado [TAM_PALAVRA];
char palavraEscolhida [TAM_PALAVRA];

char* sortearPalavra(){
    int linhaEscolhida = rand () % MAX_PALAVRAS;

    FILE* fptr = fopen(ARQUIVO, "r");
    if (fptr == NULL){
        printf("\nErro ao abrir o arquivo!");
        return NULL;
    }

    for (int i = 0; i < linhaEscolhida; i++ ) {
        if (!fgets(palavraEscolhida, TAM_PALAVRA, fptr)) {
            fclose(fptr);
            return NULL;
        }
    }

    palavraEscolhida[strcspn(palavraEscolhida, "\n")] = '\0';
    fclose(fptr);
    return palavraEscolhida;
}

int contarLetras(char* palavra){
    return strlen(palavra);
}

void inicializarJogo(){
    memset(resultado, '\0', TAM_PALAVRA);

    for (int i = 0; i < 26; i++){
        alfabeto[i] = i + 65;
    }
}

void exibirForca(int erros, int letras){
    printf("\nErros: %d/%d\n", erros, MAX_ERROS);
    printf(" _______\n");
    printf(" |     |\n");
    printf(" |     %c\n", (erros >= 1 ? 'O' : ' '));
    printf(" |    %c%c%c\n", (erros >= 3 ? '/' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 4 ? '\\' : ' '));
    printf(" |    %c %c\n", (erros >= 5 ? '/' : ' '), (erros >= 6 ? '\\' : ' '));
    printf("_|_\n\n");

    for (int i = 0; i < letras; i++ ) {
        if (resultado[i] != '\0'){
            printf(" %c ", resultado[i]);
        } else {
            printf(" _ ");
        }
    }

    printf("\n\n");
}

void exibirAlfabeto(){
    for (size_t i = 0; i < 26; i++){
        printf(" %c ", alfabeto[i]);
        if ((i + 1) % 13 == 0){
            printf("\n");
        }
    }
}

void excluirLetraAlfabeto(int letraEscolhida){
    for (size_t i = 0; i < 26; i++){
        if (letraEscolhida == alfabeto[i]){
            alfabeto[i] = ' ';
        }
    }
}

bool validarCaractere(char letraEscolhida){
    if ((int)letraEscolhida < 65 || (int)letraEscolhida > 90){
        return false;
    }
    return true;
}

int validarLetra(char letraEscolhida, int letras){
    int validacao = 0;

    for (int i = 0; i < 26; i++){
        if (letraEscolhida == alfabeto[i]){
            validacao = -1;
            excluirLetraAlfabeto(letraEscolhida);
            break;
        }
    }


    if (validacao == 0){
        return validacao;
    }

    for (int i = 0; i < letras; i++){
        if (letraEscolhida == palavraEscolhida[i]) {
            resultado[i] = letraEscolhida;
            validacao = 1;
        }
    }

    return validacao;
}

bool verificarVitoria(){
    if (strcmp(palavraEscolhida, resultado) == 0){
        return true;
    }
    return false;
}
