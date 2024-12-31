#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "edit_distance.h"

//Growth factor used to reallocate the array when it's full
#define GROWTH_FACTOR 1.5

typedef struct {
    char *string;
} Word;

typedef struct {
    Word *array;
    size_t size;
    size_t capacity;
} WordArray;

int is_alphanumeric(char c) {
    return isalnum((unsigned char)c);
}

void remove_punctuation(char *str) {
    char *source = str;
    char *destination = str;

    while (*source != '\0') {
        if (is_alphanumeric(*source)) {
            *destination = (char)tolower((unsigned char)*source);
            destination++;
        }
        source++;
    }
    *destination = '\0';
}

void init_word_array(WordArray *warr, size_t initial_capacity) {
    warr->size = 0;
    warr->capacity = initial_capacity;
    warr->array = (Word *)malloc(sizeof(Word) * initial_capacity);
    if (!warr->array) {
        fprintf(stderr, "Unable to allocate memory for WordArray\n");
        exit(EXIT_FAILURE);
    }
}

void add_word(WordArray *warr, const char *new_word) {
    if (warr->size == warr->capacity) {
        warr->capacity = (size_t)(warr->capacity * GROWTH_FACTOR);
        Word *temp = (Word *)realloc(warr->array, sizeof(Word) * warr->capacity);
        if (!temp) {
            fprintf(stderr, "Unable to reallocate memory for WordArray\n");
            exit(EXIT_FAILURE);
        }
        warr->array = temp;
    }
    size_t len = strlen(new_word);
    warr->array[warr->size].string = (char *)malloc(len + 1);
    if (!warr->array[warr->size].string) {
        fprintf(stderr, "Unable to allocate memory for new_word\n");
        exit(EXIT_FAILURE);
    }
    strcpy(warr->array[warr->size].string, new_word);
    warr->size++;
}

void free_word_array(WordArray *warr) {
    for (size_t i = 0; i < warr->size; i++) {
        free(warr->array[i].string);
    }
    free(warr->array);
    warr->array = NULL;
    warr->size = 0;
    warr->capacity = 0;
}

void read_dictionary(FILE *fp, WordArray *dictionary) {
    char buffer[512];

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
            len--;
        }
        add_word(dictionary, buffer);
    }
}

void read_correctme(FILE *fp, WordArray *correctme) {
    char buffer[512];

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
        char *word = strtok(buffer, " ");
        while (word != NULL) {
            remove_punctuation(word);
            if (strlen(word) > 0) {
                add_word(correctme, word);
            }
            word = strtok(NULL, " ");
        }
    }
}

void get_minimum_distance_words(WordArray *dictionary, const char *word) {
    int min_distance = INT_MAX;
    size_t count = 0;
    Word *min_words = NULL;

    for (size_t i = 0; i < dictionary->size; i++) {
        int distance = edit_distance_dyn(word, dictionary->array[i].string);
        if (distance < min_distance) {
            min_distance = distance;
            count = 0; 
            if (min_words) { 
                free(min_words);
                min_words = NULL;
            }
        }
        if (distance == min_distance) {
            min_words = (Word *)realloc(min_words, (count + 1) * sizeof(Word)); 
            if (!min_words) {
                fprintf(stderr, "Failed to allocate memory for min_words\n");
                exit(EXIT_FAILURE);
            }
            min_words[count++] = dictionary->array[i];
        }
    }

    printf("Words with minimum distance %d from \"%s\": ", min_distance, word);
    for (size_t i = 0; i < count; i++) {
        printf("%s ", min_words[i].string);
    }
    printf("\n");

    free(min_words); 
}

void scan_words(WordArray *correctme, WordArray *dictionary) {
    for (size_t i = 0; i < correctme->size; i++) {
        get_minimum_distance_words(dictionary, correctme->array[i].string);
    }
}



int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Two arguments needed. Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    FILE *dictionary_file = fopen(argv[1], "r");
    FILE *correctme_file = fopen(argv[2], "r");

    if(dictionary_file == NULL || correctme_file == NULL){
        fprintf(stderr, "Couldn't open dictionary or correctme file\n");
        exit(EXIT_FAILURE);
    }

    WordArray dictionary_array;
    WordArray correctme_array;

    init_word_array(&dictionary_array, 10);
    init_word_array(&correctme_array, 10);

    read_dictionary(dictionary_file, &dictionary_array);
    read_correctme(correctme_file, &correctme_array);

    fclose(dictionary_file);
    fclose(correctme_file);

    scan_words(&correctme_array, &dictionary_array);

    free_word_array(&dictionary_array);
    free_word_array(&correctme_array);

    return 0;
}
