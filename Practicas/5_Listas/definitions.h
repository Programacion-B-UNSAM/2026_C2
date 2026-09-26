typedef struct Nodo {
    int dato;
    struct Nodo* next;
} Nodo;

Nodo* createNodo(int nuevoDato);
void insFirst(Nodo** PrimerNodo, int nuevoDato);
void delLast(Nodo** PrimerNodo);
void showFull(Nodo* PrimerNodo);
// void freeList(Nodo** PrimerNodo);
