#ifndef RECORD_LOADER_H
#define RECORD_LOADER_H

#include "limits.h"

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

#endif //RECORD_LOADER_H
