#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "record.h"

void **load_file(FILE *infile) {

  record **records = NULL;
  long record_count = 0;

  char buffer[1024];
  const char *sep = ",";
  char *token;
  while (fgets(buffer, sizeof(buffer), file) && record_count < RECORD_READ_LIMIT) {
    record_count++;
    records = realloc(records, record_count * sizeof(record *));

    token = strtok(buffer, sep);
    int id = atoi(token);

    token = strtok(NULL, sep);
    char *char_field = token;

    token = strtok(NULL, sep);
    int int_field = atoi(token);

    token = strtok(NULL, sep);
    float float_field = atof(token);

    records[record_count-1] = create_record(id, char_field, int_field, float_field);
  }

  RECORD_COUNTER = record_count;

  return records;
}

void write_sorted_record(void **records, FILE *outfile) {
  for (int i = 0; i < RECORD_COUNTER; i++) {
    fprintf(file, "%d,%s,%d,%f\n", records[i]->id, records[i]->char_field, records[i]->int_field, records[i]->float_field);
  }
}

void* create_record(int id, char *char_field, int int_field, float float_field) {
  record *record_p = malloc(sizeof(record));
  record_p->id = id;
  record_p->char_field = strdup(char_field);
  record_p->int_field = int_field;
  record_p->float_field = float_field;
  return record_p;
}

void free_records(record **records) {
  for (int i = 0; i < RECORD_COUNTER; i++) {
    free(records[i]->char_field);
    free(records[i]);
  }
  free(records);
}