#include <stdio.h>

int main(){
    // define variáveis dos valores

    int i, divisor; //variável de controle do loop e variavel de operação

    //imprime todos os numeros de 0 a 200 que são divisíveis por 4
    divisor=4;
    for ( i = 1; i < 200; i++)
    {   


        if (i%divisor==0)
        {
            printf("\n%d/%d = 0 portanto %d é divisível por %d \n",i ,divisor ,i ,divisor);
        }
    
        
    }
        

};
