#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <direct.h>
#include "menus.h"
#include "operacoes.h"

// FUNÇÕES PARA CONTROLE DE USUÁRIOS

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
        printf("-------------- Cadastrar Usuário --------------\n");

        printf("\n==>  --------  DADOS PESSOAIS  --------  <==\n");

        printf("\nInforme o nome do usuário: ");
        lerEntradaAlfanumerica(novo.nome, sizeof(novo.nome));

        printf("\nInforme o CPF do usuário (apenas números): ");
        do {
            lerEntradaAlfanumerica(novo.cpf, sizeof(novo.cpf));
            cpfValido = validarCpf(novo.cpf);

            if(!cpfValido){
                printf("\nO CPF digitado é inválido!\nInforme o CPF corretamente: ");
            }

        } while (!cpfValido);
        
        printf("\nInforme o telefone ou celular do usuário (apenas números, insira o DDD): ");
        do {
            lerEntradaAlfanumerica(novo.telefone, sizeof(novo.telefone));
            telefoneValido = validarTelefone(novo.telefone);

            if(!telefoneValido){
                printf("\nO número digitado é inválido!\nInforme o telefone ou celular corretamente: ");
            }
            
        } while (!telefoneValido);

        printf("\nInforme o e-mail do usuário: ");
        do {
            lerEntradaAlfanumerica(novo.email, sizeof(novo.email));
            emailValido = validarEmail(novo.email);

            if(!emailValido){
                printf("\nO e-mail digitado é inválido!\nInforme e-mail corretamente: ");
            }
            
        } while (!emailValido);

        printf("\nInforme o salário do usuário: ");
        do {
            novo.salario = lerEntradaNumericaDecimal();

            if(novo.salario <= 0){
                printf("\nO salário digitado é inválido!\nInforme o salário corretamente: ");
            }

        } while (novo.salario <= 0);

        printf("\n==>  --------  DADOS DE ENDEREÇO  --------  <==\n");

        printf("\nInforme o estado (UF) do usuário (apenas a sigla): ");
        do {
            lerEntradaAlfanumerica(novo.endereco.estado, sizeof(novo.endereco.estado));

            for(int i = 0; novo.endereco.estado[i] != '\0'; i++){
                novo.endereco.estado[i] = toupper(novo.endereco.estado[i]);
            }
            estadoValido = validarUnidadeFederativa(novo.endereco.estado);

            if(!estadoValido){
                printf("\nA sigla digitada é inexistente!\nInforme uma UF existente: ");
            }

        } while (!estadoValido);

        printf("\nInforme a cidade do usuário: ");
        lerEntradaAlfanumerica(novo.endereco.cidade, sizeof(novo.endereco.cidade));

        printf("\nInforme o bairro do usuário: ");
        lerEntradaAlfanumerica(novo.endereco.bairro, sizeof(novo.endereco.bairro));
        
        printf("\nInforme a rua do usuário: ");
        lerEntradaAlfanumerica(novo.endereco.rua, sizeof(novo.endereco.rua));

        printf("\nInforme o número do usuário: ");
        do {
            novo.endereco.numero = lerEntradaNumericaInteira();

            if(novo.endereco.numero <= 0){
                printf("\nO número digitado é inválido!\nInforme o número corretamente: ");
            }

        } while (novo.endereco.numero <= 0);

        novo.codigo = codigoAtual;
        time_t now = time(NULL);
        novo.data = *localtime(&now);
        novo.removido = false;
        
        printf("\n==>  --------  REVISÃO  --------  <==\n\n");
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

        printf("\nDeseja cadastrar outro usuário? (S / N): ");
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
        printf("-------------- Procurar  Usuário --------------\n");

        printf("\nInforme o código do usuário que deseja procurar: ");
        do {
            while(scanf("%i", &codigoProcura) != 1){
                printf("\nErro, entrada inválida!\nInsira outro valor: ");
                limpezaBuffer();
            }
            limpezaBuffer();

            if(codigoProcura < 100){
                printf("\nO código digitado é inválido!\nInforme o código corretamente: ");
            }

        } while (codigoProcura < 100);

        if(!buscarDados(arquivoCadastros, codigoProcura, &editar)){
            printf("\nO código digitado não existe no sistema ou o usuário foi removido!\n");
        } else {
            printf("\n==>  --------  USUÁRIO  ENCONTRADO  --------  <==\n\n");
            imprimirDados(editar);

            printf("\n==>  --------  ALTERAR DADOS SALVOS  --------  <==\n");

            printf("\nAlterar nome: ");
            lerEntradaAlfanumerica(editar.nome, sizeof(editar.nome));

            printf("Alterar CPF: ");
            do {
                lerEntradaAlfanumerica(editar.cpf, sizeof(editar.cpf));
                cpfValido = validarCpf(editar.cpf);

                if(!cpfValido){
                    printf("\nO CPF digitado é inválido!\nInforme o CPF corretamente: ");
                }

            } while (!cpfValido);
            
            printf("Alterar telefone: ");
            do {
                lerEntradaAlfanumerica(editar.telefone, sizeof(editar.telefone));
                telefoneValido = validarTelefone(editar.telefone);

                if(!telefoneValido){
                    printf("\nO número digitado é inválido!\nInforme o telefone ou celular corretamente: ");
                }
                
            } while (!telefoneValido);

            printf("Alterar e-mail: ");
            do {
                lerEntradaAlfanumerica(editar.email, sizeof(editar.email));
                emailValido = validarEmail(editar.email);

                if(!emailValido){
                    printf("\nO e-mail digitado é inválido!\nInforme e-mail corretamente: ");
                }
                
            } while (!emailValido);

            printf("Alterar salário: ");
            do {
                editar.salario = lerEntradaNumericaDecimal();

                if(editar.salario <= 0){
                    printf("\nO salário digitado é inválido!\nInforme o salário corretamente: ");
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
                    printf("\nA sigla digitada é inexistente!\nInforme uma UF existente: ");
                }

            } while (!estadoValido);

            printf("Alterar cidade: ");
            lerEntradaAlfanumerica(editar.endereco.cidade, sizeof(editar.endereco.cidade));

            printf("Alterar bairro: ");
            lerEntradaAlfanumerica(editar.endereco.bairro, sizeof(editar.endereco.bairro));
            
            printf("Alterar rua: ");
            lerEntradaAlfanumerica(editar.endereco.rua, sizeof(editar.endereco.rua));

            printf("Alterar número: ");
            do {
                editar.endereco.numero = lerEntradaNumericaInteira();

                if(editar.endereco.numero <= 0){
                    printf("\nO número digitado é inválido!\nInforme o número corretamente: ");
                }

            } while (editar.endereco.numero <= 0);
            
            printf("\n==>  --------  REVISÃO  --------  <==\n\n");
            imprimirDados(editar);
            printf("\nRevise os dados acima!\n");

            printf("\nDeseja salvar as alterações? (S / N): ");
            alterar = validarCaractere();

            if(alterar == 'S'){
                fseek(arquivoCadastros, -sizeof(Cadastro), SEEK_CUR);
                fwrite(&editar, sizeof(editar), 1, arquivoCadastros);
                printf("\nCadastro atualizado com sucesso!\n");
            } else {
                printf("\nEdição cancelado!\n");
            }
        }

        printf("\nDeseja editar outro usuário? (S / N): ");
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
        printf("-------------- Procurar  Usuário --------------\n");

        printf("\nInforme o código do usuário que deseja procurar: ");
        do {
            codigoProcura = lerEntradaNumericaInteira();

            if(codigoProcura < 100){
                printf("\nO código digitado é inválido!\nInforme o código corretamente: ");
            }

        } while (codigoProcura < 100);

        if(!buscarDados(arquivoCadastros, codigoProcura, &procurar)){
            printf("\nO código digitado não existe no sistema ou o usuário foi removido!\n");
        } else {
            printf("\n==>  --------  USUÁRIO  ENCONTRADO  --------  <==\n\n");
            imprimirDados(procurar);
        }

        printf("\nDeseja procurar outro usuário? (S / N): ");
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
        printf("------------ Listar Todos Usuários ------------\n");

        while(fread(&listar, sizeof(Cadastro), 1, arquivoCadastros)){
            if(!listar.removido){
                printf("\n==>  --------  CADASTRO NÚMERO %i  --------  <==\n\n", ++contadorCadastros);
                imprimirDados(listar);
            }
        }

        if(!contadorCadastros){
            printf("\nNenhum usuário válido encontrado no sistema!\n");
        }

        printf("\nDeseja listar os usuários novamente? (S / N): ");
        continuar = validarCaractere();

    } while (continuar != 'N');

    fclose(arquivoCadastros);
}

