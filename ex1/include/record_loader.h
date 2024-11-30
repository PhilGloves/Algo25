#ifndef RECORD_LOADER_H
#define RECORD_LOADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define RECORD_READ_LIMIT 5000000
//#define RECORD_READ_LIMIT INT_MAX

typedef struct {
  int id;
  char *char_field;
  int int_field;
  double double_field;
} record;

record **load_file(FILE *infile, long *record_count);

void write_sorted_record(FILE *outfile, record **sorted_records, long record_count);

void free_records(record **record, long record_count);

record *create_record(int id, char *char_field, int int_field, double double_field);

#endif //RECORD_LOADER_H
