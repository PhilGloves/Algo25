#include <stdio.h>
#include "edit_distance.h"

int main(int argc, char *argv[]) {
    const char *s1 = "tassa";
    const char *s2 = "passato";
    int distance = edit_distance_dyn(s1, s2);
    printf("Edit distance between '%s' and '%s' is %d\n", s1, s2, distance);
    return 0;
}
