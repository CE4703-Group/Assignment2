#include <stdlib.h>
#include <stdio.h>

#define NUMBER_ADDED 1           /**< Indicates successful addition of an element. */
#define NUMBER_ALREADY_IN_SET 0  /**< Indicates the element already exists in the set. */

/**
 * @brief Structure representing an ordered set implemented as a linked list.
 */
typedef struct {
    struct Node* head;      /**< Pointer to the head of the set. */
} intSet;

/**
 * @brief Adds a new element to an ordered set.
 *
 * This function ensures that the set remains ordered and does not allow duplicate elements.
 * If the element already exists in the set, it is not added again.
 *
 * @param[in,out] s Pointer to the head of the ordered set (linked list).
 * @param[in] elem The element to be added to the set.
 * @return int Returns:
 * - `NUMBER_ADDED` if the element was successfully added.
 * - `NUMBER_ALREADY_IN_SET` if the element already exists in the set.
 * - `-1` if memory allocation for the new node failed.
 */
int addElement(struct Node** s, int elem) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        return -1; // Memory allocation failed
    }
    newNode->data = elem;    // Set the data of the new node
    newNode->next = NULL;    // Initialize the next pointer to NULL

    // Check if the list is empty or 'elem' should be inserted at the head
    if (*s == NULL || (*s)->data > elem) {
        // Check if the element already exists at the head
        if (*s != NULL && (*s)->data == elem) {
            free(newNode); // Free the memory allocated for the duplicate node
            return NUMBER_ALREADY_IN_SET;
        }
        // Insert the new node at the beginning of the list
        newNode->next = *s;
        *s = newNode;
        return NUMBER_ADDED; // Element added successfully
    }

    // Traverse the list to find the correct position for insertion
    struct Node* temp = *s;
    while (temp->next != NULL && temp->next->data < elem) {
        temp = temp->next; // Move to the next node
    }

    // Check if 'elem' already exists in the set
    if (temp->data == elem || (temp->next != NULL && temp->next->data == elem)) {
        free(newNode); // Free the memory allocated for the duplicate node
        return NUMBER_ALREADY_IN_SET;
    }

    // Insert the new node in the correct position
    newNode->next = temp->next; // Link the new node to the next node
    temp->next = newNode;       // Link the current node to the new node
    return NUMBER_ADDED;        // Element added successfully
}


/**
 * @brief Computes the intersection of two ordered sets.
 *
 * Creates a new set containing the intersection of two given ordered sets `s1` and `s2`.
 * The intersection includes only the elements present in both sets.
 * Neither `s1` nor `s2` is modified during this operation.
 *
 * Behavior:
 * - If both sets are empty or have no common elements, the result is an empty set.
 * - If memory allocation fails during the operation, the function returns `NULL`.
 *
 * @param[in] s1 Pointer to the first ordered set (linked list).
 * @param[in] s2 Pointer to the second ordered set (linked list).
 * @return intSet* Pointer to the newly created set containing the intersection of `s1` and `s2`.
 *         - Returns `NULL` if memory allocation fails.
 */
intSet* setIntersection(intSet* s1, intSet* s2) {
    // Create a new set to store the intersection result
    intSet* intersectionSet = (intSet*)malloc(sizeof(intSet));
    if (intersectionSet == NULL) {
        return NULL; // Memory allocation failed
    }
    intersectionSet->head = NULL; // Initialize the head of the new set

    // Pointers to traverse the two sets
    struct Node* ptr1 = s1->head; // Pointer for the first set
    struct Node* ptr2 = s2->head; // Pointer for the second set

    // Traverse both sets simultaneously to find common elements
    while (ptr1 != NULL && ptr2 != NULL) { //ptr1 and 2 is s1 and s2
        if (ptr1->data < ptr2->data) {
            // Move the pointer in the first set 
            ptr1 = ptr1->next;
        }
        else if (ptr1->data > ptr2->data) {
            // Move the pointer in the second set 
            ptr2 = ptr2->next;
        }
        else {
            // if Elements are equal, add to the intersection set
            if (addElement(&(intersectionSet->head), ptr1->data) == -1) {
                // Memory allocation failed while adding an element
                printf("Error: Memory allocation failed while adding an element.\n");
                free(intersectionSet); // Free memory allocated for the intersection set
                return NULL;
            }
            // Move both pointers forward
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    return intersectionSet; // Return the resulting intersection set
}

