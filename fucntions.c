#include <stdlib.h>
#include <stdio.h>


//OP 7

//a linked list node
struct Node { //typedef used to 
	int data; //storing data in node
	struct Node* next; //pointer to next node
	struct Node* prev; //pointer to prev node
};

//double linked list 
struct doubleLinkedList {
	struct Node* head; //pointer to head
	struct Node* tail; //pointer to tail 
	struct Node* current // point to current node
};

//function to set current node to tail 
void gotoTail(doubleLinkedList) {
	//pre
	if (list== Null || list -> NULL) { //checks if list or tail no exists
		//set current node to taik 
		printf("List or tail dont exist. \n");
	}
	//post
	list->current = list->tail; //current node set to tail
}




//OP 8

struct Node* newNode{
	int newdata;
	struct Node* head; //pointer to head
	struct Node* tail; //pointer to tail
	struct Node* current // point to current node
};

void insertAfter(struct doubleLinkedList*, int newdata) {
	//pre 
	if (list == NULL || list->current == NULL) { //checks if list and current node exists
		//check if they exist
		printf("Valid double linked lists or new data non existant / invalid. \n");
		return;
	}
	
	//create new node 
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //allocates memeory
	if (newNode == NULL) { //check if allocating memory succesful or not 
		printf("Error: Memory allocation failed for new node.\n");
		return;
	}

	//initialising new code
	newNode->data = newdata; //sets the data to the new node
	newNode->next = NULL;// Set the next pointer to NULL (updated later)
	newNode->prev = NULL;// Set the prev pointer to NULL (updated later)

	// Node creation and initialization is complete
	printf("New node created and initialized with data: %d\n", newdata);

	//putting the new node into list
	if (list->current == list->tail) { //if current node = tail
		list->current->next = newNode; //link current node to the new node
		newNode->prev = list->current; //link new node back to current node
		list->tail = newNode; //update lists tail pointer
	} 
	else { //current node isnt the tail
	newNode->next = list->current->next; //link the new node to the node after the current node
	newNode->orev = list->current; //link the new node back to the current node
	list->current->next->prev = newNode; // Update the next node's prev pointer
	list->current->next = newNode;       // Update the current node's next pointer
	
	}

	//if it works
	printf("New node with data %d inserted after the current node.\n", newdata);

}













