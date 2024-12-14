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
    RUN_TEST(test_hash_table_update_value);
    RUN_TEST(test_hash_table_put_and_get);
    RUN_TEST(test_hash_table_remove);
    RUN_TEST(test_hash_table_keyset);

    return UNITY_END();
}

/*
 ALTRI TEST
#include "unity.h"
#include "hash_table.h"
#include <stdlib.h>
#include <string.h>

// Funzioni di hash e confronto per stringhe
int string_compare(const void* a, const void* b) {
    return strcmp((const char*)a, (const char*)b);
}

unsigned long string_hash(const void* key) {
    const char* str = (const char*)key;
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

// Test principale
void test_hash_table_massive_operations(void) {
    HashTable* table = hash_table_create(string_compare, string_hash);

    const int total_keys = 10000; // Numero totale di coppie chiave-valore
    const int test_keys = total_keys / 5; // Percentuale di chiavi da testare

    char** keys = malloc(total_keys * sizeof(char*));
    char** values = malloc(total_keys * sizeof(char*));

    // Generazione di coppie chiave-valore casuali e inserimento nella hash table
    for (int i = 0; i < total_keys; i++) {
        keys[i] = malloc(16);
        values[i] = malloc(16);
        snprintf(keys[i], 16, "key%d", i);
        snprintf(values[i], 16, "value%d", i);
        hash_table_put(table, strdup(keys[i]), strdup(values[i]));
    }

    char buffer[1024];

    // Test recupero casuale di chiavi esistenti
    for (int i = 0; i < test_keys; i++) {
        int index = rand() % total_keys;
        char* result = (char*)hash_table_get(table, keys[index]);
        if (result == NULL) {
            snprintf(buffer , sizeof(buffer),
                "Chiave %s non trovata (indice %d)", keys[index], index);
            TEST_FAIL_MESSAGE(buffer);
        } else if (strcmp(result, values[index]) != 0) {
            snprintf(buffer , sizeof(buffer),
                "Valore errato per chiave %s (indice %d). Atteso: %s, Ottenuto: %s",
                keys[index], index, values[index], result);
            TEST_FAIL_MESSAGE(buffer);
        }
    }

    // Rimozione di una percentuale delle chiavi
    for (int i = 0; i < test_keys; i++) {
        int index = rand() % total_keys;
        hash_table_remove(table, keys[index]);
    }

    // Verifica che le chiavi rimosse non siano recuperabili
    for (int i = 0; i < test_keys; i++) {
        int index = rand() % total_keys;
        char* result = (char*)hash_table_get(table, keys[index]);
        if (result != NULL) {
            snprintf(buffer , sizeof(buffer),
                "Chiave %s trovata dopo rimozione (indice %d). Valore: %s",
                keys[index], index, result);
            TEST_FAIL_MESSAGE(buffer);
        }
    }

    // Verifica che le chiavi non rimosse siano ancora recuperabili
    for (int i = 0; i < test_keys; i++) {
        int index = rand() % total_keys;
        if (hash_table_contains_key(table, keys[index])) {
            char* result = (char*)hash_table_get(table, keys[index]);
            if (result == NULL) {
                snprintf(buffer , sizeof(buffer),
                    "Chiave %s non recuperabile dopo rimozioni (indice %d)",
                    keys[index], index);
                TEST_FAIL_MESSAGE(buffer);
            } else if (strcmp(result, values[index]) != 0) {
                snprintf(buffer , sizeof(buffer),
                    "Valore errato per chiave %s (indice %d) dopo rimozioni. Atteso: %s, Ottenuto: %s",
                    keys[index], index, values[index], result
                );
                TEST_FAIL_MESSAGE(buffer);
            }
        }
    }

    // Pulizia memoria
    for (int i = 0; i < total_keys; i++) {
        free(keys[i]);
        free(values[i]);
    }
    free(keys);
    free(values);
    hash_table_free(table);
}


void test_hash_table_delete_stress(void) {
    HashTable* table = hash_table_create(string_compare, string_hash);

    const int max_elements = 50000; // Numero massimo di elementi da inserire
    char** keys = malloc(max_elements * sizeof(char*));
    char** values = malloc(max_elements * sizeof(char*));

    // Inserimento di elementi nella tabella hash
    for (int count = 0; count < max_elements; count++) {
        keys[count] = malloc(16);
        values[count] = malloc(16);
        snprintf(keys[count], 16, "key%d", count);
        snprintf(values[count], 16, "value%d", count);

        hash_table_put(table, strdup(keys[count]), strdup(values[count]));
    }

    // Verifica iniziale: tutti gli elementi devono essere presenti
    for (int i = 0; i < max_elements; i++) {
        char* result = (char*)hash_table_get(table, keys[i]);
        if (!result || strcmp(result, values[i]) != 0) {
            printf("Errore: Chiave %s non trovata o valore errato. Atteso: %s, Ottenuto: %s\n",
                   keys[i], values[i], result ? result : "NULL");
            assert(0);
        }
    }

    printf("Inseriti %d elementi, verifica iniziale completata.\n", max_elements);

    // Cancellazione progressiva e verifica
    for (int count = 0; count < max_elements; count++) {
        hash_table_remove(table, keys[count]);

        // Verifica che l'elemento rimosso non sia più presente
        if (hash_table_get(table, keys[count]) != NULL) {
            printf("Errore: Chiave %s ancora presente dopo la rimozione.\n", keys[count]);
            assert(0);
        }

        // Verifica che gli elementi rimanenti siano ancora presenti
        for (int i = count + 1; i < max_elements; i++) {
            char* result = (char*)hash_table_get(table, keys[i]);
            if (!result || strcmp(result, values[i]) != 0) {
                printf("Errore: Chiave %s non trovata o valore errato dopo rimozione. Atteso: %s, Ottenuto: %s\n",
                       keys[i], values[i], result ? result : "NULL");
                assert(0);
            }
        }

        // Debug per verificare le dimensioni della tabella
        if ((count + 1) % 1000 == 0) {
            printf("Rimossi %d elementi, dimensione tabella: %d, capacita': %zu\n",
                   count + 1, hash_table_size(table), table->capacity);
        }
    }

    // Pulizia memoria
    for (int i = 0; i < max_elements; i++) {
        free(keys[i]);
        free(values[i]);
    }
    free(keys);
    free(values);
    hash_table_free(table);

    printf("Test completato con successo\n");
}
*/