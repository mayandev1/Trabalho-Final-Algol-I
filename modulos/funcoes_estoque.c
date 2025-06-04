#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funcoes_estoque.h"

#define MAX 100

// Função pra limpar o terminal
void limparTela(){
    system("cls"); 
}

// Função pra limpar o buffer pós scanf
void limparBuffer(){
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

// Função para dá uma pequena pausa entre as mensagens/menus
void pequenaPausa(){
    printf("\nPressione ENTER para continuar...");
    
    limparBuffer();
    
    int key;
    do {
        key = getchar();
    } while (key != '\n' && key != EOF);
    
    limparBuffer();
}

// Adicionei a função da betania e passei os parametros + algumas correções
void cadastrarItem(int id[], char nome[][50], float preco[], int quantidade[], int total_de_produtos){
    if(total_de_produtos >= MAX){
        printf("Passou do limite\n");
        return;
    }

    int novoID;
    printf("Digite o ID do produto:\n");
    scanf("%d", &novoID);

    // Verifica se o ID já existe
    for(int i = 0; i < total_de_produtos; i++){
        if(id[i] == novoID){
            printf("ID já existe. Digite outro!\n");
            return;
        }
    }

    id[total_de_produtos] = novoID;

    printf("Digite o nome do produto:\n");
    scanf(" %[^\n]", nome[total_de_produtos]);

    printf("Digite o preço do produto:\n");
    scanf("%f", &preco[total_de_produtos]);

    printf("Digite a quantidade em estoque:\n");
    scanf("%d", &quantidade[total_de_produtos]);

    printf("Produto adicionado com sucesso!\n");
}

// Faltou retornar o valor
int excluirItem(int codigo[], char nome[][50], float preco[], int quantidade[], int total){
    int cod, i, j, k, encontrado = 0;

    if(total > 0){
        limparTela();
        printf("\n------- OPÇÃO EXCLUIR PRODUTO -------\n");
        printf("Digite o código do produto:\n");
        scanf("%d", &cod);
        limparTela();

        for(i = 1; i <= 3; i++){
            printf("Buscando %d...\n", i);
            Sleep(650);
            limparTela();
        }

        for(i = 0; i < total; i++){
            if(cod == codigo[i]){
                encontrado = 1;
                for(j = i; j < total - 1; j++){
                    codigo[j] = codigo[j + 1];
                    preco[j] = preco[j + 1];
                    quantidade[j] = quantidade[j + 1];

                    for(k = 0; k < 50; k++){
                        nome[j][k] = nome[j + 1][k];
                    }
                }
                printf("Código do produto excluído: %d\n", cod);
                total--;
                break;
            }
        }

        if(!encontrado){
            printf("Produto não encontrado.\n");
        }
    } else {
        printf("Estoque vazio.\n");
    }

    return total; // retornando o total
}

// Faltou passar os parametros tambem
void editarItem(int id[], char nome[][50], float preco[], int quantidade[], int total_de_produtos){
    int codi, i, op, encontrado = 0;

    printf("\n----- OPÇÃO EDITAR PRODUTO -----\n");
    printf("Digite o código do produto que deseja editar: ");
    scanf("%d", &codi);

    for(i = 0; i < total_de_produtos; i++){
        if(id[i] == codi){
            encontrado = 1;

            printf("\nProduto encontrado!\n");
            printf("Código: %d\n", id[i]);
            printf("Nome: %s\n", nome[i]);
            printf("Preço: %.2f\n", preco[i]);
            printf("Quantidade: %d\n", quantidade[i]);

            printf("\nO que deseja editar?\n");
            printf("1 - Nome\n");
            printf("2 - Código\n");
            printf("3 - Preço\n");
            printf("4 - Quantidade\n");
            scanf("%d", &op);

            switch(op){
                case 1:
                    printf("Novo nome: ");
                    scanf(" %[^\n]", nome[i]);
                    printf("Nome atualizado com sucesso!\n");
                    break;
                case 2:
                    printf("Novo código: ");
                    scanf("%d", &id[i]);
                    printf("Código atualizado com sucesso!\n");
                    break;
                case 3:
                    printf("Novo preço: ");
                    scanf("%f", &preco[i]);
                    printf("Preço atualizado com sucesso!\n");
                    break;
                case 4:
                    printf("Nova quantidade: ");
                    scanf("%d", &quantidade[i]);
                    printf("Quantidade atualizada com sucesso!\n");
                    break;
                default:
                    printf("Opção inválida.\n");
            }
            break;
        }
    }

    if(!encontrado){
        printf("Produto com código %d não encontrado.\n", codi);
    }
}

void listarItens(int id[], char nome[][50], float preco[], int quantidade[], int total_de_produtos){
    if (total_de_produtos <= 0){
        limparTela();
        printf("NENHUM PRODUTO CADASTRADO PARA LISTAR!\n");
        pequenaPausa();
        return;
    }

    printf("======== LISTA DE PRODUTOS CADASTRADOS ========\n");
    for (int i = 0; i < total_de_produtos; i++){
        printf("ID: %d | Nome: %s | Preco: %.2f | Quantidade: %d |\n", id[i], nome[i][50], preco[i], quantidade[i]);
    }
    
    
}

void consultarProduto(int id[], char nome_do_produto[][50], float preco[], int quantidade[], int total_de_produtos) {
    int codigo;
    printf("Informe o código do produto: ");
    scanf("%d", &codigo);

    for (int i = 0; i < total_de_produtos; i++) {
        if (id[i] == codigo) {
            printf("===================================================\n");
            printf("Produto encontrado:\n");
            printf("Código: %d\n", id[i]);
            printf("Nome: %s\n", nome_do_produto[i]);
            printf("Preço: R$ %.2f\n", preco[i]);
            printf("Quantidade em estoque: %d\n", quantidade[i]);
            printf("===================================================\n");
            return;
        }
    }

    printf("Produto não encontrado.\n");
}