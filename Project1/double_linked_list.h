/**
 * @file double_linked_list.h
 * 
 * @authors 
 * - Aia Al Mansori (23358904)
 * - Anaswara Johnson (23287322)
 * - Aishat Yusuff (23362146)
 * - Maya Niessen (23391731)
 * - Xuyang Tan (24168033)
 */

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H


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
doubleLinkedList* createDoubleLinkedList ();

/**
 * @brief 
 * funvtion to delete the doubly linked list starting from the head and the memory allocated for each node is then freed. 
 * 
 *
 * @param  head  a double pointer to the head node of the doubly linked list.
 */
void deleteDoubleLinkedList (Node** head);

/**
 * @brief Retrieves the data associated with current node.
 *
 * This function gets data associated with current node and returns its value.
 *
 * @param list A pointer to the double linked list where data of current node is to be retrieved.
 * @return The data stored in the node.
 */
int getData(doubleLinkedList* list);

/**
 * @brief Sets current node to the successor of current.
 *
 * This function checks if the `next` pointer of the given node is `NULL`. If it is `NULL`, 
 * it returns the current node. Otherwise, it sets current node to the successor of current.
 *
 * @param list A pointer to the doubly linked list structure.
 */

void gotoNextNode(doubleLinkedList* list);

/**
 * @brief Sets current node to the predeccessor of current.
 *
 * This function checks if the `prev` pointer of the given node is `NULL`. If it is `NULL`,
 * it returns the current node. Otherwise, it sets current node to the predeccessor of current.
 * 
 * @param list A pointer to the doubly linked list structure.
 */

void gotoPreviousNode(doubleLinkedList* list);

/**
 * @brief Moves the current pointer of a doubly linked list to the head node.
 *
 * This function sets the `current` pointer of the provided doubly linked list
 * to the `head` node. If the list or its head is `NULL`, it prints an error message
 * and does not modify the `current` pointer.
 *
 * @param list A pointer to the doubly linked list structure.
 *
 * @note The function assumes that the `doubleLinkedList` structure contains
 *       at least the following fields:
 *       - `head`: A pointer to the last node in the list.
 *       - `current`: A pointer to the current node in the list.
 * 
 * @pre The `list` and `list->head` must not be `NULL`.
 * @post If the preconditions are met, `list->current` will point to `list->head`.
 */
void gotoHead(doubleLinkedList* list);

/**
 * @brief Moves the current pointer of a doubly linked list to the tail node.
 *
 * This function sets the `current` pointer of the provided doubly linked list
 * to the `tail` node. If the list or its tail is `NULL`, it prints an error message
 * and does not modify the `current` pointer.
 *
 * @param list A pointer to the doubly linked list structure.
 *
 * @note The function assumes that the `doubleLinkedList` structure contains
 *       at least the following fields:
 *       - `tail`: A pointer to the last node in the list.
 *       - `current`: A pointer to the current node in the list.
 * 
 * @pre The `list` and `list->tail` must not be `NULL`.
 * @post If the preconditions are met, `list->current` will point to `list->tail`.
 */
void gotoTail(doubleLinkedList* list);

// Function to insert a node after the current node
/**
 * @brief Inserts a new node after the current node in the list.
 *
 * @param[in, out] list Pointer to the doubly linked list.
 * @param[in] newdata Data to insert into the new node.
 */
void insertAfter(doubleLinkedList* list, int newdata);

/**
 * @brief Deletes the current node from the doubly linked list.
 *
 * @param[in, out] head Pointer to the head of the list.
 * @param[in] current Pointer to the current node to delete.
 */

//this is to delete the node that is currently being used, i.e the currentnode and then point the right pointer to one another
void deletecurr(Node** head, Node* current);

/**
 * @brief Inserts a new node with the specified data before the given position in the list.
 *
 * @param[in, out] head Pointer to the head of the list.
 * @param[in] newData The data for the new node.
 * @param[in] currpos The position before which to insert the new node.
 */
//insertbefore(newdata) so you will add a newnode in the position before the position of the current node
//essentially if the position of the currentnode is 3 i have to insert the newbode at 2
//always have to remember that for linked list it starts at 1 instead of 0
void insertbeforecurr(Node** head, int newData, int currpos); 

/**
 * @brief Displays the data in the doubly linked list. FOR TESTING
 *
 * @param[in] head Pointer to the head of the list.
 */
void displayList(Node* head);
#endif
