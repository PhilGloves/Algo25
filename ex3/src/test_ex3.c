#include "hash_table.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>

// Computes a hash value for a given string.
unsigned long string_hash(const void* key) {
    const char* str = (const char*)key;
    unsigned long hash = 5381;
    while (*str) {
        hash = ((hash << 5) + hash) + *str++; // hash * 33 + c
    }
    return hash;
}

int string_compare(const void* a, const void* b) {
    return strcmp((const char*)a, (const char*)b);
}

void setUp(void) {
}

void tearDown(void) {
}

void test_hash_table_create_and_free(void) {
    HashTable* table = hash_table_create(string_compare, string_hash);
    TEST_ASSERT_NOT_NULL(table);
    TEST_ASSERT_EQUAL(0, hash_table_size(table));
    hash_table_free(table);
}

void test_hash_table_put_and_get(void) {
    HashTable* table = hash_table_create(string_compare, string_hash);

    char* key1 = "chiave1";
    char* value1 = "valore1";
    hash_table_put(table, strdup(key1), strdup(value1));
    char* result = (char*)hash_table_get(table, key1);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING(value1, result);

    hash_table_free(table);
}

void test_hash_table_update_value(void) {
    HashTable* table = hash_table_create(string_compare, string_hash);

    char* key = "chiave";
    char* value1 = "valore1";
    char* value2 = "valore2";

    hash_table_put(table, strdup(key), strdup(value1));
    hash_table_put(table, strdup(key), strdup(value2));

    char* result = (char*)hash_table_get(table, key);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING(value2, result);

    hash_table_free(table);
}

void test_hash_table_remove(void) {
    HashTable* table = hash_table_create(string_compare, string_hash);

    char* key = "chiave";
    char* value = "valore";

    hash_table_put(table, strdup(key), strdup(value));
    hash_table_remove(table, key);

    void* result = hash_table_get(table, key);
    TEST_ASSERT_NULL(result);

    hash_table_free(table);
}

void test_hash_table_keyset(void) {
    HashTable* table = hash_table_create(string_compare, string_hash);

    char* key1 = "chiave1";
    char* value1 = "valore1";
    char* key2 = "chiave2";
    char* value2 = "valore2";

    hash_table_put(table, strdup(key1), strdup(value1));
    hash_table_put(table, strdup(key2), strdup(value2));

    void** keys = hash_table_keyset(table);
    TEST_ASSERT_NOT_NULL(keys);
    TEST_ASSERT_EQUAL(2, hash_table_size(table));

    free(keys);
    hash_table_free(table);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_hash_table_create_and_free);
    RUN_TEST(test_hash_table_update_value);
    RUN_TEST(test_hash_table_put_and_get);
    RUN_TEST(test_hash_table_remove);
    RUN_TEST(test_hash_table_keyset);

    return UNITY_END();
}