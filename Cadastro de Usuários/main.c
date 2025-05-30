#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include "menus.h"
#include "operacoes.h"

int main() {
    setlocale(LC_ALL, "portuguese");
    int opcao;

    do {
        imprimirCabecalho();
        printf("\n       [1] Cadastrar Usu�rio\n");
        printf("       [2] Editar Usu�rio\n");
        printf("       [3] Procurar Usu�rio\n");
        printf("       [4] Listar Usu�rios\n");
        printf("       [5] Remover Usu�rio\n");
        printf("       [6] Readicionar Usu�rio\n");
        printf("       [7] Listar Usu�rios Removidos\n");
        printf("       [8] Gerar Relat�rio\n");
        printf("       [0] Encerrar o programa\n\n");
        printf("----------------------------------------------\n\n");
        
        printf("Escolha uma das op��es acima: ");
        opcao = lerEntradaNumericaInteira();

        switch (opcao) {
        
        case 0: break;
        case 1: cadastrarUsuario(); break;
        case 2: editarUsuario(); break;
        case 3: procurarUsuario(); break;
        case 4: listarUsuarios(); break;
        case 5: removerUsuario(); break;
        case 6: readicionarUsuario(); break;
        case 7: listarUsuariosRemovidos(); break;
        case 8: gerarRelatorio(); break;
        
        default: printf("\nOp��o inv�lida! Tente novamente."); getch(); break;
        }

    } while(opcao);

    return 0;
}
