#include <stdio.h>
int main(void){
    // define variáveis dos valores

    int i, C, F; //variável de controle do loop e variavel de operação

    //formula (°C x 9/5) + 32 = °F

   /* valores de conversão de graus Celsius em
    graus Fahrenheit, de dez em dez graus. iniciando
    a contagem em dez graus Celsius e finalizando em
    cem graus Celsius.*/
    
    for ( i = 1; i <= 10 ; i++)
    {
        C=10*i;
        F=(C*9/5)+32;

        printf("\n%d°C = %d°F", C, F);
    }
    
    
};
