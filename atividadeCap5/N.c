#include <stdio.h>



//fiquei com dúvida nessa questão






int main(void){
    // define variáveis dos valores
    int i,pos, cont; //variável de controle do loop e variavel de operação
    cont=1;
    double resultado, valores[cont], media;

    /*
    */

    cont=1;
    printf("\ndigite o valor %d:", pos);
    scanf("%lf", &valores[0]);
    if (valores[0]<0)
    {
        cont=0;
        i=1;
    }
    
    while(i==0)//ler os valores
    {
        pos=cont+1;
        printf("\ndigite o valor %d:", pos);
        scanf("%lf", &valores[cont]);
        if (valores[cont]<0)
        {
            i=1;
        }
        cont++; 
    }

    printf("\n----------------------------\n");

    printf("\ntem um total de %d valores\n", cont);

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
