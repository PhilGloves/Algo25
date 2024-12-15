#include "edit_distance.h"

char *rest(const char *string);

int edit_distance(const char *s1, const char* s2){
    int d_no_op;
    if(strlen(s1) == 0){
        return strlen(s2);
    } else if(strlen(s2) == 0){
        return strlen(s1);
    } else{
        if(*s1 == *s2){
            d_no_op = edit_distance(rest(s1), rest(s2));
        } else{
            d_no_op = INT_MAX;
        }
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
}
