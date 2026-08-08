#include <stdio.h>

int a = 500; /* Variable global */
void Contar(void){
  int a = 0;
  printf("a(func) =  %d\n", a);
}
int main(void){
  Contar();
  printf("a(main) =  %d\n", a);
  for (int i = 0 ; i <3; i++)
    a *= 3;
  Contar();
  printf("a(main) =  %d\n", a);
  return 0;
}
