#include <stdlib.h>

struct Node {
    void* data;
    struct Node* next;
    struct Node* prev;
} typedef Node;

struct LinkedList {
    Node* head;
    Node* tail;
    size_t size;
} typedef LinkedList;

LinkedList* linkedListInit ();
Node* createNode (void* data);
void freeList (LinkedList* list);
void push (LinkedList* list, void* data);
Node* getLastNode (LinkedList* list);
Node* getFirstNode (LinkedList* list);
Node* getNextNode (Node* node);
Node* getPrevNode (Node* node);
Node* getNodeByIndex (LinkedList* list, size_t index);
void pop (LinkedList* list);
