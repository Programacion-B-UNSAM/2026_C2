#include <stdio.h>
#include <stdlib.h>

#include "definiciones.h"

NodoGrilla* CATEDRA_CrearGrilla(void) {
    int matriz[7][6] = {
        {8, 6, 4, 2, 9, 3}, {1, 7, 3, 4, 5, 8}, {5, 9, 6, 1, 2, 7}, {4, 2, 8, 6, 1, 5},
        {7, 3, 1, 9, 4, 2}, {6, 5, 7, 3, 8, 1}, {2, 4, 9, 5, 6, 3},
    };

    int rows = 7;
    int cols = 6;

    NodoGrilla* nodos[7][6];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            nodos[i][j] = (NodoGrilla*)malloc(sizeof(NodoGrilla));
            if (nodos[i][j] == NULL) {
                perror("Memory allocation failed!\n");
                exit(1);
            }
            nodos[i][j]->dato = matriz[i][j];
            nodos[i][j]->nextDato = 0;
            nodos[i][j]->up = NULL;
            nodos[i][j]->down = NULL;
            nodos[i][j]->left = NULL;
            nodos[i][j]->right = NULL;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i > 0) {
                nodos[i][j]->up = nodos[i - 1][j];
            }
            if (i < rows - 1) {
                nodos[i][j]->down = nodos[i + 1][j];
            }
            if (j > 0) {
                nodos[i][j]->left = nodos[i][j - 1];
            }
            if (j < cols - 1) {
                nodos[i][j]->right = nodos[i][j + 1];
            }
        }
    }

    return nodos[0][0];
}
