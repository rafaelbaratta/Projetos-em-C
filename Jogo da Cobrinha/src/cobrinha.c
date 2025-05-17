#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include "cobrinha.h"

Posicao cobra[TAM_MAX_COBRA];
Posicao comida;

Direcao direcao;

int tamanhoAtualCobra = 1;

int escolherDificuldade(int dificuldadeEscolhida){
    if(dificuldadeEscolhida == 3) {
        return 120;
    }
    if(dificuldadeEscolhida == 2) {
        return 250;
    }
    return 500;
}

void iniciarJogo(){
    cobra[0].y = ALTURA / 2;
    cobra[0].x = LARGURA / 2;
    
    for(int i = 1; i < TAM_MAX_COBRA; i++){
        cobra[i].x = cobra[i].y = 0;
    }

    posicionarComida();
}

void exibirTabuleiro(){
    for (int i = 0; i < LARGURA + 2; i++){
        printf("#");
    }
    printf("\n");

    for(int i = 1; i < ALTURA; i++){
        for(int j = 0; j < LARGURA + 2; j ++){
            if (j == 0 || j == LARGURA + 1){
                printf("#");
            } else {
                bool exibiuCorpo = false;
                if (j == cobra[0].x && i == cobra[0].y){
                    printf("@");
                } else {
                    if (j == comida.x && i == comida.y){
                        printf("O");
                } else {
                    for (int k = 1; k < tamanhoAtualCobra; k++){
                        if (cobra[k].x == j && cobra[k].y == i){
                            printf("0");
                            exibiuCorpo = true;
                        }
                    }
                    if (!exibiuCorpo){
                        printf(" ");
                    }
                }
                }
            }
        }
        printf("\n");
    }

    for (int i = 0; i < LARGURA + 2; i++){
        printf("#");
    }
}

void posicionarComida(){
    comida.x = (rand() % LARGURA) + 1;
    comida.y = (rand() % ALTURA) + 1;
}

void identificarComando(){
    if(_kbhit()){
        switch (tolower(_getch())) {
        case 'w':
            if(direcao != BAIXO){
                direcao = CIMA;
            }
            break;

        case 'a':
            if(direcao != DIREITA){
                direcao = ESQUERDA;
            }
            break;

        case 's':
            if(direcao != CIMA){
                direcao = BAIXO;
            }
            break;

        case 'd':
            if(direcao != ESQUERDA){
                direcao = DIREITA;
            }
            break;

        default:
            break;
        }
    }
}

void movimentacaoCobra(){
    int posicaoAtualX = cobra[0].x;
    int posicaoAtualY = cobra[0].y;

    for (int i = 1; i < tamanhoAtualCobra; i++){
        int auxiliarX = cobra[i].x;
        int auxiliarY = cobra[i].y;
        cobra[i].x = posicaoAtualX;
        cobra[i].y = posicaoAtualY;
        posicaoAtualX = auxiliarX;
        posicaoAtualY = auxiliarY;
    }

    switch (direcao) {
        case CIMA:
            cobra[0].y--;
            break;

        case ESQUERDA:
            cobra[0].x--;
            break;

        case BAIXO:
            cobra[0].y++;
            break;

        case DIREITA:
            cobra[0].x++;
            break;

        default:
            break;
    }

    identificarPegouComida();

}

bool identificarDerrota(){
    if (cobra[0].x == 0 || cobra[0].x == LARGURA + 1 || cobra[0].y == 0 || cobra[0].y == ALTURA + 1){
        return true;
    }

    for (int i = 1; i < tamanhoAtualCobra; i++){
        if (cobra[0].x == cobra[i].x && cobra[0].y == cobra[i].y){
            return true;
        }
    }
    
    return false;
}

void identificarPegouComida(){
    if (cobra[0].x == comida.x && cobra[0].y == comida.y){
        posicionarComida();
        tamanhoAtualCobra++;
    }
}

int pontuacaoJogo(){
    return (tamanhoAtualCobra - 1) * 10;
}
