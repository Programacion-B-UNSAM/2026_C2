#include <stdio.h>

void Contar(void){
  int a = 0;
  a++;
  printf("a vale %d\n", a);
}

int main(void){

  int aux;
  Contar();
  Contar();
  Contar();
  int a = 0;
  for (int i =0; i< 10; i++){
    a +=2;
  }
  printf("a = %d\n", a);
  Contar();

  return 0;
}
