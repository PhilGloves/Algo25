## Iterazione 1 
### Input
Libreria generica su hash table concatenate e tutte le funzioni da generare, fornite nella consegna
### Output
Libreria completa, fornito il codice dei file ".c" e ".h" commentato.

__File: hash_table.h__
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

__File: hash_table.c__

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
---
## Iterazione 2
Dati i possibili errori, chiedo in maniera generica come sarebbe possibile migliorare la libreria appena generata.
### Input
Come miglioreresti il codice sopra fornito?
### Output
Come notato alla fine della prima iterazione, il LLM ha dato suggerimenti su:
- Gestione della memoria: Supporto opzionale per liberare la memoria delle chiavi e dei valori.
- Gestione della capacità: Ridimensionamento automatico per mantenere un buon fattore di carico ed evitare il degrado delle prestazioni.
- Error handling: Restituire valori indicativi per verificare errori o stati della struttura.

__Nuovo file header :__
```
// Struttura modificata
typedef struct HashTable {
    HashNode** buckets;                       // Array di bucket
    size_t capacity;                          // Numero di bucket
    size_t size;                              // Numero di elementi
    int (*compare_keys)(const void*, const void*);   // Funzione di confronto
    unsigned long (*hash_func)(const void*);         // Funzione di hash
    void (*free_key)(void*);                  // Funzione opzionale per liberare le chiavi
    void (*free_value)(void*);                // Funzione opzionale per liberare i valori
} HashTable;

// Funzioni principali
HashTable* hash_table_create(
    int (*compare_keys)(const void*, const void*), 
    unsigned long (*hash_func)(const void*), 
    void (*free_key)(void*), 
    void (*free_value)(void*)
);

int hash_table_put(HashTable*, const void* key, const void* value); // Restituisce 0 se OK, -1 se errore
void* hash_table_get(const HashTable*, const void* key);            // Valore o NULL se non trovato
int hash_table_contains_key(const HashTable*, const void* key);     // 1 se trovato, 0 altrimenti
int hash_table_remove(HashTable*, const void* key);                 // 0 se OK, -1 se errore
size_t hash_table_size(const HashTable*);                           // Numero di elementi
void** hash_table_keyset(const HashTable*, size_t* count);          // Array di chiavi
void hash_table_resize(HashTable*);                                 // Ridimensiona dinamicamente
void hash_table_free(HashTable*);                                   // Libera memoria
```

__Funzioni modificate :__
<details>
  <summary>hash_table_create</summary>

```
HashTable* hash_table_create(
    int (*compare_keys)(const void*, const void*), 
    unsigned long (*hash_func)(const void*), 
    void (*free_key)(void*), 
    void (*free_value)(void*)
) {
    HashTable* table = malloc(sizeof(HashTable));
    table->capacity = 16;
    table->size = 0;
    table->buckets = calloc(table->capacity, sizeof(HashNode*));
    table->compare_keys = compare_keys;
    table->hash_func = hash_func;
    table->free_key = free_key;
    table->free_value = free_value;
    return table;
}
```
</details>
<details>
  <summary>hash_table_put</summary>

```
int hash_table_put(HashTable* table, const void* key, const void* value) {
    if ((float)table->size / table->capacity > 0.75) {
        hash_table_resize(table);
    }

    unsigned long hash = table->hash_func(key) % table->capacity;
    HashNode* current = table->buckets[hash];

    while (current) {
        if (table->compare_keys(current->key, key) == 0) {
            if (table->free_value) {
                table->free_value(current->value);
            }
            current->value = (void*)value;
            return 0;
        }
        current = current->next;
    }

    HashNode* new_node = malloc(sizeof(HashNode));
    if (!new_node) return -1; // Errore di allocazione
    new_node->key = (void*)key;
    new_node->value = (void*)value;
    new_node->next = table->buckets[hash];
    table->buckets[hash] = new_node;
    table->size++;
    return 0;
}
```
</details>
<details>
  <summary>hash_table_resize</summary>

```
void hash_table_resize(HashTable* table) {
    size_t new_capacity = table->capacity * 2;
    HashNode** new_buckets = calloc(new_capacity, sizeof(HashNode*));

    for (size_t i = 0; i < table->capacity; i++) {
        HashNode* current = table->buckets[i];
        while (current) {
            unsigned long new_hash = table->hash_func(current->key) % new_capacity;

            HashNode* next = current->next;
            current->next = new_buckets[new_hash];
            new_buckets[new_hash] = current;

            current = next;
        }
    }

    free(table->buckets);
    table->buckets = new_buckets;
    table->capacity = new_capacity;
}
```
</details>
<details>
  <summary>hash_table_remove</summary>

```
int hash_table_remove(HashTable* table, const void* key) {
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

            if (table->free_key) {
                table->free_key(current->key);
            }
            if (table->free_value) {
                table->free_value(current->value);
            }

            free(current);
            table->size--;
            return 0;
        }
        prev = current;
        current = current->next;
    }
    return -1; // Chiave non trovata
}
```
</details>
<details>
  <summary>hash_table_free</summary>

