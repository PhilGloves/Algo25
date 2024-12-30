#ifndef COMPARATOR_H
#define COMPARATOR_H

/**
* @brief Compare the String field of two records
*
* @param a Pointer to the first record
* @param b Pointer to the second record
*
* @return -1 if a is less than b, 0 if a is equal to b, 1 if a is greater than b

* @note strcmp() is used for the comparison
*/
int str_compare(const void *a, const void *b);

/**
* @brief Compare the Int field of two records
*
* @param a Pointer to the first record
* @param b Pointer to the second record
*
* @return -1 if a is less than b, 0 if a is equal to b, 1 if a is greater than b
*/
int int_compare(const void *a, const void *b);

/**
* @brief Compare the Double field of two records
*
* @param a Pointer to the first record
* @param b Pointer to the second record
*
* @return -1 if a is less than b, 0 if a is equal to b, 1 if a is greater than b
*/
int double_compare(const void *a, const void *b);

#endif //COMPARATOR_H
