#include <stdio.h>
#include <stdlib.h>
#include "data_structures.h"



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



