#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
//this is to delete the node that is currently being used, i.e the currentnode and then point the right pointer to one another
void deletecurr(Node** head, Node* current) {
    if (*head == NULL) {
        printf("The list is already empty.\n");
        return;
    } 

    if (current == NULL) {
        printf("Nothing to delete :( ");
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
//insertbefore(newdata) so you will add a newnode in the position before the position of the current node
//essentially if the position of the currentnode is 3 i have to insert the newbode at 2
//always have to remember that for linked list it starts at 1 instead of 0
void insertbeforecurr(Node** head, int newData, int currpos) {
    Node* newNode;
    if (currpos < 1) {
        printf("not allowed");
        return;
    }
   // int newpos;
    if (currpos == 1) { //this is for when the data that the current pointer is pointing to is the head i.e 1
        newNode = createNode(newData);
        newNode->next = *head;
        newNode->prev = NULL;

        if (*head != NULL) {
            (*head)->prev = newNode;


        }
        *head = newNode;
        printf("at the head\n");
        return;
    }
        //Node* newNode = createNode(newData);
        Node* temp = *head;
        for (int i = 1; temp != NULL && i < currpos; i++) { //it stops right bfore currpos ie if currpos is 3 it stops at 2 and adds the new node
            temp = temp->next;
        }
        if (temp == NULL) {
            printf(
                "Position greater than the number of nodes.\n");
            return;
        }
        newNode = createNode(newData);
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev != NULL) { //ie if the there is nothing before the temp
            temp->prev->next = newNode;
        }
       /* else {
            *head = newNode;
        }*/
        temp->prev = newNode; 
}

void displayList(Node* head) {
        Node* temp = head;
        printf("Doubly Linked List: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
 }

int main() {
    Node* head = NULL;

    // Create a sample list: 10 <-> 20 <-> 30 <-> 40
    head = createNode(10);
    head->next = createNode(20);
    head->next->prev = head;
    head->next->next = createNode(30);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(40);
    head->next->next->next->prev = head->next->next;

    printf("Initial List:\n");
    displayList(head);
    // this is to see the problem
    printf("\nDeleting node at position 3:\n");
    Node* temp = head->next->next; // Node with data 25
    deletecurr(&head, temp);
    displayList(head);

    // Test insertbeforecur
    printf("\nInserting 25 before position 3:\n");
    insertbeforecurr(&head, 25, 3);
    displayList(head);

    printf("\nInserting 5 at position 1 (head):\n");
    insertbeforecurr(&head, 5, 1);
    displayList(head);

    // Test deletecurr
    printf("\nDeleting node at position 3:\n");
   // Node* temp = head->next->next; // Node with data 25
    deletecurr(&head, temp);
    displayList(head);

    return 0;
}