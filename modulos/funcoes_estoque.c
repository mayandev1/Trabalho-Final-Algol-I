#include <stdio.h>
#include "funcoes_estoque.h"

void limparTela(){
    system("cls");
}

void cadastrarItem(){
}

int excluirItem(int codigo[], char nome[][50], float preco[], int quantidade){
    int cod, i, j, k, encontrado = 0;
    char saida[10];

    if(quantidade > 0){
        limparTela();
        printf("\n-------OPCAO EXCLUIR PRODUTO -------\n");
        printf("Digite o codigo do produto:\n");
        scanf("%d",&cod);
        limparTela();

        printf("\n-------OPCAO EXCLUIR PRODUTO -------\n");
        for(i = 1; i <= 3; i++){
            printf("Buscando %d...",i);
            Sleep(650);
            limparTela();
        }

        for(i = 0; i < quantidade; i++){
            if(cod == codigo[i]){
                encontrado = 1;
                for(j = i; j < quantidade - 1; j++){
                    codigo[j] = codigo[j + 1];
                    preco[j] = preco[j + 1];

                    for(k = 0; k < 50; k++){
                        nome[j][k] = nome[j + 1][k];
                    }
                }
                printf("CODIGO DO PRODUTO EXCLUIDO: %d\n",cod);
                quantidade = quantidade - 1;
                break;
            }
        }
    }
}

void editaritem(int codigo[], char nome[][50], float preco[], int quantidade[]){
    int codigo, i, op, encontrado = 0;

    printf("\n----- OPÇÃO EDITAR PRODUTO -----\n");
    printf("Digite o código do produto que deseja editar: ");
    scanf("%d", &codigo);

    for ( i = 0; i < quantidade; i++)
    {
        if (codigo[i] == codigo)
        {
            encontrado = 1;
        }
        
    }
    
}