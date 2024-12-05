#include <stdio.h>
#include <stdlib.h>
#include "data_structures.h"


typedef struct orderedIntSet {
    doubleLinkedList* list;
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

orderedIntSet* setUnion(orderedIntSet* s1, orderedIntSet* s2){
    orderedIntSet* s3 = s1;
    Node* s2curr = s2->list->head;
    while(s2curr != NULL){
        addElement(s3, getData(s2curr));
        s2curr = s2curr->next;
    }
    return s3;
}

orderedIntSet* setDifference(orderedIntSet* s1, orderedIntSet* s2){
    orderedIntSet* s3 = createOrderedSet();
    Node* s1curr = s1->list->head;
    Node* s2curr = s2->list->head;
    while(s2curr != NULL){
        int hasSame = 0;
        while (s1curr != NULL){
            if(s1curr == s2curr){
                hasSame = 1;
            }
            s1curr = s1curr->next;
        }
        if (!hasSame){
            addElement(s3, getData(s2curr));
        }
        s2curr = s2curr->next;
    }
    return s3;
}