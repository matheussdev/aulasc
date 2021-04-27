#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

typedef struct contato CONTATO;
struct contato
{
    char nome[40];
    char telefone[20];
};''
void header()
{
    printf("---------------\n");
    printf("AGENDA\n");
}
void add_new_contact()
{
    FILE *arquivo;
    CONTATO ctt;
    int resp;
    header();
    arquivo = fopen("agenda.txt", "ab");
    if (arquivo == NULL)
    {
        printf("Problema na abertura do arquivo");
    }
    else
    {
        do
        {
            fflush(stdin);
            printf("Digite o nome:");
            setbuf(stdin, NULL);
            gets(ctt.nome);

            fflush(stdin);
            printf("Digite o telefone:");
            setbuf(stdin, NULL);
            gets(ctt.telefone);

            fwrite(&ctt, sizeof(CONTATO), 1, arquivo);
            printf("Deseja continuar?\n");
            printf("0 - Sair\n");
            printf("1- Continuar \n");
            scanf("%d", &resp);

        } while (resp == 1);
        fclose(arquivo);
    }
}
void list_contacts()
{
    FILE *arquivo;
    CONTATO ctt;

    header();
    arquivo = fopen("agenda.txt", "rb");
    if (arquivo == NULL)
    {
        printf("\nProblema na abertura do arquivo\n");
    }
    else
    {
        while (fread(&ctt, sizeof(CONTATO), 1, arquivo) == 1)
        {
            printf("\nNome:%s", ctt.nome);
            printf("   Telefone:%s\n", ctt.telefone);
        }
    }
    fclose(arquivo);
}
void search()
{
    FILE *arquivo;
    CONTATO ctt;
    char nome[30];
    header();
    arquivo = fopen("agenda.txt", "rb");
    if (arquivo == NULL)
    {
        printf("Problema na abertura do arquivo!\n");
    }
    else
    {
        fflush(stdin);
        printf("Digite o nome que você quer pesquisar:\n");
        setbuf(stdin, NULL);
        gets(nome);

        while (fread(&ctt, sizeof(CONTATO), 1, arquivo) == 1)
        {
            if (strcmp(nome, ctt.nome) == 0)
            {
                printf("\nNome:%s", ctt.nome);
                printf("   Telefone:%s\n", ctt.telefone);
            }
        }
    }
    fclose(arquivo);
}
void delete ()
{
    FILE *arquivo;
    FILE *arqsaida;
    CONTATO ctt;
    char procurado[30];
    header();
    arquivo = fopen("agenda.txt", "rb");
    arqsaida = fopen("agenda_nova.txt", "w");

    if (arquivo == NULL || arqsaida == NULL)
    {
        printf("Problema na abertura do arquivo!\n");
        return;
    }
    else
    {
        fflush(stdin);
        printf("Digite o nome que você quer apagar:\n");
        setbuf(stdin, NULL);
        gets(procurado);

        while (!feof(arquivo))
        {
            fread(&ctt, sizeof(CONTATO), 1, arquivo);

            if (strcmp(procurado, ctt.nome) == 0)
            {
                printf("Contato encontrado %s!\n", ctt.nome);
                fwrite(NULL, sizeof(CONTATO), 1, arqsaida);
            }
            else
            {
                if (feof(arquivo))
                    break;
                fwrite(&ctt, sizeof(CONTATO), 1, arqsaida);
            }
        }
    }
    fclose(arquivo);
    fclose(arqsaida);
    //remove backup antigo / novo backup / agenda final
    remove("agenda_backup.txt");
    rename("agenda.txt", "agenda_backup.txt");
    rename("agenda_nova.txt", "agenda.txt");
}

int main()
{
    int opcao;

    do
    {
        header();
        printf("Escolha uma opção:\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar \n");
        printf("3 - Pesquisar \n");
        printf("4 - Excluir \n");
        printf("5 - Sair \n");
        printf("---------------\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            add_new_contact();
            break;
        case 2:
            list_contacts();
            break;
        case 3:
            search();
            break;
        case 4:
            delete ();
            break;
        default:
            printf("Opcao invalida!");
            break;
        }
    } while (opcao != 5);
    return 0;
}