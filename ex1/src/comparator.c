#include <string.h>
#include <stdlib.h>

int str_compare(const void *a, const void *b) {
  char *x = ((record *)a)->char_field;
  char *y = ((record *)b)->char_field;
  return strcmp(x, y);
}

int int_compare(const void *a, const void *b) {
  int x = ((record *)a)->int_field;
  int y = ((record *)b)->int_field;
  return x>y ? 1 : x<y ? -1 : 0;
}

int float_compare(const void *a, const void *b) {
  float x = ((record *)a)->float_field;
  float y = ((record *)b)->float_field;
  return x>y ? 1 : x<y ? -1 : 0;
}