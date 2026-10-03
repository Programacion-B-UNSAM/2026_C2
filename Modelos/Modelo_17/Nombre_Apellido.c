
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "Catedra_M17.c"

#define EJ1
#define EJ2

int main()
{

#ifdef EJ1
    printf("--- EJERCICIO 1 ---\n\n");
    NodoGrilla *primerNodo = CATEDRA_CrearGrilla();
    /* Imprimir Grilla */

    /* Info Item B  */
    NodoGrilla **targets;
    int size, distancia;
    NodoGrilla *start = CATEDRA_InfoRandom(primerNodo, &targets, &size, &distancia);

    /* Imprimir start, targets y distancia */

    /* Imprimir los caminos que cumplan */

#endif // EJ1

#ifdef EJ2
    printf("--- EJERCICIO 2 ---\n\n");
    int tamanio = 0;
    Node *first = CATEDRA_CrearLista();

    /* Item a --> Lista original */

    /* item b --> Lista original "marcada" */

    /* Item c --> Funcion */

    /* item d --> Lista final y vector*/

#endif // EJ2
    return 0;
}