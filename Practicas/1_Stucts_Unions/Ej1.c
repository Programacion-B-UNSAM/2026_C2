/*
1. Piense una estructura para guardar el nombre y la nota de un alumno
 
2. Haga funciones para:
    - Imprimir ambos datos
    - En caso de tener nota menor a 4 pida al usuario una nota de recuperatorio y devuelva Nombre y Nota recu

3. Cambie el 4 por NOTA_APROBACION (Macro)
*/

#include <stdint.h>
#include <stdio.h>

#define NOTA_APROBACION 4

typedef struct {
    char nombre[20];
    short nota;
} alumno_t;

void printData(alumno_t);

alumno_t checkRecu(alumno_t);

int main() {
    alumno_t alumno1 = {
        .nombre = "Juan",
        .nota = 6,
    };

    printData(alumno1);

    alumno1 = checkRecu(alumno1);

    printData(alumno1);
    printf("\n");
}

void printData(alumno_t alumno) {
    printf("\n");
    printf("Nombre: %s \t", alumno.nombre);
    printf("Nota: %d", alumno.nota);
}

alumno_t checkRecu(alumno_t alumno) {
    if (alumno.nota < NOTA_APROBACION) {
        printf("\n\n");
        printf("%s tiene que recuperar \n", alumno.nombre);

        printf("Ingrese la nota del recuperatorio: ");
        scanf("%hd", &alumno.nota);
    }
    return alumno;
}
