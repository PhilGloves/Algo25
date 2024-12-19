#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct graph{
  HashTable* nodes;
  size_t nodes_size;
  int labelled;
  int directed;
};

typedef struct edge_info {
  void* label;
  void* cost;
}EdgeInfo;

Graph graph_create(int labelled, int directed, int (*compare)(const void*, const void*), unsigned long (*hash)(const void*)) {
  Graph gr = malloc(sizeof(struct graph));
  if (gr == NULL) {
    return NULL;
  }
  gr->nodes_size = 0;
  gr->labelled = labelled;
  gr->directed = directed;
  gr->nodes = hash_table_create(compare, hash);
  if (gr->nodes == NULL) {
    free(gr);
    return NULL;
  }
  return gr;
}

int graph_is_directed(const Graph gr) {
  return gr == NULL ? -1 : gr->directed;
}

int graph_is_labelled(const Graph gr) {
  return gr == NULL ? -1 : gr->labelled;
}

int graph_add_node(Graph gr, const void* node) {
  if (gr == NULL || node == NULL) {
    return -1;
  }
  if (graph_contains_node(gr, node)) {
    return 0;
  }

  hash_table_put(
      gr->nodes, node,
      hash_table_create(gr->nodes->compare_keys, gr->nodes->hash_func));

  gr->nodes_size++;

  return 1;
}

int graph_add_edge(Graph gr, const void* node1, const void* node2, const void* label) {
  if (gr == NULL || node1 == NULL || node2 == NULL) {
    return -1;
  }

  if (gr->labelled && label == NULL) {
    return -1;
  }

  if (/*!graph_contains_node(gr, node1)*/ !hash_table_get(gr->nodes, node1))
    graph_add_node(gr, node1);

  if (/*!graph_contains_node(gr, node2)*/!hash_table_get(gr->nodes, node1))
    graph_add_node(gr, node2);

  if (graph_contains_edge(gr, node1, node2) == 1) {
    return 0;
  }

  EdgeInfo* edge_info = malloc(sizeof(EdgeInfo));
  if (edge_info == NULL) {
    return -1;
  }
  edge_info->label = (void*)label;
  edge_info->cost = NULL;

  hash_table_put(hash_table_get(gr->nodes, node1), node2, edge_info);

  if (gr->directed) {
    hash_table_put(hash_table_get(gr->nodes, node2), node1, edge_info);
  }

  return 1;
}

int graph_contains_node(const Graph gr, const void* node) {
  if (gr == NULL || node == NULL) {
    return -1;
  }

  return hash_table_get(gr->nodes, node) == NULL ? 0 : 1;
}

int graph_contains_edge(const Graph gr, const void* node1, const void* node2) {
  if (gr == NULL || node1 == NULL || node2 == NULL) {
    return -1;
  }

  return hash_table_get(hash_table_get(gr->nodes, node1), node2) == NULL ? 0 : 1;
}

int graph_remove_node(Graph gr, const void* node) {
  if (gr == NULL || node == NULL) {
    return -1;
  }

  if (!graph_contains_node(gr, node)) {
    return 0;
  }

  //pulisco nodo e archi
  HashTable* edge_table = hash_table_get(gr->nodes, node);
  void** keyset = hash_table_keyset(edge_table);
  size_t keyset_size = hash_table_size(edge_table);

  for (size_t i = 0; i < keyset_size; i++) {
    free(hash_table_get(edge_table, keyset[i]));
  }
  hash_table_free(edge_table);
  free(keyset);
  hash_table_remove(gr->nodes, node);

  //pulisco archi che puntano a nodo
  keyset = hash_table_keyset(gr->nodes);
  for (size_t i = 0; i < gr->nodes_size; i++) {
    edge_table = hash_table_get(gr->nodes, keyset[i]);
    if (hash_table_get(edge_table, node) != NULL) {
      free(hash_table_get(edge_table, node));
      hash_table_remove(edge_table, node);
    }
  }

  gr->nodes_size--;

  return 1;
}

