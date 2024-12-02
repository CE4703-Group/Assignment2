#include <stdio.h>
#include <stdlib.h>

// Define the structure of Node
typedef struct Node {

    // Data field
    int data;

    // Pointer to the next node
    struct Node *next;

    // Pointer to the previous node
    struct Node *prev;
} Node;

Node* createNode(int data) {
    struct Node* newNode =
      (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int getData(Node* node) {
    return node -> data;
}

Node* gotoNextNode(Node* node){
    if(node->next == NULL){
        return node;
    }else{
        return node->next;
    }
}

Node* gotoPreviousNode(Node* node) {
    if (node->prev == NULL) {
        return node;
    }

    else {
        return node->prev;
    }
}
//void gotoHead(Node* node) {
//    
//}