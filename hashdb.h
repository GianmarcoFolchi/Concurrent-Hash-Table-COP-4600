#include <pthread.h>  // For pthread_rwlock_t
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hash_struct {
    uint32_t hash;
    char name[50];
    uint32_t salary;
    struct hash_struct *next;
} hashRecord;

hashRecord *insert(hashRecord *head, const char *key, uint32_t salary);
hashRecord *search(hashRecord *head, const char *key);
hashRecord *delete(hashRecord *head, const char *key);
uint32_t hash(const uint8_t *name, size_t length);
void printList(hashRecord *head);