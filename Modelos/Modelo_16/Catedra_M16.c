#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

NodoGrilla *CATEDRA_CrearGrilla()
{
    char matriz[5][7] = {
        {'Q', '3', 'M', 'A', 'X', '7', 'J'},
        {'2', 'T', 'F', '0', 'Z', 'K', 'P'},
        {'V', 'B', '5', 'Y', 'H', '1', 'S'},
        {'6', 'D', 'L', '8', 'O', 'W', 'E'},
        {'I', '4', 'R', 'C', 'U', 'N', 'G'}};

    NodoGrilla *nodos[5][7];

    // Instanciar nodos en memoria
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            nodos[i][j] = (NodoGrilla *)malloc(sizeof(NodoGrilla));
            nodos[i][j]->dato = matriz[i][j];
            nodos[i][j]->up = NULL;
            nodos[i][j]->down = NULL;
            nodos[i][j]->left = NULL;
            nodos[i][j]->right = NULL;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (i > 0)
                nodos[i][j]->up = nodos[i - 1][j];
            if (i < 4)
                nodos[i][j]->down = nodos[i + 1][j];
            if (j > 0)
                nodos[i][j]->left = nodos[i][j - 1];
            if (j < 6)
                nodos[i][j]->right = nodos[i][j + 1];
        }
    }

    return nodos[0][0];
}

NodoGrilla *CATEDRA_NodoRandom(NodoGrilla *first)
{
    srand(time(NULL));

    int fila = rand() % 5;
    int columna = rand() % 7;

    NodoGrilla *actual = first;

    for (int i = 0; i < fila; i++)
    {
        actual = actual->down;
    }

    for (int j = 0; j < columna; j++)
    {
        actual = actual->right;
    }

    return actual;
}

customElement *CATEDRA_CrearVector(int *tamanio)
{
    *tamanio = 24;
    customElement *vec = (customElement *)malloc(sizeof(customElement) * (*tamanio));

    if (vec == NULL)
        return NULL;

    // Randomly initialize the remaining 16 elements (8-23)
    for (int i = 0; i < *tamanio; i++)
    {
        // Randomly choose 0 (char) or 1 (number)
        vec[i].esNro = rand() % 2;

        if (vec[i].esNro == 0)
        {
            // Random uppercase letter (ASCII 65-90)
            vec[i].dato.caracter = 'A' + (rand() % 26);
        }
        else
        {
            // Random number between 0 and 99
            vec[i].dato.numero = rand() % 100;
        }
    }

    return vec;
}
