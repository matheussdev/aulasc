#include <stdio.h>
#include <string.h>

/* -------- Definicao dos tipos a serem usados */
typedef struct tipo_endereco /* Tipo tEndereco: */
{                            /* Dados relativos ao endereco */
    int numero;
    char bairro[20];
    char cidade[30];
    char sigla_estado[4];
    long int CEP;
} tEndereco;

typedef struct ficha_pessoal /* Tipo tPessoal: */
{                            /* Dados da pessoa */
    char nome[50];           /* A ficha da pessoa sera */
    char telefone[20];       /* uma variavel do tipo tPessoal */
    tEndereco endereco;
} tPessoal;

typedef struct _lista /* Tipo tLista: */
{                     /* Armazena uma lista de fichas. */
    tPessoal *fichas; /* *Nao* e uma implementacao */
    int tamanho;      /* de uma lista encadeada */
} tLista;

/* ----------- Prototipos das funcoes */
tLista ad_reg(tLista);
void find(tLista);
void altera(tLista);
tLista le_arquivo(FILE *);
void salva(FILE *, tLista);
void le_reg(tPessoal *);
void le_str(char *s, int n, FILE *arq);
void imprime(tPessoal);

/* ----------------------------------------------------------
   Programa principal
   ---------------------------------------------------------- */

void main(void)
{
    char n_arq[30]; /* Nome do arquivo a ser manipulado */
    FILE *fonte;    /* Arquivo a ser manipulado */
    int opcao;      /* Opcao escolhida no Menu */
    tLista lista;   /* Lista de registros (ver definicao de tLista */
    char c;         /* Utilidade geral */

    printf("\n\n Gerenciador de dados: Versao 1.0");
    printf("\n --------------------------------");

    /* --> Le o nome da lista com a qual vai trabalhar */
    do
    {
        printf("\n\n Entre com o nome do arquivo de dados: ");
        gets(n_arq);
        fonte = fopen(n_arq, "r");
    } while (fonte == NULL);

    /* --> Le o arquivo e guarda na memoria */
    lista = le_arquivo(fonte);
    fclose(fonte);

    if (lista.fichas == NULL)
    {
        printf("\nErro! Nao e possivel ler e armazenar a lista!!");
        exit(0);
    }

    /* --> Comeca o loop principal */
    do
    {
        printf("\n\n 1 - Insere novo registro");
        printf("\n 2 - Procura registro gravado");
        printf("\n 3 - Altera registro");
        printf("\n 0 - Abandona a execucao");
        printf("\n\n Entre com sua opcao: ");
        scanf("%d%c", &opcao, &c); /* Le a opcao */
        switch (opcao)
        {
        case 1:
            lista = ad_reg(lista);
            break;
        case 2:
            find(lista);
            break;
        case 3:
            altera(lista);
            break;
        }
    } while (opcao != 0);

    /* --> Salva arquivo na saida */
    if ((fonte = fopen(n_arq, "w")) != NULL)
    {
        salva(fonte, lista);
        fclose(fonte);
    }
    else
        printf("\n\nERRO! Alteracoes nao foram salvas!!\n");
}

/* ---------------------------------------------------------
   Definicao das funcoes:
   --------------------------------------------------------- */

/* ---------------------------------------------------------
   Funcao ad_reg: Adiciona um registro a lista
   Para tanto, ela cria uma segunda lista com o novo registro
   no topo e os demais sao copiados nas posicoes seguintes.  */

tLista ad_reg(tLista lista)
{
    tPessoal ficha;
    tLista nova_lista;
    int i;

    /* Le o novo registro */
    printf("\n\n---------Inserir Registro:");
    le_reg(&ficha);

    /* Primeiro aloca a memoria necessaria para a nova lista... */
    nova_lista.tamanho = lista.tamanho + 1;
    if ((nova_lista.fichas = (tPessoal *)calloc(nova_lista.tamanho, sizeof(tPessoal))) == NULL)
    {
        printf("\n\nProblemas de memoria: Impossivel acrescentar o registro..\n");
        return lista;
    }

    /* Copia o novo registro... */
    memcpy(&(nova_lista.fichas[0]), &ficha, sizeof(tPessoal));

    /* Copia os registros antigos... */
    for (i = 1; i < nova_lista.tamanho; i++)
        memcpy(&(nova_lista.fichas[i]), &(lista.fichas[i - 1]), sizeof(tPessoal));

    /* Libera a memoria da primeira lista.. */
    free(lista.fichas);

    /* retorna a nova lista */
    return nova_lista;
}

/* -------------------------------------------------------
   Funcao find: Encontra uma expressao de procura na lista.
   A expressao sera comparada somente com o campo nome.   */

void find(tLista lista)
{
    int i, resp = -1;
    char exp[50], *s;

    /* Solicita a expressao de busca */
    printf("\n\nDigite a expressao de busca: ");
    gets(exp);
    if ((s = strchr(exp, '\n')) != NULL) /* retira o \n se houver */
        s[0] = '\0';

    /* Varre a lista procurando a primeira ocorrencia da expressao */
    for (i = 0; i < lista.tamanho; i++)
        if ((strstr(lista.fichas[i].nome, exp)) != NULL)
        {
            resp = i;
            break;
        }
    if (resp < 0)
        printf("\nExpressao nao encontrada.");
    else
    {
        printf("\nExpressao encontrada no registro %d", resp + 1);
        imprime(lista.fichas[resp]);
    }
}

