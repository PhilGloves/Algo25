#ifndef GRAPH_H
#define GRAPH_H

typedef struct graph* Graph;

typedef struct edge {
   void* source;
   void* dest;
   void* label;
}Edge;

/**
 * @brief Creates a new graph.
 *
 * @param labelled Indicates if the graph is labelled.
 * @param directed Indicates if the graph is directed.
 * @param compare Pointer to the function to compare nodes.
 * @param hash Pointer to the function to compute hash values for nodes.
 *
 * @return Pointer to the newly created graph, or NULL if allocation fails.
 */
Graph graph_create(int labelled, int directed,
                     int (*compare)(const void*, const void*),
                     unsigned long (*hash)(const void*));

/**
 * @brief Checks if the graph is directed.
 *
 * @param gr Pointer to the graph.
 *
 * @return Non-zero value if the graph is directed, 0 otherwise.
 */
int graph_is_directed(const Graph gr);

/**
 * @brief Checks if the graph is labelled.
 *
 * @param gr Pointer to the graph.
 *
 * @return Non-zero value if the graph is labelled, 0 otherwise.
 */
int graph_is_labelled(const Graph gr);

/**
 * @brief Adds a node to the graph.
 *
 * @param gr Pointer to the graph.
 * @param node Pointer to the node to be added.
 *
 * @return 1 if the node is successfully added, 0 if it already exists.
 */
int graph_add_node(Graph gr, const void* node);

/**
 * @brief Adds an edge to the graph.
 *
 * @param gr Pointer to the graph.
 * @param node1 Pointer to the source node.
 * @param node2 Pointer to the destination node.
 * @param label Pointer to the edge label (must not be NULL if the graph is labelled).
 *
 * @note If the nodes of the edge you want to add are not in the graph, they will be added.
 * @return 1 if the edge is successfully added, 0 if it already exists.
 */
int graph_add_edge(Graph gr, const void* node1, const void* node2, const void* label);

/**
 * @brief Checks if a node exists in the graph.
 *
 * @param gr Pointer to the graph.
 * @param node Pointer to the node to check.
 *
 * @return 1 if the node exists, 0 otherwise.
 */
int graph_contains_node(const Graph gr, const void* node);

/**
* @brief Checks if an edge exists in the graph.
*
* @param gr Pointer to the graph.
* @param node1 Pointer to the source node.
* @param node2 Pointer to the destination node.
*
* @return 1 if the edge exists, 0 otherwise.
*/
int graph_contains_edge(const Graph gr, const void* node1, const void* node2);

/**
 * @brief Removes a node and all its associated edges from the graph.
 *
 * @param gr Pointer to the graph.
 * @param node Pointer to the node to be removed.
 *
 * @return 1 if the node is successfully removed, 0 otherwise.
 */
int graph_remove_node(Graph gr, const void* node);

/**
 * @brief Removes an edge from the graph.
 *
 * @param gr Pointer to the graph.
 * @param node1 Pointer to the source node.
 * @param node2 Pointer to the destination node.
 *
 * @return 1 if the edge is successfully removed, 0 otherwise.
 */
int graph_remove_edge(Graph gr, const void* node1, const void* node2);

/**
 * @brief Retrieves the number of nodes in the graph.
 *
 * @param gr Pointer to the graph.
 *
 * @return The number of nodes in the graph.
 */
int graph_num_nodes(const Graph gr);

/**
 * @brief Calculates the total number of edges in a graph.
 *
 * @param gr Pointer to the graph.
 *
 * @return The number of edges in the graph.
 */
int graph_num_edges(const Graph gr);

/**
 * @brief Calculates the total number of nodes in a graph.
 *
 * @param gr Pointer to the graph.
 *
 * @return Array of pointers to all nodes in the graph.
 */
void** graph_get_nodes(const Graph gr);

/**
 * @brief Retrieves all the edges in the graph.
 *
 * @param gr Pointer to the graph.
 *
 * @return Array of pointers to all edges in the graph, NULL on failure.
 */
Edge** graph_get_edges(const Graph gr);

/**
 * @brief Retrieves the neighbors of a given node in the graph.
 *
 * @param gr Pointer to the graph.
 * @param node Pointer to the node whose neighbors are to be retrieved.
 *
 * @return Array of pointers to all neighbor nodes.
 */
void** graph_get_neighbours(const Graph gr, const void* node);

/**
 * @brief Retrieves the number of neighbors of a specific node in the graph.
 *
 * @param gr Pointer to the graph.
 * @param node Pointer to the node whose neighbors are to be counted.
 *
 * @return The number of neighbors of the node.
 */
int graph_num_neighbours(const Graph gr, const void* node);

/**
 * @brief Retrieves the label of an edge between two nodes in the graph.
 *
 * @param gr Pointer to the graph.
 * @param node1 Pointer to the source node.
 * @param node2 Pointer to the destination node.
 *
 * @return Pointer to the label of the edge, or NULL if no edge exists.
 */
void* graph_get_label(const Graph gr, const void* node1, const void* node2);

/**
 * @brief Frees all memory associated with the graph.
 *
 * @param gr Pointer to the graph to be freed.
 */
void graph_free(Graph gr);

#endif //GRAPH_H