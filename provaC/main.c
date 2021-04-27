#include <stdio.h>
struct ficha_de_produto
{
    char nome[20];
    char codbarras[10];
    float custo;
    float preco;
};

struct ficha_de_produto produtos[10]; //cria o vetor para produtos
int products_lenght = 0;

// cria um novo produto
void add_product()
{
    printf("\n\n---------- Cadastro de produtos -----------\n\n\n");

    printf("Nome......: ");
    fflush(stdin);
    scanf("%s", produtos[products_lenght].nome);

    printf("código de barras (ex: AHG7162GH)......: ");
    fflush(stdin);
    scanf("%s", produtos[products_lenght].codbarras);

    printf("custo (ex: 10.5)......: ");
    fflush(stdin);
    scanf("%f", &produtos[products_lenght].custo);

    printf("preço (ex: 20)......: ");
    fflush(stdin);
    scanf("%f", &produtos[products_lenght].preco);

    products_lenght++;


}

void product_list()
{
    
    printf("\n---------- lista de produtos -----------\n\n");

    if(products_lenght==0){
        printf("Lista de produtos vazia!\n\n Digite 1 e adicione um produto...");
    }else{
        for(int i=0; i< products_lenght; i++ ){
            printf("\nProduto: %s", produtos[i].nome);
            printf("\nCusto: R$ %.2f", produtos[i].custo);
            printf("\nPreço: R$ %.2f", produtos[i].preco);
            printf("\nCódigo de barras: %s", produtos[i].codbarras);
             printf("\n=============================");
        }
    }
}

void sair()
{
    printf("Encerrando programa...\n");
}

int main()
{
    int continuar = 1;
    do
    {
        printf("\n\tAPP MEUS produtos\n\n");
        printf("1. Adicionar produtos\n");
        printf("2. Listar produtos\n");
        printf("0. Sair\n");

        scanf("%d", &continuar);
        printf("\e[H\e[2J");
        switch (continuar)
        {
        case 1:
            add_product();
            break;

        case 2:
            product_list();
            break;
        case 0:
            sair();
            break;

        default:
            printf("Digite uma opcao válida\n");
        }
    } while (continuar);
}