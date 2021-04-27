#include <stdio.h>
int main(void){
    // define variáveis dos valores
    int i,pos, valores[15]; //variável de controle do loop e variavel de operação
    double resultado, fatoriais[15], fatorial_soma;

    /*
        calcular os fatoriais de 15 numeros e fazer o somatório de todos eles
    */

    for (i=0;i<15;i++)//ler os valores
    {
        pos=i+1;
        printf("\ndigite o valor %d:", pos);
        scanf("%d", &valores[i]);
    }

    printf("\n----------------------------\n");

    // calcular o fatorial de cada valor    
    for ( i = 0; i <15; i++)
    {
        int valor=valores[i];
        printf("\nO fatorial do valor %d é :\n", valor);
        //calculo de fatorial do valor isolado
        
        resultado=1;
        printf("1");
        for (int f = 2; f <= valor; f++)
        {
            resultado=f*resultado;
            printf(" x %d", f);
        }
        printf(" = %.0f\n", resultado);

        fatoriais[i]=resultado;
    }
    printf("\n----------------------------\n");
    printf("\nsoma de todos os fatoriais\n");

    printf("%.0f", fatoriais[0]);
    fatorial_soma = fatoriais[0];
    for (i = 1; i < 15; i++)
    {
        fatorial_soma=fatoriais[i]+fatorial_soma;
        printf(" + %.0f", fatoriais[i]);

    }
    printf("= %.0f", fatorial_soma);


    printf("\n----------------------------\n");
    
};
