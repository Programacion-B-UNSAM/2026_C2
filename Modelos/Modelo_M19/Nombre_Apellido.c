#include <stdio.h>
#include <stdlib.h>
#include "Catedra_M19.c"
#include "definiciones.h"
#include "funciones.c"

#define EJ1
#define EJ2

int main(void) {
#ifdef EJ1
    printf("\n ==== EJERCICIO 1 ==== \n");
    NodoGrilla* primerNodo = CATEDRA_CrearGrilla();

    /* Imprimir grilla original */

    /* Ordenar grilla */

    /* Imprimir grilla ordenada */

#endif

#ifdef EJ2
    printf("\n ==== EJERCICIO 2 ==== \n");
    int numerosParaInsertar[] = {2, 4, 5, 6, 7, 8, 1, 3, 5, 4, 6, 8, 7, 9, 2};

    NodoArbol* raiz = NULL;
    /* Insertar numeros del vector de forma ordenada */

#endif

    return 0;
}
