#include <stdio.h>
#include <stdlib.h>

#include "definitions.h"

int main() {
    Nodo* PrimerNodo = NULL;

    insFirst(&PrimerNodo, 10);
    insFirst(&PrimerNodo, 20);
    insFirst(&PrimerNodo, 30);
    insFirst(&PrimerNodo, 40);
    insFirst(&PrimerNodo, 50);
    insFirst(&PrimerNodo, 60);
    insFirst(&PrimerNodo, 70);
    insFirst(&PrimerNodo, 80);

    printf("\nLista enlazada: \n\t");
    showFull(PrimerNodo);

    delLast(&PrimerNodo);
    printf("\nLista enlazada: \n\t");
    showFull(PrimerNodo);

    delLast(&PrimerNodo);
    printf("\nLista enlazada: \n\t");
    showFull(PrimerNodo);

    delLast(&PrimerNodo);
    printf("\nLista enlazada: \n\t");
    showFull(PrimerNodo);

    // freeList(&PrimerNodo);

    printf("\nLista enlazada: \n\t");
    showFull(PrimerNodo);

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
    nuevoNodo->next = NULL;

    return nuevoNodo;
}

// Crea un nodo y lo inserta al principio de la lista
void insFirst(Nodo** PrimerNodo, int nuevoDato) {
    Nodo* nuevoNodo = createNodo(nuevoDato);

    if (*PrimerNodo == NULL) {
        *PrimerNodo = nuevoNodo;
        return;
    }

    nuevoNodo->next = *PrimerNodo;
    *PrimerNodo = nuevoNodo;
}

// Muestra la lista completa
void showFull(Nodo* PrimerNodo) {
    Nodo* actual = PrimerNodo;

    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->next;
    }

    printf("NULL\n");
}

// Elimina y libera de la memoria el ultimo nodo de la lista
void delLast(Nodo** PrimerNodo) {
    if (*PrimerNodo == NULL) {
        perror("La lista esta vacia");
        return;
    }
    if ((*PrimerNodo)->next == NULL) {
        free(*PrimerNodo);
        *PrimerNodo = NULL;
        return;
    }

    Nodo* actual = *PrimerNodo;
    Nodo* prev = NULL;

    while (actual->next != NULL) {
        prev = actual;
        actual = actual->next;
    }
    prev->next = NULL;
    free(actual);
}

// Libera la lista de la memoria
void freeList(Nodo** PrimerNodo) {
    Nodo* current = *PrimerNodo;
    Nodo* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *PrimerNodo = NULL;
}
