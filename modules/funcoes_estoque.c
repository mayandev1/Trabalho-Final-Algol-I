#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    printf("\nPressione ENTER para continuar...\n");

    int key;
    do {
        key = getchar();
    } while (key != '\n' && key != EOF);
}

// Função para cadastrar um novo item
int cadastrarItem(int id[], char nome[][50], float preco[], int quantidade[], int total_de_produtos){
    // Verifica se o limite de produtos foi atingido
    if(total_de_produtos >= MAX){
        limparTela();
        printf("Limite de produtos atingido\n");
        getchar();
        pequenaPausa();
        return 0; // Retorna 0 para indicar que o cadastro falhou
    }

    int novoID;

    // Solicita o ID do novo produto
    printf("Digite o ID do produto: ");
    scanf("%d", &novoID);
    limparBuffer();

    // Verifica se o ID já está cadastrado
    for(int i = 0; i < total_de_produtos; i++){
        if(id[i] == novoID){
            printf("ID ja existe. Digite outro!\n");
            pequenaPausa();
            return 0; // Retorna 0 se o ID já existir
        }
    }

    // Armazena o novo ID no vetor
    id[total_de_produtos] = novoID;

    // Solicita o nome do produto
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", nome[total_de_produtos]);
    limparBuffer();

    // Solicita o preço do produto
    printf("Digite o preco do produto: ");
    scanf("%f", &preco[total_de_produtos]);
    limparBuffer();

    // Solicita a quantidade do produto em estoque
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &quantidade[total_de_produtos]);
    limparBuffer();

    limparTela();
    printf("Produto adicionado com sucesso!\n");
    pequenaPausa();

    return 1; // Retorna 1 para indicar sucesso no cadastro
}

//Função para excluir um item
int excluirItem(int id[], char nome[][50], float preco[], int quantidade[], int total_de_produtos) {
    int cod, encontrado = 0;

    if(total_de_produtos <= 0){
        limparTela();
        printf("Estoque vazio!\n");
        getchar();
        pequenaPausa();
        return total_de_produtos;
    }

    limparTela();
    printf("======= OPCAO EXCLUIR PRODUTO =======\n");
    printf("Digite o ID do produto: ");
    scanf("%d", &cod);
    limparBuffer();

    limparTela();
    for(int i = 1; i <= 3; i++){
        printf("Buscando");
        for (int j = 0; j < i; j++){
            printf(".");
        }
        Sleep(650);
        limparTela();
    }

    for(int i = 0; i < total_de_produtos; i++){
        if(cod == id[i]){
            encontrado = 1;
            for(int j = i; j < total_de_produtos - 1; j++){
                id[j] = id[j + 1];
                preco[j] = preco[j + 1];
                quantidade[j] = quantidade[j + 1];
                strcpy(nome[j], nome[j + 1]);
            }
            limparTela();
            printf("ENCONTRADO!\n");
            printf("ID DO PRODUTO EXCLUIDO: %d\n", cod);
            total_de_produtos--;
            pequenaPausa();
            break;
        }
    }

    if(!encontrado){
        limparTela();
        printf("O PRODUTO NAO FOI ENCONTRADO.\n");
        pequenaPausa();
    }

    return total_de_produtos;
}

