#include <stdio.h>

int main(){
    // define variáveis dos valores

    int i, limite, resultado; //variável de controle do loop e variavel de operação


    //Apresenta os valores de numeros impares até um certo limite
    printf("\ndigite o até que numero você quer conferir os números primos:");
    scanf("%d", &limite);
    printf("\nEsses são os numeros ímpares de 0 a %d: \n\n", limite);
    for ( i = 0; i < limite; i++)
    {   


         if (i%2==0)
        {   
            i++;
            printf("\n%d = ", i);

            resultado=1;
            printf("1");
            for (int f = 2; f <= i; f++)
            {
                resultado= f*resultado;
                printf(" x %d", f);
            }
            printf(" O fatorial é : %d\n", resultado);
        }
        
    }
        

};
