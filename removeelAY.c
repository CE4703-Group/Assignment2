/**
 * @file functionsAY.c
 * @author AISHAT AYOMIDE YUSUFF
 * @brief Implements operations on a doubly linked list.
 *
 * This program demonstrates deleting an elemnt from an ordered set,
 * and printing it in a particular order
 */


#include <stdio.h>
#include <stdlib.h>

#define NUMBER_REMOVED "number removed"
#define NUMBER_NOT_IN_SET "number not in set"

 /**
  * @struct Node
  * @brief Represents a node in a doubly linked list.
  *
  * A node in the doubly linked list contains an integer data, a pointer to the next node,
  * and a pointer to the previous node.
  */
typedef struct Node {
    int data;            // Storing data in node
    struct Node* next;   // Pointer to the next node
    struct Node* prev;   // Pointer to the previous node
} Node;

/**
 * @struct ordset
 * @brief Represents an ordered set using a doubly linked list.
 *
 * The ordered set is implemented as a doubly linked list with pointers to the head and
 * tail nodes, as well as a counter to track the number of elements.
 */
typedef struct ordset {
    Node* head;    // Pointer to the head
    Node* tail;    // Pointer to the tail
    int count; //tracking the num in elemnt
} ordset;


/**
 * @brief Removes an element from the ordered set.
 *
 * This function searches for an element in the ordered set and removes it if found.
 * If the element is not present, it returns an appropriate message.
 *
 * @param s Pointer to the ordered set.
 * @param elem The element to be removed.
 * @return A string indicating whether the element was removed or not found in the set.
 */
char* removeElement(ordset* s, int elem) {
    if (s == NULL || s->tail == NULL) { // Check if list or tail doesn't exist
        printf("List or tail doesn't exist.\n");
        return;
    }
    Node* current = s->head;

    while (current != NULL) { //so far the list still has a value
        if (current->data == elem) {
            if (current->prev != NULL) { //to check if there is something before and if there isnt that means current is the head
                current->prev->next = current->next;
            }
            else {
                s->head = current->next; //then we have to remove the head
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);

            s->count--;

            return NUMBER_REMOVED;
        }
        current = current->next;
    }
    return NUMBER_NOT_IN_SET;
}
/**
 * @brief Prints the elements of the ordered set to standard output.
 *
 * This function iterates through the ordered set and prints all the elements
 * in the set. If the set is empty, it prints an empty set representation (`{}`).
 *
 * The elements are displayed in order, separated by commas.
 *
 * @param s Pointer to the ordered set.
 */

void printToStdout(ordset* s) {
    if (s == NULL || s->head == NULL) {
        printf("{}\n");
        return;
    }
    Node* temp = s->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        if (temp->next != NULL) {
            printf(",");
        }
        temp = temp->next;
    }
    printf("} \n ");
}
