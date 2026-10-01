# Parcial (M16) - Programacion en C - 2026C1

# Consideraciones 

- Las resoluciones deben ser genéricas
- No deben usar ni modificar nada del archivo Catedra_M16.c
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

b) Escriba una función que reciba como argumento la dirección de memoria de un nodo y devuelva su posición en la grilla, utilizando el struct Posición. (Puede usar la función CATEDRA_RandomNodo() para probar su función).

c) Escriba una función que tome como argumento dos posiciones distintas, e imprima el camino más corto para llegar de una a otra. Asuma que la grilla es rectangular.

Por ejemplo, para la siguiente grilla:

```c
// Ejercicio 1
A B C D E F G
H I J K L M N
O P Q R S T U
V W X Y Z 1 2 
3 4 5 6 7 8 9   
```

Si la función CATEDRA_RandomNodo() me devuelve la dirección del nodo E

```c
Posición = {.fila = 0, .columna = 4}
// Tambien podria ser fila = 1 y columna = 5
```

Si luego se nos pide el camino más corto entre (3, 1) y (4, 5), una posible respuesta sería:

```c
W > X > Y > Z > 1 ⌄ 7 
```

PD: Flechitas para los prints = < > ^ ⌄

* * *

## Ejercicio 2

La función CATEDRA_CrearVector devuelve un vector de los siguientes structs:

```c
typedef struct {
    int esNro; // 1 si es número, 0 si es carácter
    union {
        int numero;
        char caracter;
    } dato;
} customElement;
```

a) Imprima el vector original
b) Escriba una función que reciba un vector de 'customElement', su tamaño y el puntero al inicio de una lista doblemente enlazada.
La función debe recorrer el vector y:

- Si el elemento es un número, **eliminarlo** del vector (actualizando su tamaño).
- Insertar dicho número en la lista doblemente enlazada de forma **ordenada ascendente**.

c) Imprima la lista doblemente enlazada resultante.
d) Imprima el vector modificado.