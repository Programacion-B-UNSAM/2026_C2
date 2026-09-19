/*
    Se quiere leer un archivo con n numeros para luego guardarlos en un vector, este debe modificar su tamaño en cada lectura.
    Imprima el tamaño final de la lista.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/* 
Opcion 1: 
1- Leer el archivo unicamente para saber la cantidad de elementos (size)
2- Crear un vector de tamaño size
3- Volver a leer la lista y guardar los datos en el vector
*/
int main() {
    FILE* file;
    int size = 0, temp;

    file = fopen("lista.bin", "rb+");
    if (file == NULL) {
        perror("Error al abrir el archivo");
    }

    while (fread(&temp, sizeof(int), 1, file)) {
        size++;
    }
    rewind(file);

    int* list = malloc(sizeof(int) * size);
    if (list == NULL) {
        perror("Error de asignación de memoria");
        return 1;
    }

    size = 0;
    while (fread(&list[size], sizeof(int), 1, file)) {
        size++;
    }

    printf("\nTamaño de la lista: %d ", size);

    free(list);
    fclose(file);

    return 0;
}

/* 
Opcion 2: 
1- Crear un vector de tamaño 1
2- Leer el archivo y en cada lectura
    1- Guardar en el vector el dato leido
    2- Agrandar el tamaño del vector
*/
int main2() {
    FILE* file;
    int size = 0, temp;

    file = fopen("lista.bin", "rb+");
    if (file == NULL) {
        perror("Error al abrir el archivo");
    }

    int* list = malloc(sizeof(int));
    if (list == NULL) {
        perror("Error de asignación de memoria");
        return 1;
    }

    while (fread(&list[size], sizeof(int), 1, file)) {
        size++;
        list = (int*)realloc(list, sizeof(int) * (size + 1));
        if (list == NULL) {
            perror("Error de asignación de memoria");
            return 1;
        }
    }

    printf("\nTamaño de la lista: %d ", size);

    free(list);
    fclose(file);

    return 0;
}
