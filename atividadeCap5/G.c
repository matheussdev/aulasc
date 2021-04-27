#include <stdio.h>
#include <math.h>
int main(void){
    // define variáveis dos valores

    int i, base, potencia; //variável de controle do loop e variavel de operação

    //resultados das potencias de base 3 elevada a expoentes de 0 a 15
    base=3;
    for ( i = 0; i <= 15; i++)
    {   

        potencia = pow(base,i);

        printf("\n%d^%d = %d\n", base, i, potencia);
   
    }
        

};
