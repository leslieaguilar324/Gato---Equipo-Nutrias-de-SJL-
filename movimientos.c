#include <stdio.h>

void inicializar_matriz(char matriz[][3]);
void realizar_movimientos(char matriz[][3]);
void imprime_matriz(char matriz[][3]);

int main()
{
    char matriz[3][3];
    inicializar_matriz(matriz);
    realizar_movimientos(matriz);
    return 0;
}

void inicializar_matriz(char matriz[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int x = 0; x < 3; x++)
        {
            matriz[i][x] = ' ';
        }
    }
}

void imprime_matriz(char matriz[][3])
{
    printf("Tablero actual:\n");
    
    for (int i = 0; i < 3; i++)
    {
        for (int x = 0; x < 3; x++)
        {
            printf("| %c ", matriz[i][x]);
        }
        printf("|\n");
        printf("-------------\n"); 
    }
}

void realizar_movimientos(char matriz[][3])
{
    char turno = 'x';
    int fila;
    int columna;
    int jugador = 1;

    while (1)
    {
        imprime_matriz(matriz);
        printf("\n");
        printf("Es turno del Jugador %d (%c)\n", jugador, turno);
        printf("\n");
        printf("Introduce la fila y columna donde quieres colocar (ejemplo: 1 2): ");
        scanf("%d %d", &fila, &columna);

        if (fila >= 1 && fila <= 3 && columna >= 1 && columna <= 3 && matriz[fila - 1][columna - 1] == ' ')
        {
            matriz[fila - 1][columna - 1] = turno;

            if (jugador == 1)
            {
                jugador = 2;
            }
            else
            {
                jugador = 1;
            }

            if (turno == 'x')
            {
                turno = 'o';
            }
            else
            {
                turno = 'x';
            }
        }
        else
        {
            printf("\n");
            printf("Movimiento no valido. \n");
            printf("\n");
        }
    }
}
