#include <stdio.h>

void mostrar_tablero(char Gato[][3]);

int main (){

    char Gato[3][3]={
        ' ','x',' ',
        'o','x',' ',
        ' ',' ','o'
    };

    mostrar_tablero(Gato);

    return 0;
}

void mostrar_tablero(char Gato[][3])
{
    for (int i=0; i<=2;i++)
    {
        printf (" \n");
        for (int j=0; j<=2; j++)
        {
            if (j != 0) printf("|");
            printf (" %c ",Gato[i][j]);
        }
        if (i != 2) printf("\n-----------");
    }
}
