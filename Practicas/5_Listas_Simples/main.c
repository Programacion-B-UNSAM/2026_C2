#include <stdio.h>

#include "def.h"
#include "funcs.c"
int main()
{

  nodo_t *first = NULL;
  first = ins_first(first, 0);
  del_last(&first);
  first = ins_first(first, 1);
  first = ins_first(first, 2);

  nodo_t *aux = first;
  while (aux != NULL)
  {
    printf("%d -> ", aux->num);
    aux = aux->next;
  }
  printf("\n");

  return 0;
}