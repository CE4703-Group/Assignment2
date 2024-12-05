#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"

// Ordered int set structure
/**
 * @struct orderedIntSet
 * @brief Represents a Ordered int set structure.
 */
typedef struct orderedIntSet {
    // pointer to a doubly linked list
    doubleLinkedList* list;
    // count of the number of elements in the set
    int count;
} orderedIntSet;

/**
 * @brief Creates an empty ordered set.
 *creates an empty ordered set where the no of elements is set to 0.
 * 
 * @return A pointer to the newly created ordered set.
 */
orderedIntSet* createOrderedSet() {
    orderedIntSet* set = (orderedIntSet*)malloc(sizeof(orderedIntSet)) ; // allocates memory for the set
    set->list = createDoubleLinkedList(); // initialising an empty set
    int count = 0;
    return set;


 /**
 * @brief Deletes an ordered set and frees its memory.
 * the function deletes all the elements in the ordered set from the memory.
 * @param set A pointer to the ordered set to be deleted.
 *
 */
}
void deleteOrderedSet(orderedIntSet* set) {
    Node* current = set->list->head; // setting the current node to the head node
    while (current) {
        Node* temp = current;// creating  a temp node to store the current value for deletion
        current = current->next; 
        free(temp);// free thememory for the  temp node

    }
    free(set->list);// free the memory for the linked list
    free(set); // free the memory for the set
    


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
        addElement(s3, getData(s1curr));
        s1curr = s1curr->next;
    }

    // Add elements from s2 that are not already in s3
    Node* s2curr = s2->list->head;
    while (s2curr != NULL) {
        addElement(s3, getData(s2curr));
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
            if(s1curr == s2curr){
                hasSameEle = 1;
            }
            s1curr = s1curr->next;
        }
        if (!hasSameEle){
            addElement(s3, getData(s2curr));
        }
        s2curr = s2curr->next;
    }
    
    return s3;
}