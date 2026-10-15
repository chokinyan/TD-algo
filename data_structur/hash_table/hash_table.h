#ifndef MY_HASH_TABLE_H
#define MY_HASH_TABLE_H

#define HASH_DEFAULT_SIZE 10007

typedef struct HashEntry {
    char* key;
    long long value;
    struct HashEntry* nextSameHash;
} HashEntry;

HashEntry* new_hash_map();

static unsigned long hash(const char* key);

void put(HashEntry* hashTable, const char* key, long long value);

void delete_hash_key(HashEntry* hashTable, const char* key);

long long get(HashEntry* hashTable, const char* key);

static char* copy_key(const char* key);

#endif
