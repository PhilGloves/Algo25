#include "unity.h"
#include "graph.h"
#include "hash_table.h"
#include <string.h>


#define DIRECTED 0

// Funzioni di hash e compare
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

static Graph graph;

void tearDown(void) {
    graph_free(graph);
}

void test_graph_create(void) {
    graph = graph_create(1,DIRECTED, hash_table_compare_strings, hash_table_hash_string);
    TEST_ASSERT_NOT_NULL(graph);
    TEST_ASSERT_EQUAL(1, graph_is_labelled(graph));
    TEST_ASSERT_EQUAL(DIRECTED, graph_is_directed(graph));
    TEST_ASSERT_EQUAL(0, graph_num_nodes(graph));
    TEST_ASSERT_EQUAL(0, graph_num_edges(graph));
}

void test_graph_add_node(void) {
    graph = graph_create(1,DIRECTED, hash_table_compare_strings, hash_table_hash_string);
    const char* node = "A";
    TEST_ASSERT_EQUAL(1, graph_add_node(graph, node));
    TEST_ASSERT_EQUAL(1, graph_num_nodes(graph));
    TEST_ASSERT_EQUAL(1, graph_contains_node(graph, node));
}

void test_graph_add_same_node(void) {
    graph = graph_create(1,DIRECTED, hash_table_compare_strings, hash_table_hash_string);
    const char* node = "A";
    graph_add_node(graph, node);
    TEST_ASSERT_EQUAL(0, graph_add_node(graph, node));
    TEST_ASSERT_EQUAL(1, graph_num_nodes(graph));
}

void test_graph_add_edge(void) {
    graph = graph_create(1,DIRECTED, hash_table_compare_strings, hash_table_hash_string);
    const char* node1 = "A";
    const char* node2 = "B";

    graph_add_node(graph, node1);
    graph_add_node(graph, node2);

    TEST_ASSERT_EQUAL(1, graph_add_edge(graph, node1, node2, "AB"));
    if (DIRECTED) {
        TEST_ASSERT_EQUAL(1, graph_num_edges(graph));
        TEST_ASSERT_EQUAL(1, graph_contains_edge(graph, node1, node2));
        TEST_ASSERT_EQUAL(0, graph_contains_edge(graph, node2, node1));
    } else {
        TEST_ASSERT_EQUAL(2, graph_num_edges(graph));
        TEST_ASSERT_EQUAL(1, graph_contains_edge(graph, node1, node2));
        TEST_ASSERT_EQUAL(1, graph_contains_edge(graph, node2, node1));
    }
    TEST_ASSERT_EQUAL_STRING("AB", graph_get_label(graph, node1, node2));

}

void test_graph_add_same_edge(void) {
    graph = graph_create(1,DIRECTED, hash_table_compare_strings, hash_table_hash_string);
    const char* node1 = "A";
    const char* node2 = "B";

    graph_add_node(graph, node1);
    graph_add_node(graph, node2);
    graph_add_edge(graph, node1, node2, "AB");

    TEST_ASSERT_EQUAL(0, graph_add_edge(graph, node1, node2, "AB"));
    TEST_ASSERT_EQUAL(1, graph_contains_edge(graph, node1, node2));
}

void test_graph_add_nodes_with_edge(void) {
    graph = graph_create(1,DIRECTED, hash_table_compare_strings, hash_table_hash_string);
    const char* node1 = "A";
    const char* node2 = "B";

    TEST_ASSERT_EQUAL(1, graph_add_edge(graph, node1, node2, "AB"));
    TEST_ASSERT_EQUAL(1, graph_contains_node(graph, node1));
    TEST_ASSERT_EQUAL(1, graph_contains_node(graph, node2));
}

void test_graph_remove_node(void) {
    graph = graph_create(1,DIRECTED, hash_table_compare_strings, hash_table_hash_string);
    const char* node = "A";
    graph_add_node(graph, node);
    TEST_ASSERT_EQUAL(1, graph_remove_node(graph, node));
    TEST_ASSERT_EQUAL(0, graph_num_nodes(graph));
    TEST_ASSERT_EQUAL(0, graph_contains_node(graph, node));
}

void test_graph_remove_non_existing_node(void) {
    graph = graph_create(1,DIRECTED, hash_table_compare_strings, hash_table_hash_string);
    const char* node = "A";
    TEST_ASSERT_EQUAL(0, graph_remove_node(graph, node));
}

void test_graph_remove_edge(void) {
    graph = graph_create(1,DIRECTED, hash_table_compare_strings, hash_table_hash_string);
    const char* node1 = "A";
    const char* node2 = "B";

    graph_add_node(graph, node1);
    graph_add_node(graph, node2);
    graph_add_edge(graph, node1, node2, "AB");

    if (DIRECTED) {
        TEST_ASSERT_EQUAL(1, graph_remove_edge(graph, node1, node2));
        TEST_ASSERT_EQUAL(0, graph_contains_edge(graph, node1, node2));
    } else {
        TEST_ASSERT_EQUAL(1, graph_remove_edge(graph, node1, node2));
        TEST_ASSERT_EQUAL(0, graph_contains_edge(graph, node1, node2));
        TEST_ASSERT_EQUAL(0, graph_contains_edge(graph, node2, node1));
    }
}

void test_graph_remove_non_existing_edge(void) {
    graph = graph_create(1,DIRECTED, hash_table_compare_strings, hash_table_hash_string);
    const char* node1 = "A";
    const char* node2 = "B";
    graph_add_node(graph, node1);
    graph_add_node(graph, node2);

    TEST_ASSERT_EQUAL(0, graph_remove_edge(graph, node1, node2));
}

void test_graph_get_num_neighbours(void) {
    graph = graph_create(1,DIRECTED, hash_table_compare_strings, hash_table_hash_string);
    const char* node1 = "A";
    const char* node2 = "B";
    const char* node3 = "C";

    graph_add_node(graph, node1);
    graph_add_node(graph, node2);
    graph_add_node(graph, node3);
    graph_add_edge(graph, node1, node2, "AB");
    graph_add_edge(graph, node1, node3, "AC");

    void** neighbours = graph_get_neighbours(graph, node1);
    TEST_ASSERT_NOT_NULL(neighbours);
    TEST_ASSERT_EQUAL(2, graph_num_neighbours(graph, node1));
    free(neighbours);
}

void test_graph_get_label(void) {
    graph = graph_create(1,DIRECTED, hash_table_compare_strings, hash_table_hash_string);
    const char* node1 = "A";
    const char* node2 = "B";

    graph_add_node(graph, node1);
    graph_add_node(graph, node2);
    graph_add_edge(graph, node1, node2, "AB");

    if (DIRECTED) {
        TEST_ASSERT_EQUAL_STRING("AB", graph_get_label(graph, node1, node2));
    } else {
        TEST_ASSERT_EQUAL_STRING("AB", graph_get_label(graph, node1, node2));
        TEST_ASSERT_EQUAL_STRING("AB", graph_get_label(graph, node2, node1));
    }
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_graph_create);
    RUN_TEST(test_graph_add_node);
    RUN_TEST(test_graph_add_same_node);
    RUN_TEST(test_graph_add_edge);
    RUN_TEST(test_graph_add_same_edge);
    RUN_TEST(test_graph_add_nodes_with_edge);
    RUN_TEST(test_graph_remove_node);
    RUN_TEST(test_graph_remove_non_existing_node);
    RUN_TEST(test_graph_remove_edge);
    RUN_TEST(test_graph_remove_non_existing_edge);
    RUN_TEST(test_graph_get_num_neighbours);
    RUN_TEST(test_graph_get_label);

    return UNITY_END();
}
