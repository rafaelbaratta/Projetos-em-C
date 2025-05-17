#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>
#include "comandos.h"
#include "funcionalidades.h"

int aleatorio;

void aleatorizarRespostas(char* comando[]) {
    aleatorio = rand() % 5;
    printf("%s\n\n", comando[aleatorio]);
}

void conversaComando(char* comando) {
    printf("\nSara: ");
    if (validarComando(comando, aniversario)) {
        aleatorizarRespostas(aniversarioRespostas);
        return;
    }
    if (validarComando(comando, bomDia)) {
        aleatorizarRespostas(bomDiaRespostas);
        return;
    }
    if (validarComando(comando, boaTarde)) {
        aleatorizarRespostas(boaTardeRespostas);
        return;
    }
    if (validarComando(comando, boaNoite)) {
        aleatorizarRespostas(boaNoiteRespostas);
        return;
    }
    if (validarComando(comando, comoVai)) {
        aleatorizarRespostas(comoVaiRespostas);
        return;
    }
    if (validarComando(comando, tudoBem)) {
        aleatorizarRespostas(tudoBemRespostas);
        return;
    }
    if (validarComando(comando, tudoMal)) {
        aleatorizarRespostas(tudoMalRespostas);
        return;
    }
    if (validarComando(comando, legal)) {
        aleatorizarRespostas(legalRespostas);
        return;
    }
    if (validarComando(comando, obrigado)) {
        aleatorizarRespostas(obrigadoRespostas);
        return;
    }
    if (validarComando(comando, ola)) {
        aleatorizarRespostas(olaRespostas);
        return;
    }
    if (validarComando(comando, tchau)) {
        aleatorizarRespostas(tchauRespostas);
        return;
    }
    respostaComando(comando);
}

void respostaComando(char* comando) {
    if (validarComando(comando, ajuda)) {
        printf("Precisa de ajuda? Aqui estão alguns comandos existentes: \n");
        exibirComandos();
        return;
    }
    if (validarComando(comando, horas)) {
        printf("Horário atual: ");
        exibirHorarios();
        return;
    }
    if (validarComando(comando, hoje)) {
        printf("Hoje é ");
        exibirData();
        return;
    }
    if (validarComando(comando, limpar)) {
        system("cls");
        printf("==============================================\n");
        printf("  **********  ASSISTENTE VIRTUAL  **********  \n");
        printf("==============================================\n");
        printf(" (evite acentos e outros caracteres especiais) \n\n");
        return;
    }
    if (validarComando(comando, piada)) {
        printf("Claro, aqui vai uma piada: ");
        piadas();
        return;
    }
    if (validarComando(comando, curiosidade)) {
        printf("Claro, aqui vai uma curiosidade: ");
        curiosidades();
        return;
    }
    if (validarComando(comando, travaLingua)) {
        printf("Claro, aqui vai um trava-língua: ");
        travaLinguas();
        return;
    }
    if (validarComando(comando, calculos)) {
        printf("Qual conta você gostaria que eu resolvesse?\n\n");
        calcular();
        return;
    }

    printf("Desculpa, não entendi o que você queria dizer, pode reformular? Se não conhecer os comandos digite \"ajuda\"\n\n");
}

void minusculas(char* comando) {
    int i = 0;
    while (comando[i]) {
        comando[i] = tolower(comando[i]);
        i++;
    }
}