/* --------------------------------------------------------
   Funcao altera: altera um registro baseado na sua posicao
   na lista. Para fazer a alteracao, a pessoa devera saber qual
   posicao do registro na lista (pode ser conseguida atraves da
   funcao find, acionada pela opcao 1 do menu).
   A funcao altera le o novo registro do teclado e o substitui
   na posicao desejada.                                       */

void altera(tLista lista)
{
    int n;
    char c;
    tPessoal aux;

    printf("\nDigite o numero do registro que deseja alterar: ");
    scanf("%d%c", &n, &c); /* Le o numero do registro e o lixo do buffer */

    /* Le o novo registro */
    printf("\nDigite o novo registro:\n");
    le_reg(&aux);

    /* Atualiza na lista */
    memcpy(&(lista.fichas[n - 1]), &aux, sizeof(tPessoal));
    printf("\nRegistro alterado.\n");
}

/* ---------------------------------------------------------
   Funcao le_arquivo: Recebe um apontador para o arquivo aberto
   e retorna uma lista montada a partir do arquivo              */

tLista le_arquivo(FILE *arq)
{
    tLista l;
    tPessoal ficha;
    int i;
    char c, *s;

    /* Le o tamanho do arquivo (qtos registros possui) */
    fscanf(arq, "%d", &(l.tamanho));

    /* Aloca a memoria necessaria para armazenar o arquivo
   em RAM e em seguida le registro por registro        */
    if ((l.fichas = (tPessoal *)calloc(l.tamanho, sizeof(tPessoal))) != NULL)
        for (i = 0; i < l.tamanho; i++)
        {
            /* Le cada ficha */
            c = getc(arq); /* Para o cursor mudar de linha no arquivo */
            le_str(ficha.nome, 50, arq);
            le_str(ficha.telefone, 20, arq);
            le_str(ficha.endereco.rua, 50, arq);
            fscanf(arq, "%d\n", &(ficha.endereco.numero));
            le_str(ficha.endereco.bairro, 20, arq);
            le_str(ficha.endereco.cidade, 30, arq);
            le_str(ficha.endereco.sigla_estado, 3, arq);
            fscanf(arq, "%d", &(ficha.endereco.CEP));
            while ((c = getc(arq)) != '$')
                ; /* Sincronismo! */
            memcpy(&(l.fichas[i]), &ficha, sizeof(tPessoal));
            if (feof(arq))
                i = l.tamanho;
        }

    /* retorna a lista criada */
    return l;
}

/* -----------------------------------------------------------
   Funcao salva: salva a lista l no arquivo arq, observando a
   sintaxe necessaria para o arquivo de leitura. Ao final,
   libera a memoria da lista                                  */

void salva(FILE *arq, tLista l)
{
    int i;
    fprintf(arq, "%d\n", l.tamanho);
    for (i = 0; i < l.tamanho; i++)
    {
        fprintf(arq, "%s\n", l.fichas[i].nome);
        fprintf(arq, "%s\n", l.fichas[i].telefone);
        fprintf(arq, "%s\n", l.fichas[i].endereco.rua);
        fprintf(arq, "%d\n", l.fichas[i].endereco.numero);
        fprintf(arq, "%s\n", l.fichas[i].endereco.bairro);
        fprintf(arq, "%s\n", l.fichas[i].endereco.cidade);
        fprintf(arq, "%s\n", l.fichas[i].endereco.sigla_estado);
        fprintf(arq, "%d\n", l.fichas[i].endereco.CEP);
        fprintf(arq, "$\n");
    }
    free(l.fichas);
}

/* -----------------------------------------------------------
   Funcao le_reg: le um registro via teclado                   */

void le_reg(tPessoal *reg)
{
    tPessoal ficha;
    char c;
    printf("\n\nNome: ");
    gets(ficha.nome);
    printf("Telefone: ");
    gets(ficha.telefone);
    printf("\nEndereco");
    printf("\nRua: ");
    gets(ficha.endereco.rua);
    printf("Numero: ");
    scanf("%d", &(ficha.endereco.numero));
    scanf("%c", &c); /* Para absorver o \n que fica no buffer */
    printf("Bairro: ");
    gets(ficha.endereco.bairro);
    printf("Cidade: ");
    gets(ficha.endereco.cidade);
    printf("Sigla do Estado: ");
    gets(ficha.endereco.sigla_estado);
    printf("CEP: ");
    scanf("%d", &(ficha.endereco.CEP));
    scanf("&c", &c);
    memcpy(reg, &ficha, sizeof(tPessoal));
}

/* ----------------------------------------------------------
   Funcao le_str: le uma string em um arquivo e faz as
   devidas correcoes.
   Se a string lida possuir um final de linha ('\n'), a funcao
   o localiza e o retira                                       */

void le_str(char *s, int n, FILE *arq)
{
    fgets(s, n, arq);
    if ((s = strchr(s, '\n')) != NULL)
        s[0] = '\0';
}

/* ----------------------------------------------------------
   Funcao imprime: Imprime Uma ficha na tela                   */

void imprime(tPessoal f)
{
    printf("\n%s\n", f.nome);
    printf("%s\n", f.telefone);
    printf("%s\n", f.endereco.rua);
    printf("%d\n", f.endereco.numero);
    printf("%s\n", f.endereco.bairro);
    printf("%s\n", f.endereco.cidade);
    printf("%s\n", f.endereco.sigla_estado);
    printf("%d\n\n", f.endereco.CEP);
}
