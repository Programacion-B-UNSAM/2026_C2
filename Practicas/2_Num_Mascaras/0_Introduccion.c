/*
  Tengo un sensor de temperatura y humedad que me da 1 solo dato the 16 bits

  Los 8 bits menos significativos son de temperatura.
  Los 8 bits restantes son de humedad

  Como separo la informacion?
*/

#include <stdio.h>
#include <stdint.h>

void printBinario(uint64_t);

int main(void)
{
  uint16_t data = 13450;
  printBinario(data);
  /* 0b _ _ _ _  _ _ _ _   _ _ _ _  _ _ _ _ */
  /*        HUMEDAD      |  TEMPERATURA    */

  // uint8_t temp = data & 0b11111111;
  // 0xF = 0b1111
  uint8_t temp = data & 0xFF;
  uint8_t hume = data >> 8;
  printf("Temp = ");
  printBinario(temp);

  printf("Hume = ");
  printBinario(hume);
  printf("Humedad     = %d \n", hume);
  printf("Temperatura = %d ºC\n", temp);

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