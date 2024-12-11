## Iterazione 1
### Input
Libreria generica su hash table concatenate e tutte le funzioni da generare, fornite nella consegna
### Output
Libreria completa, fornito il codice dei file ".c" e ".h" commentato.

<details>
  <summary>File hash_table.h</summary>

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
</details>

<details>
  <summary>File: hash_table.c</summary>

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
</details>

Da notare che nel input fornito la funzione di creazione della hash table non aveva dei parametri con un nome esplicativo, il LLM gli ha dato la giusta interpretazione.
Il codice fornito soddisfa le richieste della traccia, anche se è possibile notare :

- una mancanza di gestione degli errori
- una capacità iniziale, alla creazione della hash table che non puoi scegliere
- una possibile cattiva gestione della memoria dovuta al free che non libera la memoria occupata dai valori (<chiave,valore>) e anche della chiave (es. una coppia <struct,struct>)
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

<details>
  <summary>File hash_table.h</summary>

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
</details>

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
<details>
  <summary>File hash_table.h</summary>

```
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

// Nuova funzione: Ridimensionamento forzato della tabella
int hash_table_resize_to(HashTable* table, int new_capacity);

#endif // HASH_TABLE_H
```
</details>

<details>
  <summary>File hash_table.c</summary>

```
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
```
</details>

Il codice fornito ora sembra soddisfare tutte le richieste e offre varie possibilità di personalizzazione.
Adesso procedo con scrivere il codice e testarlo con unit test che creerò nella prossima iterazione grazie al LLM.

___

## Iterazione 5

### Input
Scrivi degli unit test per testare ogni funzione della libreria in "modalità" diverse quindi utilizzando o no le funzioni di free e allow_resize. gli unit test devono essere fatti grazie alla libreria unity e devono essere fatti su situazione "particolari".
### Output

<details>
  <summary>File test_ex3.c</summary>

```
#include "unity.h"
#include "hash_table.h"
#include <string.h>
#include <stdlib.h>

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

// Test del comportamento con capacità insufficiente
void test_put_over_capacity_no_resize(void) {
    table = hash_table_create(2, false, compare_keys, hash_func, NULL, NULL);
    hash_table_put(table, "key1", "value1");
    hash_table_put(table, "key2", "value2");

    // Il terzo inserimento non deve essere permesso
    int result = hash_table_put(table, "key3", "value3");
    TEST_ASSERT_EQUAL(-1, result);
    TEST_ASSERT_EQUAL(2, hash_table_size(table));
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
    RUN_TEST(test_put_over_capacity_no_resize);

    return UNITY_END();
}
```
</details>

La serie di test generati vengono eseguiti correttamente e testano varie funzionalità della libreria. L'unico test che fallisce è l'ultimo, perchè non ha tenuto in memoria il cambiamento che ho richiesto nella scorsa iterazione, rendendo il test inutile.

Ora tolgo il test inutile e ne aggiungo di significativi.

___

## Iterazione 6
Questa iterazione è stata fatta in un momento e una chat diversa.
### Input
Crea un programma che calcola la parola più frequente con lunghezza minima da un file di testo, usando questa libreria: *file hash_table.c*
### Output

<details>
  <summary>File main_ex3.c</summary>

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hash_table.h"

// Funzione hash per le stringhe
unsigned long string_hash(const void* key) {
    const char* str = (const char*)key;
    unsigned long hash = 5381;
    while (*str) {
        hash = ((hash << 5) + hash) + *str++; // hash * 33 + c
    }
    return hash;
}

// Funzione di confronto per le stringhe
int string_compare(const void* a, const void* b) {
    return strcmp((const char*)a, (const char*)b);
}

