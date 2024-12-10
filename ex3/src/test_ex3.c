#include <stdio.h>

#include "unity.h"
#include "hash_table.h"
#include <string.h>
#include <stdlib.h>

#include "unity_internals.h"

// Funzioni di supporto per il test
static int compare_keys(const void* a, const void* b) {
    return strcmp((const char*)a, (const char*)b);
}

static unsigned long hash_func(const void* key) {
    const char* str = (const char*)key;
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    return hash;
}

static void free_key(void* key) {
    free(key);
}

static void free_value(void* value) {
    free(value);
}

// Variabili per i test
HashTable* table;

// Test di setup
void setUp(void) {
    // Viene chiamato prima di ogni test
}

// Test di teardown
void tearDown(void) {
    // Viene chiamato dopo ogni test
    if (table) {
        hash_table_free(table);
        table = NULL;
    }
}

// Test della creazione della hash table
void test_create_table_no_resize_no_free(void) {
    table = hash_table_create(10, false, compare_keys, hash_func, NULL, NULL);
    TEST_ASSERT_NOT_NULL(table);
    TEST_ASSERT_EQUAL(10, table->capacity);
    TEST_ASSERT_EQUAL(0, table->size);
    TEST_ASSERT_FALSE(table->allow_resize);
}

void test_create_table_with_resize_and_free(void) {
    table = hash_table_create(5, true, compare_keys, hash_func, free_key, free_value);
    TEST_ASSERT_NOT_NULL(table);
    TEST_ASSERT_EQUAL(5, table->capacity);
    TEST_ASSERT_EQUAL(0, table->size);
    TEST_ASSERT_TRUE(table->allow_resize);
}

// Test dell'inserimento con chiavi duplicate
void test_put_duplicate_key(void) {
    table = hash_table_create(10, false, compare_keys, hash_func, free_key, free_value);
    hash_table_put(table, strdup("key1"), strdup("value1"));
    hash_table_put(table, strdup("key1"), strdup("value2")); // Sovrascrive "value1"

    TEST_ASSERT_EQUAL(1, hash_table_size(table));
    char* value = hash_table_get(table, "key1");
    TEST_ASSERT_NOT_NULL(value);
    TEST_ASSERT_EQUAL_STRING("value2", value);
}

// Test dell'inserimento con ridimensionamento
void test_put_with_resize(void) {
    table = hash_table_create(2, true, compare_keys, hash_func, NULL, NULL);
    hash_table_put(table, "key1", "value1");
    hash_table_put(table, "key2", "value2");
    hash_table_put(table, "key3", "value3"); // Triggers resize

    TEST_ASSERT_EQUAL(4, table->capacity);
    TEST_ASSERT_EQUAL(3, hash_table_size(table));
    TEST_ASSERT_EQUAL_STRING("value1", hash_table_get(table, "key1"));
    TEST_ASSERT_EQUAL_STRING("value2", hash_table_get(table, "key2"));
    TEST_ASSERT_EQUAL_STRING("value3", hash_table_get(table, "key3"));
}

// Test del ridimensionamento forzato
void test_resize_to(void) {
    table = hash_table_create(5, false, compare_keys, hash_func, NULL, NULL);
    hash_table_put(table, "key1", "value1");
    hash_table_put(table, "key2", "value2");

    TEST_ASSERT_EQUAL(5, table->capacity);
    TEST_ASSERT_EQUAL(2, hash_table_size(table));

    hash_table_resize_to(table, 10);

    TEST_ASSERT_EQUAL(10, table->capacity);
    TEST_ASSERT_EQUAL(2, hash_table_size(table));
    TEST_ASSERT_EQUAL_STRING("value1", hash_table_get(table, "key1"));
    TEST_ASSERT_EQUAL_STRING("value2", hash_table_get(table, "key2"));
}

