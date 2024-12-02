/**
 * @file dll.c
 * 
 * created by Maya Niessen on 29.11.24
 */

#include "dll.h"
#include <stdio.h>
#include<stdlib.h>


/**
 * @brief this defines the structure of the Node
 * 
 * @details node is going to contain a pointer for the previoud and next node in that list
 */
typedef struct Node {
    struct  Node* next; ///< pointer to next node
    struct Node* prev; //< pointer to previous node

} Node; 

//defines the structure of doubly linked list
/**
 * @brief this defines the structure of the Doubly Linked List
 * 
 * @details each Doubly linked list is going to contain a pointer each, to the head & tail of the list
 */
typedef struct DoublyLinkedList {
    struct Node* head; //< pointer to head node
    struct Node* tail;  //< pointer to tail node
} DoublyLinkedList;



/** 
 * @brief this creates an empty list with a head and tail
 * 
 * @details 
 * This going to allocate memory for the following: list, head & tail nodes.
 * It is also going to initialise nodes and link the nodes together 
 * 
 * @return The empty list
 * 
 */
DoublyLinkedList* createDoubleLinkedList (){
    
    //< allocate memory for list
    struct DoublyLinkedList* list = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));
    
    //< allocates memory for head & tail nodes
    struct Node *headNode = (Node *)malloc(sizeof(Node)); 
    struct Node *tailNode = (Node *)malloc(sizeof(Node));
    

    //< initalise head & tail nodes
    headNode -> prev = NULL; // value before head = NULL
    headNode -> next = tailNode; // creates headNode <-> tailNode

    tailNode -> prev = headNode; // value before tailNode points to head
    tailNode -> next = NULL; // sets node after tail to 0

    list -> head = headNode // links head to its node
    list -> tail = tailNode // links tail to its node

    return list; 
}



/**
 * @brief 
 * funvtion to delete the doubly linked list starting from the head and the memory allocated for each node is then freed. 
 * 
 *
 * @param  head  a double pointer to the head node of the doubly linked list.
 */
DoublyLinkedList* deleteDoubleLinkedList (Node** head){
    Node* temp = *head; //creates a node for the head
    *head = (*head)->next;  // head becomes the value after the original value

    if (*head != NULL){
        (*head) -> prev = NULL; 
    }
    free(temp); 
}