// FUNÇÕES PARA CONTROLE DE USUÁRIOS REMOVIDOS

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
        printf("-------------- Remover  Usuário --------------\n");

        printf("\nInforme o código do usuário que deseja remover: ");
        do {
            codigoProcura = lerEntradaNumericaInteira();

            if(codigoProcura < 100){
                printf("\nO código digitado é inválido!\nInforme o código corretamente: ");
            }

        } while (codigoProcura < 100);

        if(!buscarDados(arquivoCadastros, codigoProcura, &remover)){
            printf("\nO código digitado não existe no sistema ou o usuário já foi removido!\n");
        } else {
            printf("\n==>  --------  USUÁRIO  ENCONTRADO  --------  <==\n\n");
            imprimirDados(remover);

            printf("\nDeseja remover esse usuário? (S / N): ");
            remocao = validarCaractere();

            if(remocao == 'S'){
                remover.removido = true;
                fseek(arquivoCadastros, -sizeof(Cadastro), SEEK_CUR);
                fwrite(&remover, sizeof(remover), 1, arquivoCadastros);
                printf("\nRemoção realizada com sucesso!\n");
            } else {
                printf("\nRemoção cancelado!\n");
            }
        }
        
        printf("\nDeseja remover outro usuário? (S / N): ");
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
        printf("------------ Readicionar  Usuário ------------\n");

        printf("\nInforme o código do usuário que deseja adicionar novamente: ");
        do {
            codigoProcura = lerEntradaNumericaInteira();

            if(codigoProcura < 100){
                printf("\nO código digitado é inválido!\nInforme o código corretamente: ");
            }

        } while (codigoProcura < 100);

        if(!buscarDadosRemovidos(arquivoCadastros, codigoProcura, &adicionar)){
            printf("\nO código digitado não existe no sistema ou o usuário não foi removido!\n");
        } else {
            printf("\n==>  --------  USUÁRIO  ENCONTRADO  --------  <==\n\n");
            imprimirDados(adicionar);

            printf("\nDeseja adicionar novamente esse usuário? (S / N): ");
            adicao = validarCaractere();

            if(adicao == 'S'){
                adicionar.removido = false;
                fseek(arquivoCadastros, -sizeof(Cadastro), SEEK_CUR);
                fwrite(&adicionar, sizeof(adicionar), 1, arquivoCadastros);
                printf("\nAdição realizada com sucesso!\n");
            } else {
                printf("\nAdição cancelada!\n");
            }
        }
        
        printf("\nDeseja adicionar outro usuário? (S / N): ");
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
        printf("---------- Listar Usuários Removidos ----------\n");

        while(fread(&listar, sizeof(Cadastro), 1, arquivoCadastros)){
            if(listar.removido){
                printf("\n==>  --------  CADASTRO NÚMERO %i  --------  <==\n\n", ++contadorCadastros);
                imprimirDados(listar);
            }
        }

        if(!contadorCadastros){
            printf("\nNenhum usuário removido encontrado no sistema!\n");
        }

        printf("\nDeseja listar os usuários novamente? (S / N): ");
        continuar = validarCaractere();

    } while (continuar != 'N');

    fclose(arquivoCadastros);
}