//Função para editar um produto
void editarItem(int id[], char nome[][50], float preco[], int quantidade[], int total_de_produtos){
    int cod, encontrado = 0;

    limparTela();
    printf("===== OPCAO EDITAR PRODUTO =====\n");
    printf("Digite o ID do produto que deseja editar: ");
    scanf("%d", &cod);
    limparBuffer();

    limparTela();
    for(int i = 1; i <= 3; i++){
        printf("Buscando");
        for (int j = 0; j < i; j++){
            printf(".");
        }
        Sleep(650);
        limparTela();
    }
    
    for(int i = 0; i < total_de_produtos; i++){
        if(id[i] == cod){
            encontrado = 1;
            int op;
            
            limparTela();
            printf("===== OPCAO EDITAR PRODUTO =====\n");
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
            printf("5 - Editar Tudo\n");
            printf("Opcao: ");
            scanf("%d", &op);
            limparBuffer();

            switch(op){
                case 1:
                    limparTela();
                    printf("Novo ID: ");
                    scanf("%d", &id[i]);
                    printf("ID atualizado com sucesso!\n");
                    pequenaPausa();
                    break;
                case 2:
                    limparTela();
                    printf("Novo nome: ");
                    scanf(" %[^\n]", nome[i]);
                    printf("Nome atualizado com sucesso!\n");
                    pequenaPausa();
                    break;
                case 3:
                    limparTela();
                    printf("Novo preco: ");
                    scanf("%f", &preco[i]);
                    printf("Preco atualizado com sucesso!\n");
                    pequenaPausa();
                    break;
                case 4:
                    limparTela();
                    printf("Nova quantidade: ");
                    scanf("%d", &quantidade[i]);
                    printf("Quantidade atualizada com sucesso!\n");
                    pequenaPausa();
                    break;
                case 5:
                    limparTela();
                    printf("Novo nome: ");
                    scanf("%[^\n]", &nome[i]);

                    printf("Novo ID: ");
                    scanf("%d", &id[i]);

                    printf("Novo preco: ");
                    scanf("%f", &preco[i]);

                    printf("Nova quantidade: ");
                    scanf("%d", &quantidade[i]);

                    limparTela();
                    printf("Todos os dados foram atualizados com sucesso!");
                    pequenaPausa();
                    break;
                default:
                    limparTela();
                    printf("Opcao invalida.\n");
                    pequenaPausa();
            }
            limparBuffer();
            break;
        }
    }

    if(!encontrado){
        limparTela();
        printf("PRODUTO COM ID %d NAO ENCONTRADO.\n", cod);
        pequenaPausa();
    }
}

//Função para listar todos os produtos cadastrados
void listarItens(int id[], char nome[][50], float preco[], int quantidade[], int total_de_produtos){
    if(total_de_produtos == 0){
        limparTela();
        printf("NENHUM PRODUTO CADASTRADO PARA LISTAR!\n");
        getchar();
        pequenaPausa();
        return;
    }

    //Loop para ordenar pelo ID
    for(int i = 0; i < total_de_produtos - 1; i++){
        for(int j = 0; j < total_de_produtos - i - 1; j++){
            if(id[j] > id[j + 1]){
                //Trocar ID
                int temp_id = id[j];
                id[j] = id[j + 1];
                id[j + 1] = temp_id;

                //Trocar Nome
                char temp_nome[50];
                strcpy(temp_nome, nome[j]);
                strcpy(nome[j], nome[j + 1]);
                strcpy(nome[j + 1], temp_nome);

                //Trocar Preço
                float temp_preco = preco[j];
                preco[j] = preco[j + 1];
                preco[j + 1] = temp_preco;

                //Trocar Quantidade
                int temp_quant = quantidade[j];
                quantidade[j] = quantidade[j + 1];
                quantidade[j + 1] = temp_quant;
            }
        }
    }

    limparBuffer();
    printf("======== LISTA DE PRODUTOS CADASTRADOS ========\n");
    for(int i = 0; i < total_de_produtos; i++){
        printf("ID: %d | Nome: %s | Preco: %.2f | Quantidade: %d\n", id[i], nome[i], preco[i], quantidade[i]);
    }
    pequenaPausa();
}

//Função para buscar um produto e mostrar suas informações
void buscarItem(int id[], char nome[][50], float preco[], int quantidade[], int total_de_produtos){
    int codigo;

    printf("Informe o ID do produto: ");
    scanf("%d", &codigo);
    limparBuffer();

    limparTela();
    for(int i = 1; i <= 3; i++){
        printf("Buscando");
        for (int j = 0; j < i; j++){
            printf(".");
        }
        Sleep(650);
        limparTela();
    }

    for(int i = 0; i < total_de_produtos; i++){
        if(id[i] == codigo){
            printf("=====================================\n");
            printf("Produto encontrado:\n");
            printf("ID: %d\n", id[i]);
            printf("Nome: %s\n", nome[i]);
            printf("Preco: R$ %.2f\n", preco[i]);
            printf("Quantidade em estoque: %d\n", quantidade[i]);
            printf("=====================================\n");

            pequenaPausa();
            return;
        }
    }

    limparTela();
    printf("O PRODUTO NAO FOI ENCONTRADO.\n");
    pequenaPausa();
}