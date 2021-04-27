#include <stdio.h>
int main(void){
    // define variáveis dos valores

    int i, base, expoente; //variável de controle do loop e variavel de operação
    double resultado;
    //resultados das potencias de base qualquer elevada a expoentes qualquer
    printf("\n----------------------\n");
    printf("digite a Base:");
    scanf("%d", &base);
    printf("\ndigite o Expoente:");
    scanf("%d", &expoente);
    resultado=1;

    if (expoente==0)
    {
        resultado=1;
    }else
    {
        for ( i = 1; i <= expoente; i++)
        {   
            resultado=base*resultado;
        }
    }
    
    printf("\n\n%d^%d = %lf", base, expoente, resultado);
    printf("\n\n----------------------\n");
};
