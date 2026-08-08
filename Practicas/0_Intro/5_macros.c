#include <stdio.h>

#define ROJO 0xFFFF

#define CIEN DIEZ*10
#define DIEZ 10 

#define SUM(A,B) (A+B)
#define MULT(A,B) A*B

int main (void){

  int b = CIEN;
  printf("DIEZ = %d\n", DIEZ);
  printf("CIEN = b = %d\n", b);

  int c = SUM(DIEZ,b);
  printf("c = %d\n",c);

  int d = MULT(c+DIEZ, b);
  printf("d = %d\n",d);
  return 0;
}