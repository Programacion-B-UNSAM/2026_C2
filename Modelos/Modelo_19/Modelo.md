# Parcial (M19) - Programacion en C - 2026C2

# Consideraciones 

- Las resoluciones deben ser genéricas
- No deben usar ni modificar nada del archivo Catedra_M18.c
- Un punto del exámen queda asociado a:

    - Utilización del formato provisto de la catedra
    - Claridad y orden de su código
    - Presentación clara y concisa de resultados
    - Utilización correcta de los recursos
    
- Recuerde liberar toda la memoria utilizada al finalizar el programa


## Ejercicio 1

La función CATEDRA_CrearGrilla devuelve la dirección de memoria de el primer nodo de una grilla (el de arriba a la izquierda), cada nodo de la grilla cumple la siguiente estructura.

```c
typedef struct NodoGrilla {
    int dato;
    int nextDato;
    struct NodoGrilla* up;
    struct NodoGrilla* down;
    struct NodoGrilla* left;
    struct NodoGrilla* right;
} NodoGrilla;
```

*Consigna:*
Escriba una función que 
- Recorra la grilla de arriba hacia abajo y compare los valores de un nodo y el inferior. 
- En caso de que el nodo de arriba sea mayor que el de abajo, modifique intercambie los valores de ambos, pero coloque el dato intercambiado en 'nextDato'.
- Vuelva a recorrer la grilla reeplazando en cada nodo 'dato' con 'nextDato'.

Por ejemplo, para estos dos nodos con A siendo el nodo de arriba de B:
```c
original:
A.dato = 8    A.nextDato=NULL
B.dato = 2    B.nextDato=NULL

paso 1:
A.dato = 8    A.nextDato=2
B.dato = 2    B.nextDato=8

paso 2:
A.dato = 2    A.nextDato=2
B.dato = 8    B.nextDato=8
```

Ejecute la funcion hasta que la grilla quede completamente ordenada.

Por ejemplo, para la siguiente grilla:

```c
8 6 4 2
1 7 3 4
5 9 6 1 
```

La grilla deberia quedar asi:

```c
1 6 3 1
5 7 4 2
8 9 6 4 
```

* * *

## Ejercicio 2

*Consigna:*
Escriba una función que inserte de forma ordenada los numeros del vector en el arbol, si el numero no existe en el arbol todavia la cantidad inicial es 1, en caso de ya existir, se debe aumentar la cantidad.
Cada nodo del arbol debe seguir la siguente escructura

```c
typedef struct NodoArbol {
    int dato;
    int cantidad;
    struct NodoArbol* der;
    struct NodoArbol* izq;
} NodoArbol;
```
