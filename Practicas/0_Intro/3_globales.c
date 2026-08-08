#include <stdio.h>

int g_a = 0; /* Variable global */

void Contar(void){
  g_a++;
  printf("g_a vale %d\n", g_a);
}

void Contar_MAL(void){
  g_a=0;
}

int main(void){

  Contar();

  for (int i = 0 ; i <3; i++)
    g_a *= 3;

  Contar_MAL();
  Contar();

  return 0;
}
