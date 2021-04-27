#include <stdio.h>

int main(){
    // define variáveis dos valores

    int i, resultado; //variável de controle do loop e variavel de operação
    resultado=0;
    //operar valores soma numeros de 1 a 100 (1+2+3...+100)

    for ( i = 1; i <= 100; i++)
    {   
        resultado = resultado + i;
    }
        printf("%d", resultado);
        

};
