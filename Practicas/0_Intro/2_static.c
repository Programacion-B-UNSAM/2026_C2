#include <stdio.h>

void Contar(void){
  static int a = 2;
  a*=a;
  printf("a vale %d\n", a);
}

int main(void){

  Contar();
  Contar();
  Contar();

  return 0;
}
