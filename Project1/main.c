/**
 * @file main.c
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

// /**
//  * @brief defines the structure of the array created 
//  */

// typedef struct {
//     int* elements; // pointer to dynamic array holding the elements 
// } Set;

/**
 * @brief checks if input is valid and returns the valid input
 */
int checkInput(int min, int max){

    int choice = 0;
    bool valid = false;

    printf("Input a value from %d to %d:", min, max);
    scanf("%d", &choice);

    while(!valid){
        if(choice <= max && choice >= min ){
            valid = true; //stops loop if the input is valid
        } else{
            printf("Input is invalid, please enter a number from %d to %d:", min, max); //goes back to loop if input is invalid
            scanf("%d", &choice);
        }
    }
    return choice; 
}

/**
 * @brief checks if input is a negative number
 */
bool checkNegative(int x){

    bool negative = NULL;

    if(x < 0){
        negative = true;
    } else {
        negative = false; 
    }

    return negative; 
}


/**
 * @mainpage Assignment 2
 * 
 * @section intro_sec Introduction
 *
 * This project implements an **Ordered Set** data structure using a doubly linked list.
 * The program allows users to create, delete, and manipulate ordered sets interactively via a menu-driven interface. 
 * The ordered set supports fundamental set operations such as **union**, **intersection**, and **difference**, 
 * while maintaining the order of elements and preventing duplicates.
 *
 * The program is divided into three core parts:
 * - **Double Linked List**: Provides the implementation of a doubly linked list.
 * - **Ordered Set**: Defines the ordered set structure and associated set operations.
 * - **Main**: Provides a user interface for interacting with the program and performing set operations.
 *
 * @section features_sec Features
 *
 * The project supports the following features:
 * 1. **Create Ordered Sets**: Initialize new ordered sets at specified indices.
 * 2. **Delete Ordered Sets**: Remove ordered sets from memory.
 * 3. **Add Elements**: Insert elements into an ordered set while maintaining order and ensuring uniqueness.
 * 4. **Remove Elements**: Delete elements from an ordered set.
 * 5. **Set Operations**:
 *    - **Intersection**: Compute the intersection of two sets and store the result in a new set.
 *    - **Union**: Compute the union of two sets and store the result in a new set.
 *    - **Difference**: Compute the difference between two sets and store the result in a new set.
 * 6. **Dynamic Menu-Driven Interface**: Guides users through available options and ensures valid input.
 *
 * @section usage_sec Usage
 *
 * Upon running the program, the user is presented with a menu offering the following options:
 * - **Option 1**: Create an empty ordered set.
 * - **Option 2**: Delete an ordered set.
 * - **Option 3**: Add elements to an ordered set.
 * - **Option 4**: Remove elements from an ordered set.
 * - **Option 5**: Compute the intersection of two ordered sets.
 * - **Option 6**: Compute the union of two ordered sets.
 * - **Option 7**: Compute the difference between two ordered sets.
 * - **Option 8**: Terminate the program.
 *
 * Each option prompts the user for additional input as needed (e.g., indices of sets, values to add or remove).
 *
 * @section dependencies_sec Dependencies
 *
 * The project relies on the following files:
 * - **double_linked_list.h/c**: Defines and implements the doubly linked list structure and associated operations.
 * - **ordered_set.h/c**: Defines and implements the ordered set structure and associated operations.
 * - **main.c**: Provides the user interface and coordinates interactions between the modules.
 *
 * @section data_structures_sec Core Data Structures
 *
 * 1. **Node**:
 *    - Represents an individual element in the doubly linked list.
 *    - Contains pointers to the previous and next nodes.
 * 2. **doubleLinkedList**:
 *    - Represents the doubly linked list used as the underlying data structure for ordered sets.
 *    - Maintains pointers to the head, tail, and current node.
 * 3. **orderedIntSet**:
 *    - Represents the ordered set.
 *    - Contains a pointer to a doubly linked list and a count of elements.
 *
 * @section authors_sec Authors
 * - Aia Al Mansori (23358904)
 * - Anaswara Johnson (23287322)
 * - Aishat Yusuff (23362146)
 * - Maya Niessen (23391731)
 * - Xuyang Tan (24168033)
 */