// OUTRAS FUNÇÕES

void gerarRelatorio(){
    Cadastro relatorio;
    memset(&relatorio, 0, sizeof(Cadastro));
    int contadorCadastros;

    char diretorioAtual[300];
    _getcwd(diretorioAtual, sizeof(diretorioAtual));

    char caminhoRelatorio[400];
    snprintf(caminhoRelatorio, sizeof(caminhoRelatorio), "%s\\data\\relatório.txt", diretorioAtual);

    FILE *arquivoCadastros;
    arquivoCadastros = fopen(ARQUIVO, "rb");
    arquivoAberto(arquivoCadastros);

    FILE *arquivoRelatorio;
    arquivoRelatorio = fopen(RELATORIO, "w");
    arquivoAberto(arquivoRelatorio);

    contadorCadastros = 0;
    rewind(arquivoCadastros);
    imprimirCabecalho();
    printf("--------------- Gerar Relatório ---------------\n");

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
        printf("\nNenhum usuário encontrado no sistema!\n");
    } else {
        printf("\nRelatório gerado com sucesso!\n");
        printf("\nCaminho completo do relatório: %s\n", caminhoRelatorio);
    }

    printf("\nAperte qualquer tecla para voltar ao menu\n\n");

    getch();

    fclose(arquivoRelatorio);
    fclose(arquivoCadastros);
}
