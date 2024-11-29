
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

struct Node* createNode(int data) {
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

int main() {
  
    // Sample usage of the doubly linked list and
    // traversal functions
    Node* head = createNode(1);
    Node* second = createNode(2);
    Node* third = createNode(3);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    printf("head data is: %d\n", getData(head));
    printf("next one is: %d\n", getData(gotoNextNode(head)));
    printf("one after is: %d\n", getData(gotoNextNode(second)));

    // Free memory allocated for nodes
    free(head);
    free(second);
    free(third);

    return 0;
}



