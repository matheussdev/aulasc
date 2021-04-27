#include <stdio.h>
#include <stdlib.h>
struct ficha_de_contato
{
    char nome[20];
    char telefone[10];
};

struct ficha_de_contato *contatos; //cria o ponteiro para contatos
int contact_length = 0;
int capacity = 10;
int capacityL = 10;

FILE *abre_arquivo(char modo, char caminho[30])
{
    FILE *arquivo;
    switch (modo)
    {
    case 'g':
        arquivo = fopen(caminho, "wt");
        break;
    case 'l':
        arquivo = fopen(caminho, "rt");
        break;
    case 'a':
        arquivo = fopen(caminho, "a");
        break;
    }
    if (arquivo == NULL)
    { //Se houver algum erro, o ponteiro apontará para NULL
        printf("Nao foi possivel abrir o arquivo");
        exit(0);
    }
    return arquivo;
}

void init_contacts()
{
    FILE *arquivo;
    int i;
    int result;
    int position;
    arquivo = abre_arquivo('l', "agenda.txt");

    while (!feof(arquivo))
    {
        fscanf(arquivo, "%s %s\n", contatos[contact_length].nome, contatos[contact_length].telefone);
        contact_length++;
    }
    printf("lista de contatos\n");
    printf("================================\n");

    for(i=0; i<contact_length; i++){
         printf("Nome: %s  -  Telefone: %s\n", contatos[i].nome, contatos[i].telefone);
    }

    printf("\n");
    fclose(arquivo);
}

// cria um novo contato
void add_contact()
{

    FILE *arquivo;
    int i;
    int result;
    arquivo = abre_arquivo('a', "agenda.txt"); // Cria um arquivo texto para gravação

    printf("\n\n---------- Cadastro de contatos -----------\n\n\n");

    printf("Nome......: ");
    fflush(stdin);
    scanf("%s", contatos[contact_length].nome);

    printf("contatos (ex: 999999999)......: ");
    fflush(stdin);
    scanf("%s", contatos[contact_length].telefone);

    for (i = 0; i < contact_length; i++)
    {
        // A funcao 'fprintf' devolve o número de bytes gravados
        // ou EOF se houve erro na gravação
        fprintf(arquivo, "%s %s\n", contatos[i].nome, contatos[i].telefone);
    }
    contact_length++;

    fclose(arquivo);
    if (contact_length >= capacity)
    {
        capacity += 10;
        contatos = (struct ficha_de_contato *)realloc(contatos, sizeof(struct ficha_de_contato) * capacity);
    }
}

void contact_list()
{

    FILE *arquivo;
    char Linha[100];
    char *result;
    int i;
    char *listaDefault;
    //   system("cls");
    // Abre um arquivo TEXTO para LEITURA
    arquivo = abre_arquivo('l', "agenda.txt");
    i = 1;
    printf("lista de contatos\n");
    printf("================================\n");

    while (!feof(arquivo))
    {
        // Lê uma linha (inclusive com o '\n')
        result = fgets(Linha, 100, arquivo); // o 'fgets' lê até 99 caracteres ou até o '\n'
        if (result)                          // Se foi possível ler
            printf("%s", Linha);
        i++;
    }
    printf("\n");
    fclose(arquivo);
}

void sair()
{
    printf("Encerrando programa...\n");
}

int main()
{

    //aloca a memoria nescessaria para o array
    contatos = (struct ficha_de_contato *)malloc(sizeof(struct ficha_de_contato) * (capacity));
    int continuar = 1;
    init_contacts();
    do
    {
        printf("\n\tAPP MEUS contatos\n\n");
        printf("1. Adicionar contatos\n");
        printf("2. Listar contatos\n");
        printf("0. Sair\n");

        scanf("%d", &continuar);
        printf("\e[H\e[2J");
        switch (continuar)
        {
        case 1:
            add_contact();
            break;

        case 2:
            contact_list();
            break;
        case 0:
            sair();
            break;

        default:
            printf("Digite uma opcao válida\n");
        }
    } while (continuar);
    free(contatos);
}