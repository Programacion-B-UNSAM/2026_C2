# Funciones - Punteros

1. Escribe una función que intercambie los valores de dos variables enteras usando punteros. Luego, llama a esta función desde `main` y muestra los valores antes y después del intercambio.
2. Escribe una función que reciba un puntero a un array de enteros y su tamaño, y devuelva la suma de sus elementos. Luego, llama a esta función desde `main` y muestra el resultado.
3. Escribe una función que reciba un puntero a una cadena (`\\0` representa el final de cadena) de caracteres (string) y devuelva su longitud. Luego, llama a esta función desde `main` y muestra el resultado.
4. Escribe una función que reciba un puntero a un array de enteros y su tamaño, y multiplique cada elemento por 2. Luego, llama a esta función desde `main`  y muestra los elementos del array antes y después de la modificación.
5. Escribe una función que reciba dos punteros a cadenas de caracteres y copie el contenido de la segunda cadena en la primera. Luego, llama a esta función desde `main` y muestra las cadenas antes y después de la copia.
6. Escribe una función que reciba un puntero a un array de enteros y su tamaño, y devuelva un puntero al elemento de mayor valor en el array. Luego, llama a esta función desde `main` y muestra el valor del elemento de mayor valor.
7. Escribe una función que reciba un puntero a una cadena de caracteres y un carácter, y devuelva la posición (índice) de la primera ocurrencia del carácter en la cadena. Si el carácter no se encuentra en la cadena, la función debe devolver -1. Luego, llama a esta función desde `main` y muestra el resultado.

## Ejercicio Integrador

1. Dado el array de numeros del archivo `lista.h` :
    1. Calcule la suma de todos los números del vector.
    2. Calcule el promedio de todas las direcciones de memoria de los números del vector.
    3. Ordene los números de menor a mayor, de acuerdo a la suma de sus dígitos. Por ejemplo: 
        
        32, 50, 19 —sorted—> 32, 50, 19 o 50, 32, 19
        
        Imprima los primeros y últimos 5 números del vector ordenado, junto con sus direcciones de memoria.
        
    4. Modifique los valores de los numeros en el array de acuerdo a las siguientes condiciones:
        1. Si la **dirección de memoria**, en binario, tiene una cantidad PAR de unos, multipliquelo por 5
        2. Si el **número** es IMPAR dividalo por 5.
        
        Por ejemplo: 
        
        Si la dirección de memoria es 0061FEFC lo multiplico por 5
        
        Si el número es 7: lo divido por 5 .
        
        obs. Es posible que a algunos números haya que aplicarles ambas operaciones.
        
    5. Calcule una vez más la suma de los números y el promedio de las direcciones de memoria del vector. Imprima un mensaje indicando si son iguales, o distintos que los calculados anteriormente.
    
    Consideraciones: Intente que su código recorra el vector la menor cantidad de veces posible. NO genere un menu con los items, el código debe ser ejecutado una única vez, realizando todo lo que se pide. Sea prolijo a la hora de imprimir las cosas que se piden.