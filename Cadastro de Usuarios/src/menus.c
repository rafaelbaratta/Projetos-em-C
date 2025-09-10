#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <direct.h>
#include "menus.h"
#include "operacoes.h"

// FUN��ES PARA CONTROLE DE USU�RIOS

void cadastrarUsuario(){
    Cadastro novo;
    memset(&novo, 0, sizeof(Cadastro));
    bool cpfValido, telefoneValido, emailValido, estadoValido;
    char continuar, registrar;

    FILE *arquivoCadastros;
    int codigoAtual = contarRegistros() + 100;
    arquivoCadastros = fopen(ARQUIVO, "ab");
    arquivoAberto(arquivoCadastros);

    do {
        imprimirCabecalho();
        printf("-------------- Cadastrar Usu�rio --------------\n");

        printf("\n==>  --------  DADOS PESSOAIS  --------  <==\n");

        printf("\nInforme o nome do usu�rio: ");
        lerEntradaAlfanumerica(novo.nome, sizeof(novo.nome));

        printf("\nInforme o CPF do usu�rio (apenas n�meros): ");
        do {
            lerEntradaAlfanumerica(novo.cpf, sizeof(novo.cpf));
            cpfValido = validarCpf(novo.cpf);

            if(!cpfValido){
                printf("\nO CPF digitado � inv�lido!\nInforme o CPF corretamente: ");
            }

        } while (!cpfValido);
        
        printf("\nInforme o telefone ou celular do usu�rio (apenas n�meros, insira o DDD): ");
        do {
            lerEntradaAlfanumerica(novo.telefone, sizeof(novo.telefone));
            telefoneValido = validarTelefone(novo.telefone);

            if(!telefoneValido){
                printf("\nO n�mero digitado � inv�lido!\nInforme o telefone ou celular corretamente: ");
            }
            
        } while (!telefoneValido);

        printf("\nInforme o e-mail do usu�rio: ");
        do {
            lerEntradaAlfanumerica(novo.email, sizeof(novo.email));
            emailValido = validarEmail(novo.email);

            if(!emailValido){
                printf("\nO e-mail digitado � inv�lido!\nInforme e-mail corretamente: ");
            }
            
        } while (!emailValido);

        printf("\nInforme o sal�rio do usu�rio: ");
        do {
            novo.salario = lerEntradaNumericaDecimal();

            if(novo.salario <= 0){
                printf("\nO sal�rio digitado � inv�lido!\nInforme o sal�rio corretamente: ");
            }

        } while (novo.salario <= 0);

        printf("\n==>  --------  DADOS DE ENDERE�O  --------  <==\n");

        printf("\nInforme o estado (UF) do usu�rio (apenas a sigla): ");
        do {
            lerEntradaAlfanumerica(novo.endereco.estado, sizeof(novo.endereco.estado));

            for(int i = 0; novo.endereco.estado[i] != '\0'; i++){
                novo.endereco.estado[i] = toupper(novo.endereco.estado[i]);
            }
            estadoValido = validarUnidadeFederativa(novo.endereco.estado);

            if(!estadoValido){
                printf("\nA sigla digitada � inexistente!\nInforme uma UF existente: ");
            }

        } while (!estadoValido);

        printf("\nInforme a cidade do usu�rio: ");
        lerEntradaAlfanumerica(novo.endereco.cidade, sizeof(novo.endereco.cidade));

        printf("\nInforme o bairro do usu�rio: ");
        lerEntradaAlfanumerica(novo.endereco.bairro, sizeof(novo.endereco.bairro));
        
        printf("\nInforme a rua do usu�rio: ");
        lerEntradaAlfanumerica(novo.endereco.rua, sizeof(novo.endereco.rua));

        printf("\nInforme o n�mero do usu�rio: ");
        do {
            novo.endereco.numero = lerEntradaNumericaInteira();

            if(novo.endereco.numero <= 0){
                printf("\nO n�mero digitado � inv�lido!\nInforme o n�mero corretamente: ");
            }

        } while (novo.endereco.numero <= 0);

        novo.codigo = codigoAtual;
        time_t now = time(NULL);
        novo.data = *localtime(&now);
        novo.removido = false;
        
        printf("\n==>  --------  REVIS�O  --------  <==\n\n");
        imprimirDados(novo);
        printf("\nRevise os dados acima!\n");

        printf("\nDeseja registrar esses dados? (S / N): ");
        registrar = validarCaractere();

        if(registrar == 'S'){
            fwrite(&novo, sizeof(novo), 1, arquivoCadastros);
            codigoAtual++;
            printf("\nCadastro realizado com sucesso!\n");
        } else {
            printf("\nCadastro cancelado!\n");
        }

        printf("\nDeseja cadastrar outro usu�rio? (S / N): ");
        continuar = validarCaractere();

    } while (continuar != 'N');

    fclose(arquivoCadastros);
}

