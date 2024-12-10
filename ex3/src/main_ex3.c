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
