# Parcial (M17) - Programación en C - 2026 C1

## Consideraciones

- Las resoluciones deben ser genéricas
- No deben usar ni modificar nada del archivo Catedra_M17.c
- Un punto del exámen queda asociado a:
  - Utilización del formato provisto de la catedra
  - Claridad y orden de su código
  - Presentación clara y concisa de resultados
  - Utilización correcta de los recursos
- Recuerde liberar toda la memoria utilizada al finalizar el programa

## Ejercicio 1

La función CATEDRA_CrearGrilla devuelve la dirección de memoria de el primer nodo de una grilla (el de arriba a la izquierda)

```c
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
```

a) Imprima la grilla.

b) La funcion Catedra_InfoRandom() devuelve:

- La direccion de un nodo random de la grilla (`start`).
- Un vector que contiene la direccion de memoria de varios nodos de la grilla (`targets`)
- El tamaño de ese vector (`size`)
- Una distancia.

Resolución:

1. Imprima, `start`, el vector de nodos (`targets`) y la `distancia`
2. Escriba una función que tome como argumentos:
   a. La direccion de memoria de un nodo `start`
   b. Un vector de direcciones de memoria con otros nodos de la grilla (`targets`) y su tamaño  (`size`)
   c. Una `distancia`

  La función debe imprimir un unico camino desde  `start` a los `targets`, teniendo en cuenta que solo debe imprimirse el camino más corto entre `start` y `target` si el mismo tiene una longitud igual a `distancia`

**Obs.** Puede ser que ningun camino cumpla! En ese caso, imprimir un mensaje que lo indique

Ej:

```c
// Ejercicio 1
A B C D E F G
H I J R L M N
O P Q X S T U
V W A K Z 1 2 
3 4 5 6 7 8 9   

// Ejercicio 2
start = I
targets = [A, F, K, 9, 6]
dist = 5

Caminos que cumplen:
I > J > R > L > M > F
I > J > R v X v K v 6
```

PD: Flechitas para los prints = < > ^ ⌄

* * *

## Ejercicio 2

La función CATEDRA_CrearLista devuelve una lista circular simplemente enlazada cuyos nodos son como se los muestra a continuacion:

```c
typedef struct {
    uint8_t num;
    struct Node *next;
} Node;
```

a. Imprima la lista original completa
b. Imprima la lista original, marcando los nodos cuyos 2 bits menos significativos sean 1
c. Escriba una función que tome como argumento el primer nodo de la lista y:

  i. Elimine los nodos necesarios de manera tal que, en la lista final, no quede ningun nodo que este en una posicion par **y** cumpla con la mascara.
  ii. Los agregue a un vector de tamaño dinámico.
  iii. Devuelva la direccion de memoria del vector
  
d. Imprima la lista modificada y el vector.

Ej:

```c
// item a
10 -> 11 -> 12 -> 3 -> 9 -> NULL 

// item b
10 -> (11) -> 12 -> (3) -> 9 -> NULL 

// item d
Lista:
10 -> 12 -> 3 -> 9

Vector:
11
```
