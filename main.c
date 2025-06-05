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
        limparTela();

        switch(opcao){
            case 1:
                cadastrarItem(id, nome, preco, quantidade, total_de_produtos);
                total_de_produtos++;
                limparTela();
                break;
            case 2:
                listarItens(id, nome, preco, quantidade, total_de_produtos);
                limparTela();
                break;
            case 3:
                editarItem(id, nome, preco, quantidade, total_de_produtos);
                limparTela();
                break;
            case 4:
                buscarItem(id, nome, preco, quantidade, total_de_produtos);
                limparTela();
                break;
            case 5:
                excluirItem(id, nome, preco, quantidade, total_de_produtos);
                limparTela();
                break;
            case 6:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while(opcao != 6);

    return 0;
}