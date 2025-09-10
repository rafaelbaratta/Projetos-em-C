#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "manipulacao.h"

const char ALFABETO_MAIUSCULO[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char ALFABETO_MINUSCULO[27] = "abcdefghijklmnopqrstuvwxyz";

void imprimirCabecalho(){
    system("cls");
    printf("==============================================\n");
    printf("  ********  MANIPULAÇÃO DE STRINGS  ********  \n");
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

char *lerString(char *mensagem){
    static char frase[MAX_CARACTERES];

    printf("%s", mensagem);
    setbuf(stdin, NULL);

    fgets(frase, sizeof(frase), stdin);
    removerQuebraLinha(frase);

    return frase;
}

// FUNÇÕES PARA MANIPULAÇÃO DE CARACTERES

char caractereParaMaiusculas(char c){
    if (c >= 'a' && c <= 'z'){
        c -= 32;
    }
    return c;
}

char caractereParaMinusculas(char c){
    if (c >= 'A' && c <= 'Z'){
        c += 32;
    }
    return c;
}

char inverterCaixaCaractere(char c){
    if (c >= 'A' && c <= 'Z'){
        c += 32;
        return c;
    }

    if (c >= 'a' && c <= 'z'){
        c -= 32;
        return c;
    }

    return c;
}

// FUNÇÕES PARA MANIPULAÇÃO DE STRINGS

char *stringParaMaiusculas(char string[]){
    for (int i = 0; i < tamanhoString(string); i++){
        string[i] = caractereParaMaiusculas(string[i]);
    }
    return string;
}

char *stringParaMinusculas(char string[]){
    for (int i = 0; i < tamanhoString(string); i++){
        string[i] = caractereParaMinusculas(string[i]);
    }
    return string;
}

char *inverterCaixaString(char string[]){
    for (int i = 0; i < tamanhoString(string); i++){
        string[i] = inverterCaixaCaractere(string[i]);
    }
    return string;
}

char *inverterString(char string[]){
    int tamanho = tamanhoString(string);
    static char destino[MAX_CARACTERES];

    for (int i = 0; i < tamanho; i++){
        destino[i] = string[tamanho - i - 1];
    }

    destino[tamanho] = '\0';
    return destino;
}

char *concatenarStrings(char string1[], char string2[]){
    static char concatenacao[2 * MAX_CARACTERES];
    copiarString(concatenacao, string1);

    int tamanho1 = tamanhoString(string1);
    int tamanhoTotal = tamanho1 + tamanhoString(string2);

    int i = 0;

    while (tamanho1 < tamanhoTotal){
        concatenacao[tamanho1] = string2[i];
        i++;
        tamanho1++;
    }

    return concatenacao;
}

char *removerEspacos(char string[]){
    static char resultado[MAX_CARACTERES];
    int k = 0;

    for (int i = 0; i < tamanhoString(string); i++){
        if (!verificarEspacos(string[i])){
            resultado[k] = string[i];
            k++;
        }
    }
    return resultado;
}



void copiarString(char destino[], char origem[]){
    for (int i = 0; i < tamanhoString(origem) + 1; i++){
        destino[i] = origem[i];
    }
    return;
}

void removerQuebraLinha(char string[]){
    int i = 0;
    while (string[i] != '\0'){
        if (string[i] == '\n'){
            string[i] = '\0';
            return;
        }
        i++;
    }
}

int tamanhoString(char string[]){
    int i = 0;
    while (string[i] != '\0'){
        i++;
    }
    return i;
}

bool compararStrings(char string1[], char string2[]){
    int tamanho1 = tamanhoString(string1);
    int tamanho2 = tamanhoString(string2);

    if (tamanho1 != tamanho2){
        return false;
    }

    for (int i = 0; i < tamanho1; i++){
        if (string1[i] != string2[i]){
            return false;
        }
    }

    return true;
}

// FUNÇÕES PARA VERIFICAÇÃO DE CARACTERES

bool verificarVogal(char c){
    char lista[] = "aeiouAEIOU";

    for (int i = 0; i < tamanhoString(lista); i++){
        if (c == lista[i]){
            return true;
        }
    }

    return false;
}

bool verificarConsoante(char c){
    char lista[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";

    for (int i = 0; i < tamanhoString(lista); i++){
        if (c == lista[i]){
            return true;
        }
    }

    return false;
}

bool verificarLetra(char c){
    if (verificarVogal(c) || verificarConsoante(c)){
        return true;
    }
    return false;
}

bool verificarEspacos(char c){
    if (c == ' '){
        return true;
    }
    return false;
}

// FUNÇÕES PARA CONTAGEM DE LETRAS E PALAVRAS DE STRINGS

int contarLetras(char string[]){
    int letras = 0;
    for (int i = 0; i < tamanhoString(string); i++){
        if (verificarLetra(string[i])){
            letras ++;
        }
    }
    return letras;
}

int contarVogais(char string[]){
    int vogais = 0;

    for (int i = 0; i < tamanhoString(string); i++){
        if (verificarVogal(string[i])){
            vogais ++;
        }
    }
    return vogais;
}

int contarConsoantes(char string[]){
    int consoantes = 0;

    for (int i = 0; i < tamanhoString(string); i++){
        if (verificarConsoante(string[i])){
            consoantes ++;
        }
    }
    return consoantes;
}

int contarPalavras(char string[]){
    int palavras = 0;
    for (int i = 0; i < tamanhoString(string); i++){
        if (verificarEspacos(string[i])){
            palavras ++;
        }
    }
    return palavras + 1;
}

// FUNÇÕES DE CODIFICAÇÃO

char *codificarCesar(int chave, char texto[]){
    static char criptografia[MAX_CARACTERES];
    copiarString(criptografia, texto);

    for (int i = 0; i < tamanhoString(texto); i++){
        if (texto[i] >= 'A' && texto[i] <= 'Z'){
            int codigo = texto[i] - 'A';
            criptografia[i] = ((codigo + chave) % 26) + 'A';
        } else {
            if (texto[i] >= 'a' && texto[i] <= 'z'){
                int codigo = texto[i] - 'a';
                criptografia[i] = ((codigo + chave) % 26) + 'a';
            }
        }
    }

    return criptografia;
}

char *decodificarCesar(int chave, char texto[])
{
    static char criptografia[MAX_CARACTERES];
    copiarString(criptografia, texto);
    for (int i = 0; i < tamanhoString(texto); i++)
    {
        if (texto[i] >= 'A' && texto[i] <= 'Z')
        {
            int codigo = texto[i] - 'A';
            criptografia[i] = ((codigo - chave) % 26) + 'A';
        }
        else
        {
            if (texto[i] >= 'a' && texto[i] <= 'z')
            {
                int codigo = texto[i] - 'a';
                criptografia[i] = ((codigo - chave) % 26) + 'a';
            }
        }
    }

    return criptografia;
}

char *codificarSubstituicao(char chave[], char texto[]){

    static char criptografia[MAX_CARACTERES];
    copiarString(criptografia, texto);

    for (int i = 0; i < tamanhoString(texto); i++)
    {
        if (texto[i] >= 'A' && texto[i] <= 'Z')
        {
            for (int j = 0; j < 26; j++)
            {
                if (texto[i] == ALFABETO_MAIUSCULO[j])
                {
                    criptografia[i] = caractereParaMaiusculas(chave[j]);
                    break;
                }
            }
        }
        else
        {
            if (texto[i] >= 'a' && texto[i] <= 'z')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (texto[i] == ALFABETO_MINUSCULO[j])
                    {
                        criptografia[i] = caractereParaMinusculas(chave[j]);
                        break;
                    }
                }
            }
        }
    }

    return criptografia;
}

char *decodificarSubstituicao(char chave[], char texto[]){

    static char criptografia[MAX_CARACTERES];
    copiarString(criptografia, texto);

    for (int i = 0; i < tamanhoString(texto); i++)
    {
        if (texto[i] >= 'A' && texto[i] <= 'Z')
        {
            for (int j = 0; j < 26; j++)
            {
                if (texto[i] == caractereParaMaiusculas(chave[j]))
                {
                    criptografia[i] = ALFABETO_MAIUSCULO[j];
                    break;
                }
            }
        }
        else
        {
            if (texto[i] >= 'a' && texto[i] <= 'z')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (texto[i] == caractereParaMinusculas(chave[j]))
                    {
                        criptografia[i] = ALFABETO_MINUSCULO[j];
                        break;
                    }
                }
            }
        }
    }

    return criptografia;
}

