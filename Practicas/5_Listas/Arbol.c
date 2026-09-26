#include <stdio.h>
#include <stdlib.h>

#include "definitions_arbol.h"

int main() {
    Nodo* PrimerNodo = NULL;

    insOrdenado(&PrimerNodo, 10);
    insOrdenado(&PrimerNodo, 5);
    insOrdenado(&PrimerNodo, 15);
    insOrdenado(&PrimerNodo, 7);
    insOrdenado(&PrimerNodo, 20);
    insOrdenado(&PrimerNodo, 18);
    insOrdenado(&PrimerNodo, 23);

    return 0;
}

// Crea el nodo en memoria, separado de la lista
Nodo* createNodo(int nuevoDato) {
    Nodo* nuevoNodo = malloc(sizeof(Nodo));
    if (!nuevoNodo) {
        perror("Error en la creacion del nodo\n");
        exit(1);
    }

    nuevoNodo->dato = nuevoDato;
    nuevoNodo->der = NULL;
    nuevoNodo->izq = NULL;

    return nuevoNodo;
}

// Crea un nodo y lo inserta al principio de la lista
void insOrdenado(Nodo** PrimerNodo, int nuevoDato) {
    Nodo* nuevoNodo = createNodo(nuevoDato);

    if (*PrimerNodo == NULL) {
        *PrimerNodo = nuevoNodo;
        return;
    }

    Nodo* temp = *PrimerNodo;

    while (1) {
        if (temp->dato > nuevoNodo->dato) {
            if (temp->izq == NULL) {
                temp->izq = nuevoNodo;
                return;
            }
            temp = temp->izq;
        } else if (temp->dato < nuevoNodo->dato) {
            if (temp->der == NULL) {
                temp->der = nuevoNodo;
                return;
            }
            temp = temp->der;
        }
    }
}
