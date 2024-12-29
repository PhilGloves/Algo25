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
