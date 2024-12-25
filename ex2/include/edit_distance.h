#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H

/**
* @brief Calculates the edit distance between two strings s1 and s2
*
* @param s1 Pointer to the source string
* @param s2 Pointer to the target string
*
* @return Int value of edit distance between the two strings
*/
int edit_distance(const char *s1, const char *s2);

/**
* @brief Wrapper function to calculate the minimum edit distance between two strings s1 and s2 using dynamic programming
*
* This function initializes the required memoization matrix, calls the recursive function 
* to compute the edit distance, and ensures proper memory management
* 
* @param s1 Pointer to the source string
* @param s2 Pointer to the target string
*
* @return Int value of edit distance between the two strings
*/
int edit_distance_dyn(const char *s1, const char *s2);

#endif //EDIT_DISTANCE_H