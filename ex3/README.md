## Iterazione 1 
### Input
Libreria generica su hash table concatenate e tutte le funzioni da generare, fornite nella consegna
### Output
Libreria completa, fornito il codice dei file ".c" e ".h" commentato.

File: hash_table.h
```
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
```

File: hash_table.c

```
#include "hash_table.h"
#include <string.h>

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

// Funzione per inserire un elemento
void hash_table_put(HashTable* table, const void* key, const void* value) {
unsigned long hash = table->hash_func(key) % table->capacity;
HashNode* current = table->buckets[hash];

    // Cerca se la chiave esiste già
    while (current) {
        if (table->compare_keys(current->key, key) == 0) {
            current->value = (void*)value; // Aggiorna il valore
            return;
        }
        current = current->next;
    }

    // Altrimenti, aggiunge un nuovo nodo
    HashNode* new_node = malloc(sizeof(HashNode));
    new_node->key = (void*)key;
    new_node->value = (void*)value;
    new_node->next = table->buckets[hash];
    table->buckets[hash] = new_node;
    table->size++;
}

// Funzione per ottenere un valore
void* hash_table_get(const HashTable* table, const void* key) {
unsigned long hash = table->hash_func(key) % table->capacity;
HashNode* current = table->buckets[hash];

    while (current) {
        if (table->compare_keys(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL; // Chiave non trovata
}

// Funzione per verificare la presenza di una chiave
int hash_table_contains_key(const HashTable* table, const void* key) {
return hash_table_get(table, key) != NULL;
}

// Funzione per rimuovere un elemento
void hash_table_remove(HashTable* table, const void* key) {
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

// Funzione per liberare la memoria
void hash_table_free(HashTable* table) {
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
```

Da notare che nel input fornito la funzione di creazione della hash table non aveva dei parametri con un nome esplicativo, il LLM gli ha dato la giusta interpretazione.
Il codice fornito soddisfa le richieste della traccia, anche se è possibile notare :

- una mancanza di gestione degli errori
- una capacità iniziale, alla creazione della hash table che non puoi scegliere
- una possibile cattiva gestione della memoria dovuta al free che non libera la memoria occupata dai valori (<chiave,valore>) e anche della chiave (es. una coppia <string,string>)

## Iterazione 2
Dati i possibili errori, chiedo in maniera generica come sarebbe possibile migliorare la libreria appena generata.
### Input
Come miglioreresti il codice sopra fornito?
### Output
