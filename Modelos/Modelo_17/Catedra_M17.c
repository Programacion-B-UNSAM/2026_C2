#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "header.h"

/* =========================================================
    EJERCICIO 1
========================================================= */

NodoGrilla *CATEDRA_CrearGrilla()
{
    char matriz[6][7] = {
        {'Q', '3', 'M', 'A', 'X', '7', 'J'},
        {'2', 'T', 'F', '0', 'Z', 'K', 'P'},
        {'V', '4', '5', 'Y', 'H', '1', 'S'},
        {'6', 'D', 'L', '8', 'B', 'W', 'E'},
        {'I', '9', 'R', 'C', 'U', 'N', 'G'},
        {'O', '!', '@', '#', '$', '%', '&'}};

    NodoGrilla *
        nodos[6][7];

    /* Crear nodos */
    for (int i = 0; i < 6; i++)
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

    /* Conectar nodos */
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (i > 0)
                nodos[i][j]->up = nodos[i - 1][j];

            if (i < 5)
                nodos[i][j]->down = nodos[i + 1][j];

            if (j > 0)
                nodos[i][j]->left = nodos[i][j - 1];

            if (j < 6)
                nodos[i][j]->right = nodos[i][j + 1];
        }
    }

    return nodos[0][0];
}

NodoGrilla *CATEDRA_InfoRandom(NodoGrilla *primerNodo,
                               NodoGrilla ***vec,
                               int *size,
                               int *distancia)
{
    const int rows = 6;
    const int columns = 7;

    NodoGrilla *aux = NULL;

    static int initialized = 0;

    if (!initialized)
    {
        srand((unsigned)time(NULL));
        initialized = 1;
    }

    // ============================================
    // Random distance between 1 and 10
    // ============================================

    *distancia = (rand() % 10) + 1;

    // ============================================
    // Random vector size between 4 and 8
    // ============================================

    *size = (rand() % 7) + 4;

    // Allocate vector
    *vec = malloc((*size) * sizeof(NodoGrilla *));

    if (*vec == NULL)
        return NULL;

    // ============================================
    // Select random node to return
    // ============================================

    int fila = rand() % rows;
    int columna = rand() % columns;

    aux = primerNodo;

    for (int i = 0; i < fila; i++)
        aux = aux->down;

    for (int j = 0; j < columna; j++)
        aux = aux->right;

    // Avoid forbidden node
    if (aux->dato == 'X')
    {
        if (aux->up != NULL)
            aux = aux->up;
        else if (aux->left != NULL)
            aux = aux->left;
    }

    NodoGrilla *randomNode = aux;

    // ============================================
    // Fill vector with unique random nodes
    // ============================================

    int count = 0;

    while (count < *size)
    {
        fila = rand() % rows;
        columna = rand() % columns;

        aux = primerNodo;

        for (int i = 0; i < fila; i++)
            aux = aux->down;

        for (int j = 0; j < columna; j++)
            aux = aux->right;

        // Avoid forbidden node
        if (aux->dato == 'X')
        {
            if (aux->up != NULL)
                aux = aux->up;
            else if (aux->left != NULL)
                aux = aux->left;
        }

        // Check if already selected
        int repeated = 0;

        for (int i = 0; i < count; i++)
        {
            if ((*vec)[i] == aux)
            {
                repeated = 1;
                break;
            }
        }

        if (!repeated)
        {
            (*vec)[count] = aux;
            count++;
        }
    }

    return randomNode;
}

/* =========================================================
    EJERCICIO 2
========================================================= */

Node *CATEDRA_CrearLista(void)
{
    const int MAX_NODES = 15;

    Node *head = NULL;
    Node *newNode;
    Node *last = NULL;

    int cantidad;

    static int initialized = 0;

    if (!initialized)
    {
        srand((unsigned)time(NULL));
        initialized = 1;
    }

    // Random amount of nodes: 5 to 30
    cantidad = (rand() % MAX_NODES) + 5;

    for (int i = 0; i < cantidad; i++)
    {
        newNode = malloc(sizeof(Node));

        if (newNode == NULL)
            return NULL;

        newNode->dato = (uint8_t)(rand() % 256);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            last->next = newNode;
        }

        last = newNode;
    }

    // Make list circular
    last->next = head;

    return head;
}
