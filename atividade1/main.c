#include <stdio.h>

int main(){
    // define variáveis dos valores

    int A, B, C, D, E;

    //ler valores
    printf("digite o 1* número:");
    scanf("%d", &A);
    printf("digite o 2* número:");
    scanf("%d", &B);
    printf("digite o 3* número:");
    scanf("%d", &C);
    printf("digite o 4* número:");
    scanf("%d", &D);
    printf("digite o 5* número:");
    scanf("%d", &E);

    //define variáveis de maior e menor 
    int maior, menor;

    //maior
    if(A>B && A>C && A>D && A>E){ //se A for maior
        maior=A;
    };
    if(B>A && B>C && B>D && B>E){ //se B for maior
        maior=B;
    };
    if(C>B && C>A && C>D && C>E){ //se C for maior
        maior=C;
    };
    if(D>B && D>C && D>A && D>E){ //se D for maior
        maior=D;
    };
    if(E>B && E>C && E>D && E>A){ //se E for maior
        maior=E;
    };  
    
    //menor
    if(A<B && A<C && A<D && A<E){ //se A for maior
        menor=A;
    };
    if(B<A && B<C && B<D && B<E){ //se B for maior
        menor=B;
    };
    if(C<B && C<A && C<D && C<E){ //se C for maior
        menor=C;
    };
    if(D<B && D<C && D<A && D<E){ //se D for maior
        menor=D;
    };
    if(E<B && E<C && E<D && E<A){ //se E for maior
        menor=E;
    };  

    printf("\n\n O MAIOR É: %d \n O MENOR É: %d \n\n", maior, menor);

};
