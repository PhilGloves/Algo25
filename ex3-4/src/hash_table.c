#include "hash_table.h"

#include <stdio.h>

// Funzione di creazione della tavola hash
HashTable* hash_table_create(int (*f1)(const void*, const void*), unsigned long (*f2)(const void*)) {
HashTable* table = malloc(sizeof(HashTable));
table->capacity = 16; // Capacità iniziale
table->size = 0;
table->buckets = calloc(table->capacity, sizeof(HashNode*));
table->compare_keys = f1;
table->hash_func = f2;
return table;
}

static void hash_table_resize(HashTable* table) {
    size_t new_capacity = table->capacity * 2;
    HashNode** new_buckets = calloc(new_capacity, sizeof(HashNode*));
    if (!new_buckets) return; // Fallisce silenziosamente per semplicità

    for (size_t i = 0; i < table->capacity; i++) {
        HashNode* current = table->buckets[i];
        while (current) {
            // Ricalcola l'hash per la nuova capacità
            size_t new_index = current->cached_hash % new_capacity;
            HashNode* next = current->next;

            // Inserisce il nodo nella nuova tabella
            current->next = new_buckets[new_index];
            new_buckets[new_index] = current;

            current = next;
        }
    }

    // Libera i vecchi bucket e aggiorna la tabella
    free(table->buckets);
    table->buckets = new_buckets;
    table->capacity = new_capacity;
}

// Funzione per inserire un elemento
void hash_table_put(HashTable* table, const void* key, const void* value) {
    if (!table || !key) return;

    if ((float)(table->size + 1) / table->capacity > 0.75) {
        hash_table_resize(table); // Ridimensiona se necessario
    }

    unsigned long hash = table->hash_func(key);
    unsigned long index = hash % table->capacity;
    HashNode* current = table->buckets[index];

    while (current) {
        if (table->compare_keys(current->key, key) == 0) {
            current->value = (void*)value; // Aggiorna il valore
            return;
        }
        current = current->next;
    }

    // Inserisce un nuovo nodo
    HashNode* new_node = malloc(sizeof(HashNode));
    if (!new_node) return; // Gestione del fallimento dell'allocazione
    new_node->key = (void*)key;
    new_node->value = (void*)value;
    new_node->cached_hash = hash;
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
    table->size++;
}

// Funzione per ottenere un valore
void* hash_table_get(const HashTable* table, const void* key) {
    if (!table || !key) return NULL;

    unsigned long hash = table->hash_func(key) % table->capacity;
    HashNode* current = table->buckets[hash];

    while (current) {
        if (table->compare_keys(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

// Funzione per verificare la presenza di una chiave
int hash_table_contains_key(const HashTable* table, const void* key) {
return hash_table_get(table, key) != NULL;
}

// Funzione per rimuovere un elemento
void hash_table_remove(HashTable* table, const void* key) {
    if (!table || !key) return;

    unsigned long hash = table->hash_func(key) % table->capacity;
    HashNode* current = table->buckets[hash];
    HashNode* prev = NULL;

    while (current) {
        if (table->compare_keys(current->key, key) == 0) {
            if (prev) {
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

// Funzione per ottenere il numero di elementi
int hash_table_size(const HashTable* table) {
return table->size;
}

// Funzione per ottenere tutte le chiavi
void** hash_table_keyset(const HashTable* table) {
    void** keys = malloc(table->size * sizeof(void*));
    size_t index = 0;

    for (size_t i = 0; i < table->capacity; i++) {
        HashNode* current = table->buckets[i];
        while (current) {
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

            free(temp); // Liberare anche key/value se necessario
        }
    }

    free(table->buckets);
    free(table);
}