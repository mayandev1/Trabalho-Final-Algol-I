#include <stdio.h>
#include <stdio.h>
 #define MAX 100

    void cadastrarproduto(int codigo[],char nome[][50],float preco[],int quantidade){
        if(quantidade >= MAX){
            printf("EXCEDEU O LIMITE DE CADASTRO \n");
        }else{
            printf("digite o codigo do produto \n");
            scanf("%d",&codigo[quantidade]);
            printf("digite o nome do produto \n");
            scanf("%s", nome[quantidade]);
            printf("digite o preco do produto\n");
            scanf("%f",&preco[quantidade]);
            printf("produto cadastrado com sucesso!!!\n");
            printf("CODIGO: %d, NOME: %s, PRECO %.2f \n",codigo[quantidade],nome[quantidade],preco[quantidade]);
  
        }
    }
        void listarproduto(int codigo[], char nome[][50],float preco[],int quantidade){
            int i;
            if(quantidade==0){
                printf("NENHUM PRODUTO CADASTRAD \n");
            }else{
            for(i=0;i< quantidade;i++){
                printf("CODIGO: %d, NOME: %s, PRECO %.2f \n",codigo[i],nome[i],preco[i]);
            }
        }
        }

int excluirproduto(int codigo[],char nome[][50],float preco[],int quantidade){
    int cod,i,j,k,encontrado=0;

    printf("digite o codigo do produto \n");
    scanf("%d",&cod);

    for(i=0;i<quantidade;i++){
        if(cod== codigo[i]){
            encontrado=1;
            for(j=i;j<quantidade-1;j++){
                codigo[j]=codigo[j+1];
                preco[j]=preco[j+1];
                for(k=0;k<50;k++){
                    nome[j][k]=nome[j+1][k];
                }
            }
            printf("PRODUTO EXCLUIDO \n");
        quantidade= quantidade-1;
        break;
        }
        
        
    }
    if(encontrado==0){
    printf("PRODUTO NAO ENCONTRADO \n");
    }
    return quantidade;
}
    
  
    
int main() {
    int codigo[MAX],quantidade=0;
    float preco[MAX];
    char nome[MAX][50];
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
                cadastrarproduto(codigo,nome,preco,quantidade);
                quantidade++;
                
                break;
            case 2:
                printf("Opcao: Listar\n");
                listarproduto(codigo,nome,preco,quantidade);
                break;
            case 3:
                printf("Opcao: Buscar\n");
                break;
            case 4:
                printf("Opcao: Excluir\n");
                quantidade = excluirproduto(codigo,nome,preco,quantidade);
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
