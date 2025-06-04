#include <stdio.h>
#include <stdlib.h>
#include "modulos/funcoes_estoque.h"
#include "modulos/modulo_print.h"

#define MAX 100

int main(){
    int id[MAX];                   
    char nome[MAX][50];
    float preco[MAX];
    int quantidade[MAX];
    int total_de_produtos = 0;
    int opcao;

    do {
        printMenuPrincipal();
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                limparTela();
                cadastrarItem(id, nome, preco, quantidade, total_de_produtos);
                total_de_produtos++;
                break;

            case 2:
                printf("Opcao: Listar\n");
                break;
            case 3:
                printf("Opcao: Buscar\n");
                break;
            case 4:
                printf("Opcao: Excluir\n");
                break;
            case 5:
                printf("Opcao: Alterar\n");
                break;
            case 6:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);

    return 0;
}