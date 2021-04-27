#include <stdio.h>

int main(){
    // define variáveis dos valores

    int i, limite; //variável de controle do loop e variavel de operação


    //Apresenta os valores de numeros impares até um certo limite
    printf("\ndigite o até que numero você quer conferir os números primos:");
    scanf("%d", &limite);
    printf("\nEsses são os numeros ímpares de 0 a %d: \n\n", limite);
    for ( i = 0; i <= limite; i++)
    {   


        if (i==limite)
        {
            printf("\n");
        }
        
        else if (i%2==0)
        {   
            i++;
            printf("%d, ", i);
        }
        
    }
        

};
