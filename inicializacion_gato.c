#include <stdio.h>

void inicalizar_matriz(char matriz[][3]);


int main()
{
    char matriz [3][3];
    inicializar_matriz(matriz);
    return 0;
}

void inicializar_matriz(char matriz [][3])
{
    for (int i=0; i<3; i++)
    {
        for (int x =0; x<3; x++)
        {
            matriz[i] [x]= ' ';
        }
    }
}
