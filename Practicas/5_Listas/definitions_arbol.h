typedef struct Nodo {
    int dato;
    struct Nodo* der;
    struct Nodo* izq;
} Nodo;

Nodo* createNodo(int nuevoDato);
void insOrdenado(Nodo** PrimerNodo, int nuevoDato);