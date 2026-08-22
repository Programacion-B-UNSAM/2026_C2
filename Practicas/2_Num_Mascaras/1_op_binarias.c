/*

Hagan:
  a. Funcion que me diga el estado (lea) de cualquier bit
      uint8_t leeBit(uint64_t dato, uint8_t bitALeer);

  b. Funcion que prenda cualquier bit
  c. Funcion que apague cualquier bit
  d. Funcion que invierta el estado de cualquier bit

*/

#include <stdint.h>
#include <stdio.h>

void printBinario(uint64_t);
void leerBit(uint64_t, uint8_t);
uint64_t prenderBit(uint64_t, uint8_t);
uint64_t apagarBit(uint64_t, uint8_t);
int main(void)
{
  uint64_t dato = 13;
  /*0b0000 0000 0000 1101*/

  printBinario(dato);
  leerBit(dato, 2);
  dato = prenderBit(dato, 4);
  printBinario(dato);
  dato = apagarBit(dato, 2);
  printBinario(dato);

  return 0;
}

void printBinario(uint64_t dato)
{
  printf("0b");
  for (int i = 15; i >= 0; i--)
  {
    printf("%d", (dato >> i) & 0b1);
    if ((i % 4 == 0))
      printf(" ");
  }
  printf("\n");
  return;
}

void leerBit(uint64_t dato, uint8_t bit)
{
  /* Dos formas equivalentes */
  /* Aca muevo el dato */
  printf("%d\n", (dato >> bit) & 0b1);

  /* Aca muevo el bit */
  // uint64_t mask = dato & (0b1 << bit);
  // printf("%d", mask == mask);
  return;
}

uint64_t prenderBit(uint64_t dato, uint8_t bit)
{
  /* Prender un bit --> OR */
  uint64_t mask = 0b1 << bit;
  dato = dato | mask;
  return dato;

  /* dato = 0b 1100 0000 */
  /*              _      */
  /*     OR 0b 0001 0000  <-- mascara*/
}

uint64_t apagarBit(uint64_t dato, uint8_t bit)
{
  /* Apagar un bit --> AND */
  uint64_t mask = ~(0b1 << bit);
  dato = dato & mask;
  return dato;

  /* dato  =  0b 1101 0000 */
  /*              -        */
  /*     NOT (0b 0100 0000)  <-- mascara*/
  /*     AND  0b 1011 1111   <-- mascara*/
  /*          0b 1001 0000 */
}

uint64_t toggleBit(uint64_t dato, uint8_t bit)
{
  /* Tarea para el hogra (tip: mirar ppt)*/
  // uint64_t mask = ??;
  // dato  = dato ? mask;
  // return dato;
}