void editarUsuario(){
    Cadastro editar;
    memset(&editar, 0, sizeof(Cadastro));
    bool cpfValido, telefoneValido, emailValido, estadoValido;
    int codigoProcura;
    char alterar, continuar;

    FILE *arquivoCadastros;
    arquivoCadastros = fopen(ARQUIVO, "rb+");
    arquivoAberto(arquivoCadastros);

    do {
        rewind(arquivoCadastros);
        imprimirCabecalho();
        printf("-------------- Procurar  Usu�rio --------------\n");

        printf("\nInforme o c�digo do usu�rio que deseja procurar: ");
        do {
            while(scanf("%i", &codigoProcura) != 1){
                printf("\nErro, entrada inv�lida!\nInsira outro valor: ");
                limpezaBuffer();
            }
            limpezaBuffer();

            if(codigoProcura < 100){
                printf("\nO c�digo digitado � inv�lido!\nInforme o c�digo corretamente: ");
            }

        } while (codigoProcura < 100);

        if(!buscarDados(arquivoCadastros, codigoProcura, &editar)){
            printf("\nO c�digo digitado n�o existe no sistema ou o usu�rio foi removido!\n");
        } else {
            printf("\n==>  --------  USU�RIO  ENCONTRADO  --------  <==\n\n");
            imprimirDados(editar);

            printf("\n==>  --------  ALTERAR DADOS SALVOS  --------  <==\n");

            printf("\nAlterar nome: ");
            lerEntradaAlfanumerica(editar.nome, sizeof(editar.nome));

            printf("Alterar CPF: ");
            do {
                lerEntradaAlfanumerica(editar.cpf, sizeof(editar.cpf));
                cpfValido = validarCpf(editar.cpf);

                if(!cpfValido){
                    printf("\nO CPF digitado � inv�lido!\nInforme o CPF corretamente: ");
                }

            } while (!cpfValido);
            
            printf("Alterar telefone: ");
            do {
                lerEntradaAlfanumerica(editar.telefone, sizeof(editar.telefone));
                telefoneValido = validarTelefone(editar.telefone);

                if(!telefoneValido){
                    printf("\nO n�mero digitado � inv�lido!\nInforme o telefone ou celular corretamente: ");
                }
                
            } while (!telefoneValido);

            printf("Alterar e-mail: ");
            do {
                lerEntradaAlfanumerica(editar.email, sizeof(editar.email));
                emailValido = validarEmail(editar.email);

                if(!emailValido){
                    printf("\nO e-mail digitado � inv�lido!\nInforme e-mail corretamente: ");
                }
                
            } while (!emailValido);

            printf("Alterar sal�rio: ");
            do {
                editar.salario = lerEntradaNumericaDecimal();

                if(editar.salario <= 0){
                    printf("\nO sal�rio digitado � inv�lido!\nInforme o sal�rio corretamente: ");
                }

            } while (editar.salario <= 0);

            printf("\nAlterar estado (UF): ");
            do {
                lerEntradaAlfanumerica(editar.endereco.estado, sizeof(editar.endereco.estado));

                for(int i = 0; editar.endereco.estado[i] != '\0'; i++){
                    editar.endereco.estado[i] = toupper(editar.endereco.estado[i]);
                }
                estadoValido = validarUnidadeFederativa(editar.endereco.estado);

                if(!estadoValido){
                    printf("\nA sigla digitada � inexistente!\nInforme uma UF existente: ");
                }

            } while (!estadoValido);

            printf("Alterar cidade: ");
            lerEntradaAlfanumerica(editar.endereco.cidade, sizeof(editar.endereco.cidade));

            printf("Alterar bairro: ");
            lerEntradaAlfanumerica(editar.endereco.bairro, sizeof(editar.endereco.bairro));
            
            printf("Alterar rua: ");
            lerEntradaAlfanumerica(editar.endereco.rua, sizeof(editar.endereco.rua));

            printf("Alterar n�mero: ");
            do {
                editar.endereco.numero = lerEntradaNumericaInteira();

                if(editar.endereco.numero <= 0){
                    printf("\nO n�mero digitado � inv�lido!\nInforme o n�mero corretamente: ");
                }

            } while (editar.endereco.numero <= 0);
            
            printf("\n==>  --------  REVIS�O  --------  <==\n\n");
            imprimirDados(editar);
            printf("\nRevise os dados acima!\n");

            printf("\nDeseja salvar as altera��es? (S / N): ");
            alterar = validarCaractere();

            if(alterar == 'S'){
                fseek(arquivoCadastros, -sizeof(Cadastro), SEEK_CUR);
                fwrite(&editar, sizeof(editar), 1, arquivoCadastros);
                printf("\nCadastro atualizado com sucesso!\n");
            } else {
                printf("\nEdi��o cancelado!\n");
            }
        }

        printf("\nDeseja editar outro usu�rio? (S / N): ");
        continuar = validarCaractere();

    } while (continuar != 'N');

    fclose(arquivoCadastros);
}

