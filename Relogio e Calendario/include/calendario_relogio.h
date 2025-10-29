#pragma once

extern char *meses[];

void imprimirCabecalho();

// FUNÇÕES PARA ENTRADA DE VALORES

int lerInteiro(char *mensagem);

// FUNÇÕES DO CALENDÁRIO

int verBissexto(int ano);
int diasMeses(int mes, int ano);
int inicio_mes(int mes, int ano);
void calendario(int mes, int ano);
void calendarioMenu(int opcao);

// FUNÇÕES DO RELÓGIO

void relogio();
void cronometro();
void temporizador();
