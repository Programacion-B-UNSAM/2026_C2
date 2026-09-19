#include <stdlib.h>
#include <stdio.h>
#include "def.h"

nodo_t *crear_nodo(int dato)
{
  nodo_t *nodo = (nodo_t *)malloc(sizeof(nodo_t));
  if (nodo == NULL)
  {
    printf("No se pudo crear el nodo %d", dato);
    return NULL;
  }
  nodo->num = dato;
  nodo->next = NULL;
  return nodo;
}

nodo_t *ins_first(nodo_t *first, int dato)
{
  nodo_t *nuevoNodo = crear_nodo(dato);
  nuevoNodo->next = first;
  return nuevoNodo;
}

void del_last(nodo_t **first)
{
  if ((*first)->next == NULL)
  {
    free(*first);
    *first = NULL;
    return;
  }

  nodo_t *aux = *first;
  while (aux->next->next != NULL)
  {
    aux = aux->next;
  }
  nodo_t *aux2 = aux->next;
  free(aux2);
  aux->next = NULL;
}
