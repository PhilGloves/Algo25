#include "hash_table.h"

#include <stdio.h>

HashTable* hash_table_create(int (*f1)(const void*, const void*), unsigned long (*f2)(const void*)) {
    HashTable* table = malloc(sizeof(HashTable));
    table->capacity = 16;
    table->size = 0;
    table->buckets = calloc(table->capacity, sizeof(HashNode*));
    for (int i = 0; i < table->capacity; i++) {
        table->buckets[i] = NULL;
    }
    table->compare_keys = f1;
    table->hash_func = f2;
    return table;
}

static void hash_table_resize(HashTable* table) {
    int old_capacity = table->capacity;
    HashNode** old_buckets = table->buckets;

    int new_capacity = table->capacity * 2;
    HashNode** new_buckets = calloc(new_capacity, sizeof(HashNode*));
    if (!new_buckets) return;
    for (int i = 0; i < new_capacity; i++) {
        new_buckets[i] = NULL;
    }

    table->capacity = new_capacity;
    table->buckets = new_buckets;
    table->size = 0;

    for (size_t i = 0; i < old_capacity; i++) {
        HashNode* current = old_buckets[i];
        while (current != NULL) {
            hash_table_put(table, current->key, current->value);
            HashNode* inserted_node = current;
            current = current->next;
            free(inserted_node);
        }
    }

    free(old_buckets);
}

void hash_table_put(HashTable* table, const void* key, const void* value) {
    if (!table || !key) return;

    if ((float)(table->size + 1) / table->capacity > 0.75) {
        hash_table_resize(table);
    }

    unsigned long hash = table->hash_func(key);
    unsigned long index = hash % table->capacity;
    HashNode* current = table->buckets[index];

    while (current) {
        if (table->compare_keys(current->key, key) == 0) {
            current->value = (void*)value;
            return;
        }
        current = current->next;
    }

    HashNode* new_node = malloc(sizeof(HashNode));
    if (!new_node) return;
    new_node->key = (void*)key;
    new_node->value = (void*)value;
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
    table->size++;
}

void* hash_table_get(const HashTable* table, const void* key) {
    if (!table || !key) return NULL;

    unsigned long hash = table->hash_func(key) % table->capacity;
    HashNode* current = table->buckets[hash];

    while (current != NULL) {
        if (table->compare_keys(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

int hash_table_contains_key(const HashTable* table, const void* key) {
return hash_table_get(table, key) != NULL;
}

void hash_table_remove(HashTable* table, const void* key) {
    if (!table || !key) return;

    unsigned long hash = table->hash_func(key) % table->capacity;
    HashNode* current = table->buckets[hash];
    HashNode* prev = NULL;

    while (current != NULL) {
        if (table->compare_keys(current->key, key) == 0) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                table->buckets[hash] = current->next;
            }

            free(current);
            table->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

int hash_table_size(const HashTable* table) {
return table->size;
}

void** hash_table_keyset(const HashTable* table) {
    if (!table || table->size == 0) return NULL;
    void** keys = malloc(table->size * sizeof(void*));
    size_t index = 0;

    for (size_t i = 0; i < table->capacity; i++) {
        HashNode* current = table->buckets[i];
        while (current != NULL) {
            keys[index++] = current->key;
            current = current->next;
        }
    }
    return keys;
}

void hash_table_free(HashTable* table) {
    if (!table) return;

    for (size_t i = 0; i < table->capacity; i++) {
        HashNode* current = table->buckets[i];
        while (current) {
            HashNode* temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(table->buckets);
    free(table);
}