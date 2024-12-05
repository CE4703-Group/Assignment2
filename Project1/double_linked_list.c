/**
 * @file double_linked_list.c
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
doubleLinkedList* createDoubleLinkedList (){
    
    //< allocate memory for list
    doubleLinkedList* list = ( doubleLinkedList*)malloc(sizeof( doubleLinkedList));
    
    //< allocates memory for head & tail nodes
     //Node *node = (Node *)malloc(sizeof(Node)); 
 /*   struct Node *tailNode = (Node *)malloc(sizeof(Node));*/
    

    //< initalise head & tail nodes
    //headNode -> prev = NULL; // value before head = NULL
    //headNode -> next = tailNode; // creates headNode <-> tailNode

    //tailNode -> prev = headNode; // value before tailNode points to head
    //tailNode -> next = NULL; // sets node after tail to 0

    list -> head = NULL; // links head to its node
    list -> tail = NULL; // links tail to its node
    list->current = NULL;

    return list; 
}



/**
 * @brief 
 * funvtion to delete the doubly linked list starting from the head and the memory allocated for each node is then freed. 
 * 
 *
 * @param  head  a double pointer to the head node of the doubly linked list.
 */
doubleLinkedList* deleteDoubleLinkedList (Node** head){
    Node* temp = *head; //creates a node for the head
    *head = (*head)->next;  // head becomes the value after the original value

    if (*head != NULL){
        (*head) -> prev = NULL; 
    }
    free(temp); 
}

/**
 * @brief Retrieves the data associated with current node.
 *
 * This function gets data associated with current node and returns its value.
 *
 * @param list A pointer to the double linked list where data of current node is to be retrieved.
 * @return The data stored in the node.
 */
int getData(doubleLinkedList* list) {
    return list -> current -> data;
}

/**
 * @brief Sets current node to the successor of current.
 *
 * This function checks if the `next` pointer of the given node is `NULL`. If it is `NULL`, 
 * it returns the current node. Otherwise, it sets current node to the successor of current.
 *
 * @param list A pointer to the doubly linked list structure.
 * @return A pointer to the next node, or the current node if no next node exists.
 */
void gotoNextNode(doubleLinkedList* list){
    if(list->current->next != NULL){
        list->current = list->current->next;
    }
}

/**
 * @brief Sets current node to the predeccessor of current.
 *
 * This function checks if the `prev` pointer of the given node is `NULL`. If it is `NULL`,
 * it returns the current node. Otherwise, it sets current node to the predeccessor of current.
 * 
 * @param list A pointer to the doubly linked list structure.
 * @return A pointer to the prev node, or the current node if no prev node exists.
 */

void gotoPreviousNode(doubleLinkedList* list) {
    if(list->current->prev != NULL){
        list->current = list->current->prev;
    }
}

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
void gotoHead(doubleLinkedList* list) {
    if (list == NULL || list->head == NULL) { 
        // Check if list or tail doesn't exist
        printf("List or head doesn't exist.\n");
        return;
    }else{
        // Set current node to tail
        list->current = list->head;
        printf("Current node set to head.\n");
    }
}

// Function to set the current node to the tail

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
void gotoTail(doubleLinkedList* list) {
    // Precondition check
    if (list == NULL || list->tail == NULL) { // Check if list or tail doesn't exist
        printf("List or tail doesn't exist.\n");
    }else{
        // Set current node to tail
        list->current = list->tail;
        printf("Current node set to tail.\n");
    }
    
}

// Function to insert a node after the current node
/**
 * @brief Inserts a new node after the current node in the list.
 *
 * @param[in, out] list Pointer to the doubly linked list.
 * @param[in] data Data to insert into the new node.
 */
 /**
  * @brief Moves the current pointer to the tail of the list.
  *
  * @param[in, out] list Pointer to the doubly linked list.
  */
void insertAfter(doubleLinkedList* list, int newdata) {
    // Precondition check
    if (list == NULL || list->current == NULL) { // Check if list and current node exist
        printf("Valid double linked list or current node does not exist.\n");
        return;
    }

    // Create a new node
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory
    if (newNode == NULL) { // Check if memory allocation is successful
        printf("Error: Memory allocation failed for new node.\n");
        return;
    }

    // Initialize the new node
    newNode->data = newdata;  // Set the data to the new node
    newNode->next = NULL;     // Set the next pointer to NULL (updated later)
    newNode->prev = NULL;     // Set the prev pointer to NULL (updated later)

    // Node creation and initialization is complete
    printf("New node created and initialized with data: %d\n", newdata);

    // Insert the new node into the list
    if (list->current == list->tail) { // If the current node is the tail
        list->current->next = newNode; // Link current node to the new node
        newNode->prev = list->current; // Link new node back to the current node
        list->tail = newNode;          // Update the list's tail pointer
    }
    else { // If the current node is not the tail
        newNode->next = list->current->next; // Link the new node to the node after the current node
        newNode->prev = list->current;       // Link the new node back to the current node
        list->current->next->prev = newNode; // Update the next node's prev pointer
        list->current->next = newNode;       // Update the current node's next pointer
    }

    // Success message
    printf("New node with data %d inserted after the current node.\n", newdata);
}

/**
 * @brief Deletes the current node from the doubly linked list.
 *
 * @param[in, out] head Pointer to the head of the list.
 * @param[in] current Pointer to the current node to delete.
 */

//this is to delete the node that is currently being used, i.e the currentnode and then point the right pointer to one another
void deletecurr(Node** head, Node* current) {
    if (*head == NULL) {
        printf("The list is already empty.\n");
        return;
    } 

    if (current->prev != NULL) {
        //printf("not deleting head or tail node \n");
        current->prev->next = current->next;
        //return;
    }
    else {
        *head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);

    printf("current deleted \n");

   
}

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
void insertbeforecurr(Node** head, int newData, int currpos) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory
    if (currpos < 1) {
        printf("not allowed");
        return;
    }
   // int newpos;
    if (currpos == 1) { //this is for when the data that the current pointer is pointing to is the head i.e 1
        newNode->data = newData;
        newNode->next = *head;
        newNode->prev = NULL;

        if (*head != NULL) {
            (*head)->prev = newNode;


        }
        *head = newNode;
        printf("at the head\n");
        return;
    }
        Node* temp = *head;
        for (int i = 1; temp != NULL && i < currpos; i++) { //it stops right bfore currpos ie if currpos is 3 it stops at 2 and adds the new node
            temp = temp->next;
        }
        if (temp == NULL) {
            printf(
                "Position greater than the number of nodes.\n");
            return;
        }
        newNode->data = newData;
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev != NULL) { //ie if the there is nothing before the temp
            temp->prev->next = newNode;
        }
        temp->prev = newNode; 
}

/**
 * @brief Displays the data in the doubly linked list. FOR TESTING
 *
 * @param[in] head Pointer to the head of the list.
 */
void displayList(Node* head) {
        Node* temp = head;
        printf("Doubly Linked List: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
 }

