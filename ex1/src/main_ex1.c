#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "record_loader.h"

void sort_records(FILE *infile, FILE *outfile, size_t field, size_t algo) {

  clock_t begin_read = clock();
  record **records = load_file(infile);
  clock_t end_read = clock();

  clock_t elapsed_read = (end_read - begin_read) / CLOCKS_PER_SEC;
  printf("Time taken by reading records %f seconds\n", elapsed_read);

  clock_t begin_sort = clock();
  
  clock_t end_sort = clock();
  clock_t begin_write = clock();

  clock_t end_write = clock();




  clock_t elapsed_write = (end_write - begin_write) / CLOCKS_PER_SEC;
  clock_t elapsed_sort = (end_sort - begin_sort ) / CLOCKS_PER_SEC;
}

int main(int argc, char *argv[]) {

  if (argc != 5) {
    printf("Not enough arguments\n");
    return 1;
  }

  char *infile_name = argv[1];
  char *outfile_name = argv[2];
  //1->string 2->int 3->double
  size_t field_num = atoi(argv[3]);
  //1->merge 2->quick
  size_t algo_num = atoi(argv[4]);

  if(0<=field_num && field_num>=4) {
    printf("Available field: 1->string 2->int 3->double\nSelected field: %d\n", field_num);
  }

  if(0<=field_num && field_num>=3) {
    printf("Available algoritm: 1->merge sort 2->quick sort\nSelected algoritm: %d\n", field_num);
  }

  FILE *infile = fopen(infile_name, "r");
  if (file == NULL) {
    printf("Error opening input file\n");
    return 1;
  }

  FILE *outfile = fopen(outfile_name, "w");
  if (file == NULL) {
    printf("Error opening output file\n");
    fclose(infile);
    return 1;
  }

  sort_records(infile, outfile, field_num, algo_num);

  fclose(infile);
  fclose(outfile);
}