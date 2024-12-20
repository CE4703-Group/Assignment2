/**
 * @file ordered_set.c
 *
 * @authors
 * - Aia Al Mansori (23358904)
 * - Anaswara Johnson (23287322)
 * - Aishat Yusuff (23362146)
 * - Maya Niessen (23391731)
 * - Xuyang Tan (24168033)
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "double_linked_list.h"
#include "ordered_set.h"



/**
 * @brief Checks if a specified element exists in the given ordered integer set.
 *
 * This function traverses the linked list representation of the ordered integer set
 * and checks if the specified data element is present. If the set or its internal
 * list is NULL or empty, the function returns false.
 *
 * @param set Pointer to the ordered integer set to search in.
 * @param data The integer element to search for in the set.
 * @return true if the element exists in the set, false otherwise.
 *
 * @note The function assumes that the ordered integer set is implemented as a linked list.
 */
 // Function to check if an element exists in a set
bool isElementInSet(orderedIntSet* set, int data) {
    // Ensure the set is not NULL
    if (set == NULL || set->list == NULL || set->list->head == NULL) {
        return false; // Element cannot exist in an empty set
    }

    // Traverse the linked list in the set
    Node* current = set->list->head;
    while (current != NULL) {
        if (current->data == data) {
            return true; // Element found
        }
        current = current->next;
    }

    return false; // Element not found
}


enum return_value{
    NUMBER_ALREADY_IN_SET = 0, //0
    NUMBER_NOT_IN_SET = 1,  //1
    NUMBER_ADDED = 2, // 2
    NUMBER_REMOVED = 3, // 3
    ALLOCATION_ERROR = 4 //4
};


// Ordered int set structure
/**
 * @struct orderedIntSet
 * @brief Represents a Ordered int set structure.
 */
//typedef struct orderedIntSet {
//    // pointer to a doubly linked list
//    doubleLinkedList* list;
//    // count of the number of elements in the set
//    int count;
//} orderedIntSet;

/**
 * @brief Creates an empty ordered set.
 *creates an empty ordered set where the no of elements is set to 0.
 *
 * @return A pointer to the newly created ordered set.
 */
orderedIntSet* createOrderedSet() {
    orderedIntSet* set = (orderedIntSet*)malloc(sizeof(orderedIntSet)) ; // allocates memory for the set
    if (set == NULL) { // Check if memory allocation is successful
        printf("Error: Memory allocation failed for new ordered set.\n");
        return ALLOCATION_ERROR;
    }
    set->list = createDoubleLinkedList(); // initialising an empty set
    int count = 0;
    return set;
}

 /**
 * @brief Deletes an ordered set and frees its memory.
 * the function deletes all the elements in the ordered set from the memory.
 * @param set A pointer to the ordered set to be deleted.
 *
 */
void deleteOrderedSet(orderedIntSet* set) {
    Node* current = set->list->head; // setting the current node to the head node
    deleteDoubleLinkedList(current);
    free(set); // free the memory for the set
    printf("Ordered set is successfully deleted!\n");
}


/**
 * @brief Adds a new element to an ordered set.
 *
 * This function ensures that the set remains ordered and does not allow duplicate elements.
 * If the element already exists in the set, it is not added again.
 *
 * @param[in,out] set  Pointer to the ordered set (linked list).
 * @param[in] elem The element to be added to the set.
 * @return int Returns:
 * - `NUMBER_ADDED` if the element was successfully added.
 * - `NUMBER_ALREADY_IN_SET` if the element already exists in the set.
 * - `-1` if memory allocation for the new node failed.
 */
int addElement(orderedIntSet* set, int elem) {
    // Allocate memory for a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return ALLOCATION_ERROR; // Memory allocation failed
    }
    // first element to insert
    if(set->list->head == NULL){
        newNode->data = elem;
        newNode->next = NULL;
        newNode->prev = NULL;
        set->list->head = newNode;
        set->list->tail = newNode;
        set->count = 1;
        return NUMBER_ADDED;
    }else{
        Node* s = set->list->head;
        newNode->data = elem;    // Set the data of the new node
        newNode->next = NULL;    // Initialize the next pointer to NULL

        // Check if the list is empty or 'elem' should be inserted at the head
        if (s == NULL || (s)->data > elem) {
            // Check if the element already exists at the head
            if (s != NULL && (s)->data == elem) {
                free(newNode); // Free the memory allocated for the duplicate node
                return NUMBER_ALREADY_IN_SET;
            }
            // Insert the new node at the beginning of the list
            newNode->next = s;
            s = newNode;
            set->count += 1;
            return NUMBER_ADDED; // Element added successfully
        }

        // Traverse the list to find the correct position for insertion
        struct Node* temp = s;
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
        set->count += 1;
        return NUMBER_ADDED;        // Element added successfully
    }
    
}


