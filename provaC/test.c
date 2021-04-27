#include <stdio.h>
#include <stdlib.h>

int main()
{

    int menu = -1;
    int indice = 0;
    int capacidade = 10;
    int *temperaturas = NULL;
    int t;

    temperaturas = (int *)malloc(sizeof(int) * capacidade);

    while (menu != 0)
    {

        printf("1 - Inserir temperatura\n");
        printf("2 - Listar temperaturas\n");
        printf("3 - Estado do array\n");
        printf("0 - Sair do programa\n");
        scanf("%d", &menu);

        switch (menu)
        {
        case 0:
            break;
        case 1:

            printf("Introduza a temperatura: ");
            scanf("%d", &t);
            temperaturas[indice] = t;
            indice++;
            if (indice >= capacidade)
            {
                capacidade += 10;
                temperaturas = (int *)realloc(temperaturas, sizeof(int) * capacidade);
            }
            break;
        case 2:
            for (int i = 0; i < indice; i++)
            {
                printf("Temperatura no dia %d = %d\n", i, temperaturas[i]);
            }
            break;
        case 3:
            printf("Elementos introduzidos: %d\n", indice);
            printf("Capacidade do array: %d\n", capacidade);
            break;
        default:
            printf("Opção inválida!");
            break;
        }
    }

    free(temperaturas);

    return 0;
}