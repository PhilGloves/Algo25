#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int hash_table_compare_strings(const void* a, const void* b) {
  return strcmp((const char*)a, (const char*)b);
}

unsigned long hash_table_hash_string(const void* key) {
  const char* str = (const char*)key;
  unsigned long hash = 5381;
  int c;
  while ((c = *str++)) {
    hash = ((hash << 5) + hash) + c;
  }
  return hash;
}

void load_file(Graph graph, char* filename) {
  FILE* file = fopen(filename, "r");
  if (!file) {
    printf("Error opening file %s\n", filename);
  }

  char buffer[256];

  while (fgets(buffer, 256, file)) {
    char* source = strtok(buffer, ",");
    char* dest = strtok(NULL, ",");
    char* label = strtok(NULL, ",");

    if (source && dest && label) {
      graph_add_edge(graph,strdup(source), strdup(dest), strdup(label));
    }
  }
  fclose(file);
}

void graph_visit(const char* infile, const char* start, const char* outfile) {
  //graph = graph_create(1,0,hash_table_compare_strings,hash_table_hash_string);

}

int main(int argc, char** argv) {
  if (argc != 4) {
    printf("Not enough arguments\n");
    return 1;
  }

  const char* infile = argv[1];
  const char* start = argv[2];
  const char* outfile = argv[3];

  graph_visit(infile, start, outfile);

  return 0;
}