int main(){
    
    orderedIntSet* setsArray[10]; //initilaise all pointers to NULL
    int choice = 0;

    while(choice != 8){
        printf("Enter 1 to CREATE an empty Ordered Set \n");
        printf("Enter 2 to DELETE an Ordered Set \n");
        printf("Enter 3 to ADD elements to an Ordered Set \n");
        printf("Enter 4 to REMOVE Elements from an Ordered Set \n ");
        printf("Enter 5 to Set INTERSECTION \n");
        printf("Enter 6 to set UNION \n");
        printf("Enter 7 to Set DIFFERENCE \n") ;
        printf("Enter 8 to TERMINATE program \n");

        printf("Choose an option: \n");

        scanf("%d", &choice);
    

        switch(choice){
            case 1:{
            /**
             * @brief creates an ordered set
             * @details 
             * option prompts user to enter the index for the new array in SetsArray
             */
                int x = 0;
                printf("Choose position for the new set (0 to 9): ");
                x = checkInput(0, 9);

                if (setsArray[x] != NULL) {
                    printf("Set already exists at index %d. Please delete it first.\n", x);
                } else {
                    setsArray[x] = createOrderedSet();
                    printf("Created an empty set at index %d.\n", x);
                }
                break;
            }

            case 2:{
            /**
             * @brief deletes an ordered set
             * @details 
             * prompts user to enter the index of the set in SetsArray that is to be deleted
             * 
             */

                int x = 0;
                printf("Choose position of the set you want to delete (0 to 9): ");
                x = checkInput(0, 9);

                if (setsArray[x] == NULL) {
                    printf("No set exists at index %d.\n", x);
                } else {
                    deleteOrderedSet(setsArray[x]);
                    setsArray[x] = NULL;
                    printf("Deleted set at index %d.\n", x);
                }
                break;
            }
            
            case 3:{
            /**
             * @brief add elements to ordered set
             * @details 
             * takes input and adds to set using addElement()
             * If a negative number is enetered, it stops input process
             * For each number, it will report wether addElement() returned NUMBER_ADDED or NUMBER_ALREADY_IN_SET.
             * At the end, this function will print resulting set.
             * 
             */

                bool negative = false; //set to true if input is negative
                int elem = 0; // input value
                int s; //variable that holds the index of set 
                int add; // variable that stores if the value was added or was already in the set
                bool addValid = false; 

                printf("Choose the set you want to add the value to: ");
                scanf("%d", &s);
                s = checkInput(0,9); //checks if index of set is within range

            while (negative == false){
                printf("Choose the value you want to add or if you want to terminate process enter a negative value: ");
                scanf("%d", &elem);
                negative = checkNegative(elem); // set to true if the input was negative

                if (negative == true){
                    break;
                } else {

                    while(addValid == negative){
                        add = addElement(setsArray[s]->list->head, elem); //returns if element was added or was akready in set

                        if(add == 2){
                            printf("Number added to set!");
                            addValid = true; 

                        } else if(add == 0){
                            printf("Number already in set. Choose a different value.");
                        }

                    }
                        
                }
            }
            printToStdout(setsArray[s]); 
            break;
        }
            
        case 4:{
            /**
             * @brief removes elements from ordered set
             * @details 
             * Takes input and deletes teh value from the set using removeElement().
             * If the input is negative, the process is terminated.
             * For each input, it's reported wether if the input value was removed or wether it is not in the set.
             * Then prints the resulting set. 
            */
            
            bool negative = false; //set to true if input is negative
            int elem = 0; // input value
            int s; //variable that holds the index of set 
            int del; // variable that stores if the value was added or was already in the set
            bool delValid = false; 

            printf("Choose the set you want to delete the value from: ");
            scanf("%d", &s);
            s = checkInput(0,9); //checks if index of set is within range

            printf("Choose the set you want to remove the value from. \n");
            s = checkInput(0,9); //checks if index of set is within range

            if (negative == true){
                break;

            } else {
                while(delValid == negative){
                    removeElement(setsArray[s],elem); //returns if element was added or was akready in set
                    // if(del == 3){
                    //     printf("Number added to set!");
                    //     delValid = true; 

                    // } else if(del == 0){
                    //     printf("Number already in set. Choose a different value.");
                    // }

                }
            }
                        
            
            printToStdout(setsArray[s]); 
            break;

        }
        
        case 5:{
            /**
             * @brief sets intersection
             * @details
             * prompts user to enter three indices for three sets in SetsArray
             * Then calls setIntersection(s1,s2) to obtain the intersection.
             * Stores the result into s3.
             * Then prints s3.
             */

            int s1,s2,s3;
            bool notUsed; 

            for(int i= 0; i < 3; i++){
                printf("Choose set %d \n", (i+1));
                
                
                if(i == 0){
                    s1 = checkInput(0,9); //checks if index is within range

                } else if (i == 1){

                    notUsed = false;

                    while (notUsed == false){

                        s2 = checkInput(0,9); //sets index of set 2

                        if( s1 == s2){
                            printf("Set has already been selected, choose another."); //if s1 and s2 are the same, goes back to loop
                        } else {
                            notUsed = true; // if s1 and s2 are different, leaves s2 as is and terminates loop
                        }
                    }      
                } else {
                    notUsed = false; 

                    while (notUsed == false){
                        s3 = checkInput(0,9); // sets index of set 3

                        if(s1 == s3 || s2 == s3) {
                            printf("Set has already been selected, choose another."); // if set is the same as either one of set 2 or 1, loops back
                        } else {
                            notUsed = true; // if s3 isn't s1 or s2, sets notUsed to true
                        }
                    }
                }  
            }
            setsArray[s3] = setIntersection(setsArray[s1],setsArray[s2]); //finds the intersection and stored into s3
            printToStdout(setsArray[s3]);
            break;           
        }
        case 6:{
            /**
             * @brief set union
             * @details 
             * prompts user to enter three indices for three sets in SetsArray.
             * Then calls setIntersection(s1,s2) to obtain the intersection of the two sets.
             * Store the resulting set into s3. 
             * prints the resulting set out
             * 
             */

            int s1,s2,s3;
            bool notUsed; 

            for(int i= 0; i < 3; i++){
                printf("Choose set %d \n", (i+1));
                
                if(i == 0){
                    s1 = checkInput(0,9); //checks if index is within range

                } else if (i == 1){

                    notUsed = false;

                    while (notUsed == false){

                        s2 = checkInput(0,9); //sets index of set 2

                        if( s1 == s2){
                            printf("Set has already been selected, choose another."); //if s1 and s2 are the same, goes back to loop
                        } else {
                            notUsed = true; // if s1 and s2 are different, leaves s2 as is and terminates loop
                        }
                    }      
                } else {
                    notUsed = false; 

                    while (notUsed == false){
                        s3 = checkInput(0,9); // sets index of set 3

                        if(s1 == s3 || s2 == s3) {
                            printf("Set has already been selected, choose another."); // if set is the same as either one of set 2 or 1, loops back
                        } else {
                            notUsed = true; // if s3 isn't s1 or s2, sets notUsed to true
                        }
                    }
                }  
            }
            setsArray[s3] = setUnion(setsArray[s1],setsArray[s2]); //finds the intersection and stored into s3
            printToStdout(setsArray[s3]);

            break;
        }
        
        case 7: {
            /**
             * @brief set difference
             * @details 
             * prompts user to enter three indices for three sets in SetsArray.
             * Then calls setDifference(s1,s2) to obtain the difference of the two sets.
             * Store the resulting set into s3. 
             * prints the resulting set out
             * 
             */

            int s1,s2,s3;
            bool notUsed; 

            for(int i= 0; i < 3; i++){
                printf("Choose set %d \n", (i+1));
                
                if(i == 0){
                    s1 = checkInput(0,9); //checks if index is within range

                } else if (i == 1){

                    notUsed = false;

                    while (notUsed == false){

                        s2 = checkInput(0,9); //sets index of set 2

                        if( s1 == s2){
                            printf("Set has already been selected, choose another."); //if s1 and s2 are the same, goes back to loop
                        } else {
                            notUsed = true; // if s1 and s2 are different, leaves s2 as is and terminates loop
                        }
                    }      
                } else {
                    notUsed = false; 

                    while (notUsed == false){
                        s3 = checkInput(0,9); // sets index of set 3

                        if(s1 == s3 || s2 == s3) {
                            printf("Set has already been selected, choose another."); // if set is the same as either one of set 2 or 1, loops back
                        } else {
                            notUsed = true; // if s3 isn't s1 or s2, sets notUsed to true
                        }
                    }
                }  
            }
            setsArray[s3] = setDifference(setsArray[s1],setsArray[s2]); //finds the intersection and stored into s3
            printToStdout(setsArray[s3]);

            break;
        }
        
        case 8:
            printf("Terminate the program...");
            break;

        default: 
            printf("Invlaid option. Try Again. \n");
            break;
            
        }

            
    }

    return 0;
    
}


