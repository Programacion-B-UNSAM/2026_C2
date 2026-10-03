#ifndef CATEDRA_H
#define CATEDRA_H

#include "header.h"
#include "stdint.h"

/* =========================================================
    ESTRUCTURAS
========================================================= */

typedef struct NodoGrilla
{
    char dato;
    struct NodoGrilla *up;
    struct NodoGrilla *down;
    struct NodoGrilla *left;
    struct NodoGrilla *right;
} NodoGrilla;

typedef struct
{
    int fila;
    int columna;
} Posicion;

typedef struct Node{
    uint8_t dato;
    struct Node *next;
} Node;

#endif // CATEDRA_H