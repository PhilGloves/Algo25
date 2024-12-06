#include "hash_table.h"
#include <string.h>
#include <stdio.h>

// Funzione per creare una nuova hash table
HashTable* hash_table_create(
    int initial_capacity,
    bool allow_resize,
    int (*compare_keys)(const void*, const void*),
    unsigned long (*hash_func)(const void*),
    void (*free_key)(void*),
    void (*free_value)(void*)
) {
    if (initial_capacity <= 0 || !compare_keys || !hash_func) {
        return NULL;
    }

    HashTable* table = malloc(sizeof(HashTable));
    if (!table) return NULL;

    table->capacity = initial_capacity;
    table->size = 0;
    table->allow_resize = allow_resize;
    table->compare_keys = compare_keys;
    table->hash_func = hash_func;
    table->free_key = free_key;
    table->free_value = free_value;
    table->buckets = calloc(table->capacity, sizeof(HashNode*));
    if (!table->buckets) {
        free(table);
        return NULL;
    }

    return table;
}

// Funzione per ridimensionare la tabella hash
static int resize_table_internal(HashTable* table, int new_capacity) {
    if (new_capacity <= 0 || new_capacity < table->size) {
        return -1; // Capacità non valida
    }

    HashNode** new_buckets = calloc(new_capacity, sizeof(HashNode*));
    if (!new_buckets) return -1;

    for (int i = 0; i < table->capacity; i++) {
        HashNode* current = table->buckets[i];
        while (current) {
            unsigned long new_index = table->hash_func(current->key) % new_capacity;
            HashNode* next = current->next;

            current->next = new_buckets[new_index];
            new_buckets[new_index] = current;
            current = next;
        }
    }

    free(table->buckets);
    table->buckets = new_buckets;
    table->capacity = new_capacity;

    return 0;
}

// Funzione pubblica per ridimensionare a una capacità desiderata
int hash_table_resize_to(HashTable* table, int new_capacity) {
    if (!table) return -1;
    return resize_table_internal(table, new_capacity);
}

// Inserisce o aggiorna un elemento nella hash table
int hash_table_put(HashTable* table, const void* key, const void* value) {
    if (!table || !key) return -1;

    // Ridimensiona se necessario
    if (table->allow_resize && (float)table->size / table->capacity > 0.75) {
        resize_table_internal(table, table->capacity * 2);
    }

    unsigned long index = table->hash_func(key) % table->capacity;
    HashNode* current = table->buckets[index];

    while (current) {
        if (table->compare_keys(current->key, key) == 0) {
            if (table->free_value) table->free_value(current->value);
            current->value = (void*)value;
            return 0;
        }
        current = current->next;
    }

    HashNode* new_node = malloc(sizeof(HashNode));
    if (!new_node) return -1;
    new_node->key = (void*)key;
    new_node->value = (void*)value;
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
    table->size++;

    return 0;
}

// Ottiene un valore dalla hash table
void* hash_table_get(const HashTable* table, const void* key) {
    if (!table || !key) return NULL;

    unsigned long index = table->hash_func(key) % table->capacity;
    HashNode* current = table->buckets[index];

    while (current) {
        if (table->compare_keys(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

// Verifica se una chiave esiste nella tabella
int hash_table_contains_key(const HashTable* table, const void* key) {
    return hash_table_get(table, key) != NULL;
}

// Rimuove un elemento dalla hash table
void hash_table_remove(HashTable* table, const void* key) {
    if (!table || !key) return;

    unsigned long index = table->hash_func(key) % table->capacity;
    HashNode* current = table->buckets[index];
    HashNode* prev = NULL;

    while (current) {
        if (table->compare_keys(current->key, key) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                table->buckets[index] = current->next;
            }

            if (table->free_key) table->free_key(current->key);
            if (table->free_value) table->free_value(current->value);
            free(current);
            table->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Ritorna il numero di elementi nella tabella
int hash_table_size(const HashTable* table) {
    return table ? table->size : 0;
}

// Ritorna tutte le chiavi come array
void** hash_table_keyset(const HashTable* table) {
    if (!table || table->size == 0) return NULL;

    void** keys = malloc(table->size * sizeof(void*));
    if (!keys) return NULL;

    int index = 0;
    for (int i = 0; i < table->capacity; i++) {
        HashNode* current = table->buckets[i];
        while (current) {
            keys[index++] = current->key;
            current = current->next;
        }
    }
    return keys;
}

// Libera la memoria della hash table
void hash_table_free(HashTable* table) {
    if (!table) return;

    for (int i = 0; i < table->capacity; i++) {
        HashNode* current = table->buckets[i];
        while (current) {
            HashNode* next = current->next;
            if (table->free_key) table->free_key(current->key);
            if (table->free_value) table->free_value(current->value);
            free(current);
            current = next;
        }
    }

    free(table->buckets);
    free(table);
}