// previous test for double linked list

// int main() {
//     // Create a doubly linked list
//     doubleLinkedList* list = createDoubleLinkedList();
//     printf("Doubly linked list created.\n");

//     // Insert nodes into the list
//     Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory
//     if (newNode == NULL) { // Check if memory allocation is successful
//         printf("Error: Memory allocation failed for new node.\n");
//         return;
//     }

//     // Initialize the new node
//     newNode->data = 10;  // Set the data to the new node
//     newNode->next = NULL;     // Set the next pointer to NULL (updated later)
//     newNode->prev = NULL;
//     list->head = newNode;
//     list->current = newNode;
//     list->tail = newNode;
//     printf("Inserting nodes after head.\n");
//     //insertAfter(list, 10);  // Insert 10 after head
//     insertAfter(list, 20);  // Insert 20 after current node
//     list->current = list->current->next;
//     insertAfter(list, 30);  // Insert 30 after current node

//     // Display the list
//     printf("List after inserting nodes:\n");
//     displayList(list->head); // Skip the dummy head node

//     // Move to the tail and display data
//     gotoTail(list);
//     printf("Current node after moving to tail: %d\n", getData(list));

//     // Move to the previous node and display data
//     gotoPreviousNode(list);
//     printf("Current node after moving to previous: %d\n", getData(list));

//     // Move to the next node and display data
//     gotoNextNode(list);
//     printf("Current node after moving to next: %d\n", getData(list));

//     // Delete the current node
//     printf("Deleting current node.\n");
//     deletecurr(&list->head, list->current);
//     displayList(list->head); // Skip the dummy head node

//     // Insert a node before the current position
//     printf("Inserting node with data 25 before current position.\n");
//     insertbeforecurr(&list->head, 25, 2);
//     displayList(list->head); // Skip the dummy head node

//     // Clean up: delete the entire list
//     printf("Deleting the entire list.\n");
//     while (list->head != list->tail) {
//         deletecurr(&list->head, list->head->next); // Delete each node except dummy head and tail
//     }

//     // Free the dummy head and tail nodes
//     free(list->head);
//     free(list->tail);
//     free(list);
//     printf("Doubly linked list deleted.\n");

//     return 0;
// }




