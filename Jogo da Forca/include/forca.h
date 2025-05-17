#pragma once

#include <stdbool.h>

#define MAX_PALAVRAS 100
#define TAM_PALAVRA 20
#define MAX_ERROS 7
#define ARQUIVO "./data/palavras"

extern char alfabeto[26];
extern char resultado[TAM_PALAVRA];
extern char palavraEscolhida [TAM_PALAVRA];

// FUN«’ES PARA CONTROLE DA PALAVRA SORTEADA

char* sortearPalavra(void);
int contarLetras(char* palavra);

// FUN«’ES PARA CONTROLE DO AMBIENTE DO JOGO

void inicializarJogo(void);
void exibirForca(int erros, int letras);
void exibirAlfabeto(void);
void excluirLetraAlfabeto(int letraEscolhida);

// FUN«’ES PARA A VERIFICA√á√ÉO DO CARACTERE ESCOLHIDO

bool validarCaractere(char letraEscolhida);
int validarLetra(char letraEscolhida, int letras);

// FUN«√O PARA VERIFICAR SE O JOGADOR GANHOU

bool verificarVitoria(void);
