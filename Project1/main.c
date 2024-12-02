#include <stdio.h>
#include <stdlib.h>
#include "data_structures.h"



int main() {
    // Create a doubly linked list
    doubleLinkedList* list = createDoubleLinkedList();
    printf("Doubly linked list created.\n");

    // Insert nodes into the list
    gotoHead(list);
    printf("Inserting nodes after head.\n");
    insertAfter(list, 10);  // Insert 10 after head
    insertAfter(list, 20);  // Insert 20 after current node
    insertAfter(list, 30);  // Insert 30 after current node

    // Display the list
    printf("List after inserting nodes:\n");
    displayList(list->head->next); // Skip the dummy head node

    // Move to the tail and display data
    gotoTail(list);
    printf("Current node after moving to tail: %d\n", getData(list));

    // Move to the previous node and display data
    gotoPreviousNode(list);
    printf("Current node after moving to previous: %d\n", getData(list));

    // Move to the next node and display data
    gotoNextNode(list);
    printf("Current node after moving to next: %d\n", getData(list));

    // Delete the current node
    printf("Deleting current node.\n");
    deletecurr(&list->head, list->current);
    displayList(list->head->next); // Skip the dummy head node

    // Insert a node before the current position
    printf("Inserting node with data 25 before current position.\n");
    insertbeforecurr(&list->head, 25, 2);
    displayList(list->head->next); // Skip the dummy head node

    // Clean up: delete the entire list
    printf("Deleting the entire list.\n");
    while (list->head->next != list->tail) {
        deletecurr(&list->head, list->head->next); // Delete each node except dummy head and tail
    }

    // Free the dummy head and tail nodes
    free(list->head);
    free(list->tail);
    free(list);
    printf("Doubly linked list deleted.\n");

    return 0;
}