int graph_remove_edge(Graph gr, const void* node1, const void* node2) {
  if (gr == NULL || node1 == NULL || node2 == NULL) {
    return -1;
  }

  if (!graph_contains_edge(gr, node1, node2)) {
    return 0;
  }

  HashTable* edge_table = hash_table_get(gr->nodes, node1);
  free(hash_table_get(edge_table, node2));
  hash_table_remove(edge_table, node2);

  if (!gr->directed) {
    edge_table = hash_table_get(gr->nodes, node2);
    free(hash_table_get(edge_table, node1));
    hash_table_remove(edge_table, node1);
  }
  return 1;
}

int graph_num_nodes(const Graph gr) {
  if (gr == NULL || gr->nodes == NULL) {
    return -1;
  }
  return gr->nodes_size;
}

int graph_num_edges(const Graph gr) {
  if (gr == NULL) {
    return -1;
  }

  int edge_count = 0;

  void** keyset = hash_table_keyset(gr->nodes);

  for (size_t i = 0; i < gr->nodes_size; i++) {
    edge_count += hash_table_size(hash_table_get(gr->nodes, keyset[i]));
  }

  free(keyset);

  return edge_count;
}
void** graph_get_nodes(const Graph gr) {
  if (gr == NULL) {
    return NULL;
  }

  return hash_table_keyset(gr->nodes);
}

Edge** graph_get_edges(const Graph gr) {
  if (gr == NULL) {
    return NULL;
  }

  Edge** edges = calloc(sizeof(Edge*), graph_num_edges(gr));

  if (edges == NULL) {
    return NULL;
  }

  size_t index = 0;

  void** Nodes = hash_table_keyset(gr->nodes);

  for (size_t i = 0; i < gr->nodes_size; i++) {

    HashTable* edge_table = hash_table_get(gr->nodes, Nodes[i]);
    void** edge_keyset = hash_table_keyset(edge_table);

    for (size_t j = 0; j < hash_table_size(edge_table); j++) {
      EdgeInfo* edge_info = hash_table_get(edge_table, edge_keyset[j]);
      Edge* edge = malloc(sizeof(Edge));
      if (edge == NULL) {
        free(Nodes);
        free(edges);
        return NULL;
      }
      edge->source = Nodes[i];
      edge->dest = edge_keyset[j];
      edge->label = edge_info->label;

      edges[index] = edge;
      index++;
    }
    free(edge_keyset);
  }
  free(Nodes);
  return edges;
}

void** graph_get_neighbours(const Graph gr, const void* node) {
  if (gr == NULL || node == NULL) {
    return NULL;
  }

  return hash_table_keyset(hash_table_get(gr->nodes, node));
}

int graph_num_neighbours(const Graph gr, const void* node) {
  if (gr == NULL || node == NULL) {
    return -1;
  }
  return hash_table_size(hash_table_get(gr->nodes, node));
}

void* graph_get_label(const Graph gr, const void* node1, const void* node2) {
  if (gr == NULL || node1 == NULL || node2 == NULL) {
    return NULL;
  }
  EdgeInfo* info= hash_table_get(hash_table_get(gr->nodes, node1), node2);
  return info->label;
}

void graph_free(Graph gr) {
  if (gr == NULL) {
    return;
  }

  void** Nodes = hash_table_keyset(gr->nodes);

  for (size_t i = 0; i < gr->nodes_size; i++) {

    HashTable* edge_table = hash_table_get(gr->nodes, Nodes[i]);
    void** edge_keyset = hash_table_keyset(edge_table);

    for (size_t j = 0; j < hash_table_size(edge_table); j++) {
      free(hash_table_get(edge_table, edge_keyset[j]));
    }

    free(edge_keyset);
    hash_table_free(edge_table);
  }
  free(Nodes);
  hash_table_free(gr->nodes);
  free(gr);
}