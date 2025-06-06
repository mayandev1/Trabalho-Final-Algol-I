#include <stdio.h>
#include <stdlib.h>
#include "modules/funcoes_estoque.h"
#include "modules/modulo_print.h"

#define MAX 100

//Inclusão dos módulos, bibliotecas padrão e definição de costante "MAX"

int main(){
    int id[MAX];                   
    char nome[MAX][50];
    float preco[MAX];
    int quantidade[MAX];
    int total_de_produtos = 0;
    int opcao;

    do {
        limparTela();
        printMenuPrincipal();
        scanf("%d", &opcao);
        limparTela();

        switch(opcao){
            case 1:
                // Se o cadastro for bem sucedido (retorna 1), incrementa o total de produtos   
                if (cadastrarItem(id, nome, preco, quantidade, total_de_produtos)){

                    total_de_produtos++;
                }
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
                // Chama a função para excluir um item com base no ID informado pelo usuário.
                // A função retorna o novo total de produtos após a exclusão, e atualizamos a variável.
                total_de_produtos = excluirItem(id, nome, preco, quantidade, total_de_produtos);
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