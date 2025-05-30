#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "operacoes.h"

// FUNÇÕES PARA VERIFICAÇÕES

void arquivoAberto(FILE *ponteiro){
    if(ponteiro == NULL){
        printf("\nErro na abertura do arquivo!\n");
        printf("\nPrograma encerrado!\n");
        getch();
        exit(EXIT_FAILURE);
    }
}

bool validarCpf(const char *cpf){
    if(strlen(cpf) != 11){
        return false;
    }

    for(unsigned int i = 0; i < strlen(cpf); i++){
        if(!isdigit(cpf[i])){
            return false;
        }
    }

    return true;
}

bool validarTelefone(const char *telefone){
    if(strlen(telefone) != 11 && strlen(telefone) != 10){
        return false;
    }

    for(unsigned int i = 0; i < strlen(telefone); i++){
        if(!isdigit(telefone[i])){
            return false;
        }
    }

    return true;
}

bool validarEmail(const char *email){
    int posicaoArroba = -1, posicaoPonto = -1;

    if(strlen(email) < 5){
        return false;
    }

    for(unsigned int i = 0; i < strlen(email); i++){
        if(email[i] == '@'){
            if(posicaoArroba == -1){
                posicaoArroba = i;
            } else {
                return false;
            }
        } else {
            if(email[i] == '.'){
                if(posicaoArroba != -1){
                    posicaoPonto = i;
                }
            }
        }
    }

    if(posicaoArroba < 1 || (unsigned)posicaoArroba > strlen(email) - 3){
        return false;
    }

    if(posicaoPonto == -1 || posicaoPonto < posicaoArroba + 2 || (unsigned)posicaoPonto > strlen(email) - 2){
        return false;
    }

    return true;

}

bool validarUnidadeFederativa(const char *estado){
    const char siglasExistentes[][3] = {"AC", "AL", "AM", "AP", "BA", "CE", "DF", "ES", "GO", "MA", "MG", "MT", "MS", "PA", "PB", "PE", "PI", "PR", "RJ", "RN", "RS", "RO", "RR", "SP", "SC", "SE", "TO"};

    if(strlen(estado) != 2){
        return false;
    }

    for(int i = 0; i < 27; i++){
        if(strcmp(estado, siglasExistentes[i]) == 0){
            return true;
        }
    }

    return false;
}

// FUNÇÕES PARA ENTRADA DE DADOS

void lerEntradaAlfanumerica(char *destino, size_t tamanho){
    fgets(destino, tamanho, stdin);
    destino[strcspn(destino, "\n")] = '\0';
}

int lerEntradaNumericaInteira(){
    int valor = 0;

    while(scanf("%i", &valor) != 1){
            printf("Erro, entrada inválida!\nInsira outro valor: ");
			limpezaBuffer();
        }
		limpezaBuffer();

    return valor;
}

double lerEntradaNumericaDecimal(){
    double valor = 0;

    while(scanf("%lf", &valor) != 1){
            printf("Erro, entrada inválida!\nInsira outro valor: ");
			limpezaBuffer();
        }
		limpezaBuffer();

    return valor;
}

// FUNÇÕES PARA MANIPULAÇÃO DE DADOS

void imprimirDados(Cadastro imprimir){
    printf("Criação: %i/%i/%i - %i:%i:%i\n\n", imprimir.data.tm_mday, imprimir.data.tm_mon + 1, 
            imprimir.data.tm_year + 1900, imprimir.data.tm_hour, imprimir.data.tm_min, imprimir.data.tm_sec);
    printf("Código: %i\n", imprimir.codigo);
    printf("Nome: %s\n", imprimir.nome);
    printf("CPF: %s\n", imprimir.cpf);
    printf("Telefone: %s\n", imprimir.telefone);
    printf("E-mail: %s\n", imprimir.email);
    printf("Salário: R$ %.2lf\n\n", imprimir.salario);
    printf("Rua: %s, %i\n", imprimir.endereco.rua, imprimir.endereco.numero);
    printf("Bairro: %s\n", imprimir.endereco.bairro);
    printf("Cidade: %s - %s\n", imprimir.endereco.cidade, imprimir.endereco.estado);
}

bool buscarDados(FILE *ponteiro, int codigoProcura, Cadastro *cadastros){
    rewind(ponteiro);

    while(fread(cadastros, sizeof(Cadastro), 1, ponteiro)){
        if(codigoProcura == cadastros->codigo && !cadastros->removido){
            return true;
        }
    }

    return false;
}

bool buscarDadosRemovidos(FILE *ponteiro, int codigoProcura, Cadastro *cadastros){
    rewind(ponteiro);

    while(fread(cadastros, sizeof(Cadastro), 1, ponteiro)){
        if(codigoProcura == cadastros->codigo && cadastros->removido){
            return true;
        }
    }

    return false;
}

// OUTRAS FUNÇÕES

void imprimirCabecalho(){
    system("cls");
    printf("===============================================\n");
    printf("  **********  CADASTRO DE USUÁRIO  **********  \n");
    printf("===============================================\n");
}

void limpezaBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int contarRegistros(){
    int registros = 0;
    FILE *ponteiro;
    Cadastro temporario;

    ponteiro = fopen(ARQUIVO, "rb");
    arquivoAberto(ponteiro);

    while(fread(&temporario, sizeof(temporario), 1, ponteiro) == 1){
        registros ++;
    }

    fclose(ponteiro);

    return registros;
}

char validarCaractere(){
    char continuar;
    do {
        scanf(" %c", &continuar);
        limpezaBuffer();
        continuar = toupper(continuar);

        if(continuar != 'S' && continuar != 'N'){
            printf("\nOpção inválida selecionada!\nResponda apenas com 'S' (sim) ou 'N' (não): ");
        }

    } while (continuar != 'S' && continuar != 'N');

    return continuar;
}