void procurarUsuario(){
    Cadastro procurar;
    memset(&procurar, 0, sizeof(Cadastro));
    int codigoProcura;
    char continuar;

    FILE *arquivoCadastros;
    arquivoCadastros = fopen(ARQUIVO, "rb");
    arquivoAberto(arquivoCadastros);

    do {
        rewind(arquivoCadastros);
        imprimirCabecalho();
        printf("-------------- Procurar  Usu�rio --------------\n");

        printf("\nInforme o c�digo do usu�rio que deseja procurar: ");
        do {
            codigoProcura = lerEntradaNumericaInteira();

            if(codigoProcura < 100){
                printf("\nO c�digo digitado � inv�lido!\nInforme o c�digo corretamente: ");
            }

        } while (codigoProcura < 100);

        if(!buscarDados(arquivoCadastros, codigoProcura, &procurar)){
            printf("\nO c�digo digitado n�o existe no sistema ou o usu�rio foi removido!\n");
        } else {
            printf("\n==>  --------  USU�RIO  ENCONTRADO  --------  <==\n\n");
            imprimirDados(procurar);
        }

        printf("\nDeseja procurar outro usu�rio? (S / N): ");
        continuar = validarCaractere();

    } while (continuar != 'N');

    fclose(arquivoCadastros);
}

void listarUsuarios(){
    Cadastro listar;
    memset(&listar, 0, sizeof(Cadastro));
    char continuar;
    int contadorCadastros;

    FILE *arquivoCadastros;
    arquivoCadastros = fopen(ARQUIVO, "rb");
    arquivoAberto(arquivoCadastros);

    do {
        contadorCadastros = 0;
        rewind(arquivoCadastros);
        imprimirCabecalho();
        printf("------------ Listar Todos Usu�rios ------------\n");

        while(fread(&listar, sizeof(Cadastro), 1, arquivoCadastros)){
            if(!listar.removido){
                printf("\n==>  --------  CADASTRO N�MERO %i  --------  <==\n\n", ++contadorCadastros);
                imprimirDados(listar);
            }
        }

        if(!contadorCadastros){
            printf("\nNenhum usu�rio v�lido encontrado no sistema!\n");
        }

        printf("\nDeseja listar os usu�rios novamente? (S / N): ");
        continuar = validarCaractere();

    } while (continuar != 'N');

    fclose(arquivoCadastros);
}

