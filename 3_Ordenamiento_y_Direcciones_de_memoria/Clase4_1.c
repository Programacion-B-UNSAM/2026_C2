/*
Escribir una función en C que intercambie los valores de dos variables enteras utilizando punteros.

Defina una función que reciba dos punteros a enteros como parámetros.
La función debe intercambiar los valores de las dos variables a las que apuntan estos punteros.
*/
#include <stdio.h>

void Intercambio(int* x, int* y);

int main() {
    int x = 10, y = 20;

    printf("Antes del intercambio:  \t x = %d, y = %d\n", x, y);
    Intercambio(&x, &y);
    printf("Despues del intercambio:\t x = %d, y = %d\n", x, y);

    return 0;
}

void Intercambio(int* x, int* y) {
    /*               |  x |  y | aux */
    int aux = *x; /*  | 10 | 20 | 10  */
    *x = *y;      /*  | 20 | 20 | 10  */
    *y = aux;     /*  | 20 | 10 | 10  */
}