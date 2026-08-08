#include <stdio.h>

#define EJ1
// #define EJ2

void Contador(int a);

int main(void){

#ifdef EJ1
  /* Ejercicio 1: Hola mundo */
  printf("\nEJ1\n");
  printf("Hola Mundo!\n");
#endif

#ifdef EJ2
  /* Ejercicio 2: Func Contador() */
  printf("\nEJ2\n");
  Contador(10);
#endif

  return 0;
}

void Contador(int a){

  for (int i = 0; i < a; i++)
    printf("%d - ", i);
  printf("\n");
  return;
}