// FUN��ES PARA CONTROLE DE USU�RIOS REMOVIDOS

void removerUsuario(){
    Cadastro remover;
    memset(&remover, 0, sizeof(Cadastro));
    int codigoProcura;
    char continuar, remocao;

    FILE *arquivoCadastros;
    arquivoCadastros = fopen(ARQUIVO, "rb+");
    arquivoAberto(arquivoCadastros);

    do {
        rewind(arquivoCadastros);
        imprimirCabecalho();
        printf("-------------- Remover  Usu�rio --------------\n");

        printf("\nInforme o c�digo do usu�rio que deseja remover: ");
        do {
            codigoProcura = lerEntradaNumericaInteira();

            if(codigoProcura < 100){
                printf("\nO c�digo digitado � inv�lido!\nInforme o c�digo corretamente: ");
            }

        } while (codigoProcura < 100);

        if(!buscarDados(arquivoCadastros, codigoProcura, &remover)){
            printf("\nO c�digo digitado n�o existe no sistema ou o usu�rio j� foi removido!\n");
        } else {
            printf("\n==>  --------  USU�RIO  ENCONTRADO  --------  <==\n\n");
            imprimirDados(remover);

            printf("\nDeseja remover esse usu�rio? (S / N): ");
            remocao = validarCaractere();

            if(remocao == 'S'){
                remover.removido = true;
                fseek(arquivoCadastros, -sizeof(Cadastro), SEEK_CUR);
                fwrite(&remover, sizeof(remover), 1, arquivoCadastros);
                printf("\nRemo��o realizada com sucesso!\n");
            } else {
                printf("\nRemo��o cancelado!\n");
            }
        }
        
        printf("\nDeseja remover outro usu�rio? (S / N): ");
        continuar = validarCaractere();

    } while (continuar != 'N');

    fclose(arquivoCadastros);
}

void readicionarUsuario(){
    Cadastro adicionar;
    memset(&adicionar, 0, sizeof(Cadastro));
    int codigoProcura;
    char continuar, adicao;

    FILE *arquivoCadastros;
    arquivoCadastros = fopen(ARQUIVO, "rb+");
    arquivoAberto(arquivoCadastros);

    do {
        rewind(arquivoCadastros);
        imprimirCabecalho();
        printf("------------ Readicionar  Usu�rio ------------\n");

        printf("\nInforme o c�digo do usu�rio que deseja adicionar novamente: ");
        do {
            codigoProcura = lerEntradaNumericaInteira();

            if(codigoProcura < 100){
                printf("\nO c�digo digitado � inv�lido!\nInforme o c�digo corretamente: ");
            }

        } while (codigoProcura < 100);

        if(!buscarDadosRemovidos(arquivoCadastros, codigoProcura, &adicionar)){
            printf("\nO c�digo digitado n�o existe no sistema ou o usu�rio n�o foi removido!\n");
        } else {
            printf("\n==>  --------  USU�RIO  ENCONTRADO  --------  <==\n\n");
            imprimirDados(adicionar);

            printf("\nDeseja adicionar novamente esse usu�rio? (S / N): ");
            adicao = validarCaractere();

            if(adicao == 'S'){
                adicionar.removido = false;
                fseek(arquivoCadastros, -sizeof(Cadastro), SEEK_CUR);
                fwrite(&adicionar, sizeof(adicionar), 1, arquivoCadastros);
                printf("\nAdi��o realizada com sucesso!\n");
            } else {
                printf("\nAdi��o cancelada!\n");
            }
        }
        
        printf("\nDeseja adicionar outro usu�rio? (S / N): ");
        continuar = validarCaractere();

    } while (continuar != 'N');

    fclose(arquivoCadastros);
}

