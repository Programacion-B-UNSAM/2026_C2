#include <stdio.h>

void Saludo(void);

int main(void){

  Saludo();
  /* gcc <nombre_archivo>.c -o <nombre_archivo> */
  /* Windows: .\<nombre_archivo> */
  /* Linux (Ubuntu): ./*<nombre_archivo> */
  
  return 0;
}

void Saludo(void){
  printf("Hola mundo!\n");
}