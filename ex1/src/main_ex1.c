#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "record_loader.h"
#include "comparator.h"
#include "sorter.h"

/**
* @brief Sort the Records in the input file and write the sorted record on the output file
*
* @param infile Input file
* @param outfile Output file
* @param field Number of the field with which the records are sorted
* -1 : String field
* -2 : Int field
* -3 : Double field
* @param algo Number of the algorithm with which the records are sorted
* -1 : Merge sort
* -2 : Quick sort
 */
void sort_records(FILE *infile, FILE *outfile, size_t field, size_t algo) {

  long record_count = 0;
  clock_t begin_read = clock();
  Record **records = load_file(infile, &record_count);
  clock_t end_read = clock();

  double elapsed_read = (double)(end_read - begin_read) / CLOCKS_PER_SEC;
  printf("Time taken by reading records %.3f seconds\n", elapsed_read);

  int (*compar)(const void*, const void*);

  switch (field) {
    case 1:
      compar = str_compare;
      break;
    case 2:
      compar = int_compare;
      break;
    case 3:
      compar = double_compare;
      break;
    default:
      printf("Something is wrong with field parameter\n");
  }

  printf("Start sorting %ld records\n", record_count);
  clock_t begin_sort = clock();

  switch (algo) {
    case 1:
      merge_sort((void **)records, record_count, compar);
      break;
    case 2:
      quick_sort((void **)records, record_count, compar);
      break;
    default:
      printf("Something is wrong with algo parameter\n");
  }

  clock_t end_sort = clock();

  double elapsed_sort = (double)(end_sort - begin_sort ) / CLOCKS_PER_SEC;
  printf("Time taken by sorting records %.3f seconds\n", elapsed_sort);


  clock_t begin_write = clock();
  write_sorted_record(outfile, records, record_count);
  clock_t end_write = clock();

  double elapsed_write = (double)(end_write - begin_write) / CLOCKS_PER_SEC;
  printf("Time taken by writing records %.3f seconds\n", elapsed_write);

  free_records(records, record_count);

}

/**
* @brief Main function that determine the sort_record parameters, taken from the arguments
* - Argument 1 : input file path
* - Argument 2 : output file path
* - Argument 3 : number of the field with which the records are sorted
* - Argument 4 : number of the algorithm with which the records are sorted
*
* @note The output file is created or opened on write mode (its content will be deleted before the sorting begins)
 */
int main(int argc, char *argv[]) {

  if (argc != 5) {
    printf("Not enough arguments\n");
    return 1;
  }

  char *infile_name = argv[1];
  char *outfile_name = argv[2];
  size_t field_num = atoi(argv[3]);
  size_t algo_num = atoi(argv[4]);

  if(0==field_num || field_num>=4) {
    printf("Available field: 1->string 2->int 3->double\nSelected field: %llu\n", field_num);
  }

  if(0==algo_num || algo_num>=3) {
    printf("Available algorithm: 1->merge sort 2->quick sort\nSelected algorithm: %llu\n", field_num);
  }

  FILE *infile = fopen(infile_name, "r");
  if (infile == NULL) {
    printf("Error opening input file\n");
    return 1;
  }

  FILE *outfile = fopen(outfile_name, "w");
  if (outfile == NULL) {
    printf("Error opening output file\n");
    fclose(infile);
    return 1;
  }

  sort_records(infile, outfile, field_num, algo_num);

  fclose(infile);
  fclose(outfile);

  return 0;
}