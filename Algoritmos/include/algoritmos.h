#pragma once

void imprimirCabecalho();
void imprimirVetor(int vetor[], int quantidade);

// FUN��ES PARA ENTRADA DE VALORES

int lerInteiro(char *mensagem);

// FUN��ES PARA OS ALGORITMOS DE ORDENA��O

void selectionSort(int vetor[], int quantidade);
void bubbleSort(int vetor[], int quantidade);
void mergeSort(int vetor[], int esquerda, int direita);
void merge(int vetor[], int esquerda, int direita,int meio);

// FUN��ES DO MENU

void selectionSortMenu();
void bubbleSortMenu();
void mergeSortMenu();
