#ifndef SORTER_H
#define SORTER_H

#include <stdio.h>
#include "comparator.h"

/**
* @brief Sorts an array using merge sort algorithm
*
* @param base Array to be sorted
* @param nitems Number of elements of the array
* @param compar Pointer to the compare function. This determines which field of the Record is used to sort
*/
void merge_sort(void **base, size_t nitems, int (*compar)(const void*, const void*));

/**
* @brief Sorts an array using quick sort algorithm
*
* @param base Array to be sorted
* @param nitems Number of elements of the array
* @param compar Pointer to the compare function. This determines which field of the Record is used to sort
 */
void quick_sort(void **base, size_t nitems, int (*compar)(const void*, const void*));

/**
* @brief Merges two contiguous array in an orderly manner

* @param leftBase Pointer to the first array
* @param rightBase Pointer to the second array
* @param nitemsLeft Number of elements of the first array
* @param nitemsRight Number of elements of the second array
* @param compar Pointer to the compare function. This determines which field of the Record is used to sort
 */
void merge(void **leftBase, void **rightBase, size_t nitemsLeft, size_t nitemsRight, int (*compar)(const void*, const void*));

/**
* @brief Partitions an array based on a pivot
* -Left partition : elements less than or equal to the pivot
* -Right partition : elements greater than the pivot
*
* @param base Array to be partitioned
* @param nitems Number of elements of the array
* @param compar Pointer to the comparison function, this determines which field of the Record is used to sort
*
* @return Index of the pivot
 */
int partition (void **base, size_t nitems, int (*compar)(const void*, const void*));

/**
* @brief Swaps position of two elements in an array
*
* @param base Array
* @param i Index of the first element
* @param j Index of the second element
 */
void swap(void **base, int i, int j);
#endif //SORTER_H