#ifndef CATEDRA_H
#define CATEDRA_H


typedef struct NodoGrilla {
    char dato;
    struct NodoGrilla* up;
    struct NodoGrilla* down;
    struct NodoGrilla* left;
    struct NodoGrilla* right;
} NodoGrilla;

typedef struct {
    int fila;
    int columna;
} Posicion;


typedef struct {
    int esNro; // 1 si es int, 0 si es char
    union {
        int numero;
        char caracter;
    } dato;
} customElement;

typedef struct NodoDoble {
    int numero;
    struct NodoDoble* prev;
    struct NodoDoble* next;
} NodoDoble;


#endif // CATEDRA_H