// FUNÇÕES DO MENU

void alterarCaixaMenu(int tipo){
    char resultado [MAX_CARACTERES];
    imprimirCabecalho();

    if (tipo == 1){
        printf("--------- Converter Para Maiúsculas ----------\n\n");
        copiarString(resultado, stringParaMaiusculas(lerString("Insira uma string: ")));
    } else {
        if (tipo == 2){
            printf("--------- Converter Para Minúsculas ----------\n\n");
            copiarString(resultado, stringParaMinusculas(lerString("Insira uma string: ")));
        } else {
            printf("---------- Inverter Caixa da String ----------\n\n");
            copiarString(resultado, inverterCaixaString(lerString("Insira uma string: ")));
        }
    }

    printf("\nResultado: %s", resultado);
    getch();
    return;
}

void inverterStringMenu(){
    char resultado[MAX_CARACTERES];
    imprimirCabecalho();
    printf("-------------- Inverter String ---------------\n\n");

    copiarString(resultado, inverterString(lerString("Insira uma string: ")));

    printf("\nResultado: %s", resultado);
    getch();
    return;
}

void concatenarStringsMenu(){
    char resultado[2 * MAX_CARACTERES];
    imprimirCabecalho();
    printf("------------- Concatenar Strings -------------\n\n");

    char string1[MAX_CARACTERES], string2[MAX_CARACTERES];

    copiarString(string1, lerString("Insira a primeira string: "));
    copiarString(string2, lerString("Insira a segunda string: "));
    copiarString(resultado, concatenarStrings(string1, string2));

    printf("\nResultado: %s", resultado);
    getch();
    return;
}

