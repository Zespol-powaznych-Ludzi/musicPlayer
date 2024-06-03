#include "linkedList.h"

LinkedList* linkedListInit () {
    LinkedList* newList = (LinkedList*) malloc (sizeof (LinkedList));

    if (!newList) {
        return NULL;
    }

    newList->head = NULL;
    newList->size = 0;
    newList->tail = NULL;

    return newList;
}

Node* createNode (void* data) {
    Node* newNode = (Node*) malloc (sizeof (Node));

    if (!newNode) {
        return NULL;
    }

    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = data;
    
    return newNode;
}

void freeList (LinkedList* list) {

    if (!list) {
        return;
    }

    Node* current = list->head;

    while (current) {
        Node* tempNode = current;
        current = current->next;
        free (tempNode);
    }

    free (list);
}

void push (LinkedList* list, void* data) {
    Node* newNode = createNode (data);

    if (!list->head) {
        list->head = newNode;
        list->tail = list->head;
        ++list->size;
        
        return;
    }

    list->tail->next = newNode;
    newNode->prev = list->tail;
    list->tail = newNode;
    ++list->size;
}

Node* getLastNode (LinkedList* list) {

    return list->tail;
}

Node* getFirstNode (LinkedList* list) {
    
    return list->head;
}

Node* getNextNode (Node* node) {
    return node->next;
}

Node* getPrevNode (Node* node) {
    return node->prev;
}

Node* getNodeByIndex (LinkedList* list, size_t index) {
    Node* tempNode = list->head;
    size_t currentIndex = 0;

    while (currentIndex != index) {
        if (!tempNode) {
            return NULL;
        }
        tempNode = tempNode->next;
        ++currentIndex;
    }

    return tempNode;

}

void pop (LinkedList* list) {

    if (!list->tail) {
        return;
    }

    if (!list->tail->prev) {
        free (list->tail);
        free (list->head);
        list->tail = NULL;
        list->head = NULL;

        list->size = 0;

        return;
    }

    Node* tempNode = list->tail->prev;
    free (list->tail);
    list->tail = tempNode;
    tempNode->next = NULL;
    --list->size;
}
