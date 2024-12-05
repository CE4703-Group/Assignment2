#include <stdlib.h>
#include <stdio.h>
#include "set.h"  

#define NUMBER_ADDED 1          
#define NUMBER_ALREADY_IN_SET 0  

// Function to add an element to an ordered set
int addElement(struct Node** s, int elem) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        return -1; // Memory allocation failed
    }
    newNode->data = elem;    // Set the data of the new node
    newNode->next = NULL;    // Initialize the next pointer to NULL

    // Check if the list is empty or 'elem' should be inserted at the head
    if (*s == NULL || (*s)->data > elem) {
        // Check if the element already exists at the head
        if (*s != NULL && (*s)->data == elem) {
            free(newNode); // Free the memory allocated for the duplicate node
            return NUMBER_ALREADY_IN_SET;
        }
        // Insert the new node at the beginning of the list
        newNode->next = *s;
        *s = newNode;
        return NUMBER_ADDED; // Element added successfully
    }

    // Traverse the list to find the correct position for insertion
    struct Node* temp = *s;
    while (temp->next != NULL && temp->next->data < elem) {
        temp = temp->next; // Move to the next node
    }

    // Check if 'elem' already exists in the set
    if (temp->data == elem || (temp->next != NULL && temp->next->data == elem)) {
        free(newNode); // Free the memory allocated for the duplicate node
        return NUMBER_ALREADY_IN_SET;
    }

    // Insert the new node in the correct position
    newNode->next = temp->next; // Link the new node to the next node
    temp->next = newNode;       // Link the current node to the new node
    return NUMBER_ADDED;        // Element added successfully
}

// Function to compute the intersection of two ordered sets
intSet* setIntersection(intSet* s1, intSet* s2) {
    // Create a new set to store the intersection result
    intSet* intersectionSet = createSet();
    if (intersectionSet == NULL) {
        return NULL; // Memory allocation failed
    }

    // Traverse the first set (s1)
    struct Node* temp = s1->head;
    while (temp != NULL) {
        // Check if the current element in s1 exists in s2
        if (isElementInSet(s2, temp->data)) {
            // Add the element to the intersection set
            if (addElement(&(intersectionSet->head), temp->data) == -1) {
                printf("Error: Memory allocation failed while adding an element.\n");
                free(intersectionSet); // Free memory for the intersection set
                return NULL;           // Return NULL on failure
            }
        }
        temp = temp->next; // Move to the next node in s1
    }

    return intersectionSet; // Return the resulting intersection set
}
