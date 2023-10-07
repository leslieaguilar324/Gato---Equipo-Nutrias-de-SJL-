#include <stdio.h>
#include <stdlib.h>

void agregarCalificaciones(float calificaciones[][8]);
void mostrarCalificaciones(float calificaciones[][8], char nombre[20]);
float promedioSemestre(int semestre, float calificaciones[][8]);
float promedioTotal(float calificaciones[][8]);
void modificarCalificacion(int semestre, int materia, float calificaciones[][8]);

int main()
{
    char nombre[20];
    float calificaciones[3][8];

    printf("Ingresar nombre del estudiante\n");
    scanf("%s", nombre);
    agregarCalificaciones(calificaciones);

    int opcion = 0;
    int semestre;
    int materia;
    float promedio;
    float promedioTotalValue;
    do
    {
        opcion = mostrarMenu();

        switch (opcion) {
            case 1:
                mostrarCalificaciones(calificaciones, nombre);
                break;
            case 2:
                printf("De que semestre desea modificar calificacion");
                scanf("%d", &semestre);
                printf("De que materia desea modificar calificacion");
                scanf("%d", &materia);
                modificarCalificacion(semestre, materia, calificaciones);
                break;
            case 3:
                printf("De que semestre desea obtener promedio calificacion 1-3 \n");
                scanf("%d", &semestre);
                promedio = promedioSemestre(semestre, calificaciones);
                printf("El promedio del semestre %d es %f\n", semestre, promedio);
                break;
            case 4:
                promedioTotalValue = promedioTotal(calificaciones);
                printf("El promedio TOTAL es %.2f\n", promedioTotalValue);
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida. Intente de nuevo.\n");
                break;
        }

    } while (opcion != 5);

    return 0;
}

int mostrarMenu() {
    int opcion;
    printf("\nMENU\n");
    printf("1. Mostrar calificacion de estudiante\n");
    printf("2. Modificar calificacion\n");
    printf("3. Promedio por semestre\n");
    printf("4. Promedio total\n");
    printf("5. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

void agregarCalificaciones(float calificaciones[][8]) {
    for (int i = 0; i < 3 ; i ++ ) {
        for (int a = 0; a < 8 ; a ++) {
            printf("Ingresar calificacion %d de semestre %d: ", a+1, i+1);
            scanf("%f", &calificaciones[i][a]);
        }
    }
}

void mostrarCalificaciones(float calificaciones[][8], char nombre[20]) {
    printf("Calificaciones de: %s\n", nombre);
    for (int i = 0; i < 3 ; i ++ ) {
        for (int a = 0; a < 8 ; a ++) {
            printf("Calificacion %f de semestre %.2f: %.2f\n", a+1, i+1, calificaciones[i][a]);

        }
    }
}

float promedioSemestre(int semestre, float calificaciones[][8]) {
    semestre = semestre - 1;
    float promedio;
    float suma;
    for (int i = 0; i < 8; i++ ) {
        printf("Calificaciones en [%d][%d] son : %.2f \n", semestre, i, calificaciones[semestre][i]);
        suma += calificaciones[semestre][i];
    }
    promedio = suma / 8;
    return promedio;
}

float promedioTotal(float calificaciones[][8]){
    float promedio;
    float suma;
    for (int i = 0; i < 3 ; i ++ ) {
        for (int a = 0; a < 8 ; a ++) {
            suma += calificaciones[i][a];
        }
    }
    return suma / 24;
}

void modificarCalificacion(int semestre, int materia, float calificaciones[][8]) {
    float calificacion;
    printf("Que calificacion deseas poner en la materia %d del semestre %d \n", materia, semestre);
    scanf("%f", &calificacion);
    semestre = semestre - 1;
    calificaciones[semestre][materia] = calificacion;
    printf("La calificacion cambiada de la materia %d del semestre %d es : %.2f", materia, semestre + 1, calificaciones[semestre][materia]);

}

