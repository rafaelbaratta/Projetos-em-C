#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include "calendario_relogio.h"

char *meses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

void imprimirCabecalho(){
    system("cls");
    printf("==============================================\n");
    printf("  *********  RELÓGIO E CALENDÁRIO  *********  \n");
    printf("==============================================\n\n");
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

// FUNÇÕES DO CALENDÁRIO

int verBissexto(int ano){
    if((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){
        return 1;
    } else {
        return 0;
    }
}

int diasMeses(int mes, int ano){
    int totalDias [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(mes == 2 && verBissexto(ano) == 1){
        totalDias[1] = 29;
    }

    return totalDias [mes - 1];
}

int inicio_mes(int mes, int ano){
    struct tm tempo = {0};

    tempo.tm_year = ano - 1900;
    tempo.tm_mon = mes - 1;
    tempo.tm_mday = 1;
    mktime(&tempo);

    return tempo.tm_wday;
}

void calendario(int mes, int ano){
    int inicio, dias, escolha, j;

    while(1){
        inicio = inicio_mes(mes, ano);
        dias = diasMeses(mes, ano);
        imprimirCabecalho();
        printf("----- %s de %i -----\n\n", meses[mes - 1], ano);
        printf("Dom Seg Ter Qua Qui Sex Sab\n");
        for(int i = 0; i < inicio; i++){
            printf(" -- ");
        }
        for(j = 1; j <= dias; j++){
            printf("%3i ", j);
            if((inicio + j) % 7 == 0){
                printf("\n");
            }
        }
        while((inicio + j) % 7 != 0){
            printf(" -- ");
            j++;
        }
        printf(" -- ");
        printf("\n\n   -------- Ações --------   \n\n");
        printf("(1) Mês anterior\n");
        printf("(2) Mês seguinte\n");
        printf("\n(0) Voltar ao menu\n");
        escolha = lerInteiro("\nOpção: ");

        switch(escolha){
        case 1:
            mes --;
            if(mes == 0){
                mes = 12;
                ano --;
                if(ano < 1970){
                    printf("\nImpossível voltar para o ano anterior!\n");
                    getch();
                    ano = 1970;
                    mes = 1;
                }
            }
            break;
        case 2:
            mes ++;
            if(mes == 13){
                mes = 1;
                ano ++;
            }
            break;
        case 0: return;
        default: printf("\nOpção inválida!"); getch();
        }
    }
}

void calendarioMenu(int opcao){
    int mes, ano;
    time_t t;
    struct tm * atual;

    if (opcao == 1){
        t = time(NULL);
        atual = localtime(&t);
        mes = atual->tm_mon + 1;
        ano = atual->tm_year + 1900;

    } else {
        do{
            ano = lerInteiro("\nDigite o ano: ");
            if(ano < 1970){
                printf("Apenas valores maiores ou iguais a 1970: ");
            }
        } while(ano < 1970);

        do{
            mes = lerInteiro("\nDigite o mês: ");
            if(mes <= 0 || mes > 12){
                printf("Digite um valor maior que 0 e menor ou igual a 12: ");
            }
        } while(mes <= 0 || mes > 12);
    }

    calendario(mes, ano);
    return;
}

// FUNÇÕES DO RELÓGIO

void relogio(){
    time_t tempo;
    struct tm * horario;
    char botao = '1';

    while (1) {
        imprimirCabecalho();
        printf("------------------ Relógio -------------------\n\n");
        printf("(0) Voltar ao menu\n\n");

        tempo = time(NULL);
        horario = localtime(&tempo);
        printf("      [%02d : %02d : %02d]\n\n",horario->tm_hour, horario->tm_min, horario->tm_sec);
        sleep(1);

        if (kbhit()){
            botao = getch();
        }

        switch (botao){
        case '0': 
            return;
        default: botao = '1';
        }
    }
}

void cronometro(){
    int decimos = 0, segundos = 0, minutos = 0, horas = 0, x = 1, inicio = 1;
    char botao;

    while (x){
        botao = '3';

        if (inicio == 1){
            imprimirCabecalho();
            printf("----------------- Cronômetro -----------------\n\n");
            printf("Aperte qualquer tecla para iniciar o cronômetro\n\n");
            printf("      [%02d : %02d : %02d : %02d]\n\n",horas, minutos, segundos, decimos);
            inicio = 0;
            getch();
        }

        imprimirCabecalho();
        printf("----------------- Cronômetro -----------------\n\n");
        printf("(0) Voltar ao menu\n");
        printf("(1) Reiniciar o cronômetro\n");
        printf("(2) Pausar o cronômetro\n\n");

        if (decimos == 10){
            decimos = 0;
            segundos ++;
        }
        if (segundos == 60){
            segundos = 0;
            minutos ++;
        }
        if (minutos == 60){
            minutos = 0;
            horas++;
        }
        
        printf("      [%d : %d : %d : %d]\n\n",horas, minutos, segundos, decimos);
        Sleep(100);
        decimos ++;

        if (kbhit()){
            botao = getch();
        }

        switch (botao){
            case '0': return;
            case '1': horas = 0; minutos = 0; segundos = 0; decimos = 0; inicio = 1; break;
            case '2': printf("*** Cronômetro Pausado ***\n\n"); printf("Pressione qualquer tecla para retornar..."); getch(); break;
            default: break;
        }
    }
}

void temporizador(){
    int i_segundos = 0, i_minutos = 0, i_horas = 0, segundos, minutos, horas, x = 1, inicio = 1;
    char botao = 0;

    while (x){
        botao = '4';

        if (inicio == 1){
            imprimirCabecalho();
            printf("---------------- Temporizador ----------------\n\n");
            printf("Ajuste o tempo que deseja seguindo o seguinte formato: 'hh mm ss'\n");
            i_horas = lerInteiro("\nHoras: ");
            i_minutos = lerInteiro("\nMinutos: ");
            i_segundos = lerInteiro("\nSegundos: ");
            horas = i_horas; minutos = i_minutos; segundos = i_segundos;
            inicio = 0;
        }

        imprimirCabecalho();
        printf("---------------- Temporizador ----------------\n\n");
        printf("(0) Voltar ao menu\n");
        printf("(1) Reiniciar o temporizador\n");
        printf("(2) Pausar o temporizador\n");
        printf("(3) Cancelar o temporizador\n\n");
        
        if (horas == 0 && minutos == 0){
            minutos = 0;
        } else {
            if (minutos == 0 && horas >= 0 && segundos == 0){
                minutos = 60; horas --;
            }
        }
        if (segundos == 0 && minutos == 0){
            segundos = 0;
        } else {
            if (segundos == 0 && minutos >= 0){
                segundos = 59; minutos --;
            }
        }
        if (horas == 0){
            horas = 0;
        }

        printf("      [%02d : %02d : %02d]\n\n",horas, minutos, segundos);
        sleep(1);

        if (kbhit()){
            botao = getch();
        }

        switch ((int) botao){
            case '0': return;
            case '1': horas = i_horas; minutos = i_minutos; segundos = i_segundos + 1; break;
            case '2': printf("*** Temporizador Pausado ***\n\n"); printf("Pressione qualquer tecla para retornar..."); getch(); break;
            case '3': inicio = 1; break;
            default: break;
        }
        if (segundos == 0 && minutos == 0 && horas == 0){
            printf("Tempo Esgotado\n\n");
            Beep(500,3000);
            printf("Pressione qualquer tecla para continuar..."); getch();
            inicio = 1;
        }
        segundos --;
    }
}