```
void hash_table_free(HashTable* table) {
    for (size_t i = 0; i < table->capacity; i++) {
        HashNode* current = table->buckets[i];
        while (current) {
            HashNode* temp = current;
            if (table->free_key) {
                table->free_key(temp->key);
            }
            if (table->free_value) {
                table->free_value(temp->value);
            }
            current = current->next;
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}
```
</details>

Tutte le modifiche che dovevano essere apportate al codice sono state segnalate e i problemi trovati alla fine della prima iterazione sono stati risolti.
Tuttavia la possibilità di inizializzare la capacità della hash table e avere la capacità fissa (togliere il ridimensionamento automatico), sono delle caratteristiche fondamentali per una libreria generica.
---
## Iterazione 3

### Input
Potresti aggiungere la possibilità di scegliere un valore iniziale di capacità e di non permettere il suo ampliamento?
### Output
__Modifiche apportate :__
<details>
  <summary>Struct HasteTable</summary>

```
typedef struct HashTable {
    HashNode** buckets;                       // Array di bucket
    size_t capacity;                          // Numero di bucket
    size_t size;                              // Numero di elementi
    int allow_resize;                         // Flag per consentire il ridimensionamento
    int (*compare_keys)(const void*, const void*);   // Funzione di confronto
    unsigned long (*hash_func)(const void*);         // Funzione di hash
    void (*free_key)(void*);                  // Funzione opzionale per liberare le chiavi
    void (*free_value)(void*);                // Funzione opzionale per liberare i valori
} HashTable;
```
</details>
<details>
  <summary>hash_table_create</summary>

```
HashTable* hash_table_create(
    int (*compare_keys)(const void*, const void*), 
    unsigned long (*hash_func)(const void*), 
    void (*free_key)(void*), 
    void (*free_value)(void*), 
    size_t initial_capacity, 
    int allow_resize
) {
    if (initial_capacity == 0) {
        initial_capacity = 16; // Capacità predefinita
    }

    HashTable* table = malloc(sizeof(HashTable));
    table->capacity = initial_capacity;
    table->size = 0;
    table->buckets = calloc(table->capacity, sizeof(HashNode*));
    table->compare_keys = compare_keys;
    table->hash_func = hash_func;
    table->free_key = free_key;
    table->free_value = free_value;
    table->allow_resize = allow_resize;
    return table;
}
```
</details>
<details>
  <summary>hash_table_put</summary>

```
int hash_table_put(HashTable* table, const void* key, const void* value) {
    if (table->allow_resize && (float)table->size / table->capacity > 0.75) {
        hash_table_resize(table);
    } else if (!table->allow_resize && table->size >= table->capacity) {
        return -1; // Errore: capacità massima raggiunta
    }

    unsigned long hash = table->hash_func(key) % table->capacity;
    HashNode* current = table->buckets[hash];

    while (current) {
        if (table->compare_keys(current->key, key) == 0) {
            if (table->free_value) {
                table->free_value(current->value);
            }
            current->value = (void*)value;
            return 0;
        }
        current = current->next;
    }

    HashNode* new_node = malloc(sizeof(HashNode));
    if (!new_node) return -1; // Errore di allocazione
    new_node->key = (void*)key;
    new_node->value = (void*)value;
    new_node->next = table->buckets[hash];
    table->buckets[hash] = new_node;
    table->size++;
    return 0;
}
```
</details>
<details>
  <summary>hash_table_resize</summary>

```
void hash_table_resize(HashTable* table) {
    if (!table->allow_resize) return; // Non ridimensionare se il flag è disabilitato

    size_t new_capacity = table->capacity * 2;
    HashNode** new_buckets = calloc(new_capacity, sizeof(HashNode*));

    for (size_t i = 0; i < table->capacity; i++) {
        HashNode* current = table->buckets[i];
        while (current) {
            unsigned long new_hash = table->hash_func(current->key) % new_capacity;

            HashNode* next = current->next;
            current->next = new_buckets[new_hash];
            new_buckets[new_hash] = current;

            current = next;
        }
    }

    free(table->buckets);
    table->buckets = new_buckets;
    table->capacity = new_capacity;
}
```
</details>

Le modifiche sono corrette, ma ha imposto un limite di elementi inseribili nel caso di hash table non ridimensionabile. Tenere in considerazione il fattore di carico (size/capacity) è giusto, ma è compito del programmatore non sovraccaricare la hash table. Inoltre vorresti avere la possibilità di modificare la capacità a una quantità desiderata in qualsiasi momento.

---
## Iterazione 4

### Input
Puoi scrivere la libreria togliendo il limite di elementi che puoi aggiungere in base alla capacità(nella funzione put) e inserire una funzione che ti permetta in qualsiasi momento di modificare la capacità?
### Output
