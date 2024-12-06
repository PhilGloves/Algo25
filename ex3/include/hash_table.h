#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <stdbool.h>

// Nodo della lista concatenata per un bucket
typedef struct HashNode {
    void* key;
    void* value;
    struct HashNode* next;
} HashNode;

// Struttura principale della hash table
typedef struct HashTable {
    HashNode** buckets;               // Array di bucket
    int capacity;                     // Numero di bucket
    int size;                         // Numero di elementi attualmente presenti
    bool allow_resize;                // Consente il ridimensionamento
    int (*compare_keys)(const void*, const void*);
    unsigned long (*hash_func)(const void*);
    void (*free_key)(void*);
    void (*free_value)(void*);
} HashTable;

// Funzioni principali
HashTable* hash_table_create(
    int initial_capacity,
    bool allow_resize,
    int (*compare_keys)(const void*, const void*),
    unsigned long (*hash_func)(const void*),
    void (*free_key)(void*),
    void (*free_value)(void*)
);
int hash_table_put(HashTable* table, const void* key, const void* value);
void* hash_table_get(const HashTable* table, const void* key);
int hash_table_contains_key(const HashTable* table, const void* key);
void hash_table_remove(HashTable* table, const void* key);
int hash_table_size(const HashTable* table);
void** hash_table_keyset(const HashTable* table);
void hash_table_free(HashTable* table);
int hash_table_resize_to(HashTable* table, int new_capacity);

#endif // HASH_TABLE_H