/**
 * @brief Computes the intersection of two ordered sets.
 *
 * Creates a new set containing the intersection of two given ordered sets `s1` and `s2`.
 * The intersection includes only the elements present in both sets.
 * Neither `s1` nor `s2` is modified during this operation.
 *
 * Behavior:
 * - If both sets are empty or have no common elements, the result is an empty set.
 * - If memory allocation fails during the operation, the function returns `NULL`.
 *
 * @param[in] s1 Pointer to the first ordered set (linked list).
 * @param[in] s2 Pointer to the second ordered set (linked list).
 * @return intSet* Pointer to the newly created set containing the intersection of `s1` and `s2`.
 *         - Returns `NULL` if memory allocation fails.
 */
orderedIntSet* setIntersection(orderedIntSet* s1, orderedIntSet* s2) {
    
    orderedIntSet* s3 = createOrderedSet();

    Node* s2curr = s2->list->head;

    // for every elements in s2, check if there is the same one in s1
    while(s2curr != NULL){
        int hasSameEle = 0;
        Node* s1curr = s1->list->head;
        while (s1curr != NULL){
            if(s1curr->data == s2curr->data){
                hasSameEle = 1;
                break;
            }
            s1curr = s1curr->next;
        }
        if (hasSameEle){
            int a = addElement(s3, s2curr->data);
            if(a == NUMBER_ADDED){
                s3->count++;
            }
        }
        s2curr = s2curr->next;
    }

    return s3;
}





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
char* removeElement(orderedIntSet* s, int elem) {
    if (s == NULL || s->list->tail == NULL) { // Check if list or tail doesn't exist
        printf("List or tail doesn't exist.\n");
        return NUMBER_NOT_IN_SET;
    }
    Node* current = s->list->head;

    while (current != NULL) { //so far the list still has a value
        if (current->data == elem) {
            if (current->prev != NULL) { //to check if there is something before and if there isnt that means current is the head
                current->prev->next = current->next;
            }
            else {
                s->list->head = current->next; //then we have to remove the head
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
 * @brief Computes the union of two ordered integer sets.
 *
 * This function takes two ordered integer sets (`s1` and `s2`) and returns a new set
 * that represents the union of the two sets. The union includes all elements from
 * both sets without duplicates.
 *
 * @param[in] s1 Pointer to the first ordered integer set.
 * @param[in] s2 Pointer to the second ordered integer set.
 * @return Pointer to an ordered integer set representing the union of `s1` and `s2`.
 *
 * @note The function modifies will not modify 's1' or 's2' when computing the union set
 */

orderedIntSet* setUnion(orderedIntSet* s1, orderedIntSet* s2){

    orderedIntSet* s3 = createOrderedSet();

    // Add all elements in s1 to s3
    Node* s1curr = s1->list->head;
    while (s1curr != NULL) {
        int a = addElement(s3, s1curr->data);
        if(a == NUMBER_ADDED){
            s3->count++;
        }
        s1curr = s1curr->next;
    }

    // Add elements from s2 that are not already in s3
    Node* s2curr = s2->list->head;
    while (s2curr != NULL) {
        int a = addElement(s3, s2curr->data);
        if(a == NUMBER_ADDED){
            s3->count++;
        }
        s2curr = s2curr->next;
    }

    return s3;
}

/**
 * @brief Computes the difference of two ordered integer sets.
 *
 * This function takes two ordered integer sets (`s1` and `s2`) and returns a new set
 * that contains elements present in `s1` but not in `s2`.
 *
 * @param[in] s1 Pointer to the first ordered integer set.
 * @param[in] s2 Pointer to the second ordered integer set.
 * @return Pointer to an ordered integer set representing the difference (`s1 - s2`).
 *
 * @note The function creates a new set (`s3`) to store the result, so `s1` and `s2` remain
 *       unmodified.
 */

orderedIntSet* setDifference(orderedIntSet* s1, orderedIntSet* s2){

    orderedIntSet* s3 = createOrderedSet();

    Node* s2curr = s2->list->head;

    // for every elements in s2, check if there is the same one in s1
    while(s2curr != NULL){
        int hasSameEle = 0;
        Node* s1curr = s1->list->head;
        while (s1curr != NULL){
            if(s1curr->data == s2curr->data){
                hasSameEle = 1;
            }
            s1curr = s1curr->next;
        }
        if (!hasSameEle){
            int a = addElement(s3, s2curr->data);
            if(a == NUMBER_ADDED){
                s3->count++;
            }
        }
        s2curr = s2curr->next;
    }

    return s3;
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

void printToStdout(orderedIntSet* s) {
    if (s == NULL || s->list->head == NULL) {
        printf("{}\n");
        return;
    }
    printf("{ ");
    Node* temp = s->list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        if (temp->next != NULL) {
            printf(",");
        }
        temp = temp->next;
    }
    printf("}\n");
}
