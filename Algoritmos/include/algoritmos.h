#pragma once

void imprimirCabecalho();
void imprimirVetor(int vetor[], int quantidade);

// FUN합ES PARA ENTRADA DE VALORES

int lerInteiro(char *mensagem);

// FUN합ES PARA OS ALGORITMOS DE ORDENA플O

void selectionSort(int vetor[], int quantidade);
void bubbleSort(int vetor[], int quantidade);
void mergeSort(int vetor[], int esquerda, int direita);
void merge(int vetor[], int esquerda, int direita,int meio);

// FUN합ES DO MENU

void selectionSortMenu();
void bubbleSortMenu();
void mergeSortMenu();
