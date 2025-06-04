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

void editaritem(int codigo[], char nome[][50], float preco[], int quantidade[], int total){
    int cod, i, op, encont = 0;

    printf("\n----- OPÇÃO EDITAR PRODUTO -----\n");
    printf("Digite o código do produto que deseja editar: ");
    scanf("%d", &codigo);

    for ( i = 0; i < total; i++)
    {
        if (codigo[i] == cod)
        {
            encont = 1;

            printf("\nProduto encontrado!\n");
            printf("Código: %d\n", codigo[i]);
            printf("Nome: %s\n", nome[i]);
            printf("Preço: %2.f\n", preco[i]);
            printf("Quantidade: %d\n", quantidade[i]);

            printf("\nO que deseja editar?\n");
            printf("1 - Nome\n");
            printf("2 - Código\n");
            printf("3 - Preço\n");
            printf("4 - Quantidade\n");
            scanf("%d", &op);

            switch (op)
            {
            case 1:
                printf("Novo nome: ");
                scanf(" %[^\n]", nome[i]);
                printf("Nome atualizado com sucesso!\n");
                break;
            case 2:
                printf("Novo código: ");
                scanf("%d", &codigo[i]);
                printf("Código atualizado com sucesso!\n");
                break;
            case 3:
                printf("Novo preço: ");
                scanf("%f", &preco[i]);
                printf("Preço atualizado com sucesso!\n");
                break;
            case 4:
                printf("Nova quantidade: ");
                scanf("%d", quantidade[i]);
                printf("Quantidade atualizada com sucesso!\n");
                break;
            default:
                printf("Opção invalida.\n");
            }
        }
        break;
    }
    
}

