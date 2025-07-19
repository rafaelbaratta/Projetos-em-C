#include <conio.h>
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
        printf("%i ", vetor[i]);
    }
}

// FUNÇÕES PARA ENTRADA DE VALORES

int lerInteiro(char *mensagem){
    int valor;

    printf("%s", mensagem);
    while (scanf(" %i", &valor) != 1) {
        printf("\nErro, entrada inválida!\n%s", mensagem);
        setbuf(stdin, NULL);
    }
    setbuf(stdin, NULL);

    return valor;
}

// FUNÇÕES PARA OS ALGORITMOS DE ORDENAÇÃO

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

// FUNÇÕES DO MENU

void selectionSortMenu(){
    imprimirCabecalho();
    printf("--------------- Selection Sort ----------------\n\n");

    int quantidade = lerInteiro("Digite quantos dígitos deseja inserir no vetor: ");

    int vetor[quantidade];
    for (int i = 0; i < quantidade; i++){
        vetor[i] = lerInteiro("Digite um valor: ");
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

    int quantidade = lerInteiro("Digite quantos dígitos deseja inserir no vetor: ");

    int vetor[quantidade];
    for (int i = 0; i < quantidade; i++){
        vetor[i] = lerInteiro("Digite um valor: ");
    }

    bubbleSort(vetor, quantidade);

    printf("\n\nVetor organizado: ");
    imprimirVetor(vetor, quantidade);

    getch();
    return;
}

void mergeSortMenu(){
    imprimirCabecalho();
    printf("----------------- Merge Sort ------------------\n\n");

    int quantidade = lerInteiro("Digite quantos dígitos deseja inserir no vetor: ");

    int vetor[quantidade];
    for (int i = 0; i < quantidade; i++){
        vetor[i] = lerInteiro("Digite um valor: ");
    }

    mergeSort(vetor, 0, quantidade - 1);

    printf("\n\nVetor organizado: ");
    imprimirVetor(vetor, quantidade);

    getch();
    return;
}
