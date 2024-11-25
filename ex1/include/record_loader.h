#ifndef RECORD_LOADER_H
#define RECORD_LOADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define RECORD_READ_LIMIT 1000
//#define RECORD_READ_LIMIT INT_MAX

#define RECORD_COUNTER 0

typedef struct {
  int id;
  char *char_field;
  int int_field;
  double double_field;
} record;

void **load_file(FILE *infile);

void write_sorted_record(void **records, FILE *outfile);

void free_records(record **record);

void *create_record(int id, char *char_field, int int_field, double double_field);



#endif //RECORD_LOADER_H
