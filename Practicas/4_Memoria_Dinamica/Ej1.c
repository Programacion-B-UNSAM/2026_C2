/*
    Se quiere crear un vector dinamico para guardar numeros enteros.
    El usuario debe ingresar el tamaño primero y luego completarlo con numeros.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 0;
    int* list;

    printf("Ingrese el tamaño del vector: ");
    scanf("%d", &size);

    // int vector[size]; // No se puede

    list = (int*)malloc(size * sizeof(int));
    if (list == NULL) {
        perror("Error de asignación de memoria");
        return 1;
    }

    printf("Ingrese el valor de los %d numeros:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }

    printf("Valores:\n");
    for (int i = 0; i < size; i++) {
        printf("%d  ", list[i]);
    }

    free(list);

    return 0;
}