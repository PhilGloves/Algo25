#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "record_loader.h"

record **load_file(FILE *infile, long *record_count) {

  size_t capacity = 10;
  record **records = malloc(capacity * sizeof(void *));

  char buffer[1024];
  const char *sep = ",";
  char *token;
  while (fgets(buffer, sizeof(buffer), infile) && *record_count < RECORD_READ_LIMIT) {
    (*record_count)++;

    if (*record_count > capacity) {
      capacity = (size_t)(capacity * 1.1);
      records = realloc(records, capacity * sizeof(void *));
    }

    token = strtok(buffer, sep);
    int id = atoi(token);

    token = strtok(NULL, sep);
    char *char_field = strdup(token);

    token = strtok(NULL, sep);
    int int_field = atoi(token);

    token = strtok(NULL, sep);
    double double_field = atof(token);

    records[*record_count-1] = create_record(id, char_field, int_field, double_field);
    free(char_field);
  }

  records = realloc(records, *record_count * sizeof(void *));

  printf("Loaded %ld records\n", *record_count);
  return records;
}

void write_sorted_record(FILE *outfile, record **sorted_records, long record_count) {
  for (int i = 0; i < record_count; i++) {
    fprintf(outfile, "%d,%s,%d,%f\n", sorted_records[i]->id, sorted_records[i]->char_field, sorted_records[i]->int_field, sorted_records[i]->double_field);
  }
}

record *create_record(int id, char *char_field, int int_field, double double_field) {
  record *record_p = malloc(sizeof(record));
  record_p->id = id;
  record_p->char_field = strdup(char_field);
  record_p->int_field = int_field;
  record_p->double_field = double_field;
  return record_p;
}

void free_records(record **records, long record_count) {
  for (int i = 0; i < record_count; i++) {
    free(records[i]->char_field);
    free(records[i]);
  }
  free(records);
}