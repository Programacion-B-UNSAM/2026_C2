typedef struct Node {
    int data;
    struct Node* men;
    struct Node* may;
} Node;

Node* createNode(int data);
void insOrdered(Node** Root, int new_data);
void findNode(Node* Root, int target);
void printTree(Node* n, int level, int isLeft);