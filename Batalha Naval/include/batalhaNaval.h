#pragma once

#define TAM_TAB 10
#define TAM_NAVIO_GRANDE 3
#define TAM_NAVIO_PEQUENO 2

#define QTD_NAVIOS_GRANDES 3
#define QTD_NAVIOS_PEQUENOS 3

#define TOTAL_ESPACOS_NAVIOS (QTD_NAVIOS_GRANDES * TAM_NAVIO_GRANDE + QTD_NAVIOS_PEQUENOS * TAM_NAVIO_PEQUENO)

void imprimirMenu();
int lerInteiro(char *mensagem, int min, int max);

// Funções para Controle das Jogadas

int realizarJogadaUsuario(char tabuleiro[TAM_TAB][TAM_TAB], char mascara[TAM_TAB][TAM_TAB]);
int realizarJogadaComputador(char tabuleiro[TAM_TAB][TAM_TAB], char mascara[TAM_TAB][TAM_TAB]);
int verificarVitoria(char mascara[TAM_TAB][TAM_TAB]);

// Funções para Controle dos Tabuleiros

void limparTabuleiro(char tabuleiro[TAM_TAB][TAM_TAB]);
void imprimirTabuleiro(char tabuleiro[TAM_TAB][TAM_TAB]);
void imprimirTabuleiros(char mascaraComputador[TAM_TAB][TAM_TAB], char mascaraUsuario[TAM_TAB][TAM_TAB]);

void carregarTabuleiroComputador(char tabuleiroComputador[TAM_TAB][TAM_TAB]);
void carregarTabuleiroUsuario(char tabuleiroUsuario[TAM_TAB][TAM_TAB]);
void carregarTabuleiros(char tabuleiroComputador[TAM_TAB][TAM_TAB], char tabuleiroUsuario[TAM_TAB][TAM_TAB], char mascaraComputador[TAM_TAB][TAM_TAB], char mascaraUsuario[TAM_TAB][TAM_TAB]);

