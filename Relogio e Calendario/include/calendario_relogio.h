#pragma once

extern char *meses[];

void imprimirCabecalho();

// FUN��ES PARA ENTRADA DE VALORES

int lerInteiro(char *mensagem);

// FUN��ES DO CALEND�RIO

int verBissexto(int ano);
int diasMeses(int mes, int ano);
int inicio_mes(int mes, int ano);
void calendario(int mes, int ano);
void calendarioMenu(int opcao);

// FUN��ES DO REL�GIO

void relogio();
void cronometro();
void temporizador();
