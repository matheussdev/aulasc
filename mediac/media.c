#include <stdio.h>

int main()
{
    int somatorio = 0;
    for (int i = 1; i <= 1000; i++)
    {
        somatorio = somatorio + i;
    }

    float media = somatorio/1000;
    printf("\n%.1f", media);
}