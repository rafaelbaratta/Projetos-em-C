#pragma once

#include <stdbool.h>

#define MAX_CARACTERES 300

extern const char ALFABETO_MAIUSCULO[27];
extern const char ALFABETO_MINUSCULO[27];

void imprimirCabecalho();

// FUN��ES PARA ENTRADA DE VALORES

int lerInteiro(char *mensagem);
char *lerString(char *mensagem);

// FUN��ES PARA MANIPULA��O DE CARACTERES

char caractereParaMaiusculas(char c);
char caractereParaMinusculas(char c);
char inverterCaixaCaractere(char c);

// FUN��ES PARA MANIPULA��O DE STRINGS

char *stringParaMaiusculas(char string[]);
char *stringParaMinusculas(char string[]);
char *inverterCaixaString(char string[]);
char *inverterString(char string[]);
char *concatenarStrings(char string1[], char string2[]);
char *removerEspacos(char string[]);

void copiarString(char destino[], char origem[]);
void removerQuebraLinha(char string[]);
int tamanhoString(char string[]);
bool compararStrings(char string1[], char string2[]);

// FUN��ES PARA VERIFICA��O DE CARACTERES

bool verificarVogal(char c);
bool verificarConsoante(char c);
bool verificarLetra(char c);
bool verificarEspacos(char c);

// FUN��ES PARA CONTAGEM DE LETRAS E PALAVRAS DE STRINGS

int contarLetras(char string[]);
int contarVogais(char string[]);
int contarConsoantes(char string[]);
int contarPalavras(char string[]);

// FUN��ES DE CODIFICA��O

char *codificarCesar(int chave, char texto[]);
char *decodificarCesar(int chave, char texto[]);
char *codificarSubstituicao(char chave[], char texto[]);
char *decodificarSubstituicao(char chave[], char texto[]);

// FUN��ES DO MENU

void alterarCaixaMenu(int tipo);
void inverterStringMenu();
void concatenarStringsMenu();
void compararStringsMenu();
void contagemMenu();
void verificarPalindromoMenu();
void cifraCesarMenu();
void cifraSubstituicaoMenu();
