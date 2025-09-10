#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "transacoes.h"

Conta contas[MAX_CONTAS] = { 0 };
Extrato extratos[MAX_CONTAS] = { 0 };

int numContas = 0, numTransacoes[MAX_CONTAS] = { 0 };
int cpfInvalido, senhaInvalida;
char confirmacao;

void exibirContas() {
    system("cls");
    printf("--- Todas as contas salvas ---\n\n");
    for (int i = 0; i < numContas; i++) {
        printf("%i\n", contas[i].numero);
        printf("%s\n", contas[i].nome);
        printf("%s\n", contas[i].cpf);
        printf("%s\n", contas[i].senha);
        printf("%lf\n\n", contas[i].saldo);
    }
    if (_getch()) {
        return;
    }
}

int validarCpf(char* cpf) {
    if (strlen(cpf) != NUM_CPF - 1) {
        return 1;
    }
    for (int i = 0; i < NUM_CPF - 1; i++) {
        if (!isdigit(cpf[i])) {
            return 2;
        }
    }
    return 0;
}

int validarSenha(char* senha) {
    if (strlen(senha) < 4 || strlen(senha) > NUM_SENHA - 1) {
        return 1;
    }
    for (size_t i = 0; i < strlen(senha); i++) {
        if (!isdigit(senha[i])) {
            return 2;
        }
    }
    return 0;
}

void criarConta() {
    system("cls");
    printf("==============================================\n");
    printf("  ***********  SISTEMA BANCÁRIO  ***********  \n");
    printf("==============================================\n\n");
    printf("-------------  Criar Nova Conta  -------------\n\n");

    if (numContas >= MAX_CONTAS) {
        printf("\nImpossível criar novas contas! Limite máximo atingido!\n");
        if (_getch()) {
            return;
        }
    }

    Conta criar;

    printf("Nome completo: ");
    fgets(criar.nome, 100, stdin);
    criar.nome[strcspn(criar.nome, "\n")] = '\0';
    setbuf(stdin, NULL);

    do {
        printf("\nCPF (somente números): ");
        fgets(criar.cpf, 12, stdin);
        criar.cpf[strcspn(criar.cpf, "\n")] = '\0';
        cpfInvalido = validarCpf(criar.cpf);

        if (cpfInvalido == 1) {
            printf("CPF inválido! CPF deve conter 11 dígitos.\nPressione ENTER e tente novamente.");
        }
        else {
            if (cpfInvalido == 2) {
                printf("CPF inválido! Digite apenas números.\nPressione ENTER e tente novamente.");
            }
            else {
                printf("CPF válido!\n");
            }
        }

        while (getchar() != '\n');
    } while (cpfInvalido);


    do {
        printf("\nSenha (de 4 a 10 números): ");
        fgets(criar.senha, 11, stdin);
        criar.senha[strcspn(criar.senha, "\n")] = '\0';
        senhaInvalida = validarSenha(criar.senha);

        if (senhaInvalida == 1) {
            printf("Senha inválida! Senha deve conter de 4 a 10 dígitos.\nPressione ENTER e tente novamente.");
        }
        else {
            if (senhaInvalida == 2) {
                printf("Senha inválida! Digite apenas números.\nPressione ENTER e tente novamente.");
            }
            else {
                printf("Senha válida!\n");
            }
        }

        while (getchar() != '\n');
    } while (senhaInvalida);


    printf("--- Confira os dados ---\n\n");
    printf("Nome: %s\n", criar.nome);
    printf("CPF: %s\n", criar.cpf);
    printf("Senha: %s\n", criar.senha);

    do {
        printf("\nConfirmar a criação da conta?\nS - Sim | N - Não : ");
        if (scanf(" %c", &confirmacao) != 1) {
            printf("\nErro, entrada inválida!\n\n");
            if (_getch()) {
                setbuf(stdin, NULL);
                confirmacao = '0';
                return;
            }
        }
        setbuf(stdin, NULL);
        confirmacao = toupper(confirmacao);

        if (confirmacao != 'S' && confirmacao != 'N') {
            printf("Por favor, confirme com \"S\" ou cancele com \"N\".\n");
        }

    } while (confirmacao != 'S' && confirmacao != 'N');

    if (confirmacao == 'N') {
        printf("\nOperação cancelada!\n");

    }
    else {
        contas[numContas].numero = 100 + numContas;
        contas[numContas].saldo = 0;

        strcpy(contas[numContas].nome, criar.nome);
        strcpy(contas[numContas].cpf, criar.cpf);
        strcpy(contas[numContas].senha, criar.senha);

        printf("\nNúmero da sua conta: %i", contas[numContas].numero);

        numContas++;
        printf("\n\nConta criada com sucesso!\n");
    }

    if (_getch()) {
        return;
    }
}

