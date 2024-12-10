#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Linked list node used in a hash table bucket.
 *
 * Each bucket in the hash table is a linked list to handle collisions.
 * A node contains a key, a value, and a pointer to the next node in the list.
 */
typedef struct HashNode {
    void* key;                 /**< The key associated with the value. */
    void* value;               /**< The value associated with the key. */
    struct HashNode* next;     /**< Pointer to the next node in the list. */
} HashNode;

/**
 * @brief Main structure representing a hash table.
 *
 * Holds the array of buckets, size, capacity, and other metadata
 * required to manage hash table operations.
 */
typedef struct HashTable {
    HashNode** buckets;                /**< Array of buckets. */
    int capacity;                      /**< Number of available buckets. */
    int size;                          /**< Current number of elements in the table. */
    bool allow_resize;                 /**< Flag indicating if resizing is allowed. */
    int (*compare_keys)(const void*, const void*); /**< Pointer to the function for comparing keys. */
    unsigned long (*hash_func)(const void*);       /**< Pointer to the hash function. */
    void (*free_key)(void*);                       /**< Pointer to the function for freeing keys. */
    void (*free_value)(void*);                     /**< Pointer to the function for freeing values. */
} HashTable;

/**
 * @brief Creates a new hash table.
 *
 * @param initial_capacity The initial number of buckets.
 * @param allow_resize Flag indicating whether the hash table can be resized.
 * @param compare_keys Pointer to a function used to compare keys.
 * @param hash_func Pointer to a function used to compute hash values for keys.
 * @param free_key Pointer to a function to free memory associated with keys (can be NULL).
 * @param free_value Pointer to a function to free memory associated with values (can be NULL).
 *
 * @return Pointer to the newly created hash table, or NULL if allocation fails.
 */
HashTable* hash_table_create(
    int initial_capacity,
    bool allow_resize,
    int (*compare_keys)(const void*, const void*),
    unsigned long (*hash_func)(const void*),
    void (*free_key)(void*),
    void (*free_value)(void*)
);

/**
 * @brief Inserts or updates a key-value pair in the hash table.
 *
 * If the key already exists, its associated value will be updated.
 *
 * @param table Pointer to the hash table.
 * @param key Pointer to the key to insert.
 * @param value Pointer to the value to associate with the key.
 *
 * @return 0 on success, -1 on failure (e.g., memory allocation failure).
 */
int hash_table_put(HashTable* table, const void* key, const void* value);

/**
 * @brief Retrieves the value associated with a given key.
 *
 * @param table Pointer to the hash table.
 * @param key Pointer to the key to search for.
 *
 * @return Pointer to the value associated with the key, or NULL if the key does not exist.
 */
void* hash_table_get(const HashTable* table, const void* key);

/**
 * @brief Checks if a given key exists in the hash table.
 *
 * @param table Pointer to the hash table.
 * @param key Pointer to the key to check.
 *
 * @return Non-zero if the key exists, 0 otherwise.
 */
int hash_table_contains_key(const HashTable* table, const void* key);

/**
 * @brief Removes a key-value pair from the hash table.
 *
 * Frees memory for the key and value using the provided free functions, if set.
 *
 * @param table Pointer to the hash table.
 * @param key Pointer to the key to remove.
 */
void hash_table_remove(HashTable* table, const void* key);

/**
 * @brief Retrieves the current number of elements in the hash table.
 *
 * @param table Pointer to the hash table.
 *
 * @return The number of elements in the hash table, or 0 if the table is NULL.
 */
int hash_table_size(const HashTable* table);

/**
 * @brief Retrieves all keys in the hash table as an array.
 *
 * The caller is responsible for freeing the returned array.
 *
 * @param table Pointer to the hash table.
 *
 * @return Pointer to an array of keys, or NULL if the table is empty or allocation fails.
 */
void** hash_table_keyset(const HashTable* table);

/**
 * @brief Frees all memory associated with the hash table.
 *
 * This includes all buckets, keys, and values, using the provided free functions.
 *
 * @param table Pointer to the hash table to free.
 */
void hash_table_free(HashTable* table);

/**
 * @brief Resizes the hash table to a specified capacity.
 *
 * @param table Pointer to the hash table.
 * @param new_capacity The new number of buckets.
 *
 * @return 0 on success, -1 on failure (e.g., insufficient memory or invalid capacity).
 */
int hash_table_resize_to(HashTable* table, int new_capacity);

#endif // HASH_TABLE_H