void compararStringsMenu(){
    imprimirCabecalho();
    printf("-------------- Comparar Strings --------------\n\n");

    char string1[MAX_CARACTERES], string2[MAX_CARACTERES];

    copiarString(string1, lerString("Insira a primeira string: "));
    copiarString(string2, lerString("Insira a segunda string: "));
    
    if (compararStrings(string2, string1)){
        printf("\nAs strings \"%s\" e \"%s\" são iguais!\n", string1, string2);
        getch();
        return;
    }

    printf("\nAs strings \"%s\" e \"%s\" não são iguais!\n", string1, string2);
    getch();
    return;
}

void contagemMenu(){
    imprimirCabecalho();
    printf("---------- Contar Letras e Palavras ----------\n\n");

    char string[MAX_CARACTERES];

    copiarString(string, lerString("Insira uma frase: "));

    printf("\nTotal de palavras: %i", contarPalavras(string));
    printf("\nTotal de letras: %i", contarLetras(string));
    printf("\nTotal de vogais: %i", contarVogais(string));
    printf("\nTotal de consoantes: %i", contarConsoantes(string));
    getch();
    return;
}

void verificarPalindromoMenu(){
    imprimirCabecalho();
    printf("----------- Verificar Palíndromos ------------\n\n");

    char string[MAX_CARACTERES];
    copiarString(string, lerString("Insira uma palavra ou frase: "));

    char stringPadronizada[MAX_CARACTERES];
    copiarString(stringPadronizada, string);
    copiarString(stringPadronizada, removerEspacos(stringParaMaiusculas(stringPadronizada)));

    if(compararStrings(stringPadronizada, inverterString(stringPadronizada))){
        printf("\nA frase/palavra \"%s\" é um palíndromo!\n", string);
        getch();
        return;
    }

    printf("\nA frase/palavra \"%s\" não é um palíndromo!\n", string);
    getch();
    return;
}

void cifraCesarMenu(){
    int opcao;

    imprimirCabecalho();
    printf("-------------- Cifra de César ----------------\n\n");
    printf("       [1] Codificar em cifra de César\n");
    printf("       [2] Decodificar em cifra de César\n\n");
    printf("----------------------------------------------\n\n");

    do {
        opcao = lerInteiro("Escolha se deseja codificar ou decodificar: ");
    } while (opcao != 1 && opcao != 2);

    int chave = lerInteiro("\nDigite a chave: ");
    char texto[MAX_CARACTERES];
    copiarString(texto, lerString("Digite um texto: "));

    printf("\nTexto criptografado: %s", opcao == 1 ? codificarCesar(chave, texto) : decodificarCesar(chave, texto));
    getch();
    return;
}

void cifraSubstituicaoMenu(){
    int opcao;

    imprimirCabecalho();
    printf("----------- Cifra de Substituição ------------\n\n");
    printf("   [1] Codificar em cifra de substituição\n");
    printf("   [2] Decodificar em cifra de substituição\n\n");
    printf("----------------------------------------------\n\n");

    do {
        opcao = lerInteiro("Escolha se deseja codificar ou decodificar: ");
    } while (opcao != 1 && opcao != 2);

    char chave[MAX_CARACTERES];
    bool chaveValida;
    do {
        copiarString(chave, stringParaMaiusculas(lerString("Digite a chave: ")));

        if (contarLetras(chave) != 26 || tamanhoString(chave) != 26){
            chaveValida = false;
            continue;
        }
        chaveValida = true;
        for (int i = 0; i < 26; i++){
            for (int j = i + 1; j < 26; j++){
                if (chave[i] == chave[j]){
                    chaveValida = false;
                }
            }
        }

    } while (!chaveValida);

    char texto[MAX_CARACTERES];
    copiarString(texto, lerString("Digite um texto: "));

    printf("\nTexto criptografado: %s", opcao == 1 ? codificarSubstituicao(chave, texto) 
                                                   : decodificarSubstituicao(chave, texto));
    getch();
    return;
}
