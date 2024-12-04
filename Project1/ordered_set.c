#include <stdio.h>
#include <stdlib.h>
#include "data_structures.h"


typedef struct orderedIntSet {
    doubleLinkedList* list;
    int count;
} orderedIntSet;


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