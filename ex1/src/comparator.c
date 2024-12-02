#include <string.h>

#include "comparator.h"
#include "record_loader.h"

int str_compare(const void *a, const void *b) {
  char *x = ((Record *)a)->char_field;
  char *y = ((Record *)b)->char_field;
  return strcmp(x, y);
}

int int_compare(const void *a, const void *b) {
  int x = ((Record *)a)->int_field;
  int y = ((Record *)b)->int_field;
  return x>y ? 1 : x<y ? -1 : 0;
}

int double_compare(const void *a, const void *b) {
  double x = ((Record *)a)->double_field;
  double y = ((Record *)b)->double_field;
  return x>y ? 1 : x<y ? -1 : 0;
}