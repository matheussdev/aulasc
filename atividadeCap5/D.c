#include <stdio.h>

int main(){
    // define variáveis dos valores

    int i, resultado; //variável de controle do loop e variavel de operação
    resultado=0;
    //operar valores soma numeros pares de 1 a 500 (2+4+6...+500)

    for ( i = 1; i <= 500; i++)
    {   
        if (i%2==0)
        {   
            printf("%d + ", i);
            resultado = resultado + i;
        }
        
    }
    
    printf("\n o resultado da somas dos numeros pares entre 1 a 500 é: \n %d \n\n", resultado);
        

};
