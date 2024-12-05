/**
 * @file testProgram.c
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
#include "functions.c" //> link c file with working functions

/**
 * @brief defines the structure of the array created 
 */

typedef struct {
    int* elements; // pointer to dynamic array holding the elements 
} Set;

/**
 * @brief checks if input is valid and returns the valid input
 */
int checkInput(int min, int max){

    int choice = NULL;
    bool valid = false;
    int tempMin = min--; 
    int tempMax = max++;

    printf("Input: %d", &choice);   

    while(valid == false){
        if(choice < tempMax && choice > tempMin ){
            valid = true; //stops loop if the input is valid
        } else{
            printf("Input is invalid, please enter a number from %d to %d: %d", min, max, &choice); //goes back to loop if input is invalid
        }
    }
    return choice; 
}

/**
 * @brief checks if input is a negative number
 */
bool checkNegative(int x){

    bool negative = NULL:

    if(x < 0){
        negative = true;
    } else {
        negative = false; 
    }

    return negative; 
}


int main(){
    
    Set* SetsArray[10] = {NULL}; //initilaise all pointers to NULL
    int choice;

 

    printf("Enter 1 to CREATE an empty Ordered Set \n");
    printf("Enter 2 to DELETE an Ordered Set \n");
    printf("Enter 3 to ADD elements to an Ordered Set \n");
    printf("Enter 4 to REMOVE Elements from an Ordered Set \n ");
    printf("Enter 5 to Set INTERSECTION \n");
    printf("Enter 6 to set UNION \n");
    printf("Enter 7 to Set DIFFERENCE \n") ;
    printf("Enter 8 to TERMINATE program \n");

    printf("Choose an option \n");
    choice = checkInput(1,8);
    


    switch(choice){
        case 1:{
            /**
             * @brief creates an ordered set
             * @details 
             * option prompts user to enter the index for the new array in SetsArray
             */


            int x = NULL; //input value

            scanf("Choose position for the new set 0 to 9 \n");

            x = checkInput(0,9); //checks validity of input
            
            SetsArray[x] = createOrderedSet(); // creates empty set at specified index
            break;               
        }
        case 2: {
            /**
             * @brief deletes an ordered set
             * @details 
             * prompts user to enter the index of the set in SetsArray that is to be deleted
             * 
             */

            int x = NULL;

            scanf("Choose position of the set you want to delete 0 to 9 \n"); 

            x = checkInput(0,9); 

            SetsArray[x] = deleteOrderedSet(x); //deletes set from array and memory
            break;
        }
        case 3: {
            /**
             * @brief add elements to ordered set
             * @details 
             * takes input and adds to set using addElement()
             * If a negative number is enetered, it stops input process
             * For each number, it will report wether addElement() returned NUMBER_ADDED or NUMBER_ALREADY_IN_SET.
             * At the end, this function will print resulting set.
             * 
             */

            int neagtive = false; //set to true if input is negative
            int elem = NULL; // input value
            int s; //variable that holds the index of set 

            scanf("Choose the set you want to add the value to. \n");
            s = checkInput(0,9); //checks if index of set is within range

            while (negative == false){
                scanf("Choose the value you want to add or if you want to terminate process enter a negative value: %d", &elem);
                neagtive = checkNegative(elem); // set to true if the input was negative

                if (neagtive == true){
                    break;
                } else {
                    addElement(s,elem); //returns if element was added or was akready added
                }
            }
            printToStdout(s); 
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

           int negative = false; //set to treu if element inputted is negative
           int elem = NULL; // element being removed from set
           int s; // idex that specifies the set being dealt with

           scanf("Choose the set you want to remove the value from. \n");
           s = checkInput(0,9); //checks if index of set is within range

           while (negative == false){
               scanf("Choose the value you want to remove from the set and or if you want to terminate process, enter a negative value: %d", &elem);
               negative = checkNegative(elem);

               if(negative == true){
                  break;
               } else {
                  removeElement(s, elem);
               }
           }

           printToStdout(s);
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

                    while (notUsed == fasle){

                        s2 = checkInput(0,9); //sets index of set 2

                        if( s1 == s2){
                            ("Set has already been selected, choose another."); //if s1 and s2 are the same, goes back to loop
                        } else {
                            notUsed == true; // if s1 and s2 are different, leaves s2 as is and terminates loop
                        }
                    }      
                } else {
                    notUsed = false; 

                    while (notUsed == false){
                        s3 = checkInput(0,9); // sets index of set 3

                        if(s1 == s3 || s2 == s3) {
                            ("Set has already been selected, choose another."); // if set is the same as either one of set 2 or 1, loops back
                        } else {
                            notUsed == true; // if s3 isn't s1 or s2, sets notUsed to true
                        }
                    }
                }  
            }
            SetsArray[s3] = setIntersection(s1,s2); //finds the intersection and stored into s3
            // printf() print the resulting set here

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

                    while (notUsed == fasle){

                        s2 = checkInput(0,9); //sets index of set 2

                        if( s1 == s2){
                            ("Set has already been selected, choose another."); //if s1 and s2 are the same, goes back to loop
                        } else {
                            notUsed == true; // if s1 and s2 are different, leaves s2 as is and terminates loop
                        }
                    }      
                } else {
                    notUsed = false; 

                    while (notUsed == false){
                        s3 = checkInput(0,9); // sets index of set 3

                        if(s1 == s3 || s2 == s3) {
                            ("Set has already been selected, choose another."); // if set is the same as either one of set 2 or 1, loops back
                        } else {
                            notUsed == true; // if s3 isn't s1 or s2, sets notUsed to true
                        }
                    }
                }  
            }
            SetsArray[s3] = setUnion(s1,s2); //finds the intersection and stored into s3
            // printf() print the resulting set here

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

                    while (notUsed == fasle){

                        s2 = checkInput(0,9); //sets index of set 2

                        if( s1 == s2){
                            ("Set has already been selected, choose another."); //if s1 and s2 are the same, goes back to loop
                        } else {
                            notUsed == true; // if s1 and s2 are different, leaves s2 as is and terminates loop
                        }
                    }      
                } else {
                    notUsed = false; 

                    while (notUsed == false){
                        s3 = checkInput(0,9); // sets index of set 3

                        if(s1 == s3 || s2 == s3) {
                            ("Set has already been selected, choose another."); // if set is the same as either one of set 2 or 1, loops back
                        } else {
                            notUsed == true; // if s3 isn't s1 or s2, sets notUsed to true
                        }
                    }
                }  
            }
            SetsArray[s3] = setDifference(s1,s2); //finds the intersection and stored into s3
            // printf() print the resulting set here 

            break;
        }
        case 8: {

            printf("Terminating Program ... "); 
            break;
        }
    }

    return 0;
    
}


