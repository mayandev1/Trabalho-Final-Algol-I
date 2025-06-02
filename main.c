#include <stdio.h>

int main() {
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Buscar\n");
        printf("4 - Excluir\n");
        printf("5 - Alterar\n");
        printf("6 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Opcao: Cadastrar\n");
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
    } while(opcao != 6);

    return 0;
}
