#include <stdio.h>
int main(void){
    // define variáveis dos valores

    int i, base, expoente, quadro; //variável de controle do loop e variavel de operação
    double resultado_quadro, resultado_soma;
    //resultados das potencias de base qualquer elevada a expoentes qualquer
    printf("\n----------------------\n");
    base= 2;
    expoente=63;
    resultado_quadro=1;
    resultado_soma=1;
    printf("\nquadro 1 = 1\n");            
    {
        for ( i = 1; i <= expoente; i++)
        {   
            quadro = i+1;
            resultado_quadro=base*resultado_quadro;
            resultado_soma=resultado_quadro+resultado_soma;
            printf("\nquadro %d = %.0f\n",quadro, resultado_quadro);            
        }
    }
    
    printf("\n\nA quantidade de grãos em todo tabuleiro É:\n%.0f", resultado_soma);
    printf("\n\n----------------------\n");
};
