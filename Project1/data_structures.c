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

/**
 * @brief Retrieves the data associated with current node.
 *
 * This function gets data associated with current node and returns its value.
 *
 * @param node A pointer to the node where data is to be retrieved.
 * @return The data stored in the node.
 */
int getData(Node* node) {
    return node -> data;
}

/**
 * @brief Sets current node to the successor of current.
 *
 * This function checks if the `next` pointer of the given node is `NULL`. If it is `NULL`, 
 * it returns the current node. Otherwise, it sets current node to the successor of current.
 *
 * @param node A pointer to the current node.
 * @return A pointer to the next node, or the current node if no next node exists.
 */
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