void listarUsuariosRemovidos(){
    Cadastro listar;
    memset(&listar, 0, sizeof(Cadastro));
    char continuar;
    int contadorCadastros;

    FILE *arquivoCadastros;
    arquivoCadastros = fopen(ARQUIVO, "rb");
    arquivoAberto(arquivoCadastros);

    do {
        contadorCadastros = 0;
        rewind(arquivoCadastros);
        imprimirCabecalho();
        printf("---------- Listar Usu�rios Removidos ----------\n");

        while(fread(&listar, sizeof(Cadastro), 1, arquivoCadastros)){
            if(listar.removido){
                printf("\n==>  --------  CADASTRO N�MERO %i  --------  <==\n\n", ++contadorCadastros);
                imprimirDados(listar);
            }
        }

        if(!contadorCadastros){
            printf("\nNenhum usu�rio removido encontrado no sistema!\n");
        }

        printf("\nDeseja listar os usu�rios novamente? (S / N): ");
        continuar = validarCaractere();

    } while (continuar != 'N');

    fclose(arquivoCadastros);
}

// OUTRAS FUN��ES

void gerarRelatorio(){
    Cadastro relatorio;
    memset(&relatorio, 0, sizeof(Cadastro));
    int contadorCadastros;

    char diretorioAtual[300];
    _getcwd(diretorioAtual, sizeof(diretorioAtual));

    char caminhoRelatorio[400];
    snprintf(caminhoRelatorio, sizeof(caminhoRelatorio), "%s\\data\\relat�rio.txt", diretorioAtual);

    FILE *arquivoCadastros;
    arquivoCadastros = fopen(ARQUIVO, "rb");
    arquivoAberto(arquivoCadastros);

    FILE *arquivoRelatorio;
    arquivoRelatorio = fopen(RELATORIO, "w");
    arquivoAberto(arquivoRelatorio);

    contadorCadastros = 0;
    rewind(arquivoCadastros);
    imprimirCabecalho();
    printf("--------------- Gerar Relat�rio ---------------\n");

    fprintf(arquivoRelatorio, "===============================================\n");
    fprintf(arquivoRelatorio, "  **********  CADASTRO DE USUARIO  **********  \n");
    fprintf(arquivoRelatorio, "===============================================\n");

    while(fread(&relatorio, sizeof(Cadastro), 1, arquivoCadastros)){
        fprintf(arquivoRelatorio, "\n==>  -------------------------------------  <==\n\n");
        fprintf(arquivoRelatorio, "Criacao  : %i/%i/%i - %i:%i:%i\n", relatorio.data.tm_mday, relatorio.data.tm_mon + 1, 
            relatorio.data.tm_year + 1900, relatorio.data.tm_hour, relatorio.data.tm_min, relatorio.data.tm_sec);
        fprintf(arquivoRelatorio, "Codigo   : %i\n", relatorio.codigo);
        fprintf(arquivoRelatorio, "Nome     : %s\n", relatorio.nome);
        fprintf(arquivoRelatorio, "CPF      : %s\n", relatorio.cpf);
        fprintf(arquivoRelatorio, "Telefone : %s\n", relatorio.telefone);
        fprintf(arquivoRelatorio, "E-mail   : %s\n", relatorio.email);
        fprintf(arquivoRelatorio, "Salario  : R$ %.2lf\n", relatorio.salario);
        fprintf(arquivoRelatorio, "Estado   : %s\n", relatorio.endereco.estado);
        fprintf(arquivoRelatorio, "Cidade   : %s\n", relatorio.endereco.cidade);
        fprintf(arquivoRelatorio, "Bairro   : %s\n", relatorio.endereco.bairro);
        fprintf(arquivoRelatorio, "Rua      : %s\n", relatorio.endereco.rua);
        fprintf(arquivoRelatorio, "Numero   : %i\n", relatorio.endereco.numero);
        fprintf(arquivoRelatorio, "Status   : %s\n", relatorio.removido? "Removido" : "Ativado");
        contadorCadastros++;
    }

    if(!contadorCadastros){
        printf("\nNenhum usu�rio encontrado no sistema!\n");
    } else {
        printf("\nRelat�rio gerado com sucesso!\n");
        printf("\nCaminho completo do relat�rio: %s\n", caminhoRelatorio);
    }

    printf("\nAperte qualquer tecla para voltar ao menu\n\n");

    getch();

    fclose(arquivoRelatorio);
    fclose(arquivoCadastros);
}
