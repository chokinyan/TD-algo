#include "hash_table.h"
#include <stdlib.h>
#include <string.h>

static char* copy_key(const char* key) {
    char* copy = malloc(strlen(key) + 1);

    if (copy != NULL)
        strcpy(copy, key);

    return copy;
}

static unsigned long hash(const char* key) {
    unsigned long h = 14695981039346656037UL;

    for (long i = 0; key[i] != '\0'; i++) {
        h ^= (unsigned char)key[i];
        h *= 1099511628211UL;
    }

    return h % HASH_DEFAULT_SIZE;
}

HashEntry* new_hash_map() {
    HashEntry* hashTable = calloc(HASH_DEFAULT_SIZE, sizeof(HashEntry));
    return hashTable;
}

void put(HashEntry* hashTable, const char* key, long long value) {
    unsigned long index = hash(key);
    HashEntry* head = &hashTable[index];

    if (head->key == NULL) {
        head->key = copy_key(key);

        if (head->key == NULL)
            return;

        head->value = value;
        head->nextSameHash = NULL;
        return;
    }

    HashEntry* current_entry = head;
    HashEntry* previous_entry = NULL;

    while (current_entry != NULL) {
        if (strcmp(key, current_entry->key) == 0) {
            current_entry->value = value;
            return;
        }
        previous_entry = current_entry;
        current_entry = current_entry->nextSameHash;
    }

    HashEntry* new_entry = malloc(sizeof(HashEntry));

    if (new_entry == NULL)
        return;

    new_entry->key = copy_key(key);

    if (new_entry->key == NULL) {
        free(new_entry);
        return;
    }

    new_entry->value = value;
    new_entry->nextSameHash = NULL;

    previous_entry->nextSameHash = new_entry;
}

void delete_hash_key(HashEntry* hashTable, const char* key) {
    unsigned long index = hash(key);
    HashEntry* current_entry = &hashTable[index];
    HashEntry* previous_entry = NULL;

    while (current_entry != NULL && current_entry->key != NULL) {
        if (strcmp(key, current_entry->key) == 0) {
            if (previous_entry != NULL) {
                previous_entry->nextSameHash = current_entry->nextSameHash;
                free(current_entry->key);
                free(current_entry);
            } else if (current_entry->nextSameHash != NULL) {
                HashEntry* temp = current_entry->nextSameHash;

                free(current_entry->key);
                *current_entry = *temp;
                free(temp);
            } else {
                free(current_entry->key);
                current_entry->key = NULL;
            }
            return;
        }
        previous_entry = current_entry;
        current_entry = current_entry->nextSameHash;
    }
}

long long get(HashEntry* hashTable, const char* key) {
    unsigned long index = hash(key);
    HashEntry* current_entry = &hashTable[index];

    while (current_entry != NULL && current_entry->key != NULL) {
        if (strcmp(key, current_entry->key) == 0) {
            return current_entry->value;
        }
        current_entry = current_entry->nextSameHash;
    }

    return 0;
}