#include <stdlib.h>
#include <stdbool.h>
#include "adivinhacao.h"

int escolherDificuldade(int dificuldadeEscolhida){
    if(dificuldadeEscolhida == 1) {
        return 100;
    }
    if(dificuldadeEscolhida == 2) {
        return 250;
    }
    return 500;
}

int sortearNumero(int numeroFinal){
    return (rand() % numeroFinal) + 1;
}

int verificarAcerto(int numeroEscolhido, int numeroSorteado){
    if (numeroEscolhido == numeroSorteado){
        return 0;
    }
    return compararNumeros(numeroEscolhido, numeroSorteado);
}

int compararNumeros(int numeroEscolhido, int numeroSorteado){
    if (numeroEscolhido > numeroSorteado){
        return 1;
    }
    return -1;
}
