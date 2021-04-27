#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



//este programa irá fazer sorteio de um numero aleatório
//para sorteio de uma rifa de acordo com o  numero de participantes;
// e de acordo com o numero de sorteios

int sortear(int numeros, int sorteios){
    int i, sorteado;
    
    
    for (i=1; i<=sorteios; i++){
        sleep(0.5);
        printf("\nSorteando próximo número...\n\n");
        sleep(10);
        sorteado = rand() % numeros;
        printf("***********\n   %d\n***********\n\n", sorteado);
    }
    return(sorteado);
}

int main(int argc, char *argv[]) {
    int participantes, rodadas;
    printf("\nquantos numeros tem no sorteio?");
    scanf("%d", &participantes);
    printf("\nquantos numeros você quer sortear?");
    scanf("%d", &rodadas);

    if (rodadas>1)
    {
        printf("\nos numeros sorteados foram:\n");
        sortear(participantes, rodadas);
        printf("\nParabéns aos vencedores!\n");
    }else{
        printf("\no numero sorteado foi:\n");
        sortear(participantes, rodadas);
        printf("\nParabéns ao vencedor!\n");
    }
    


}