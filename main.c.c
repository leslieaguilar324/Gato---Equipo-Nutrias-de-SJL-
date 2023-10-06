#include <stdio.h>

void inicializar_matriz(char matriz[][3]);
void imprime_matriz(char matriz[][3]);
char verificar(char array[][3]);
void realizar_movimientos(char matriz[][3]);

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

char verificar(char array[][3])
{
    for (int i = 0; i < 3; i++)
    {
        // Horizontales
        if (array[i][0] == 'x' && array[i][1] == 'x' && array[i][2] == 'x')
        {
            return 'x';
        }
        else if (array[i][0] == 'o' && array[i][1] == 'o' && array[i][2] == 'o')
        {
            return 'o';
        }
        // Verticales
        else if (array[0][i] == 'x' && array[1][i] == 'x' && array[2][i] == 'x')
        {
            return 'x';
        }
        else if (array[0][i] == 'o' && array[1][i] == 'o' && array[2][i] == 'o')
        {
            return 'o';
        }
    }

    // Diagonales
    if (array[0][0] == 'x' && array[1][1] == 'x' && array[2][2] == 'x')
    {
        return 'x';
    }
    else if (array[0][2] == 'x' && array[1][1] == 'x' && array[2][0] == 'x')
    {
        return 'x';
    }
    else if (array[0][0] == 'o' && array[1][1] == 'o' && array[2][2] == 'o')
    {
        return 'o';
    }
    else if (array[0][2] == 'o' && array[1][1] == 'o' && array[2][0] == 'o')
    {
        return 'o';
    }

    for (int i = 0; i < 3; i++)
    {
        for (int a = 0; a < 3; a++)
        {
            if (array[i][a] == ' ')
                return 'c'; // Continuar jugando
        }
    }

    return 'e'; // Empate
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

            char resultado = verificar(matriz);
            if (resultado == 'x' || resultado == 'o')
            {
                imprime_matriz(matriz);
                printf("Jugador %d (%c) ha ganado\n", jugador, turno);
                break;
            }
            else if (resultado == 'e')
            {
                imprime_matriz(matriz);
                printf("Empate\n");
                break;
            }

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
