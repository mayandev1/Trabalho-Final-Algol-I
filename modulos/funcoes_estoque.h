#ifndef ESTOQUE_H
#define ESTOQUE_H

void cadastrarItem(int id[], char nome[][50], float preco[], int quantidade[], int total_de_produtos);
int excluirItem(int codigo[], char nome[][50], float preco[], int quantidade[], int total);
void editarItem(int id[], char nome[][50], float preco[], int quantidade[], int total_de_produtos);
void buscarItem(int id[], char nome_do_produto[][50], float preco[], int quantidade[], int total_de_produtos);
void listarItens(int id[], char nome[][50], float preco[], int quantidade[], int total_de_produtos);
void limparBuffer();
void limparTela();
void pequenaPausa();

#endif