void entrarConta() {
    int numero;
    char senha[NUM_SENHA];

    system("cls");
    printf("==============================================\n");
    printf("  ***********  SISTEMA BANCÁRIO  ***********  \n");
    printf("==============================================\n\n");
    printf("------------  Entre em sua Conta  ------------\n\n");

    if (numContas == 0) {
        printf("Não há nenhuma conta registrada no sistema!");
        if (_getch()) {
            return;
        }
    }

    do {
        printf("Número da conta: ");
        if (scanf(" %i", &numero) != 1) {
            printf("\nErro, entrada inválida!\n\n");
            if (_getch()) {
                setbuf(stdin, NULL);
                numero = -1;
                return;
            }
        }
        setbuf(stdin, NULL);

        if (numero < 100) {
            printf("Número inválido digitado.\n\n");
        }
        else {
            if (numero > numContas + 99) {
                printf("Essa conta não existe.\n\n");
            }
        }

    } while (numero < 100 || numero > numContas + 99);

    for (int tentativas = 5; tentativas > 0; tentativas--) {
        printf("Senha: ");
        fgets(senha, 11, stdin);
        senha[strcspn(senha, "\n")] = '\0';
        setbuf(stdin, NULL);

        if (strcmp(contas[numero - 100].senha, senha) == 0) {
            menuConta(&contas[numero - 100]);
            return;
        }
        printf("Senha incorreta!\n\n");
    }

    printf("\nMuitas tentativas erradas! Encerrando operação.\n");
    if (_getch()) {
        return;
    }
}

