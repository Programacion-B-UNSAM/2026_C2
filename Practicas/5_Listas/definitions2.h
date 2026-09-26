typedef struct DoubleNode {
    int data;
    struct DoubleNode* next;
    struct DoubleNode* prev;
} DoubleNode;

DoubleNode* createDoubleNode(int data);
void insFirst(DoubleNode** PrimerNodo, DoubleNode** UltimoNodo, int new_data);
void delLast(DoubleNode** PrimerNodo, DoubleNode** UltimoNodo);
void showFull(DoubleNode* PrimerNodo);
void showReversed(DoubleNode* UltimoNodo);
void freeList(DoubleNode* PrimerNodo);