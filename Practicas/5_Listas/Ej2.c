#include <stdio.h>
#include <stdlib.h>

#include "definitions2.h"

int main()
{
    DoubleNode *PrimerNodo = NULL;
    DoubleNode *UltimoNodo = NULL;

    insFirst(&PrimerNodo, &UltimoNodo, 10);
    insFirst(&PrimerNodo, &UltimoNodo, 20);
    insFirst(&PrimerNodo, &UltimoNodo, 30);
    insFirst(&PrimerNodo, &UltimoNodo, 40);
    insFirst(&PrimerNodo, &UltimoNodo, 50);
    insFirst(&PrimerNodo, &UltimoNodo, 60);
    insFirst(&PrimerNodo, &UltimoNodo, 70);

    printf("\nLinked List: \n\t");
    showFull(PrimerNodo);
    printf("\n\t");
    showReversed(UltimoNodo);

    delLast(&PrimerNodo, &UltimoNodo);
    printf("\nLinked List: \n\t");
    showFull(PrimerNodo);
    printf("\n\t");
    showReversed(UltimoNodo);

    delLast(&PrimerNodo, &UltimoNodo);
    printf("\nLinked List: \n\t");
    showFull(PrimerNodo);
    printf("\n\t");
    showReversed(UltimoNodo);

    freeList(PrimerNodo);

    return 0;
}

DoubleNode *createDoubleNode(int data)
{
    DoubleNode *newDoubleNode = (DoubleNode *)malloc(sizeof(DoubleNode));
    if (!newDoubleNode)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    newDoubleNode->data = data;
    newDoubleNode->next = NULL;
    newDoubleNode->prev = NULL;
    return newDoubleNode;
}

void insFirst(DoubleNode **PrimerNodo, DoubleNode **UltimoNodo, int new_data)
{
    DoubleNode *newDoubleNode = createDoubleNode(new_data);
    if (*PrimerNodo == NULL)
    {
        *PrimerNodo = newDoubleNode;
        *UltimoNodo = newDoubleNode;
        return;
    }

    DoubleNode *current = *PrimerNodo;
    newDoubleNode->next = current;
    newDoubleNode->prev = NULL;
    current->prev = newDoubleNode;
    *PrimerNodo = newDoubleNode;
}

void delLast(DoubleNode **PrimerNodo, DoubleNode **UltimoNodo)
{
    if (*PrimerNodo == NULL)
    {
        printf("List is empty. No Node to delete.\n");
        return;
    }
    DoubleNode *current = *UltimoNodo;

    if (current->prev == NULL)
    {
        free(current);
        *PrimerNodo = NULL;
        *UltimoNodo = NULL;
        return;
    }

    *UltimoNodo = current->prev;
    (*UltimoNodo)->next = NULL;
    free(current);
}

void showFull(DoubleNode *PrimerNodo)
{
    DoubleNode *current = PrimerNodo;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void showReversed(DoubleNode *UltimoNodo)
{
    DoubleNode *current = UltimoNodo;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

void freeList(DoubleNode *PrimerNodo)
{
    DoubleNode *current = PrimerNodo;
    DoubleNode *nextDoubleNode;
    while (current != NULL)
    {
        nextDoubleNode = current->next;
        free(current);
        current = nextDoubleNode;
    }
}
