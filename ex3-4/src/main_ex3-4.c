#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "queue.h"
#include "../../ex3/include/hash_table.h"

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

void load_file(Graph graph, char* infile) {
  FILE* file = fopen(infile, "r");
  if (!file) {
    printf("Error opening file %s\n", infile);
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

//Start è il nodo di partenza da cui cominciare la visita, la funzione restituisce l'array dei nodi nell'ordine di visita.
//Eventualmente, la funzione restituisce null se il nodo start non è presente nel grafo gr.
void** breadth_first_visit(Graph gr, void* start, int (*compare)(const void*, const void*), unsigned long (*hash)(const void*)) {
  if (!gr || !start || !compare || !hash) {
    printf("Error bfv arguments\n");
    return NULL;
  }

  if (!graph_contains_node(gr, start))
    return NULL;

  Queue* queue = queue_create(graph_num_nodes(gr));

  HashTable* visited_node = hash_table_create(compare, hash);

  void** bfs_result = calloc(graph_num_nodes(gr), sizeof(void*));
  int result_index = 0;

  queue_enqueue(queue, start);
  hash_table_put(visited_node, start, (void**)1);

  while (!queue_empty(queue)) {
    void* current = queue_dequeue(queue);

    void** current_neighbours = graph_get_neighbours(gr, current);
    int current_neighbours_num = graph_num_neighbours(gr, current);
    if (current_neighbours) {
      for (int i = 0; i < current_neighbours_num; i++) {
        if (!hash_table_contains_key(visited_node, current_neighbours[i])) {
          queue_enqueue(queue, current_neighbours[i]);
          hash_table_put(visited_node, current_neighbours[i], (void**)1);
        }
      }
    }
    free(current_neighbours);
    bfs_result[result_index] = current;
    result_index++;
  }

  queue_free(queue);
  hash_table_free(visited_node);

  return bfs_result;
}

void write_visited(const char* outfile, void** visited, size_t num_nodes) {
  FILE* file = fopen(outfile, "w");
  if (!file) {
    printf("Error opening file %s\n", outfile);
  }

  for (int i = 0; i < num_nodes && visited[i]; i++) {
    fprintf(file, "%s\n", (char*)visited[i]);
  }
}

void graph_visit(const char* infile, const char* start, const char* outfile) {
  Graph graph = graph_create(1,0,hash_table_compare_strings,hash_table_hash_string);
  load_file(graph, (char*)infile);

  clock_t start_bfs = clock();

  void** visited = breadth_first_visit(graph, (void*)start, hash_table_compare_strings, hash_table_hash_string);

  clock_t end_bfs = clock();

  double elapsed_bfs = (double)(end_bfs - start_bfs) / CLOCKS_PER_SEC;
  if (visited != NULL) {
    write_visited(outfile, visited, graph_num_nodes(graph));
    printf("Time taken by the visit: %.3f\n", elapsed_bfs);
  } else {
    printf("Node requested doesn't exist\n");
  }

  free(visited);
  graph_free(graph);
}


//bin/main_ex3-4 dataset/italian_dist_graph.csv pinerolo dataset/result.txt
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