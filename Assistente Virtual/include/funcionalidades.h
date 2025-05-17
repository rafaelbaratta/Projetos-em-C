#pragma once

// VARI�VEL GLOBAL

extern int aleatorio;

// FUN��ES DE COMANDOS

void conversaComando(char* comando);
void respostaComando(char* comando);
void minusculas(char* comando);
int validarComando(char* comando, char* opcoes[]);
void aleatorizarRespostas(char* comando[]);

// FUN��ES DE FUNCIONALIDADES

void exibirHorarios(void);
void exibirData(void);
void exibirComandos(void);
void piadas(void);
void curiosidades(void);
void travaLinguas(void);
void calcular(void);
