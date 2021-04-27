#include <stdio.h>
int main(void){
    // define variáveis dos valores

    int i, atual, anterior; //variável de controle do loop e variavel de operação

    // escrever sequencia fribonacci até 15º termo
    printf("\n1º termo = 0\n2º termo = 1");
    atual=1;
    anterior=0;
    i=3;
    while (i<=15)
    {
        atual=atual+anterior;
        anterior=atual-anterior;
        printf("\n%dº termo = %d",i, atual);
        i++;
    }
    
};
