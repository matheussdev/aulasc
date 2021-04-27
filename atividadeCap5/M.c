#include <stdio.h>
int main(void){
    // define variáveis dos valores
    int i,pos; //variável de controle do loop e variavel de operação
    double resultado, valores[10], media;

    /*
        calcular os fatoriais de 10 numeros e fazer o somatório de todos eles
    */

    for (i=0;i<10;i++)//ler os valores
    {
        pos=i+1;
        printf("\ndigite o valor %d:", pos);
        scanf("%lf", &valores[i]);
    }

    printf("\n----------------------------\n");

    printf("\nsoma de todos os valores é:\n");

    // calcular a somatorio de cada valor
    resultado = valores[0];
    printf("%f", valores[0]);
    for ( i = 1; i <10; i++)
    {
        double valor=valores[i];
        resultado= valor + resultado;
        printf(" + %f", valor);
        
        
    }
    printf(" = %f", resultado);  


    printf("\n----------------------------\n");
    
    media= resultado/10;
    printf("média = %f", media);
    
    printf("\n----------------------------\n");

    
};