// Funzione per trovare la parola più frequente con lunghezza minima
char* find_most_frequent_word(const char* filename, size_t min_length) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Errore nell'aprire il file: %s\n", filename);
        return NULL;
    }

    // Crea una hash table
    HashTable* table = hash_table_create(
        16,                    // Capacità iniziale
        true,                  // Consenti ridimensionamento
        string_compare,        // Funzione di confronto
        string_hash,           // Funzione hash
        free,                  // Funzione per liberare le chiavi
        free                   // Funzione per liberare i valori
    );
    if (!table) {
        fclose(file);
        fprintf(stderr, "Errore nella creazione della hash table.\n");
        return NULL;
    }

    char word[256];
    while (fscanf(file, "%255s", word) != EOF) {
        if (strlen(word) < min_length) {
            continue;
        }

        // Controlla se la parola è già nella tabella
        int* count = (int*)hash_table_get(table, word);
        if (count) {
            (*count)++;
        } else {
            // Nuova parola
            int* new_count = malloc(sizeof(int));
            if (!new_count) {
                fprintf(stderr, "Errore di memoria.\n");
                fclose(file);
                hash_table_free(table);
                return NULL;
            }
            *new_count = 1;
            hash_table_put(table, strdup(word), new_count);
        }
    }
    fclose(file);

    // Trova la parola più frequente
    char* most_frequent_word = NULL;
    int max_count = 0;

    void** keys = hash_table_keyset(table);
    int size = hash_table_size(table);

    for (int i = 0; i < size; i++) {
        const char* key = keys[i];
        int* value = (int*)hash_table_get(table, key);
        if (*value > max_count) {
            max_count = *value;
            most_frequent_word = (char*)key; // Non liberiamo "key", è gestito dalla hash table
        }
    }
    free(keys);

    // Copia la parola più frequente per restituirla
    char* result = most_frequent_word ? strdup(most_frequent_word) : NULL;

    // Libera la tabella
    hash_table_free(table);

    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <file di testo> <lunghezza minima>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    size_t min_length = (size_t)atoi(argv[2]);

    char* result = find_most_frequent_word(filename, min_length);
    if (result) {
        printf("La parola più frequente di lunghezza almeno %zu è: %s\n", min_length, result);
        free(result);
    } else {
        printf("Nessuna parola valida trovata o errore durante l'analisi.\n");
    }

    return 0;
}
```
</details>

Il main viene eseguito correttamente e la richiesta è rispettata.
L'input in questo caso è diverso, il codice della libreria è stato letto e usato nel contesto della richiesta correttamente, ciascuna funzione utilizzata è stata compresa dal LLM.

___

## Iterazione extra
Dato che il correttore automatico per questo esercizio prevede una libreria che ha le funzioni strutturate come nella consegna, ho ripreso l'output generato alla prima iterazione e ho creato una versione base della libreria, che non prevede alcun cambiamento che è stato inserito nel corso delle iterazioni.
Per farlo è stato chiesto al LLM, come nella sesta iterazione, il main e i test, dando in input il file [hash_table.c](#iterazione-1).
Per comodità i file avranno lo stesso nome dei rispettivi sviluppati fino a ora.

### Output

<details>
  <summary>File main_ex3.c</summary>

```
#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Per funzioni di controllo sui caratteri

// Funzione hash per le stringhe
unsigned long string_hash(const void* key) {
    const char* str = (const char*)key;
    unsigned long hash = 5381;
    while (*str) {
        hash = ((hash << 5) + hash) + *str++; // hash * 33 + c
    }
    return hash;
}

// Funzione di confronto per le stringhe
int string_compare(const void* a, const void* b) {
    return strcmp((const char*)a, (const char*)b);
}

// Funzione per filtrare una parola, separando parole su caratteri non alfabetici
void filter_word(char* word) {
    size_t len = strlen(word);
    size_t j = 0;

    for (size_t i = 0; i < len; i++) {
        if (isalpha(word[i])) { // Controlla se il carattere è una lettera
            word[j++] = tolower(word[i]); // Converte il carattere in minuscolo
        } else {
            word[j] = '\0'; // Termina la parola corrente
            break; // La funzione lascia che il resto venga gestito separatamente
        }
    }
    word[j] = '\0'; // Termina la stringa
}

