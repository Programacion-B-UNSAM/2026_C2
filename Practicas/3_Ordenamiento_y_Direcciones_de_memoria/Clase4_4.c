/*
Realizar una funcion que implemente un BubbleSort:

El Bubble Sort es un algoritmo de ordenamiento que funciona
-revisando cada elemento de la vector que va a ser ordenada con el siguiente,
-intercambiándolos de posición si están en el orden equivocado.
-repetir el proceso hasta que no se necesiten másintercambios

*/
#include <stdio.h>
#include <stdlib.h>

#include "vectores.h"

void mostrarVector(int* vector, int longitud);
void BubbleSort(int* vector, int longitud);
void Intercambio(int* x, int* y);

int main() {
    int size = sizeof(shortVector) / sizeof(shortVector[0]);

    printf("\nVector inicial: \n\t");
    mostrarVector(shortVector, size);

    BubbleSort(shortVector, size);

    printf("\nBubble Sort: \n\t");
    mostrarVector(shortVector, size);

    return 0;
}

void mostrarVector(int* vector, int longitud) {
    for (int i = 0; i < longitud; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void Intercambio(int* x, int* y) {
    /*               |  x |  y | aux */
    int aux = *x; /*  | 10 | 20 | 10  */
    *x = *y;      /*  | 20 | 20 | 10  */
    *y = aux;     /*  | 20 | 10 | 10  */
}

void BubbleSort(int* vector, int longitud) {
    int n = longitud - 1;
    while (n > 0) {
        for (int i = 0; i < n; i++) {
            if (vector[i] > vector[i + 1]) {
                Intercambio(&vector[i], &vector[i + 1]);
            }
        }
        n--;
    }
}
