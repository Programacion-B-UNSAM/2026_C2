#include <stdio.h>
#include <stdlib.h>

#include "definitions.h"

int main() {
    Node* Root = NULL;

    insOrdered(&Root, 10);
    insOrdered(&Root, 20);
    insOrdered(&Root, 40);
    insOrdered(&Root, 15);
    insOrdered(&Root, 50);
    insOrdered(&Root, 60);
    insOrdered(&Root, 5);
    insOrdered(&Root, 70);

    // findNode(Root, 70);
    // findNode(Root, 15);
    // findNode(Root, 7);

    printTree(Root, 0, 0);
    printf("\n\n");

    return 0;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (!newNode) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->men = NULL;
    newNode->may = NULL;

    return newNode;
}

void insOrdered(Node** Root, int new_data) {
    Node* newNode = createNode(new_data);

    if (*Root == NULL) {
        *Root = newNode;
        return;
    }

    Node* current = *Root;

    while (1) {
        if (newNode->data > current->data) {
            if (current->may == NULL) {
                current->may = newNode;
                break;
            } else {
                current = current->may;
            }
        } else {
            if (current->men == NULL) {
                current->men = newNode;
                break;
            } else {
                current = current->men;
            }
        }
    }
}

void findNode(Node* Root, int target) {
    if (Root == NULL) {
        printf("Empty tree");
        return;
    }

    Node* current = Root;

    while (1) {
        if (current == NULL) {
            printf("No existe el dato\n");
            break;
        }

        if (current->data == target) {
            printf("%d (Encontrado)\n", target);
            break;
        } else if (current->data < target) {
            printf("%d->", current->data);
            current = current->may;
        } else if (current->data > target) {
            printf("%d->", current->data);
            current = current->men;
        }
    }
}

void printTree(Node* n, int level, int isLeft) {
    if (n == NULL) {
        return;
    }
    printf("\n");
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("%d", n->data);
    printTree(n->may, level + 1, 0);
    printTree(n->men, level + 1, 0);
}