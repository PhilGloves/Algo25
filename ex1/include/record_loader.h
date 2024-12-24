#ifndef RECORD_LOADER_H
#define RECORD_LOADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define RECORD_READ_LIMIT 5000000
//#define RECORD_READ_LIMIT INT_MAX

/**
* @brief Definition of the struct for the records
*/
typedef struct {
  int id;
  char *char_field;
  int int_field;
  double double_field;
} Record;

/**
* @brief Create an array of Records from a file
*
* @param infile Pointer to the file
* @param record_count Pointer to a counter only updated when this function returns. It contains the number of records
*
* @return An array of Records
*/
Record **load_file(FILE *infile, long *record_count);

/**
* @brief Writes the Records from the array to the file
*
* @param outfile Pointer to the file
* @param sorted_records Array of Records
* @param record_count Number of elements in the array
*/
void write_sorted_record(FILE *outfile, Record **sorted_records, long record_count);

/**
* @brief Frees the memory allocated by the Records Array
*
* @param record Array of Records
* @param record_count Number of elements in the array
*/
void free_records(Record **record, long record_count);

/**
* @brief Creates a Record
*
* @param id Record's id
* @param char_field Record's string field
* @param int_field Record's integer field
* @param double_field Record's double field
*
* @return A pointer to the Record
*/
Record *create_record(int id, char *char_field, int int_field, double double_field);

#endif //RECORD_LOADER_H
