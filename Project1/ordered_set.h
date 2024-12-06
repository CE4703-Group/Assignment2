/**
 * @file ordered_set.h
 * 
 * @authors 
 * - Aia Al Mansori (23358904)
 * - Anaswara Johnson (23287322)
 * - Aishat Yusuff (23362146)
 * - Maya Niessen (23391731)
 * - Xuyang Tan (24168033)
 */

#ifndef ORDERED_SET_H
#define ORDERED_SET_H
#include "double_linked_list.h"


// Ordered int set structure
/**
 * @struct orderedIntSet
 * @brief Represents a Ordered int set structure.
 */
typedef struct orderedIntSet {
    // pointer to a doubly linked list
    doubleLinkedList* list;
    // count of the number of elements in the set
    int count;
} orderedIntSet;


/**
 * @brief Creates an empty ordered set.
 *creates an empty ordered set where the no of elements is set to 0.
 * 
 * @return A pointer to the newly created ordered set.
 */
orderedIntSet* createOrderedSet();

 /**
 * @brief Deletes an ordered set and frees its memory.
 * the function deletes all the elements in the ordered set from the memory.
 * @param set A pointer to the ordered set to be deleted.
 *
 */
void deleteOrderedSet(orderedIntSet* set);

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
int addElement(orderedIntSet* set, int elem);

/**
 * @brief Computes the intersection of two ordered sets.
 *
 * This function creates a new set that contains the intersection of the two given sets `s1` and `s2`.
 * The intersection set includes only the elements that are present in both `s1` and `s2`.
 * Neither `s1` nor `s2` is modified during this operation.
 *
 * @param[in] s1 Pointer to the first ordered set.
 * @param[in] s2 Pointer to the second ordered set.
 * @return intSet* Pointer to the newly created set containing the intersection of `s1` and `s2`.
 * Returns `NULL` if memory allocation fails during the operation.
 */
orderedIntSet* setIntersection(orderedIntSet* s1, orderedIntSet* s2);

/**
 * @brief Removes an element from the ordered set.
 *
 * This function searches for an element in the ordered set and removes it if found.
 * If the element is not present, it returns an appropriate message.
 *
 * @param s Pointer to the ordered set.
 * @param elem The element to be removed.
 * @return A string indicating whether the element was removed or not found in the set.
 */
char* removeElement(orderedIntSet* s, int elem);

/**
 * @brief Computes the union of two ordered integer sets.
 *
 * This function takes two ordered integer sets (`s1` and `s2`) and returns a new set
 * that represents the union of the two sets. The union includes all elements from
 * both sets without duplicates.
 *
 * @param[in] s1 Pointer to the first ordered integer set.
 * @param[in] s2 Pointer to the second ordered integer set.
 * @return Pointer to an ordered integer set representing the union of `s1` and `s2`.
 *
 * @note The function modifies will not modify 's1' or 's2' when computing the union set
 */
orderedIntSet* setUnion(orderedIntSet* s1, orderedIntSet* s2);

/**
 * @brief Computes the difference of two ordered integer sets.
 *
 * This function takes two ordered integer sets (`s1` and `s2`) and returns a new set
 * that contains elements present in `s1` but not in `s2`.
 *
 * @param[in] s1 Pointer to the first ordered integer set.
 * @param[in] s2 Pointer to the second ordered integer set.
 * @return Pointer to an ordered integer set representing the difference (`s1 - s2`).
 *
 * @note The function creates a new set (`s3`) to store the result, so `s1` and `s2` remain
 *       unmodified.
 */
orderedIntSet* setDifference(orderedIntSet* s1, orderedIntSet* s2);

/**
 * @brief Prints the elements of the ordered set to standard output.
 *
 * This function iterates through the ordered set and prints all the elements
 * in the set. If the set is empty, it prints an empty set representation (`{}`).
 *
 * The elements are displayed in order, separated by commas.
 *
 * @param s Pointer to the ordered set.
 */

void printToStdout(orderedIntSet* s);

#endif
