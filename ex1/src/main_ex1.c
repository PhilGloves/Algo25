#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "record_loader.h"
#include "comparator.h"
#include "sorter.h"

void sort_records(FILE *infile, FILE *outfile, size_t field, size_t algo) {

  clock_t begin_read = clock();
  record **records = load_file(infile);
  clock_t end_read = clock();

  clock_t elapsed_read = (end_read - begin_read) / CLOCKS_PER_SEC;
  printf("Time taken by reading records %ld seconds\n", elapsed_read);

  int (*compar)(void *, void *);

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
  }

  printf("Start sorting %d records\n", RECORD_COUNTER);
  clock_t begin_sort = clock();

  switch (algo) {
    case 1:
      merge_sort(records, RECORD_COUNTER, compar);
      break;
    case 2:
      quick_sort(records, RECORD_COUNTER, compar);
      break;
  }

  clock_t end_sort = clock();

  clock_t elapsed_sort = (end_sort - begin_sort ) / CLOCKS_PER_SEC;
  printf("Time taken by sorting records %ld seconds\n", elapsed_sort);


  clock_t begin_write = clock();
  write_sorted_record(records, outfile);
  clock_t end_write = clock();

  clock_t elapsed_write = (end_write - begin_write) / CLOCKS_PER_SEC;
  printf("Time taken by writing records %ld seconds\n", elapsed_write);

  free_records(records);

}

int main(int argc, char *argv[]) {

  if (argc != 5) {
    printf("Not enough arguments\n");
    return 1;
  }

  char *infile_name = argv[1];
  char *outfile_name = argv[2];
  size_t field_num = _atoi64(argv[3]);
  size_t algo_num = _atoi64(argv[4]);

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