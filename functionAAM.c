/**
 * @file functionAAM.c
 * @author AIA AL MANSORI
 * @brief Demonstrates operations on a doubly linked list.
 * 
 * This program initializes a doubly linked list, performs node insertion,
 * and manipulates the current node pointer using basic list operations.
 */



#include <stdlib.h>
#include <stdio.h>

// A linked list node
/**
 * @struct Node
 * @brief Represents a node in a doubly linked list.
 */
typedef struct Node {
    int data;            // Storing data in node
    struct Node* next;   // Pointer to the next node
    struct Node* prev;   // Pointer to the previous node
} Node;

// Double linked list structure
/**
 * @struct doubleLinkedList
 * @brief Represents a doubly linked list structure.
 */
typedef struct doubleLinkedList {
    Node* head;    // Pointer to the head
    Node* tail;    // Pointer to the tail
    Node* current; // Pointer to the current node
} doubleLinkedList;

// Function to set the current node to the tail

void gotoTail(doubleLinkedList* list) {
    // Precondition check
    if (list == NULL || list->tail == NULL) { // Check if list or tail doesn't exist
        printf("List or tail doesn't exist.\n");
        return;
    }

    // Set current node to tail
    list->current = list->tail;
    printf("Current node set to tail.\n");
}

// Function to insert a node after the current node
/**
 * @brief Inserts a new node after the current node in the list.
 *
 * @param[in, out] list Pointer to the doubly linked list.
 * @param[in] data Data to insert into the new node.
 */
 /**
  * @brief Moves the current pointer to the tail of the list.
  *
  * @param[in, out] list Pointer to the doubly linked list.
  */
void insertAfter(doubleLinkedList* list, int newdata) {
    // Precondition check
    if (list == NULL || list->current == NULL) { // Check if list and current node exist
        printf("Valid double linked list or current node does not exist.\n");
        return;
    }

    // Create a new node
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory
    if (newNode == NULL) { // Check if memory allocation is successful
        printf("Error: Memory allocation failed for new node.\n");
        return;
    }

    // Initialize the new node
    newNode->data = newdata;  // Set the data to the new node
    newNode->next = NULL;     // Set the next pointer to NULL (updated later)
    newNode->prev = NULL;     // Set the prev pointer to NULL (updated later)

    // Node creation and initialization is complete
    printf("New node created and initialized with data: %d\n", newdata);

    // Insert the new node into the list
    if (list->current == list->tail) { // If the current node is the tail
        list->current->next = newNode; // Link current node to the new node
        newNode->prev = list->current; // Link new node back to the current node
        list->tail = newNode;          // Update the list's tail pointer
    }
    else { // If the current node is not the tail
        newNode->next = list->current->next; // Link the new node to the node after the current node
        newNode->prev = list->current;       // Link the new node back to the current node
        list->current->next->prev = newNode; // Update the next node's prev pointer
        list->current->next = newNode;       // Update the current node's next pointer
    }

    // Success message
    printf("New node with data %d inserted after the current node.\n", newdata);
}

/* This is for testing
int main() {
    // Initialize a doubly linked list
    doubleLinkedList list = { NULL, NULL, NULL };

    // Create the first node and set it as head and tail
    Node* firstNode = (Node*)malloc(sizeof(Node));
    firstNode->data = 1;
    firstNode->next = NULL;
    firstNode->prev = NULL;

    list.head = firstNode;
    list.tail = firstNode;
    list.current = firstNode;

    // Print the initial state of the list
    printf("Initial list: Head = %d, Tail = %d\n", list.head->data, list.tail->data);

    // Insert a new node after the current node
    insertAfter(&list, 2);

    // Print the updated state of the list
    printf("After insert: Head = %d, Tail = %d\n", list.head->data, list.tail->data);

    // Go to the tail node
    gotoTail(&list);
    printf("Current node after gotoTail: %d\n", list.current->data);

    return 0;
} */
