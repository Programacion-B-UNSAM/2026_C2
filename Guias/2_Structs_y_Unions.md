# Structs y Unions

## Struct

1. Leer por teclado los detalles (legajo, nombre, promedio) de n estudiantes (n < 100) y almacenarlo en el archivo estudiantes.dat.
2. Leer el archivo estudiantes.dat y mostrar el estudiante con el mayor promedio.
3. Escribir una función que reciba las coordenadas cartesianas de 2 puntos en el espacio y devuelva la distancia euclídea.
4. Escribir una función que reciba las coordenadas de dos vectores en el plano y devuelva las coordenadas del vector que resulta de componer ambos vectores
5. Escribir una función que reciba 2 horas h1 y h2 (hora, minutos y segundos) y devuelva la diferencia entre ambas (en horas, minutos y segundos). Se sabe que h2 es posterior a h1.
6. Dado el siguiente tipo de datos y teniendo en cuenta que la dirección del miembro a es 0x00546334, 
    1. Cuál sería la dirección de b?
    2. Cuál es el tamaño del struct?
    
    ```c
    struct aux {
    	int a;
    	char b;
    }
    ```
    
7. Dado el siguiente código, ¿qué se mostraría por pantalla al correrlo? (primero genere un hipotesis y luego refutela o confirmela)
    
    ```c
    struct aux {
    	int a;
    	char b;
    };
    
    int main(void){
    	struct aux var;
    	
    	var.a = 77;
    	
    	printf("a: %d\n", var.a);
    	printf("b: %c\n", var.b);
    }
    ```
    

## Union

1. ¿Cuál es la diferencia entre un struct y un union?
2. Escribir un programa que pida los datos de una persona y los imprima en pantalla. Los datos a pedir son Nombre, Nacionalidad, Edad y segun la nacionalidad, Numero de DNI o Pasaporte. (usando la menor cantidad de memoria)
3. Dado el siguiente tipo de datos y teniendo en cuenta que la dirección del miembro a es 0x00546334, 
    1. Cuál sería la dirección de b?
    2. Cuál es el tamaño del union?
    
    ```c
    union aux {
    	int a;
    	char b;
    }
    ```
    
4. Dado el siguiente código, ¿qué se mostraría por pantalla al correrlo?
(primero genere un hipotesis y luego refutela o confirmela)
    
    ```c
    union aux {
    	int a;
    	char b;
    	int c;
    };
    
    int main(void){
    	union aux var;
    	
    	var.a = 77;
    	
    	printf("a: %d\n", var.a);
    	printf("b: %c\n", var.b);
    	printf("c: %d\n", var.c);
    }
    ```