int validarComando(char* comando, char* opcoes[]) {
    for (int i = 0; opcoes[i] != NULL; i++) {
        if (strstr(comando, opcoes[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

void exibirComandos() {
    printf("1. Sair\n");
    printf("2. Ajuda\n");
    printf("3. Data\n");
    printf("4. Hora\n");
    printf("5. Limpar\n");
    printf("6. Piada\n");
    printf("7. Curiosidade\n");
    printf("8. Trava-lingua\n");
    printf("9. Calcular\n\n");
}

void exibirHorarios() {
    time_t tempo;
    struct tm* horario;
    tempo = time(NULL);
    horario = localtime(&tempo);
    printf("%02i : %02i : %02i\n\n", horario->tm_hour, horario->tm_min, horario->tm_sec);
}

void exibirData() {
    time_t tempo;
    struct tm* horario;
    tempo = time(NULL);
    horario = localtime(&tempo);

    switch (horario->tm_wday) {
    case 0:
        printf("domingo");
        break;
    case 1:
        printf("segunda-feira");
        break;
    case 2:
        printf("terça-feira");
        break;
    case 3:
        printf("quarta-feira");
        break;
    case 4:
        printf("quinta-feira");
        break;
    case 5:
        printf("sexta-feira");
        break;
    case 6:
        printf("sábado");
        break;
    }

    printf(", dia: %02i/%02i/%i\n\n", horario->tm_mday, horario->tm_mon + 1, horario->tm_year + 1900);
}

void piadas() {
    aleatorio = rand() % 10;
    switch (aleatorio) {

    case 0:
        printf("\nSara: Por que o computador foi ao médico?");
        Sleep(1000);
        printf("\nSara: Porque tinha um vírus!\n\n");
        return;

    case 1:
        printf("\nSara: Por que livro de matemática foi ao psicólogo?");
        Sleep(1000);
        printf("\nSara: Porque ele estava cheio de problemas\n\n");
        return;

    case 2:
        printf("\nSara: Por que o astronauta não confia na lua?");
        Sleep(1000);
        printf("\nSara: Porque ela está sempre em suas fases\n\n");
        return;

    case 3:
        printf("\nSara: O que o pato falou para a pata?");
        Sleep(1000);
        printf("\nSara: \"Vem quá\"\n\n");
        return;

    case 4:
        printf("\nSara: Qual é o rei dos queijos?");
        Sleep(1000);
        printf("\nSara: O ReiQueijão\n\n");
        return;

    case 5:
        printf("\nSara: O que o tomate foi fazer no banco?");
        Sleep(1000);
        printf("\nSara: Foi tirar um extrato\n\n");
        return;

    case 6:
        printf("\nSara: O que o zero falou para o oito?");
        Sleep(1000);
        printf("\nSara: Belo cinto\n\n");
        return;

    case 7:
        printf("\nSara: Qual é o vinho que não tem álcool?");
        Sleep(1000);
        printf("\nSara: Ovinho de codorna\n\n");
        return;

    case 8:
        printf("\nSara: Qual é o contrário de papelada?");
        Sleep(1000);
        printf("\nSara: pavestida\n\n");
        return;

    case 9:
        printf("\nSara: Qual é o cúmulo da paciência?");
        Sleep(1000);
        printf("\nSara: Esperar a uva passar\n\n");
        return;
    }
}

void curiosidades() {
    aleatorio = rand() % 10;
    switch (aleatorio) {

    case 0:
        printf("\nSara: Os flamingos nascem cinza e só ficam cor-de-rosa por causa da comida que comem.\n\n");
        return;

    case 1:
        printf("\nSara: O mel nunca estraga! Arqueólogos já encontraram potes de mel com mais de 3.000 anos ainda comestíveis.\n\n");
        return;

    case 2:
        printf("\nSara: O coração de uma baleia azul é tão grande que um humano poderia nadar através de suas artérias.\n\n");
        return;

    case 3:
        printf("\nSara: Os morcegos não são cegos, por mais que não seja o melhor sentido deles, eles enxergam relativamente bem.\n\n");
        return;

    case 4:
        printf("\nSara: A Torre Eiffel pode ficar até 15 centímetros mais alta no verão, devido à dilatação do metal de sua estrutura.\n\n");
        return;

    case 5:
        printf("\nSara: O primeiro e-mail foi enviado em 1971, e a mensagem era apenas 'QWERTYUIOP'.\n\n");
        return;

    case 6:
        printf("\nSara: Os polvos têm três corações: dois bombeiam sangue para as brânquias, e um para o corpo.\n\n");
        return;

    case 7:
        printf("\nSara: A luz do Sol leva cerca de 8 minutos para chegar à Terra.\n\n");
        return;

    case 8:
        printf("\nSara: O chocolate já foi usado como moeda de troca.\n\n");
        return;

    case 9:
        printf("\nSara: O filme mais longo da história tem 85 horas de duração.\n\n");
        return;
    }
}

void travaLinguas() {
    aleatorio = rand() % 10;
    switch (aleatorio) {

    case 0:
        printf("\nSara: A aranha arranha a rã. A rã arranha a aranha. Nem a aranha arranha a rã. Nem a rã arranha a aranha..\n\n");
        return;

    case 1:
        printf("\nSara: O rato roeu a roupa do rei de Roma e a rainha com raiva rasgou o resto.\n\n");
        return;

    case 2:
        printf("\nSara: O tempo perguntou pro tempo quanto tempo o tempo tem. O tempo respondeu pro tempo que o tempo tem tanto tempo quanto tempo o tempo tem.\n\n");
        return;

    case 3:
        printf("\nSara: O doce perguntou pro doce qual é o doce mais doce. O doce respondeu pro doce que o doce mais doce é o doce de batata-doce.\n\n");
        return;

    case 4:
        printf("\nSara: Num ninho de mafagafos havia cinco mafagafinhos. Quem conseguir desmafagafar esses mafagafinhos, bom desmafagafador será.\n\n");
        return;

    case 5:
        printf("\nSara: Três pratos de trigo para três tigres tristes.\n\n");
        return;

    case 6:
        printf("\nSara: O sabiá sabia assobiar, mas o sábio não sabia assobiar como o sabiá sabia.\n\n");
        return;

    case 7:
        printf("\nSara: Se Sara sarasse a sala, Sara sararia sem suor.\n\n");
        return;

    case 8:
        printf("\nSara: O pinto pia, a pia pinga. Quanto mais o pinto pia, mais a pia pinga.\n\n");
        return;

    case 9:
        printf("\nSara: Em rápido rapto, um rápido rato raptou três ratos sem deixar rastro.\n\n");
        return;
    }
}

void calcular() {
    double num1, num2, resultado;
    char operador, comando[100];

    printf("Você: ");
    fgets(comando, 100, stdin);
    comando[strcspn(comando, "\n")] = '\0';

    if (sscanf(comando, "%lf %c %lf", &num1, &operador, &num2) == 3) {
        switch (operador) {
        case '+':
            resultado = num1 + num2;
            break;

        case '-':
            resultado = num1 - num2;
            break;

        case '*':
            resultado = num1 * num2;
            break;

        case '/':
            if (num2 == 0) {
                printf("\nSara: Não existe divisão por 0!\n\n");
                return;
            }
            resultado = num1 / num2;
            break;

        default:
            printf("\nSara: Operador desconhecido, utilize apenas +, -, * ou /.\n\n");
            return;
        }
        printf("\nSara: %.1lf %c %.1lf é igual à %.1lf.\n\n", num1, operador, num2, resultado);
    }
    else {
        printf("\nSara: Não foi possível entender a conta. Use o modelo: <número> <operador> <número>.\n\n");
    }
}