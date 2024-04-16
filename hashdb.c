/*
insert(key, values)

delete(key)

search(key)
*/

#include "hashdb.h"

#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint32_t hash(const uint8_t* name, size_t length) {
    size_t i = 0;
    uint32_t hash = 0;
    while (i != length) {
        hash += name[i++];
        hash += hash << 10;
        hash ^= hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    return hash;
}