#pragma once

#define MAX_NUM 100

// FUN��O PARA ORDENAR N�MEROS

void rol(double num[MAX_NUM], int qtd);

// FUN��ES DE MEDIDAS DE POSI��O

double CalculoMedia(double num[MAX_NUM], int qtd);
double CalculoMediana(double num[MAX_NUM], int qtd);
int CalculoModa(double num[MAX_NUM], int qtd);

// FUN��ES DE MEDIDAS DE DISPERS�O

double CalculoAmplitude(double num[MAX_NUM], int qtd);
double CalculoVariancia(double num[MAX_NUM], int qtd, double media);
double CalculoDesvio(double variancia);
double CalculoCoeficienteVariacao(double desvPadrao, double media);
