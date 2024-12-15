#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H

/**
* @brief Calculates the edit distance between two strings s1 and s2
*
* @param s1 pointer to the source string.
* @param s2 pointer to the target string.
*
* @return int value of edit distance between the two strings
*/
int edit_distance(const char *s1, const char *s2);

/**
* @brief Calculates the minimum edit distance between two strings s1 and s2 using dynamic programming
*
* @param s1 pointer to the source string.
* @param s2 pointer to the target string.
*
* @return int value of edit distance between the two strings
*/
int edit_distance_dyn(const char *s1, const char *s2);

#endif //EDIT_DISTANCE_H
