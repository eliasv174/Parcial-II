#include <stdio.h>

// Definición de la estructura Estudiante
struct Estudiante {
    int id;
    char nombre[50];
    char apellido[50];
    float notas[4];
};

int main() {
    int N;
    printf("Ingrese el numero de estudiantes: ");
    scanf("%d", &N);

    // Arreglo de estructuras Estudiante
    struct Estudiante estudiantes[N];

    // Solicitar al usuario ingresar los datos de cada estudiante
    for (int i = 0; i < N; i++) {
        printf("\nIngrese los datos del estudiante %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &estudiantes[i].id);
        printf("Nombre: ");
        scanf("%s", estudiantes[i].nombre);
        printf("Apellido: ");
        scanf("%s", estudiantes[i].apellido);
        printf("Nota 1: ");
        scanf("%f", &estudiantes[i].notas[0]);
        printf("Nota 2: ");
        scanf("%f", &estudiantes[i].notas[1]);
        printf("Nota 3: ");
        scanf("%f", &estudiantes[i].notas[2]);
        printf("Nota 4: ");
        scanf("%f", &estudiantes[i].notas[3]);
    }

    // Mostrar los resultados
    printf("\nResultados:\n");
    for (int i = 0; i < N; i++) {
        float suma = 0;
        for (int j = 0; j < 4; j++) {
            suma += estudiantes[i].notas[j];
        }
        float promedio = suma / 4;
        printf("\nEstudiante %d\n", i + 1);
        printf("ID: %d\n", estudiantes[i].id);
        printf("Nombre: %s %s\n", estudiantes[i].nombre, estudiantes[i].apellido);
        printf("Promedio: %.2f\n", promedio);
        if (promedio >= 60) {
            printf("Resultado: Aprobado\n");
        } else {
            printf("Resultado: Reprobado\n");
        }
    }

    return 0;
}
