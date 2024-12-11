#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>

// Struttura per i nodi della lista concatenata
typedef struct HashNode {
    void* key;               // Chiave generica
    void* value;             // Valore generico
    struct HashNode* next;   // Puntatore al nodo successivo
} HashNode;

// Struttura per la tavola hash
typedef struct HashTable {
    HashNode** buckets;            // Array di puntatori a nodi
    size_t capacity;               // Numero di bucket
    size_t size;                   // Numero di elementi nella tavola
    int (*compare_keys)(const void*, const void*);   // Funzione di confronto
    unsigned long (*hash_func)(const void*);         // Funzione di hash
} HashTable;

// Prototipi delle funzioni
HashTable* hash_table_create(int (*f1)(const void*, const void*), unsigned long (*f2)(const void*));
void hash_table_put(HashTable*, const void*, const void*);
void* hash_table_get(const HashTable*, const void*);
int hash_table_contains_key(const HashTable*, const void*);
void hash_table_remove(HashTable*, const void*);
int hash_table_size(const HashTable*);
void** hash_table_keyset(const HashTable*);
void hash_table_free(HashTable*);

#endif // HASH_TABLE_H