#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "edit_distance.h"

const char *rest(const char *string) {
    return string + 1;
}
int edit_distance(const char *s1, const char* s2){
    if (s1 == NULL || s2 == NULL) return -1;

    int len1 = strlen(s1), len2 = strlen(s2);
    if (len1 == 0) return len2;
    if (len2 == 0) return len1;

    int d_no_op = INT_MAX;;
    if(*s1 == *s2)
            d_no_op = edit_distance(rest(s1), rest(s2));
            
    int d_canc = 1 + edit_distance(s1, rest(s2));
    int d_ins = 1 + edit_distance(rest(s1), s2);

    if (d_canc < d_ins && d_canc < d_no_op) {
        return d_canc;
        } else if (d_ins < d_no_op) {
        return d_ins;
        } else {
        return d_no_op;
        }
}

int recursive_edit_distance_dyn(const char *s1, const char *s2, int len1, int len2, int **cost_matrix){
    if (cost_matrix[len1][len2] != -1) {
        return cost_matrix[len1][len2];
    }

    if (len1 == 0) {
        cost_matrix[len1][len2] = len2;
        return len2;
    } else if (len2 == 0) {
        cost_matrix[len1][len2] = len1;
        return len1;
    }

    int d_no_op;
    if (*s1 == *s2) {
        d_no_op = recursive_edit_distance_dyn(rest(s1), rest(s2), len1 - 1, len2 - 1, cost_matrix);
    } else {
        d_no_op = INT_MAX;
    }

    int d_canc = 1 + recursive_edit_distance_dyn(s1, rest(s2), len1, len2 - 1, cost_matrix);
    int d_ins = 1 + recursive_edit_distance_dyn(rest(s1), s2, len1 - 1, len2, cost_matrix);

    int result = (d_canc < d_ins && d_canc < d_no_op) ? d_canc :
                 (d_ins < d_no_op) ? d_ins : d_no_op;

    cost_matrix[len1][len2] = result;
    return result;
}

int edit_distance_dyn(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    int **cost_matrix = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        cost_matrix[i] = (int *)malloc((len2 + 1) * sizeof(int));
        for (int j = 0; j <= len2; j++) {
            cost_matrix[i][j] = -1;
        }
    }
    
    int distance = recursive_edit_distance_dyn(s1, s2, len1, len2, cost_matrix);
    
    for (int i = 0; i <= len1; i++) {
        free(cost_matrix[i]);
    }
    free(cost_matrix);
    
    return distance;
}