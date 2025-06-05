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
        c = getchar(); //Serve para ler um caractere da entrada padrão, pausar a execução ou limpar o buffer de entrada.
    } while (c != '\n' && c != EOF); //Limpa o buffer de entrada, ignorando todos os caracteres até a quebra de linha ou fim do arquivo
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

// Função para cadastrar um novo item
void cadastrarItem(int id[], char nome[][50], float preco[], int quantidade[], int total_de_produtos){
    if(total_de_produtos >= MAX){
        limparTela();
        printf("Limite de produtos atingido\n");
        pequenaPausa();
        return;
    }

    // Cadastro do ID
    int novoID;
    printf("Digite o ID do produto: ");
    scanf("%d", &novoID);
    limparBuffer();

    // Verifica se ID já existe
    for(int i = 0; i < total_de_produtos; i++){
        if(id[i] == novoID) {
            printf("ID ja existe. Digite outro!\n");
            pequenaPausa();
            return;
        }
    }

    id[total_de_produtos] = novoID;

    // Cadastro do nome
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", nome[total_de_produtos]);
    limparBuffer();

    // Cadastro do preço
    printf("Digite o preco do produto: ");
    scanf("%f", &preco[total_de_produtos]);
    limparBuffer();

    // Cadastro da quantidade
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &quantidade[total_de_produtos]);
    limparBuffer();

    limparTela();
    printf("Produto adicionado com sucesso!\n");
    pequenaPausa();
}

//Função para excluir um item
int excluirItem(int id[], char nome[][50], float preco[], int quantidade[], int total_de_produtos) {
    int cod, encontrado = 0;

    if(total_de_produtos <= 0){
        limparTela();
        printf("Estoque vazio.\n");
        pequenaPausa();
        return total_de_produtos;
    }

    limparTela();
    printf("\n------- OPCAO EXCLUIR PRODUTO -------\n");
    printf("Digite o ID do produto:\n");
    scanf("%d", &cod);
    limparBuffer();

    for(int i = 1; i <= 3; i++){
        printf("Buscando %d...\n", i);
        Sleep(650);
        limparTela();
    }

    for(int i = 0; i < total_de_produtos; i++){
        if(cod == id[i]){
            encontrado = 1;
            for(int j = i; j < total_de_produtos - 1; j++) {
                id[j] = id[j + 1];
                preco[j] = preco[j + 1];
                quantidade[j] = quantidade[j + 1];
                strcpy(nome[j], nome[j + 1]);
            }
            limparTela();
            printf("ID do produto excluido: %d\n", cod);
            total_de_produtos--;
            pequenaPausa();
            break;
        }
    }

    if(!encontrado){
        limparTela();
        printf("O produto nao foi encontrado.\n");
        pequenaPausa();
    }

    return total_de_produtos;
}

//Função para editar um produto
void editarItem(int id[], char nome[][50], float preco[], int quantidade[], int total_de_produtos){
    int cod, encontrado = 0;

    printf("\n----- OPCAO EDITAR PRODUTO -----\n");
    printf("Digite o ID do produto que deseja editar: ");
    scanf("%d", &cod);
    limparBuffer();

    for(int i = 0; i < total_de_produtos; i++){
        if(id[i] == cod) {
            encontrado = 1;
            int op;

            printf("\nProduto encontrado!\n");
            printf("ID: %d\n", id[i]);
            printf("Nome: %s\n", nome[i]);
            printf("Preco: %.2f\n", preco[i]);
            printf("Quantidade: %d\n", quantidade[i]);

            printf("\nO que deseja editar?\n");
            printf("1 - ID\n");
            printf("2 - Nome\n");
            printf("3 - Preco\n");
            printf("4 - Quantidade\n");
            scanf("%d", &op);
            limparBuffer();

            switch(op){
                case 1:
                    printf("Novo nome: ");
                    scanf(" %[^\n]", nome[i]);
                    printf("Nome atualizado com sucesso!\n");
                    break;
                case 2:
                    printf("Novo id: ");
                    scanf("%d", &id[i]);
                    printf("id atualizado com sucesso!\n");
                    break;
                case 3:
                    printf("Novo preco: ");
                    scanf("%f", &preco[i]);
                    printf("Preco atualizado com sucesso!\n");
                    break;
                case 4:
                    printf("Nova quantidade: ");
                    scanf("%d", &quantidade[i]);
                    printf("Quantidade atualizada com sucesso!\n");
                    break;
                default:
                    printf("Opcao invalida.\n");
            }
            limparBuffer();
            break;
        }
    }

    if(!encontrado){
        limparTela();
        printf("Produto com id %d nao encontrado.\n", cod);
        pequenaPausa();
    }
}

void listarItens(int id[], char nome[][50], float preco[], int quantidade[], int total_de_produtos){
    if(total_de_produtos <= 0){
        limparTela();
        printf("NENHUM PRODUTO CADASTRADO PARA LISTAR!\n");
        pequenaPausa();
        return;
    }

    printf("======== LISTA DE PRODUTOS CADASTRADOS ========\n");
    for(int i = 0; i < total_de_produtos; i++){
        printf("ID: %d | Nome: %s | Preco: %.2f | Quantidade: %d |\n", id[i], nome[i], preco[i], quantidade[i]);
    }
}

void buscarItem(int id[], char nome[][50], float preco[], int quantidade[], int total_de_produtos){
    int codigo;

    printf("Informe o id do produto: ");
    scanf("%d", &codigo);
    limparBuffer();

    for(int i = 0; i < total_de_produtos; i++){
        if(id[i] == codigo){
            printf("===================================================\n");
            printf("Produto encontrado:\n");
            printf("ID: %d\n", id[i]);
            printf("Nome: %s\n", nome[i]);
            printf("Preco: R$ %.2f\n", preco[i]);
            printf("Quantidade em estoque: %d\n", quantidade[i]);
            printf("===================================================\n");

            return;
        }
    }

    limparTela();
    printf("O Produto nao foi encontrado.\n");
    pequenaPausa();
}