void salvarDadosContas() {
    FILE* arquivo = fopen(DADOS_BANCARIOS, "w");
    if (arquivo == NULL) {
        printf("\nERRO! Houve uma falha ao salvar os dados da conta.\n");
        return;
    }

    for (int i = 0; i < numContas; i++) {
        fprintf(arquivo, "%i\n%s\n%s\n%s\n%.2f\n\n", contas[i].numero, contas[i].nome, contas[i].cpf, contas[i].senha, contas[i].saldo);
    }
    fclose(arquivo);

    arquivo = fopen(TRANSACOES_BANCARIAS, "w");
    if (arquivo == NULL) {
        printf("\nERRO! Houve uma falha ao salvar os dados das transações.\n");
        return;
    }

    for (int i = 0; i < numContas; i++) {
        fprintf(arquivo, "%i\n", numTransacoes[i]);
        for (int j = 0; j < numTransacoes[i]; j++) {
            fprintf(arquivo, "%s\n%c\n%.2lf\n", extratos[i].data[j], extratos[i].sinal[j], extratos[i].valor[j]);
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);

    printf("\nTodos os dados foram salvos com sucesso!\n");
    return;
}

void carregarDadosContas() {
    FILE* arquivo = fopen(DADOS_BANCARIOS, "r");
    if (arquivo == NULL) {
        printf("\nERRO! Houve uma falha ao carregar os dados da conta.\n");
        return;
    }

    numContas = 0;
    while (numContas < MAX_CONTAS &&
        fscanf(arquivo, "%d\n", &contas[numContas].numero) == 1 &&
        fgets(contas[numContas].nome, 100, arquivo) &&
        fscanf(arquivo, "%s\n", contas[numContas].cpf) == 1 &&
        fscanf(arquivo, "%s\n", contas[numContas].senha) == 1 &&
        fscanf(arquivo, "%lf\n", &contas[numContas].saldo) == 1) {

        contas[numContas].nome[strcspn(contas[numContas].nome, "\n")] = '\0';

        numContas++;
        fscanf(arquivo, "\n");
    }

    fclose(arquivo);

    arquivo = fopen(TRANSACOES_BANCARIAS, "r");
    if (arquivo == NULL) {
        printf("\nERRO! Houve uma falha ao carregar os dados das transações.\n");
        return;
    }


    for (int i = 0; i < numContas; i++) {
        fscanf(arquivo, "%i\n", &numTransacoes[i]);

        for (int j = 0; j < numTransacoes[i]; j++) {
            fgets(extratos[i].data[j], 20, arquivo);
            extratos[i].data[j][strcspn(extratos[i].data[j], "\n")] = '\0';

            fscanf(arquivo, " %c\n", &extratos[i].sinal[j]);
            fscanf(arquivo, "%lf\n", &extratos[i].valor[j]);
        }
    }

    fclose(arquivo);
    printf("\nTodos os dados foram carregados com sucesso!\n");
    return;
}

void registrarTransacao(int id, int sinal, double valor) {
    if (numTransacoes[id] < MAX_TRANSACOES) {
        extratos[id].sinal[numTransacoes[id]] = sinal;
        extratos[id].valor[numTransacoes[id]] = valor;

        time_t tempo = time(NULL);
        struct tm* data = localtime(&tempo);
        sprintf(extratos[id].data[numTransacoes[id]], "%02i/%02i/%i %02i:%02i", data->tm_mday, data->tm_mon + 1, data->tm_year + 1900, data->tm_hour, data->tm_min);
        
        numTransacoes[id]++;
    }
}

void menuConta(Conta* contaAtual) {
    int opcao;

    do {
        system("cls");
        printf("==============================================\n");
        printf("  ***********  SISTEMA BANCÁRIO  ***********  \n");
        printf("==============================================\n\n");
        printf("       [1] Ver saldo\n");
        printf("       [2] Depósito\n");
        printf("       [3] Saque\n");
        printf("       [4] Transferência\n");
        printf("       [5] Extrato da conta\n\n");
        printf("       [0] Sair da conta\n\n");
        printf("----------------------------------------------\n\n");
        printf("Seja bem-vindo(a): %s\n\n", contaAtual->nome);
        printf("Escolha uma das opções acima: ");
        if (scanf(" %i", &opcao) != 1) {
            printf("\nErro, entrada inválida!\n\n");
            if (_getch()) {
                setbuf(stdin, NULL);
                opcao = -1;
                continue;
            }
        }
        setbuf(stdin, NULL);

        switch (opcao) {
        case 1: saldo(contaAtual->numero - 100); break;
        case 2: deposito(contaAtual->numero - 100); break;
        case 3: saque(contaAtual->numero - 100); break;
        case 4: transferencia(contaAtual->numero - 100); break;
        case 5: extrato(contaAtual->numero - 100); break;

        case 0: printf("\nSaindo da conta...\n"); 
            if (_getch()) {
                break;
            }

        default: printf("\nOpção inválida! Tente novamente."); 
            if (_getch()) {
                break;
            }
        }

    } while (opcao != 0);

    return;
}

void saldo(int id) {
    system("cls");
    printf("==============================================\n");
    printf("  ***********  SISTEMA BANCÁRIO  ***********  \n");
    printf("==============================================\n\n");
    printf("--------------  Saldo da Conta  --------------\n\n");

    printf("Número da conta: %i\n", contas[id].numero);
    printf("Proprietário da conta: %s\n", contas[id].nome);
    printf("\nSaldo atual: R$ %.2f", contas[id].saldo);

    printf("\n\nPressione ENTER para retornar\n");
    if (_getch()) {
        return;
    }
}

void deposito(int id) {
    char confirmarDeposito, novoDeposito = '\0';
    double valorDeposito, valorSaldo;
    valorSaldo = contas[id].saldo;

    do {
        system("cls");
        printf("==============================================\n");
        printf("  ***********  SISTEMA BANCÁRIO  ***********  \n");
        printf("==============================================\n\n");
        printf("------------  Realizar  Depósito  -------------\n\n");

        printf("Número da conta: %i\n", contas[id].numero);
        printf("Proprietário da conta: %s\n", contas[id].nome);
        printf("\nSaldo atual: R$ %.2f", contas[id].saldo);

        printf("\n\nDigite o valor do depósito: R$ ");
        if (scanf(" %lf", &valorDeposito) != 1) {
            printf("\nErro, entrada inválida!\n\n");
            if (_getch()) {
                setbuf(stdin, NULL);
                valorDeposito = -1;
                return;
            }
        }
        setbuf(stdin, NULL);

        if (valorDeposito <= 0) {
            printf("Valor inválido inserido!\n\nEncerrando operação!\n");
            if (_getch()) {
                return;
            }
        }
        else {
            if (valorDeposito > 5000) {
                printf("Valor acima do limite de R$ 5000,00!\n\nEncerrando operação!\n");
                if (_getch()) {
                    return;
                }
            }
        }

        valorSaldo += valorDeposito;
        printf("Novo saldo: R$ %.2f\n", valorSaldo);

        do {
            printf("\nDeseja confirmar o depósito?\nS - Sim | N - Não : ");
            if (scanf(" %c", &confirmarDeposito) != 1) {
                printf("\nErro, entrada inválida!\n\n");
                if (_getch()) {
                    setbuf(stdin, NULL);
                    confirmarDeposito = '0';
                    return;
                }
            }
            setbuf(stdin, NULL);
            confirmarDeposito = toupper(confirmarDeposito);

            if (confirmarDeposito != 'S' && confirmarDeposito != 'N') {
                printf("Por favor, confirme com \"S\" ou cancele com \"N\".\n");
            }

        } while (confirmarDeposito != 'S' && confirmarDeposito != 'N');

        if (confirmarDeposito == 'N') {
            printf("\nOperação cancelada!\n");
            if (_getch()) {
                return;
            }
        }
        else {
            contas[id].saldo = valorSaldo;
            registrarTransacao(id, '+', valorDeposito);
            printf("\nOperação realizada com sucesso!\n");
        }

        do {
            printf("\nDeseja realizar um novo depósito?\nS - Sim | N - Não : ");
            if (scanf(" %c", &novoDeposito) != 1) {
                printf("\nErro, entrada inválida!\n\n");
                if (_getch()) {
                    setbuf(stdin, NULL);
                    novoDeposito = '\0';
                    return;
                }
            }
            setbuf(stdin, NULL);
            novoDeposito = toupper(novoDeposito);

            if (novoDeposito != 'S' && novoDeposito != 'N') {
                printf("Por favor, confirme com \"S\" ou cancele com \"N\".\n");
            }

        } while (novoDeposito != 'S' && novoDeposito != 'N');

        if (novoDeposito == 'N') {
            printf("\nRetornando ao menu!\n");
            if (_getch()) {
                return;
            }
        }

    } while (novoDeposito == 'S');
}

void saque(int id) {
    char confirmarSaque, novoSaque = '\0';
    double valorSaque, valorSaldo;
    valorSaldo = contas[id].saldo;

    do {
        system("cls");
        printf("==============================================\n");
        printf("  ***********  SISTEMA BANCÁRIO  ***********  \n");
        printf("==============================================\n\n");
        printf("--------------  Realizar Saque  --------------\n\n");

        printf("Número da conta: %i\n", contas[id].numero);
        printf("Proprietário da conta: %s\n", contas[id].nome);
        printf("\nSaldo atual: R$ %.2f", contas[id].saldo);

        printf("\n\nDigite o valor do saque: R$ ");
        if (scanf(" %lf", &valorSaque) != 1) {
            printf("\nErro, entrada inválida!\n\n");
            if (_getch()) {
                setbuf(stdin, NULL);
                valorSaque = -1;
                return;
            }
        }
        setbuf(stdin, NULL);

        if (valorSaque <= 0) {
            printf("Valor inválido inserido!\n\nEncerrando operação!\n");
            if (_getch()) {
                return;
            }
        }
        else {
            if (valorSaque > 2000) {
                printf("Valor acima do limite de R$ 2000,00!\n\nEncerrando operação!\n");
                if (_getch()) {
                    return;
                }
            }
            else {
                if (valorSaque > valorSaldo) {
                    printf("Saldo insuficiente para realizar a transação!\n\nEncerrando operação!\n");
                    if (_getch()) {
                        return;
                    }
                }
            }
        }

        valorSaldo -= valorSaque;
        printf("Novo saldo: R$ %.2f\n", valorSaldo);

        do {
            printf("\nDeseja confirmar o saque?\nS - Sim | N - Não : ");
            if (scanf(" %c", &confirmarSaque) != 1) {
                printf("\nErro, entrada inválida!\n\n");
                if (_getch()) {
                    setbuf(stdin, NULL);
                    confirmarSaque = '0';
                    return;
                }
            }
            setbuf(stdin, NULL);
            confirmarSaque = toupper(confirmarSaque);

            if (confirmarSaque != 'S' && confirmarSaque != 'N') {
                printf("Por favor, confirme com \"S\" ou cancele com \"N\".\n");
            }

        } while (confirmarSaque != 'S' && confirmarSaque != 'N');

        if (confirmarSaque == 'N') {
            printf("\nOperação cancelada!\n");
            if (_getch()) {
                return;
            }
        }
        else {
            registrarTransacao(id, '-', valorSaque);
            contas[id].saldo = valorSaldo;
            printf("\nOperação realizada com sucesso!\n");
        }

        do {
            printf("\nDeseja realizar um novo saque?\nS - Sim | N - Não : ");
            if (scanf(" %c", &novoSaque) != 1) {
                printf("\nErro, entrada inválida!\n\n");
                if (_getch()) {
                    setbuf(stdin, NULL);
                    novoSaque = '\0';
                    return;
                }
            }
            setbuf(stdin, NULL);
            novoSaque = toupper(novoSaque);

            if (novoSaque != 'S' && novoSaque != 'N') {
                printf("Por favor, confirme com \"S\" ou cancele com \"N\".\n");
            }

        } while (novoSaque != 'S' && novoSaque != 'N');

        if (novoSaque == 'N') {
            printf("\nRetornando ao menu!\n");
            if (_getch()) {
                return;
            }
        }

    } while (novoSaque == 'S');
}

void transferencia(int id) {
    char confirmarTransferencia, novaTransferencia = '\0';
    int destino;
    double valorTransferencia, valorSaldo, valorSaldoDestino;
    valorSaldo = contas[id].saldo;

    do {
        system("cls");
        printf("==============================================\n");
        printf("  ***********  SISTEMA BANCÁRIO  ***********  \n");
        printf("==============================================\n\n");
        printf("----------  Realizar Transferência  ----------\n\n");

        printf("Número da conta: %i\n", contas[id].numero);
        printf("Proprietário da conta: %s\n", contas[id].nome);
        printf("\nSaldo atual: R$ %.2f", contas[id].saldo);

        if (numContas == 1) {
            printf("\n\nNão há outra conta no sistema para uma transação!");
            if (_getch()) {
                return;
            }
        }

        do {
            printf("\n\nDigite o numero da conta destino: ");
            if (scanf(" %i", &destino) != 1) {
                printf("\nErro, entrada inválida!\n\n");
                if (_getch()) {
                    setbuf(stdin, NULL);
                    destino = -1;
                    return;
                }
            }
            setbuf(stdin, NULL);

            if (destino < 100) {
                printf("Número inválido digitado.");
            }
            else {
                if (destino > numContas + 99) {
                    printf("Essa conta não existe.");
                }
                else {
                    if (destino - 100 == id) {
                        printf("Você não pode fazer uma transferência para sua própria conta.");
                    }
                }
            }

        } while (destino < 100 || destino > numContas + 99 || destino - 100 == id);

        valorSaldoDestino = contas[destino - 100].saldo;

        printf("\nDigite o valor da transferência: R$ ");
        if (scanf(" %lf", &valorTransferencia) != 1) {
            printf("\nErro, entrada inválida!\n\n");
            if (_getch()) {
                setbuf(stdin, NULL);
                valorTransferencia = -1;
                return;
            }
        }
        setbuf(stdin, NULL);

        if (valorTransferencia <= 0) {
            printf("Valor inválido inserido!\n\nEncerrando operação!\n");
            if (_getch()) {
                return;
            }
        }
        else {
            if (valorTransferencia > 3000) {
                printf("Valor acima do limite de R$ 3000,00!\n\nEncerrando operação!\n");
                if (_getch()) {
                    return;
                }
            }
            else {
                if (valorTransferencia > valorSaldo) {
                    printf("Saldo insuficiente para realizar a transação!\n\nEncerrando operação!\n");
                    if (_getch()) {
                        return;
                    }
                }
            }
        }

        valorSaldo -= valorTransferencia;
        valorSaldoDestino += valorTransferencia;
        printf("\n--- Confira os dados ---\n\n");
        printf("Numero da conta destino: %i\n", contas[destino - 100].numero);
        printf("Proprietário da conta destino: %s\n\n", contas[destino - 100].nome);
        printf("Novo saldo: R$ %.2f\n", valorSaldo);

        do {
            printf("\nDeseja confirmar a transferência?\nS - Sim | N - Não : ");
            if (scanf(" %c", &confirmarTransferencia) != 1) {
                printf("\nErro, entrada inválida!\n\n");
                if (_getch()) {
                    setbuf(stdin, NULL);
                    confirmarTransferencia = '0';
                    return;
                }
            }
            setbuf(stdin, NULL);
            confirmarTransferencia = toupper(confirmarTransferencia);

            if (confirmarTransferencia != 'S' && confirmarTransferencia != 'N') {
                printf("Por favor, confirme com \"S\" ou cancele com \"N\".\n");
            }

        } while (confirmarTransferencia != 'S' && confirmarTransferencia != 'N');

        if (confirmarTransferencia == 'N') {
            printf("\nOperação cancelada!\n");
            if (_getch()) {
                return;
            }
        }
        else {
            contas[id].saldo = valorSaldo;
            contas[destino - 100].saldo = valorSaldoDestino;
            registrarTransacao(id, '-', valorTransferencia);
            registrarTransacao(destino - 100, '+', valorTransferencia);
            printf("\nOperação realizada com sucesso!\n");
        }

        do {
            printf("\nDeseja realizar uma nova transferência?\nS - Sim | N - Não : ");
            if (scanf(" %c", &novaTransferencia) != 1) {
                printf("\nErro, entrada inválida!\n\n");
                if (_getch()) {
                    setbuf(stdin, NULL);
                    novaTransferencia = '\0';
                    return;
                }
            }
            setbuf(stdin, NULL);
            novaTransferencia = toupper(novaTransferencia);

            if (novaTransferencia != 'S' && novaTransferencia != 'N') {
                printf("Por favor, confirme com \"S\" ou cancele com \"N\".\n");
            }

        } while (novaTransferencia != 'S' && novaTransferencia != 'N');

        if (novaTransferencia == 'N') {
            printf("\nRetornando ao menu!\n");
            if (_getch()) {
                return;
            }
        }

    } while (novaTransferencia == 'S');
}

void extrato(int id) {
    system("cls");
    printf("==============================================\n");
    printf("  ***********  SISTEMA BANCÁRIO  ***********  \n");
    printf("==============================================\n\n");
    printf("-------------  Extrato da Conta  -------------\n\n");

    for (int i = 0; i < numTransacoes[id]; i++) {
        printf("%s %c R$ %.2lf\n", extratos[id].data[i], extratos[id].sinal[i], extratos[id].valor[i]);
    }

    if (_getch()) {
        return;
    }
}