// Funzione per trovare la parola più frequente con lunghezza minima
void find_most_frequent_word(const char* filename, int min_length) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Errore nell'aprire il file: %s\n", filename);
        return;
    }

    // Creazione della hash table
    HashTable* table = hash_table_create(string_compare, string_hash);
    if (!table) {
        fclose(file);
        fprintf(stderr, "Errore nella creazione della hash table.\n");
        return;
    }

    char word[256];
    while (fscanf(file, "%255s", word) != EOF) {
        filter_word(word); // Rimuove caratteri non validi

        if (strlen(word) < (size_t)min_length) {
            continue; // Salta le parole troppo corte
        }

        // Cerca la parola nella hash table
        int* count = (int*)hash_table_get(table, word);
        if (count) {
            (*count)++;
        } else {
            // Nuova parola, aggiungila alla hash table
            int* new_count = malloc(sizeof(int));
            if (!new_count) {
                fprintf(stderr, "Errore di memoria.\n");
                fclose(file);
                hash_table_free(table);
                return;
            }
            *new_count = 1;
            hash_table_put(table, strdup(word), new_count);
        }
    }
    fclose(file);

    // Trova tutte le parole con il conteggio massimo
    void** keys = hash_table_keyset(table);
    int size = hash_table_size(table);

    int max_count = 0;
    for (int i = 0; i < size; i++) {
        const char* key = (const char*)keys[i];
        int* count = (int*)hash_table_get(table, key);
        if (*count > max_count) {
            max_count = *count;
        }
    }

    printf("Le parole più frequenti con lunghezza almeno %d sono:\n", min_length);
    for (int i = 0; i < size; i++) {
        const char* key = (const char*)keys[i];
        int* count = (int*)hash_table_get(table, key);
        if (*count == max_count) {
            printf("'%s' (conteggio: %d)\n", key, *count);
        }
    }

    if (max_count == 0) {
        printf("Nessuna parola con lunghezza almeno %d trovata.\n", min_length);
    }

    // Libera la memoria
    free(keys);
    hash_table_free(table);
}



int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <file di testo> <lunghezza minima>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    int min_length = atoi(argv[2]);

    if (min_length <= 0) {
        fprintf(stderr, "La lunghezza minima deve essere un intero positivo.\n");
        return 1;
    }

    find_most_frequent_word(filename, min_length);

    return 0;
}
```
</details>

<details>
  <summary>File test_ex3.c</summary>

```
#include "hash_table.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>

// Funzione hash per stringhe
unsigned long string_hash(const void* key) {
    const char* str = (const char*)key;
    unsigned long hash = 5381;
    while (*str) {
        hash = ((hash << 5) + hash) + *str++; // hash * 33 + c
    }
    return hash;
}

// Funzione di confronto per stringhe
int string_compare(const void* a, const void* b) {
    return strcmp((const char*)a, (const char*)b);
}

void setUp(void) {
    // Funzione chiamata prima di ogni test
}

void tearDown(void) {
    // Funzione chiamata dopo ogni test
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
    RUN_TEST(test_hash_table_put_and_get);
    RUN_TEST(test_hash_table_update_value);
    RUN_TEST(test_hash_table_remove);
    RUN_TEST(test_hash_table_keyset);

    return UNITY_END();
}
```
</details>

I test risultano molto più semplici, dato che non ho richiesto dei test specifici. Invece il main cambia da quello già presentato, questo separa le parole, togliendo caratteri che non sono lettere e trasformando le parole tutte minuscole.
Dato che i test forniti su moodle richiedono questa versione, cambio il codice anche per la versione precedente.

___

## Conclusioni

La libreria ha subito una evoluzione significativa sia in termini di funzionalità che di robustezza, il processo di creazione è stato semplice e con la necessità di pochi input, lasciando alla interpretazione del LLM vari elementi non definiti.
Non si sono presentate problematiche gravi durante le iterazioni, sebbene una volta non abbia memorizzato il cambiamento richiesto e un'altra volta ha inserito un limite non richiesto e solitamente non utilizzato.
Questo genere di errori potrebbero essere sempre più frequenti man mano che la grandezza del codice richiesto aumenta, dato che il contesto e le conoscenze che deve avere memorizzate sono tante.
I LLM si presentano quindi molto utili al supporto alla programmazione a patto che si abbia una conoscenza dell'argomento e si sappia riconoscere gli errori. 

In questo esercizio è stato utilizzato esclusivamente ChatGPT, tutti gli input, escluso quello dell'iterazione 6, sono stati forniti sulla stessa chat.