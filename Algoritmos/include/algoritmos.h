#pragma once

void imprimirCabecalho();
void imprimirVetor(int vetor[], int quantidade);
void preencherVetor(int vetor[]);

// FUN합ES PARA ENTRADA DE VALORES

int lerInteiroPositivo(char *mensagem);

// FUN합ES PARA OS ALGORITMOS DE ORDENA플O

void insertionSort(int vetor[], int quantidade);
void selectionSort(int vetor[], int quantidade);
void bubbleSort(int vetor[], int quantidade);
void mergeSort(int vetor[], int esquerda, int direita);
void merge(int vetor[], int esquerda, int direita,int meio);

int buscaSequencial(int vetor[], int valor);
int buscaBinaria(int vetor[], int valor, int inicio, int final, int *passos);

// FUN합ES DO MENU

void insertionSortMenu();
void selectionSortMenu();
void bubbleSortMenu();
void mergeSortMenu();

void buscaSequencialMenu();
void buscaBinariaMenu();
