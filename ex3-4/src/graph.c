#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct graph{
  HashTable* nodes;
  int labelled;
  int directed;
};

Graph graph_create(int labelled, int directed, int (*compare)(const void*, const void*), unsigned long (*hash)(const void*)) {
  Graph gr = malloc(sizeof(struct graph));
  if (gr == NULL) {
    return NULL;
  }
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
  return gr->directed;
}

int graph_is_labelled(const Graph gr) {
  return gr->labelled;
}

int graph_add_node(Graph gr, const void* node) {
  if (!gr || !node) {
    perror("Errore nella creazione del nodo");
    exit(EXIT_FAILURE);
  }
  if (!hash_table_contains_key(gr->nodes, node)) {
    hash_table_put(
        gr->nodes, node,
        hash_table_create(gr->nodes->compare_keys, gr->nodes->hash_func));
    return 1;
  }

  return 0;
}

int graph_add_edge(Graph gr, const void* node1, const void* node2, const void* label) {
  if (!gr || !node1 || !node2) {
    perror("Errore nella creazione del arco");
    exit(EXIT_FAILURE);
  }

  if (gr->labelled && label == NULL) {
    perror("Etichetta NULL in grafo etichettato");
    exit(EXIT_FAILURE);
  }

  if (!hash_table_contains_key(gr->nodes, node1))
    graph_add_node(gr, node1);

  if (!hash_table_contains_key(gr->nodes, node2))
    graph_add_node(gr, node2);

  if (graph_contains_edge(gr, node1, node2) == 1) {
    return 0;
  }

  hash_table_put(hash_table_get(gr->nodes, node1), node2, label);

  if (!gr->directed) {
    hash_table_put(hash_table_get(gr->nodes, node2), node1, label);
  }

  return 1;
}

int graph_contains_node(const Graph gr, const void* node) {
  if (!gr || !node) {
    perror("Errore argomenti per contains_node");
    exit(EXIT_FAILURE);
  }

  return hash_table_contains_key(gr->nodes, node) ? 1 : 0;
}

int graph_contains_edge(const Graph gr, const void* node1, const void* node2) {
  if (!gr || !node1 || !node2) {
    perror("Errore argomenti per contains_edge");
    exit(EXIT_FAILURE);
  }
  if (!hash_table_contains_key(gr->nodes, node1)) {
    return 0;
  }
  return hash_table_contains_key(hash_table_get(gr->nodes, node1), node2)? 1 : 0;
}

int graph_remove_node(Graph gr, const void* node) {
  if (!gr || !node) {
    perror("Errore rimozione nodi");
    exit(EXIT_FAILURE);
  }

  if (!hash_table_contains_key(gr->nodes, node)) {
    return 0;
  }

  hash_table_free(hash_table_get(gr->nodes, node));
  hash_table_remove(gr->nodes, node);

  //pulisco archi che puntano a nodo
  void** keyset = hash_table_keyset(gr->nodes);
  int keyset_size = hash_table_size(gr->nodes);
  for (size_t i = 0; i < keyset_size; i++) {
    hash_table_remove(hash_table_get(gr->nodes, keyset[i]), node);
  }

  free(keyset);
  return 1;
}

int graph_remove_edge(Graph gr, const void* node1, const void* node2) {
  if (!gr || !node1 || !node2) {
    perror("Errore rimozione arco");
    exit(EXIT_FAILURE);
  }

  if (!graph_contains_edge(gr, node1, node2)) {
    return 0;
  }

  hash_table_remove(hash_table_get(gr->nodes, node1), node2);

  if (!gr->directed) {
    hash_table_remove(hash_table_get(gr->nodes, node2), node1);
  }
  return 1;
}

int graph_num_nodes(const Graph gr) {
  return gr->nodes->size;
}

int graph_num_edges(const Graph gr) {
  if (!gr) {
    perror("Errore rimozione arco");
    exit(EXIT_FAILURE);
  }

  int edge_count = 0;

  void** keyset = hash_table_keyset(gr->nodes);
  size_t keyset_size = hash_table_size(gr->nodes);

  for (size_t i = 0; i < keyset_size; i++) {
    edge_count += hash_table_size(hash_table_get(gr->nodes, keyset[i]));
  }

  free(keyset);

  return edge_count;
}

void** graph_get_nodes(const Graph gr) {
  if (!gr) {
    perror("Errore get nodi");
    exit(EXIT_FAILURE);
  }

  return hash_table_keyset(gr->nodes);
}

Edge** graph_get_edges(const Graph gr) {
  if (!gr) {
    perror("Errore get archi");
    exit(EXIT_FAILURE);
  }

  Edge** edges = calloc(sizeof(Edge*), graph_num_edges(gr));

  if (!edges) {
    perror("Errore creazione array archi");
    exit(EXIT_FAILURE);
  }

  size_t index = 0;

  void** Nodes = hash_table_keyset(gr->nodes);
  size_t nodes_size = hash_table_size(gr->nodes);

  for (size_t i = 0; i < nodes_size; i++) {

    HashTable* edge_table = hash_table_get(gr->nodes, Nodes[i]);
    void** edge_keyset = hash_table_keyset(edge_table);

    for (size_t j = 0; j < hash_table_size(edge_table); j++) {
      Edge* edge = malloc(sizeof(Edge));
      if (edge == NULL) {
        for (size_t k = 0; k < index; k++) {
          free(edges[k]);
        }
        free(edges);
        free(Nodes);
        return NULL;
      }

      edge->source = Nodes[i];
      edge->dest = edge_keyset[j];
      edge->label = hash_table_get(hash_table_get(gr->nodes, edge->source), edge->dest);

      edges[index] = edge;
      index++;
    }
    free(edge_keyset);
  }
  free(Nodes);
  return edges;
}

void** graph_get_neighbours(const Graph gr, const void* node) {
  if (!gr || !node) {
    perror("Errore get archi");
    exit(EXIT_FAILURE);
  }

  return hash_table_keyset(hash_table_get(gr->nodes, node));
}

int graph_num_neighbours(const Graph gr, const void* node) {
  if (!gr || !node) {
    perror("Errore get archi");
    exit(EXIT_FAILURE);
  }
  return hash_table_size(hash_table_get(gr->nodes, node));
}

void* graph_get_label(const Graph gr, const void* node1, const void* node2) {
  if (!gr || !node1 || !node2) {
    perror("Errore get archi");
    exit(EXIT_FAILURE);
  }
  return hash_table_get(hash_table_get(gr->nodes, node1), node2);
}

void graph_free(Graph gr) {
  if (gr == NULL) {
    return;
  }

  void** Nodes = hash_table_keyset(gr->nodes);
  size_t nodes_size = hash_table_size(gr->nodes);

  for (size_t i = 0; i < nodes_size; i++) {
    HashTable* edge_table = hash_table_get(gr->nodes, Nodes[i]);
    hash_table_free(edge_table);
  }

  free(Nodes);
  hash_table_free(gr->nodes);
  free(gr);
}