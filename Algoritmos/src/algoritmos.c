#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.h"

void imprimirCabecalho(){
    system("cls");
    printf("===============================================\n");
    printf("  ********  ALGORITMOS DE ORDENAÇÃO  ********  \n");
    printf("===============================================\n\n");
}

void imprimirVetor(int vetor[], int quantidade){
    for (int i = 0; i < quantidade; i++){
        if (vetor[i] == -1){
            printf("- ");
            continue;
        }
        printf("%i ", vetor[i]);
    }
}

void preencherVetor(int vetor[]){
    for (int i = 0; i < 100; i++){
        vetor[i] = i + 1;
    }
}

// FUNÇÕES PARA ENTRADA DE VALORES

int lerInteiroPositivo(char *mensagem){
    int valor;

    printf("%s", mensagem);
    do{
        while (scanf(" %i", &valor) != 1) {
            printf("\nErro, entrada inválida!\n%s", mensagem);
            setbuf(stdin, NULL);
        }
        setbuf(stdin, NULL);

        if(valor < 0){
            printf("\nO valor digitado ser maior ou igual a 0: ");
        }

    } while (valor < 0);

    return valor;
}

// FUNÇÕES PARA OS ALGORITMOS DE ORDENAÇÃO

void insertionSort(int vetor[], int quantidade){
    for (int i = 1; i < quantidade; i++){
        int chave = vetor[i];
        int j = i - 1;

        while (chave < vetor[j] && j >= 0){
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = chave;

        printf("\n%i° Passo: ", i);
        imprimirVetor(vetor, quantidade);
    }
}

void selectionSort(int vetor[], int quantidade){
    int menorIndice, temporario, i, j;

    for (i = 0; i < quantidade - 1; i++){
        menorIndice = i;
        for (j = i + 1; j < quantidade; j++){
            if (vetor[j] < vetor[menorIndice]){
                menorIndice = j;
            }
        }
        temporario = vetor[i];
        vetor[i] = vetor[menorIndice];
        vetor[menorIndice] = temporario;

        printf("\n%i° Passo: ", i + 1);
        imprimirVetor(vetor, quantidade);
    }
}

void bubbleSort(int vetor[], int quantidade){
    int temporario;

    for (int i = 0; i < quantidade - 1; i++){
        for (int j = 0; j < quantidade - i - 1; j++){
            if (vetor[j + 1] < vetor[j]){
                temporario = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temporario;
            }
        }
        printf("\n%i° Passo: ", i + 1);
        imprimirVetor(vetor, quantidade);
    }
}

void mergeSort(int vetor[], int esquerda, int direita){
    if (esquerda < direita){
        int meio = esquerda + (direita - esquerda) / 2;

        mergeSort(vetor, esquerda, meio);
        mergeSort(vetor, meio + 1, direita);

        merge(vetor, esquerda, direita, meio);
    }
}

void merge(int vetor[], int esquerda, int direita, int meio){
    int lado1 = meio - esquerda + 1;
    int lado2 = direita - meio;

    int vetorEsq[lado1], vetorDir[lado2];

    for (int i = 0; i < lado1; i++){
        vetorEsq[i] = vetor[esquerda + i];
    }
    for (int j = 0; j < lado2; j++){
        vetorDir[j] = vetor[meio + j + 1];
    }

    int i = 0, j = 0, k = esquerda;

    while (i < lado1 && j < lado2){
        if(vetorEsq[i] <= vetorDir[j]){
            vetor[k++] = vetorEsq[i++];
        } else {
            vetor[k++] = vetorDir[j++];
        }
    }

    while (i < lado1){
        vetor[k++] = vetorEsq[i++];
    }

    while (j < lado2){
        vetor[k++] = vetorDir[j++];
    }

}


int buscaSequencial(int vetor[], int valor){
    for (int i = 0; i < 100; i++){
        if (vetor[i] == valor) {
            printf("\n%i° Passo: %i - Igual", i + 1, vetor[i]);
            return i + 1;
        }

        printf("\n%i° Passo: %i - Diferente", i + 1, vetor[i]);
    }

    return 0;
}

int buscaBinaria(int vetor[], int valor, int inicio, int final, int *passos){
    int meio = (final + inicio) / 2;
    *passos = *passos + 1;

    if (inicio > final){
        return 0;
    }

    if (valor > vetor[meio]){
        printf("\n%i Passo: %i - Maior", *passos, vetor[meio]);
        return buscaBinaria(vetor, valor, meio + 1, final, passos);
    } else {
        if (valor < vetor[meio]){
            printf("\n%i Passo: %i - Menor", *passos, vetor[meio]);
            return buscaBinaria(vetor, valor, inicio, meio - 1, passos);
        } else {
            return 1;
        }
    } 
}

// FUNÇÕES DO MENU

void insertionSortMenu(){
    imprimirCabecalho();
    printf("--------------- Insertion  Sort ---------------\n\n");

    int quantidade = lerInteiroPositivo("Digite quantos dígitos deseja inserir no vetor: ");

    int vetor[quantidade];
    for (int i = 0; i < quantidade; i++){
        vetor[i] = lerInteiroPositivo("Digite um valor: ");
    }

    insertionSort(vetor, quantidade);

    printf("\n\nVetor organizado: ");
    imprimirVetor(vetor, quantidade);

    getch();
    return;
}

void selectionSortMenu(){
    imprimirCabecalho();
    printf("--------------- Selection  Sort ---------------\n\n");

    int quantidade = lerInteiroPositivo("Digite quantos dígitos deseja inserir no vetor: ");

    int vetor[quantidade];
    for (int i = 0; i < quantidade; i++){
        vetor[i] = lerInteiroPositivo("Digite um valor: ");
    }

    selectionSort(vetor, quantidade);

    printf("\n\nVetor organizado: ");
    imprimirVetor(vetor, quantidade);

    getch();
    return;
}

void bubbleSortMenu(){
    imprimirCabecalho();
    printf("----------------- Bubble Sort -----------------\n\n");

    int quantidade = lerInteiroPositivo("Digite quantos dígitos deseja inserir no vetor: ");

    int vetor[quantidade];
    for (int i = 0; i < quantidade; i++){
        vetor[i] = lerInteiroPositivo("Digite um valor: ");
    }

    bubbleSort(vetor, quantidade);

    printf("\n\nVetor organizado: ");
    imprimirVetor(vetor, quantidade);

    getch();
    return;
}

void mergeSortMenu(){
    imprimirCabecalho();
    printf("----------------- Merge  Sort -----------------\n\n");

    int quantidade = lerInteiroPositivo("Digite quantos dígitos deseja inserir no vetor: ");

    int vetor[quantidade];
    for (int i = 0; i < quantidade; i++){
        vetor[i] = lerInteiroPositivo("Digite um valor: ");
    }

    mergeSort(vetor, 0, quantidade - 1);

    printf("\n\nVetor organizado: ");
    imprimirVetor(vetor, quantidade);

    getch();
    return;
}


void buscaSequencialMenu(){
    imprimirCabecalho();
    printf("-------------- Busca  Sequencial --------------\n\n");

    int valor = lerInteiroPositivo("Digite o valor que deseja buscar no vetor (1 a 100): ");

    int vetor[100];
    preencherVetor(vetor);
    int passos = buscaSequencial(vetor, valor);

    if (passos == 0){
        printf("\n\nValor inserido não está no vetor!");
    } else {
        printf("\n\nValor %i encontrado em %i passos", valor, passos);
    }

    getch();
    return;
}

void buscaBinariaMenu(){
    imprimirCabecalho();
    printf("---------------- Busca Binária ----------------\n\n");

    int valor = lerInteiroPositivo("Digite o valor que deseja buscar no vetor (1 a 100): ");

    int vetor[100];
    preencherVetor(vetor);
    int passos = 0, *ponteiro;
    ponteiro = &passos;
    int encontrado = buscaBinaria(vetor, valor, 0, 99, ponteiro);

    if (!encontrado){
        printf("\n\nValor inserido não está no vetor!");
    } else {
        printf("\n\nValor %i encontrado em %i passos", valor, passos);
    }

    getch();
    return;
}
