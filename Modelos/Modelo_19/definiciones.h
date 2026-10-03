#ifndef _DEF_H
#define _DEF_H

typedef struct NodoGrilla
{
    int dato;
    int nextDato;
    struct NodoGrilla *up;
    struct NodoGrilla *down;
    struct NodoGrilla *left;
    struct NodoGrilla *right;
} NodoGrilla;

typedef struct NodoArbol
{
    int dato;
    int cantidad;
    struct NodoArbol *der;
    struct NodoArbol *izq;
} NodoArbol;

#endif