// Test del keyset
void test_keyset(void) {
    table = hash_table_create(10, false, compare_keys, hash_func, NULL, NULL);
    hash_table_put(table, "key1", "value1");
    hash_table_put(table, "key2", "value2");

    void** keys = hash_table_keyset(table);
    TEST_ASSERT_NOT_NULL(keys);

    int found_key1 = 0, found_key2 = 0;
    for (int i = 0; i < 2; i++) {
        if (strcmp((const char*)keys[i], "key1") == 0) found_key1 = 1;
        if (strcmp((const char*)keys[i], "key2") == 0) found_key2 = 1;
    }

    TEST_ASSERT_TRUE(found_key1);
    TEST_ASSERT_TRUE(found_key2);
    free(keys);
}

// Test della rimozione
void test_remove(void) {
    table = hash_table_create(10, false, compare_keys, hash_func, free_key, free_value);
    hash_table_put(table, strdup("key1"), strdup("value1"));
    hash_table_put(table, strdup("key2"), strdup("value2"));

    TEST_ASSERT_EQUAL(2, hash_table_size(table));

    hash_table_remove(table, "key1");
    TEST_ASSERT_EQUAL(1, hash_table_size(table));
    TEST_ASSERT_NULL(hash_table_get(table, "key1"));
    TEST_ASSERT_NOT_NULL(hash_table_get(table, "key2"));
}

// Test dell'accesso a chiavi non esistenti
void test_get_non_existent_key(void) {
    table = hash_table_create(10, false, compare_keys, hash_func, NULL, NULL);
    TEST_ASSERT_NULL(hash_table_get(table, "key1"));
}

void test_stress(void) {
    table = hash_table_create(100, true, compare_keys, hash_func, free_key, free_value);

    // Inserimento di molti elementi
    for (int i = 0; i < 1000; i++) {
        char* key = malloc(20);
        char* value = malloc(20);
        snprintf(key, 20, "key%d", i);
        snprintf(value, 20, "value%d", i);
        hash_table_put(table, key, value);
    }

    TEST_ASSERT_EQUAL(1000, hash_table_size(table));

    // Rimozione di alcuni elementi
    for (int i = 0; i < 500; i++) {
        char key[20];
        snprintf(key, 20, "key%d", i);
        hash_table_remove(table, key);
    }

    TEST_ASSERT_EQUAL(500, hash_table_size(table));
}

void test_null_keys_and_values(void) {
    table = hash_table_create(10, false, compare_keys, hash_func, NULL, NULL);

    // Inserimento di una chiave NULL
    int result = hash_table_put(table, NULL, "value1");
    TEST_ASSERT_EQUAL(-1, result);

    // Inserimento di un valore NULL
    result = hash_table_put(table, "key1", NULL);
    TEST_ASSERT_EQUAL(0, result);
    TEST_ASSERT_NULL(hash_table_get(table, "key1"));
}

void test_resize_to_minimum(void) {
    table = hash_table_create(10, true, compare_keys, hash_func, NULL, NULL);

    hash_table_put(table, "key1", "value1");
    hash_table_put(table, "key2", "value2");

    // Ridimensioniamo a una capacità minima
    int result = hash_table_resize_to(table, 1);
    TEST_ASSERT_EQUAL(-1, result); // Non dovrebbe essere possibile ridurre sotto il numero di elementi

    TEST_ASSERT_EQUAL(10, table->capacity); // La capacità non dovrebbe cambiare
    TEST_ASSERT_EQUAL_STRING("value1", hash_table_get(table, "key1"));
    TEST_ASSERT_EQUAL_STRING("value2", hash_table_get(table, "key2"));
}


int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_create_table_no_resize_no_free);
    RUN_TEST(test_create_table_with_resize_and_free);
    RUN_TEST(test_put_duplicate_key);
    RUN_TEST(test_put_with_resize);
    RUN_TEST(test_resize_to);
    RUN_TEST(test_keyset);
    RUN_TEST(test_remove);
    RUN_TEST(test_get_non_existent_key);
    RUN_TEST(test_stress);
    RUN_TEST(test_null_keys_and_values);
    RUN_TEST(test_resize_to_minimum);

    return UNITY_END();
}
